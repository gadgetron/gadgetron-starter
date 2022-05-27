cmake_minimum_required(VERSION 3.21)
project(gadgetron-starter)


set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS ON)
set(CUDA_NVCC_FLAGS "${CUDA_NVCC_FLAGS} -std=c++17")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++17")

set(NAME gadgetron-starter)
set(GADGETRON_INSTALL_CONFIG_PATH share/gadgetron/config)

find_package(Gadgetron REQUIRED)
find_package(cpr REQUIRED)
find_package(ISMRMRD REQUIRED)
find_package(Python3 COMPONENTS Development NumPy REQUIRED)

set(gadgetron_starter_header_files
        gadgets/AcquisitionPassthroughChannelGadget.h
        gadgets/ImagePassthroughPureGadget.h
        gadgets/ImageFixedScalePureGadget.h
        gadgets/ImageFixedScalePythonChannelGadget.h
        gadgets/SaveImageToStorageServer.h
)

set(gadgetron_starter_src_files
        gadgets/AcquisitionPassthroughChannelGadget.cpp
        gadgets/ImagePassthroughPureGadget.cpp
        gadgets/ImageFixedScalePureGadget.cpp
        gadgets/ImageFixedScalePythonChannelGadget.cpp
        gadgets/SaveImageToStorageServer.cpp
)

set(gadgetron_starter_python_files
        gadgets/ImageFixedScalePythonChannelGadget.py
)

set(gadgetron_starter_config_files
        config/default_pure_passthrough.xml
        config/default_channel_passthrough.xml
        config/default_image_fixed_scale.xml
        config/default_channel_python_fixed_scale.xml
        config/default_save_image_to_storage_server.xml
)

add_library(${NAME} SHARED
    ${gadgetron_starter_header_files}
    ${gadgetron_starter_src_files}
    ${gadgetron_starter_config_files}
    ${gadgetron_starter_python_files}
)

target_link_libraries(${NAME} 
        Gadgetron::gadgetron_core
	Gadgetron::gadgetron_mricore 
        Gadgetron::gadgetron_toolbox_python
)

install(TARGETS ${NAME}
        LIBRARY DESTINATION lib
        ARCHIVE DESTINATION lib
        RUNTIME DESTINATION bin
        COMPONENT main
)

install(FILES ${gadgetron_starter_config_files} DESTINATION ${GADGETRON_INSTALL_CONFIG_PATH} COMPONENT main)
install(FILES ${gadgetron_starter_python_files} DESTINATION ${GADGETRON_INSTALL_PYTHON_MODULE_PATH} COMPONENT main)

