#pragma once

#include "Gadget.h"
#include "hoNDArray.h"
#include "GadgetMRIHeaders.h"
#include "Node.h"
#include "Types.h"
#include "python_toolbox.h"

namespace Gadgetron{
  class SimpleFFT : public Core::ChannelGadget<IsmrmrdReconData> 
    {
      public:
        using Core::ChannelGadget<IsmrmrdReconData>::ChannelGadget;
        SimpleFFT(const Core::Context& context, const Core::GadgetProperties& props);
        ~SimpleFFT() override = default;
        
        /********************************************//**
        * Accepts incoming image data from an InputChannel, performs FFT recon using python, and returns
        * the resulting data via an OutputChannel
        * @param input Input channel of type Acquisition
        * @param out Output channel to pass reconstructed images
        ***********************************************/
        void process(Core::InputChannel<IsmrmrdReconData>& input, Core::OutputChannel& output) override;
      protected:
        Gadgetron::Core::Context::Header header;
    };
}