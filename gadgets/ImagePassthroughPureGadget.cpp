#include "ImagePassthroughPureGadget.h"

namespace Gadgetron {

    Core::Image<std::complex<float>> ImagePassthroughPureGadget::process_function(Core::Image<std::complex<float>> image) const {
        // Get the header, image data, and metadata for this image
		auto &header = std::get<ISMRMRD::ImageHeader>(image);
        auto &data = std::get<hoNDArray<std::complex<float>>>(image);
        auto &meta = std::get<Core::optional<ISMRMRD::MetaContainer>>(image);

        // Do nothing 
        GDEBUG("Passing image through.");

        // Return the modified image 
        return Core::Image<std::complex<float>>(std::move(header), std::move(data), std::move(meta));
    }
    GADGETRON_GADGET_EXPORT(ImagePassthroughPureGadget);
}
