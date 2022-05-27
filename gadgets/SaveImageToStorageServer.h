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
        void process(Core::InputChannel<Core::Image<float>>& input, Core::OutputChannel& output) override;
    protected:
        std::shared_ptr<Gadgetron::MeasurementSpace> measurementSpace;
        NODE_PROPERTY(storage_uri, std::string, "URI at which to save the image", "SaveImageSample");
        NODE_PROPERTY(storage_duration, int, "Duration to store the image in seconds", 600);    
  };
}
