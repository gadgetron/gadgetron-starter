#include "SimpleFFT_Python.h"

namespace Gadgetron{

    SimpleFFT_Python::SimpleFFT_Python(const Core::Context& context, const Core::GadgetProperties& props) : Core::ChannelGadget<Core::Acquisition>(context, props) {
        boost::filesystem::path gadgetron_python_path = context.paths.gadgetron_home / "share" / "gadgetron" / "python";
        Gadgetron::initialize_python();
        Gadgetron::add_python_path(gadgetron_python_path.generic_string());
        GDEBUG("INITIALIZE\n");
    }

    void Gadgetron::SimpleFFT_Python::process(Core::InputChannel<Core::Acquisition>& in, Core::OutputChannel& out) {
        // Create a local handle for the Python scaling function
        PythonFunction<hoNDArray<std::complex<float>>> SimpleFFT("SimpleFFT_Python", "SimpleFFT");                

        for (auto acquisition : in) {
            // Get the header, image data, and trajectory for this acquisition
		    auto &header = std::get<ISMRMRD::AcquisitionHeader>(acquisition);
            auto &data = std::get<hoNDArray<std::complex<float>>>(acquisition);
            auto &trajectory = std::get<Core::optional<hoNDArray<float>>>(acquisition);

            // Perform FFT of the acquisition data using Python
            auto image = SimpleFFT(header, data);

            // Output the acquisition
            auto imageHeader = ISMRMRD::ImageHeader();
            imageHeader.matrix_size[0] = 256;
            imageHeader.matrix_size[1] = 256;
            imageHeader.matrix_size[2] = 60;
            imageHeader.channels = 1;
            imageHeader.set = 0;

            out.push(Core::Image<std::complex<float>>(imageHeader, std::move(data), std::optional<ISMRMRD::MetaContainer>()));
        }  
    }

    GADGETRON_GADGET_EXPORT(SimpleFFT_Python)
}