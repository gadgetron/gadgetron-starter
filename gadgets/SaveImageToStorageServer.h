#pragma once

#include "Gadget.h"
#include "hoNDArray.h"
#include "GadgetMRIHeaders.h"
#include "Node.h"
#include "Types.h"

namespace Gadgetron {
    class SaveImageToStorageServer : public Core::ChannelGadget<Core::Image<float>> {
    public:
        using Core::ChannelGadget<Core::Image<float>>::ChannelGadget;
        SaveImageToStorageServer(const Core::Context& context, const Core::GadgetProperties& props);
        ~SaveImageToStorageServer() override = default;

        /********************************************//**
        * Accepts incoming image data from an InputChannel, svaes the image data to a storage URI defined by the gadget's 
        * XML configuration, then pushes the unmodified image data out via an OutputChannel
        * @param input Input channel of type Acquisition
        * @param out Output channel to pass unmodified acquisition data
        ***********************************************/
        void process(Core::InputChannel<Core::Image<float>>& input, Core::OutputChannel& output) override;
    protected:
        std::shared_ptr<Gadgetron::SessionSpace> sessionSpace;
        /********************************************//**
        *  storage_uri is a string used as a URI within the storage server. Incoming image data is saved to this URI
        ***********************************************/
        NODE_PROPERTY(storage_uri, std::string, "URI at which to save the image", "SaveImageSample");
        /********************************************//**
        *  storage_duration is an integer number of seconds for which the storage server will keep the saved image data
        ***********************************************/
        NODE_PROPERTY(storage_duration, int, "Duration to store the image in seconds", 600);    
  };
}
