# gadgetron-starter
A starter project for new Gadgetron developers

# Setting up a development environment

Create the development environment with: conda env create -f environment.yml
After activating the environment (with conda activate gadgetron-starter), you should be able to check that everything is working with gadgetron --info

# Included Samples/Templates
- ImagePassthroughPureGadget: PureGadget that accepts and returns Core::Image<complex<float>>, without modifying the image at all
- ImagePassthroughPureGadget: PureGadget that accepts and returns Core::Image<float> and has one parameter (scaleFactor). Uses an iterator to scale all pixels in the input image via multiplying by scaleFactor. 
- AcquisitionPassthroughChannelGadget: ChannelGadget that accepts and returns Core::Acquisition, without modifying the acquisition at all

