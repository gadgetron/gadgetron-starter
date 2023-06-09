cmake_minimum_required(VERSION 3.21)
project(gadgetron_simpleFFT)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS ON)
set(CUDA_NVCC_FLAGS "${CUDA_NVCC_FLAGS} -std=c++17")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++17")

set(NAME gadgetron_simpleFFT)
set(GADGETRON_INSTALL_CONFIG_PATH share/gadgetron/config)

find_package(Gadgetron REQUIRED)
find_package(ISMRMRD REQUIRED)
find_package(Python3 COMPONENTS Development NumPy REQUIRED)

set(gadgetron_simpleFFT_header_files
        gadgets/SimpleFFT_Python.h
        gadgets/SimpleFFT_CPP.h
)

set(gadgetron_simpleFFT_src_files
        gadgets/SimpleFFT_Python.cpp
        gadgets/SimpleFFT_CPP.cpp
)

set(gadgetron_simpleFFT_python_files
        gadgets/SimpleFFT_Python.py
)

set(gadgetron_simpleFFT_config_files
        config/default_simple_fft_cpp.xml
        config/default_simple_fft_python.xml
)

add_library(${NAME} SHARED
    ${gadgetron_simpleFFT_header_files}
    ${gadgetron_simpleFFT_src_files}
    ${gadgetron_simpleFFT_python_files}
    ${gadgetron_simpleFFT_config_files}
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

option(BUILD_DOCUMENTATION Off)
if(BUILD_DOCUMENTATION)
    add_subdirectory(doc)
endif()

install(FILES ${gadgetron_simpleFFT_python_files} DESTINATION ${GADGETRON_INSTALL_PYTHON_MODULE_PATH} COMPONENT main)
install(FILES ${gadgetron_simpleFFT_config_files} DESTINATION ${GADGETRON_INSTALL_CONFIG_PATH} COMPONENT main)

