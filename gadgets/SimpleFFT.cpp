#include "SimpleFFT.h"

namespace Gadgetron{

    SimpleFFT::SimpleFFT(const Core::Context& context, const Core::GadgetProperties& props) : Core::ChannelGadget<IsmrmrdReconData>(context, props) {
        boost::filesystem::path gadgetron_python_path = context.paths.gadgetron_home / "share" / "gadgetron" / "python";
        Gadgetron::initialize_python();
        Gadgetron::add_python_path(gadgetron_python_path.generic_string());
        header = context.header;
        GDEBUG("INITIALIZE\n");
    }

    void Gadgetron::SimpleFFT::process(Core::InputChannel<IsmrmrdReconData>& in, Core::OutputChannel& out) {
        // Create a local handle for the Python scaling function
        PythonFunction<hoNDArray<float>> SimpleFFT("SimpleFFT", "SimpleFFT");     
    
        // Iterate through the reconData objects           
        for (IsmrmrdReconData reconData : in) {
            for (std::vector<IsmrmrdReconBit>::iterator it = reconData.rbit_.begin(); it != reconData.rbit_.end(); ++it) {

                // Perform FFT of the acquisition data using Python
                auto image = SimpleFFT(it->data_.data_);

                // Build barebones image header
                auto imageHeader = ISMRMRD::ImageHeader();
                imageHeader.matrix_size[0] = image.get_size(0);
                imageHeader.matrix_size[1] = image.get_size(1);;
                imageHeader.matrix_size[2] = image.get_size(2);
                imageHeader.channels = image.get_size(3);
                imageHeader.image_type = ISMRMRD::ISMRMRD_ImageTypes::ISMRMRD_IMTYPE_MAGNITUDE;

                imageHeader.measurement_uid = it->data_.headers_[0].measurement_uid;
                imageHeader.field_of_view[0] = header.encoding[0].reconSpace.fieldOfView_mm.x;
                imageHeader.field_of_view[1] = header.encoding[0].reconSpace.fieldOfView_mm.y;
                imageHeader.field_of_view[2] = header.encoding[0].reconSpace.fieldOfView_mm.z;
                imageHeader.read_dir[0] = it->data_.headers_[0].read_dir[0];
                imageHeader.read_dir[1] = it->data_.headers_[0].read_dir[1];
                imageHeader.read_dir[2] = it->data_.headers_[0].read_dir[2];
                imageHeader.phase_dir[0] = it->data_.headers_[0].phase_dir[0];
                imageHeader.phase_dir[1] = it->data_.headers_[0].phase_dir[1];
                imageHeader.phase_dir[2] = it->data_.headers_[0].phase_dir[2];  
                imageHeader.slice_dir[0] = it->data_.headers_[0].slice_dir[0];
                imageHeader.slice_dir[1] = it->data_.headers_[0].slice_dir[1];
                imageHeader.slice_dir[2] = it->data_.headers_[0].slice_dir[2];  
                imageHeader.patient_table_position[0] = it->data_.headers_[0].patient_table_position[0];
                imageHeader.patient_table_position[1] = it->data_.headers_[0].patient_table_position[1];
                imageHeader.patient_table_position[2] = it->data_.headers_[0].patient_table_position[2];

                // Send images to next gadget
                out.push(Core::Image<float>(imageHeader, std::move(image), std::optional<ISMRMRD::MetaContainer>()));
            }
        }
        
    }

    GADGETRON_GADGET_EXPORT(SimpleFFT)
}