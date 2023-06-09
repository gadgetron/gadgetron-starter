#include "SimpleFFT_Python.h"

namespace Gadgetron{

    SimpleFFT_Python::SimpleFFT_Python(const Core::Context& context, const Core::GadgetProperties& props) : Core::ChannelGadget<Core::Acquisition>(context, props) {
        boost::filesystem::path gadgetron_python_path = context.paths.gadgetron_home / "share" / "gadgetron" / "python";
        Gadgetron::initialize_python();
        Gadgetron::add_python_path(gadgetron_python_path.generic_string());
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
            out.push(Core::Image<std::complex<float>>(ISMRMRD::ImageHeader(), std::move(data), std::optional<ISMRMRD::MetaContainer>()));
        }  
    }

    GADGETRON_GADGET_EXPORT(SimpleFFT_Python)
}