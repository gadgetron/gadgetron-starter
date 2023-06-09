# gadgetron_simple_fft
delor

## Included Samples/Templates

### SimpleFFT_Python
lorem

### SimpleFFT_CPP
ipsum

## Getting Started

Using vscode's devcontainer tools is the easiest way to get started. In vscode, a popup should appear when opening this repository offering to rebuild and reopen in a devcontainer - click yes, and The included docker file will be built and the repository will be mapped in so you can immediately start modifying code. 

### Dependencies for Devcontainer Environment 
1. Docker
2. VSCode
3. Devcontainer extension for VSCode

### Opening Devcontainer
1. Open vscode
2. Press F1-> Rebuild and Reopen in Devcontainer 

###Building in dev environment
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
