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

        /********************************************//**
        *  Accepts incoming image data from an InputChannel, discards the image data, replaces it with 
        *  data loaded from a storage URI, then sends the loaded image out over the OutputChannel
        *  @param input Input channel of type Image
        *  @param out Output channel to pass the loaded Image
        ***********************************************/
        void process(Core::InputChannel<Core::Image<float>>& input, Core::OutputChannel& output) override;
    protected:
        std::shared_ptr<Gadgetron::SessionSpace> sessionSpace;
        /********************************************//**
        *  storage_uri is a string used as a URI within the storage server. Image data from the URI is used to replace
        *  the incoming image dataset 
        ***********************************************/
        NODE_PROPERTY(storage_uri, std::string, "URI from which to load the image", "SaveImageSample");
  };
}
