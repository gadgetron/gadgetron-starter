#include "ImageFixedScalePythonChannelGadget.h"

namespace Gadgetron{

    ImageFixedScalePythonChannelGadget::ImageFixedScalePythonChannelGadget(const Core::Context& context, const Core::GadgetProperties& props) : Core::ChannelGadget<Core::Image<float>>(context, props) {
        boost::filesystem::path gadgetron_python_path = context.paths.gadgetron_home / "share" / "gadgetron" / "python";
        Gadgetron::initialize_python();
        Gadgetron::add_python_path(gadgetron_python_path.generic_string());
    }

    void Gadgetron::ImageFixedScalePythonChannelGadget::process(Core::InputChannel<Core::Image<float>>& in, Core::OutputChannel& out) {
        // Create a local handle for the Python scaling function
        PythonFunction<hoNDArray<float>> scaleImageData("ImageFixedScalePythonChannelGadget", "scaleImageData");                

        for (auto image : in) {
            // Get the header, image data, and trajectory for this acquisition
            auto &header = std::get<ISMRMRD::ImageHeader>(image);
            auto &data = std::get<hoNDArray<float>>(image);
            auto &meta = std::get<Core::optional<ISMRMRD::MetaContainer>>(image);

            // Scale the image data using Python
            data = scaleImageData(header, data, scaleFactor);

            // Output the acquisition
            out.push(Core::Image<float>(std::move(header), std::move(data), std::move(meta)));
        }  
    }

    GADGETRON_GADGET_EXPORT(ImageFixedScalePythonChannelGadget)
}