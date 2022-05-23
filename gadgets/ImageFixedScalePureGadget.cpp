#include "ImageFixedScalePureGadget.h"

namespace Gadgetron {

    Core::Image<float> ImageFixedScalePureGadget::process_function(Core::Image<float> image) const {
        // Get the header, image data, and metadata for this image
		auto &header = std::get<ISMRMRD::ImageHeader>(image);
        auto &data = std::get<hoNDArray<float>>(image);
        auto &meta = std::get<Core::optional<ISMRMRD::MetaContainer>>(image);

        // Multiply value by scaleFactor 
        for (auto &value : data){
            value = value * scaleFactor;
        }

        // Return the modified image 
        return Core::Image<float>(std::move(header), std::move(data), std::move(meta));
    }
    GADGETRON_GADGET_EXPORT(ImageFixedScalePureGadget);
}
