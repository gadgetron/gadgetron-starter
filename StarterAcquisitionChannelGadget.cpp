#include "StarterAcquisitionChannelGadget.h"

using namespace Gadgetron::Core;

namespace {
    Acquisition add_noise(Acquisition acq, float maxNormalizedNoise) {

        ISMRMRD::AcquisitionHeader head = std::get<ISMRMRD::AcquisitionHeader>(acq);
        hoNDArray<std::complex<float>> data = std::get<hoNDArray<std::complex<float>>>(acq);

        float random;
        float randomNoiseScalar;
        hoNDArray<std::complex<float>> noise = hoNDArray<std::complex<float>>(data);

        for (auto&& d : noise){
            random  =  (((static_cast <float> (rand()) / static_cast <float> (RAND_MAX)) - 0.5f)) * 2; // Random -1:1 float
            randomNoiseScalar = 1 + (random*maxNormalizedNoise);
            d = std::complex<float>(randomNoiseScalar);
        }

        auto dataM = as_arma_matrix(data);
        auto noiseM = as_arma_matrix(noise);
        dataM %= noiseM;

        std::get<hoNDArray<std::complex<float>>>(acq) = data;

        return acq;
    }
}

namespace Gadgetron {
    StarterAcquisitionChannelGadget::StarterAcquisitionChannelGadget(const Context& context, const GadgetProperties& props)
        : ChannelGadget<Acquisition>(context, props){}

    void StarterAcquisitionChannelGadget::process(InputChannel<Acquisition>& input, OutputChannel& output) {
        for (auto acq : input) {
            GINFO_STREAM("Adding random noise to raw data")
            output.push(std::move(add_noise(acq,MaxAddedNoise)));
        }
    }
    GADGETRON_GADGET_EXPORT(StarterAcquisitionChannelGadget)
}
