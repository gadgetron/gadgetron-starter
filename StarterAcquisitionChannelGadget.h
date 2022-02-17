#include "Node.h"
#include "Types.h"
#include "gadgetron_mricore_export.h"
#include "hoNDArray.h"
#include "hoArmadillo.h"
#include "hoMatrix.h"
#include <complex>

#include "hoMatrix.h"
#include "hoNDArray_elemwise.h"
#include "hoNDArray_linalg.h"
#include "hoNDArray_reductions.h"

namespace Gadgetron {
    class StarterAcquisitionChannelGadget : public Core::ChannelGadget<Core::Acquisition> {
      public:
        StarterAcquisitionChannelGadget(const Core::Context &, const Core::GadgetProperties &);
        void process(Core::InputChannel<Core::Acquisition> &, Core::OutputChannel &) override;
        NODE_PROPERTY(MaxAddedNoise, float, "MaxAddedNoise", 1.0f);
    };
}
