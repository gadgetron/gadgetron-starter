# gadgetron-starter
A starter project for new Gadgetron developers that includes a dockerfile for building out of tree gadgets into new docker images, a few simple template gadgets with common reference structures for Acquisition and Image datatypes, and a reference cmakelist file for building out of tree gadgets. 

This example also includes scaffolding for generating ReadTheDocs/Doxygen documentation for the included sample gadget, as well as performing integration tests on new data and configuration files using Gadgetron's test infrastructure.

## Included Samples/Templates

### AcquisitionPassthroughChannelGadget
ChannelGadget that accepts and returns Core::Acquisition, without modifying the acquisition at all

### ImagePassthroughPureGadget
PureGadget that accepts and returns Core::Image<complex<float>>, without modifying the image at all

### ImageFixedScalePureGadget
PureGadget that accepts and returns Core::Image<float> and has one parameter (scaleFactor). Uses an iterator to scale all pixels in the input image via multiplying by scaleFactor

### ImageFixedScalePythonChannelGadget
ChannelGadget that accepts and returns Core::Image<float> and has one parameter (scaleFactor). Uses a python script to perform scaling of all pixels in the input image via multiplying by scaleFactor. 

### SaveImageToStorageServer
ChannelGadget that saves incoming image data to the ISMRMRD Storage Server instance

### LoadImageFromStorageServer
ChannelGadget that loads previously-stored image data from the ISMRMRD Storage Server instance

## Getting Started

Using vscode's devcontainer tools is the easiest way to get started. In vscode, a popup should appear when opening this repository offering to rebuild and reopen in a devcontainer - click yes, and The included docker file will be built and the repository will be mapped in so you can immediately start modifying code. 

### Dependencies for Devcontainer Environment 
1. Docker
2. VSCode
3. Devcontainer extension for VSCode

### Opening Devcontainer
1. Open vscode
2. Press F1-> Rebuild and Reopen in Devcontainer 

### Building in dev environment
1. mkdir build
2. cd build
3. cmake -GNinja -DCMAKE_BUILD_TYPE=Release -DCMAKE_INSTALL_PREFIX=${CONDA_PREFIX} ../
4. ninja install

### Running Tests
1. cd test 
2. Run: ./getData.sh
3. Run: ./runTests.sh cases/* 

## Building Deployment Image
Once your code is in a stable state, a final docker container can be built using `docker build .` that strips out code and all dev dependencies to create a runtime environment including the new OOT gadgets.
