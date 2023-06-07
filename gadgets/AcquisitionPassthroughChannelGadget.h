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
        void process(Core::InputChannel<Core::Acquisition>& input, Core::OutputChannel& output) override;
    };
}