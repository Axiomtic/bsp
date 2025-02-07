cmake_minimum_required(VERSION 3.22)

#
# This file is generated only once,
# and is not re-generated if converter is called multiple times.
#
# User is free to modify the file as much as necessary
#

# Setup compiler settings
set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED ON)
set(CMAKE_C_EXTENSIONS ON)


# Define the build type
if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE "Debug")
endif()

# Set the project name
set(CMAKE_PROJECT_NAME Template_cmake)

# Include toolchain file
include("cmake/gcc-arm-none-eabi.cmake")

# Enable compile command to ease indexing with e.g. clangd
set(CMAKE_EXPORT_COMPILE_COMMANDS TRUE)

# Enable CMake support for ASM and C languages
enable_language(C ASM)

# Core project settings
project(${CMAKE_PROJECT_NAME})
message("Build type: " ${CMAKE_BUILD_TYPE})

# Create an executable object type
add_executable(${CMAKE_PROJECT_NAME})

# Add STM32CubeMX generated sources
add_subdirectory(cmake/stm32cubemx)

# Link directories setup
target_link_directories(${CMAKE_PROJECT_NAME} PRIVATE
    # Add user defined library search paths
)

# Add sources to executable
file(GLOB BOARD_SOURCES "${CMAKE_SOURCE_DIR}/Board/Src/*.c")
file(GLOB_RECURSE MIDDLEWARE_SOURCES "${CMAKE_SOURCE_DIR}/Middlewares/*.c")  # 递归查找 middleware 文件夹下的所有 .c 文件
target_sources(${CMAKE_PROJECT_NAME} PRIVATE
    # Add user sources here
    ${BOARD_SOURCES}
    ${MIDDLEWARE_SOURCES}
)

# Add include paths
target_include_directories(${CMAKE_PROJECT_NAME} PRIVATE
    # Add user defined include paths
    ${CMAKE_SOURCE_DIR}/Board/Inc  # 包含 Board 文件夹路径
    ${CMAKE_SOURCE_DIR}/Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS  # 包含 Middlewares 文件夹路径
    ${CMAKE_SOURCE_DIR}/Middlewares/Third_Party/FreeRTOS/Source/include  # 包含 Middlewares 文件夹路径
    ${CMAKE_SOURCE_DIR}/Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM4F  # 包含 Middlewares 文件夹路径
)

# Add project symbols (macros)
target_compile_definitions(${CMAKE_PROJECT_NAME} PRIVATE
    # Add user defined symbols
)

# Add linked libraries
target_link_libraries(${CMAKE_PROJECT_NAME}
    stm32cubemx

    # Add user defined libraries
)
