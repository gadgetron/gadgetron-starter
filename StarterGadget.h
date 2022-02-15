/*
 * StarterGadget.h
 *  Created on: Feb 15, 2022
 *  Author: Andrew Dupuis
 *
 *  Based On: AutoScaleGadget.h
 *      Created on: Dec 19, 2011
 *      Author: Michael S. Hansen
 */

#ifndef STARTERGADGET_H_
#define STARTERGADGET_H_

#include "Gadget.h"
#include "hoNDArray.h"
#include "gadgetron_mricore_export.h"

#include <ismrmrd/ismrmrd.h>

namespace Gadgetron{

  class EXPORTGADGETSMRICORE StarterGadget:
    public Gadget2<ISMRMRD::ImageHeader,hoNDArray< float > >
  {
  public:
    GADGET_DECLARE(StarterGadget);

    StarterGadget();
    virtual ~StarterGadget();

  protected:
    GADGET_PROPERTY(max_value, float, "Maximum value (after scaling)", 2048);

    virtual int process(GadgetContainerMessage<ISMRMRD::ImageHeader>* m1, GadgetContainerMessage< hoNDArray< float > >* m2);
    virtual int process_config(ACE_Message_Block *mb);

    unsigned int histogram_bins_;
    std::vector<size_t> histogram_;
    float current_scale_;
    float max_value_;
  };
}

#endif /* STARTERGADGET_H_ */