#pragma once

#include "PureGadget.h"
#include "Types.h"

namespace Gadgetron{
    class ImagePassthroughPureGadget : public Core::PureGadget<Core::Image<std::complex<float>>, Core::Image<std::complex<float>>> {
    public:
      using Core::PureGadget<Core::Image<std::complex<float>>, Core::Image<std::complex<float>>>::PureGadget;
        Core::Image<std::complex<float>> process_function(Core::Image<std::complex<float>> image) const override;
    };
}
