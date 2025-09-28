cmake_minimum_required(VERSION 3.16)

# Set the project name
project(personal_finance_system LANGUAGES CXX)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Add the executable target
add_executable(personal_finance_system main.cpp)

# Add include directory
target_include_directories(${PROJECT_NAME}
    PRIVATE
        ${PROJECT_SOURCE_DIR}/include
)

# Collect source files (all .cpp in src/)
file(GLOB SOURCES src/*.cpp)

# Build the single executable from your existing file
add_executable(${PROJECT_NAME} ${SOURCES})

# Optional: per-config flags (tweak as you like)
if(NOT CMAKE_CONFIGURATION_TYPES)  # single-config generators
  set(CMAKE_BUILD_TYPE Debug CACHE STRING "Build type")
endif()
set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} -O3 -DNDEBUG")
set(CMAKE_CXX_FLAGS_DEBUG   "${CMAKE_CXX_FLAGS_DEBUG}   -O0 -g")