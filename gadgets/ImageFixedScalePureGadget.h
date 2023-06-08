#pragma once

#include "PureGadget.h"
#include "Types.h"

namespace Gadgetron{
    class ImageFixedScalePureGadget : public Core::PureGadget<Core::Image<float>, Core::Image<float>> {
    public:
      using Core::PureGadget<Core::Image<float>, Core::Image<float>>::PureGadget;

      /********************************************//**
      *  Applies a fixed scaling constant, defined in the xml config of this gadget, to the input image
      * @param image Image object to scale
      ***********************************************/
      Core::Image<float> process_function(Core::Image<float> image) const override;

      /********************************************//**
      scaleFactor is a floating point scaling factor applied to incoming image voxels (multiplies all image values by this constant)
      ***********************************************/
      NODE_PROPERTY(scaleFactor, float, "Scaling factor (multiply all image values by this constant)", 1);
    };
}
