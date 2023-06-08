/*********************************************************************
 * \file  AcquisitionPassthroughChannelGadget.cpp
 * 
 * \brief Implementation of the class AcquisitionPassthroughChannelGadget.
 *********************************************************************/

#include "AcquisitionPassthroughChannelGadget.h"

namespace Gadgetron{

  /********************************************//**
  *  Accepts incoming acquisition data from an InputChannel and immediately pushes it out via an OutputChannel
  *  with no changes to the data. 
    * @param input Input channel of type Acquisition
    * @param out Output channel to pass unmodified acquisition data
  ***********************************************/
  void Gadgetron::AcquisitionPassthroughChannelGadget::process(Core::InputChannel<Core::Acquisition>& in, Core::OutputChannel& out) {
      for (auto acquisition : in) {
        // Get the header, image data, and trajectory for this acquisition
		    auto &header = std::get<ISMRMRD::AcquisitionHeader>(acquisition);
        auto &data = std::get<hoNDArray<std::complex<float>>>(acquisition);
        auto &trajectory = std::get<Core::optional<hoNDArray<float>>>(acquisition);

        // Do nothing
        GDEBUG("Passing acquisition through.");

        // Output the acquisition
        out.push(Core::Acquisition(std::move(header), std::move(data), std::move(trajectory)));
      }  
  }
  GADGETRON_GADGET_EXPORT(AcquisitionPassthroughChannelGadget)
}