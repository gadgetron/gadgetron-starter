#pragma once

#include "PureGadget.h"
#include "Types.h"

namespace Gadgetron{
    class ImageFixedScalePureGadget : public Core::PureGadget<Core::Image<float>, Core::Image<float>> {
    public:
      using Core::PureGadget<Core::Image<float>, Core::Image<float>>::PureGadget;
        Core::Image<float> process_function(Core::Image<float> image) const override;
      NODE_PROPERTY(scaleFactor, float, "Scaling factor (multiply all image values by this constant)", 1);
    };
}
