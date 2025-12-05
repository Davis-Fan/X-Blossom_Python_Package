cmake_minimum_required(VERSION 3.19)
project(X-Blossom)


# Set default build type to Release if not specified
if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE Release CACHE STRING "Choose the type of build (Debug or Release)" FORCE)
endif()

cmake_minimum_required(VERSION 3.19)
project(XBlossom LANGUAGES CXX)

# ---------------------- Build type & flags ----------------------

if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE Release CACHE STRING "Choose the type of build (Debug or Release)" FORCE)
endif()

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -pthread")
set(CMAKE_CXX_FLAGS_RELEASE "-O3")

# ---------------------- pybind11 ----------------------

add_subdirectory(external/pybind11)

# ---------------------- Core library (X-Blossom C++) ----------------------
# All core implementation files, NO main(), NO Python bindings

add_library(x_blossom_core
        x_blossom.cpp
        x_blossom_utils.cpp
)

target_include_directories(x_blossom_core
        PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}
)

# ---------------------- CLI executable (for C++ tests/benchmarks) ----------------------

add_executable(Blossom
        main.cpp
        test_x_blossom.cpp
)

target_link_libraries(Blossom
        PRIVATE
        x_blossom_core
)

# ---------------------- Python extension module: x_blossom ----------------------

pybind11_add_module(x_blossom
        x_blossom_pybind.cpp
)

target_link_libraries(x_blossom
        PRIVATE
        x_blossom_core
)





