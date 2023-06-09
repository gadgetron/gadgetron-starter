/*********************************************************************
 * \file  SimpleFFT_CPP.cpp
 * 
 * \brief Implementation of the class SimpleFFT_CPP.
 *********************************************************************/

#include "SimpleFFT_CPP.h"

namespace Gadgetron{

  void Gadgetron::SimpleFFT_CPP::process(Core::InputChannel<Core::Acquisition>& in, Core::OutputChannel& out) {
      for (auto acquisition : in) {
        // Get the header, image data, and trajectory for this acquisition
		    auto &header = std::get<ISMRMRD::AcquisitionHeader>(acquisition);
        auto &data = std::get<hoNDArray<std::complex<float>>>(acquisition);
        auto &trajectory = std::get<Core::optional<hoNDArray<float>>>(acquisition);

        // Run Recon
        auto image = data;

        // Output the acquisition
        out.push(Core::Image<std::complex<float>>(ISMRMRD::ImageHeader(), std::move(image), std::optional<ISMRMRD::MetaContainer>()));
      }  
  }
  GADGETRON_GADGET_EXPORT(SimpleFFT_CPP)
}