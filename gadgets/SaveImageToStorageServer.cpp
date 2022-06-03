#include "SaveImageToStorageServer.h"

using namespace Gadgetron;
using namespace Gadgetron::Core;

namespace Gadgetron{
    SaveImageToStorageServer::SaveImageToStorageServer(const Core::Context& context, const Core::GadgetProperties& props) 
        : Core::ChannelGadget<Core::Image<float>>(context, props),  sessionSpace(context.storage.session){
        GDEBUG("Context configured for SaveImage\n");
    }

    void Gadgetron::SaveImageToStorageServer::process(Core::InputChannel<Core::Image<float>>& in, Core::OutputChannel& out) {
        for (auto image : in) {
            // Get the header, image data, and trajectory for this acquisition
            auto &header = std::get<ISMRMRD::ImageHeader>(image);
            auto &data = std::get<hoNDArray<float>>(image);
            auto &meta = std::get<Core::optional<ISMRMRD::MetaContainer>>(image);

            try
            {
                sessionSpace->store(storage_uri, data, std::chrono::seconds(storage_duration));
            }
            catch (IncompleteStorageContextException& e)
            {
                GERROR(e.what());
            }

            // Output the image
            out.push(Core::Image<float>(std::move(header), std::move(data), std::move(meta)));
        }  
    }

    GADGETRON_GADGET_EXPORT(SaveImageToStorageServer);
}
