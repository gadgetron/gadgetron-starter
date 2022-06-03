#pragma once

#include "Gadget.h"
#include "hoNDArray.h"
#include "GadgetMRIHeaders.h"
#include "Node.h"
#include "Types.h"

namespace Gadgetron {
    class LoadImageFromStorageServer : public Core::ChannelGadget<Core::Image<float>> {
    public:
        using Core::ChannelGadget<Core::Image<float>>::ChannelGadget;
        LoadImageFromStorageServer(const Core::Context& context, const Core::GadgetProperties& props);
        ~LoadImageFromStorageServer() override = default;
        void process(Core::InputChannel<Core::Image<float>>& input, Core::OutputChannel& output) override;
    protected:
        std::shared_ptr<Gadgetron::SessionSpace> sessionSpace;
        NODE_PROPERTY(storage_uri, std::string, "URI from which to load the image", "SaveImageSample");
  };
}
