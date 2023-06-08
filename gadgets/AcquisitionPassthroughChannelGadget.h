/*********************************************************************
 * @file  AcquisitionPassthroughChannelGadget.h
 * 
 * @brief Header of the class AcquisitionPassthroughChannelGadget.
 *********************************************************************/

#pragma once

#include "Gadget.h"
#include "hoNDArray.h"
#include "GadgetMRIHeaders.h"
#include "Node.h"
#include "Types.h"

namespace Gadgetron{
  class AcquisitionPassthroughChannelGadget : public Core::ChannelGadget<Core::Acquisition> 
    {
      public:
        using Core::ChannelGadget<Core::Acquisition>::ChannelGadget;
        ~AcquisitionPassthroughChannelGadget() override = default;

        /********************************************//**
        *  Accepts incoming acquisition data from an InputChannel and immediately pushes it out via an OutputChannel
        *  with no changes to the data. 
         * @param input Input channel of type Acquisition
         * @param out Output channel to pass unmodified acquisition data
         */
        ***********************************************/
        void process(Core::InputChannel<Core::Acquisition>& input, Core::OutputChannel& output) override; 
    };
}