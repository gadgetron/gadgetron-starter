cmake_minimum_required(VERSION 3.21)
project(gadgetron-starter)
set(CMAKE_CXX_STANDARD 17)

set(NAME gadgetron-starter)
set(GADGETRON_INSTALL_CONFIG_PATH share/gadgetron/config)

find_package(Gadgetron REQUIRED)
find_package(cpr REQUIRED)
find_package(ISMRMRD REQUIRED)

set(gadgetron_starter_header_files
        gadgets/AcquisitionPassthroughChannelGadget.h
        gadgets/ImagePassthroughPureGadget.h
        gadgets/ImageFixedScalePureGadget.h
)

set(gadgetron_starter_src_files
        gadgets/AcquisitionPassthroughChannelGadget.cpp
        gadgets/ImagePassthroughPureGadget.cpp
        gadgets/ImageFixedScalePureGadget.cpp
)

set(gadgetron_starter_config_files
        config/default_pure_passthrough.xml
        config/default_channel_passthrough.xml
        config/default_image_fixed_scale.xml
)


add_library(${NAME} SHARED
    ${gadgetron_starter_header_files}
    ${gadgetron_starter_src_files}
    ${gadgetron_starter_config_files}
)

target_link_libraries(${NAME} Gadgetron::gadgetron_core)

install(TARGETS ${NAME}
        LIBRARY DESTINATION lib
        ARCHIVE DESTINATION lib
        RUNTIME DESTINATION bin
        COMPONENT main
        )

install(FILES ${gadgetron_starter_config_files} DESTINATION ${GADGETRON_INSTALL_CONFIG_PATH} COMPONENT main)
