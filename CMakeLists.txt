# Define the minimum CMAKE version for the gadget
cmake_minimum_required(VERSION 3.10)

# Name this gadget's project
project(StarterGadget LANGUAGES CXX C)

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
cuda_add_library(StarterGadget SHARED 
	StarterGadget_lib_export.h
	StarterGadget.cpp
	StarterGadget.h
)

# Link any of the Gadgetron core libraries that this gadget DLL will need
target_link_libraries(StarterGadget
	Gadgetron::gadgetron_core
	gadgetron_toolbox_hostutils
	gadgetron_toolbox_gpu
	${CUDA_LIBRARIES}
)

# Install the compiled Gadget DLL's to the proper gadgetron locations
install(TARGETS StarterGadget
	LIBRARY DESTINATION lib
	ARCHIVE DESTINATION lib
	RUNTIME DESTINATION bin
	COMPONENT main
)

# Install the gadget's xml configuration file to the proper gadgetron location
install(FILES StarterGadget.xml 
    DESTINATION ${GADGETRON_INSTALL_CONFIG_PATH} COMPONENT main
)