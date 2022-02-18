# Define the minimum CMAKE version for the gadget
cmake_minimum_required(VERSION 3.10)

# Name this gadget's project
project(StarterGadgets LANGUAGES CXX C)

# Find the Gadgetron core installation
find_package(Gadgetron REQUIRED)
find_package(CUDA)

# Set up the CMAKE compiler versions
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS ON)
set(CUDA_NVCC_FLAGS "${CUDA_NVCC_FLAGS} -std=c++17")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++17")

# Define the gadget's DLL and it's contents
cuda_add_library(StarterGadgets SHARED 
	StarterGadgets_export.h
	StarterImagePureGadget.cpp
	StarterImagePureGadget.h
	StarterImageChannelGadget.cpp
	StarterImageChannelGadget.h
	StarterAcquisitionChannelGadget.cpp
	StarterAcquisitionChannelGadget.h
)


# Link any of the Gadgetron core libraries that this gadget DLL will need
target_link_libraries(StarterGadgets
	Gadgetron::gadgetron_core
	gadgetron_toolbox_cpucore_math
)

# Install the compiled Gadget DLL's to the proper gadgetron locations
install(TARGETS StarterGadgets
	LIBRARY DESTINATION lib
	ARCHIVE DESTINATION lib
	RUNTIME DESTINATION bin
	COMPONENT main
)

# Install the gadget's xml configuration file to the proper gadgetron location
install(FILES config/StarterGadgets.xml
    DESTINATION ${GADGETRON_INSTALL_CONFIG_PATH} COMPONENT main
)