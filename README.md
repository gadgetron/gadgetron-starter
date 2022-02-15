# gadgetron-starter
A starter project for new Gadgetron developers

# Setting up a development environment
(Temporary until a dev conda package)
1. Clone the main gadgetron project (https://github.com/gadgetron/gadgetron)
2. Follow the conda environment instructions to configure and install the gadgetron. 

# Building and installing in conda environment
conda activate gadgetron
git clone https://github.com/gadgetron/gadgetron-starter.git
cd gadgetron-starter
mkdir -p build
cd build
cmake -GNinja -DCMAKE_INSTALL_PREFIX=${CONDA_PREFIX} ../
ninja
ninja install
