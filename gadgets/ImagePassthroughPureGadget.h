#pragma once

#include "PureGadget.h"
#include "Types.h"

namespace Gadgetron{
    class ImagePassthroughPureGadget : public Core::PureGadget<Core::Image<std::complex<float>>, Core::Image<std::complex<float>>> {
    public:
        using Core::PureGadget<Core::Image<std::complex<float>>, Core::Image<std::complex<float>>>::PureGadget;

        /********************************************//**
        *  Accepts an input image and passes it through without any modification
        * @param image Image object to pass through
        ***********************************************/
        Core::Image<std::complex<float>> process_function(Core::Image<std::complex<float>> image) const override;
    };
}
