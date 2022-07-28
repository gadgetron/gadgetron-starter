#include "LoadImageFromStorageServer.h"

using namespace Gadgetron;
using namespace Gadgetron::Core;

namespace Gadgetron{
    LoadImageFromStorageServer::LoadImageFromStorageServer(const Core::Context& context, const Core::GadgetProperties& props) 
        : Core::ChannelGadget<Core::Image<float>>(context, props),  sessionSpace(context.storage.session){
        GDEBUG("Context configured for LoadImage\n");
    }

    void Gadgetron::LoadImageFromStorageServer::process(Core::InputChannel<Core::Image<float>>& in, Core::OutputChannel& out) {
        for (auto image : in) {
            // Get the header, image data, and trajectory for this acquisition
            auto &header = std::get<ISMRMRD::ImageHeader>(image);
            auto &data = std::get<hoNDArray<float>>(image);
            auto &meta = std::get<Core::optional<ISMRMRD::MetaContainer>>(image);

            hoNDArray<float> loadedData;
            try
            {
                loadedData = *(sessionSpace->get_latest<hoNDArray<float>>(storage_uri));
            }
            catch (IncompleteStorageContextException& e)
            {
                GERROR(e.what());
            }

            // Output the loaded data instead of the input data
            out.push(Core::Image<float>(std::move(header), std::move(loadedData), std::move(meta)));
        }  
    }

    GADGETRON_GADGET_EXPORT(LoadImageFromStorageServer);
}
