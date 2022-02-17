#pragma once

#include "Node.h"
#include "Types.h"

namespace Gadgetron {

    /**
     * ImageIndexGadget sets the image_index fields for images.
     *
     * ImageIndexGadget will keep track of individual image series, and number images in each series
     * sequentially.
     */
    class StarterImageChannelGadget : public Core::ChannelGadget<Core::AnyImage> {
      public:
        StarterImageChannelGadget(const Core::Context &, const Core::GadgetProperties &);
        void process(Core::InputChannel<Core::AnyImage> &, Core::OutputChannel &) override;
        NODE_PROPERTY(ImageIndexOffset, int, "ImageIndexOffset", 0);
    };
}