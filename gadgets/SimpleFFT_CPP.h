/*********************************************************************
 * @file  SimpleFFT_CPP.h
 * 
 * @brief Header of the class SimpleFFT_CPP
 *********************************************************************/

#pragma once

#include "Gadget.h"
#include "hoNDArray.h"
#include "GadgetMRIHeaders.h"
#include "Node.h"
#include "Types.h"

namespace Gadgetron{
  class SimpleFFT_CPP : public Core::ChannelGadget<Core::Acquisition> 
    {
      public:
        using Core::ChannelGadget<Core::Acquisition>::ChannelGadget;
        ~SimpleFFT_CPP() override = default;

        /********************************************//**
        * Accepts incoming acquisition data from an InputChannel, performs FFT recon,
        * immediately pushes images out via an OutputChannel
        * with no changes to the data. 
        * @param input Input channel of type Acquisition
        * @param out Output channel to pass reconstructed image data
        ***********************************************/
        void process(Core::InputChannel<Core::Acquisition>& input, Core::OutputChannel& output) override; 
    };
}