# gadgetron-starter
A starter project for new Gadgetron developers

# Setting up a development environment

Create the development environment with: conda env create -f environment.yml
After activating the environment (with conda activate gadgetron-starter), you should be able to check that everything is working with gadgetron --info

# Building in dev environment
cmake -GNinja -DCMAKE_BUILD_TYPE=Release -DUSE_MKL=ON -DCMAKE_INSTALL_PREFIX=${CONDA_PREFIX} ../

# Included Samples/Templates
- AcquisitionPassthroughChannelGadget: ChannelGadget that accepts and returns Core::Acquisition, without modifying the acquisition at all
- ImagePassthroughPureGadget: PureGadget that accepts and returns Core::Image<complex<float>>, without modifying the image at all
- ImageFixedScalePureGadget: PureGadget that accepts and returns Core::Image<float> and has one parameter (scaleFactor). Uses an iterator to scale all pixels in the input image via multiplying by scaleFactor. 
- ImageFixedScalePythonChannelGadget: ChannelGadget that accepts and returns Core::Image<float> and has one parameter (scaleFactor). Uses a python script to perform scaling of all pixels in the input image via multiplying by scaleFactor. 
- SaveImageToStorageServer: ChannelGadget that saves incoming image data to the ISMRMRD Storage Server instance
- LoadImageFromStorageServerr: ChannelGadget that loads previously-stored image data from the ISMRMRD Storage Server instance


# Running Tests
1. cd test 
2. Run: gadgetron_get_integration_test_data
3. Run: gadgetron_run_integration_tests cases/* 