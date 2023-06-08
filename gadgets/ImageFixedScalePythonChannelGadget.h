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
        
        /********************************************//**
        * Accepts incoming image data from an InputChannel, applies a constant scaling factor, and outputs
        * the image data via an OutputChannel
        * @param input Input channel of type Acquisition
        * @param out Output channel to pass unmodified acquisition data
        ***********************************************/
        void process(Core::InputChannel<Core::Image<float>>& input, Core::OutputChannel& output) override;

        /********************************************//**
        scaleFactor is a floating point scaling factor applied to incoming image voxels (multiplies all image values by this constant)
        ***********************************************/
        NODE_PROPERTY(scaleFactor, float, "Scaling factor (multiply all image values by this constant)", 0.1);
    };
}