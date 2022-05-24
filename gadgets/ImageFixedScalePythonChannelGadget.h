#pragma once

#include "Gadget.h"
#include "hoNDArray.h"
#include "GadgetMRIHeaders.h"
#include "Node.h"
#include "Types.h"
#include "python_toolbox.h"

namespace Gadgetron{
  class ImageFixedScalePythonChannelGadget : public Core::ChannelGadget<Core::Image<float>> 
    {
      public:
        using Core::ChannelGadget<Core::Image<float>>::ChannelGadget;
        ImageFixedScalePythonChannelGadget(const Core::Context& context, const Core::GadgetProperties& props);
        ~ImageFixedScalePythonChannelGadget() override = default;
        void process(Core::InputChannel<Core::Image<float>>& input, Core::OutputChannel& output) override;
        NODE_PROPERTY(scaleFactor, float, "Scaling factor (multiply all image values by this constant)", 0.1);
    };
}