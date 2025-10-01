cmake_minimum_required(VERSION 3.16)

# Set the project name
project(personal_finance_system LANGUAGES CXX)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Library with your app sources
add_library(bank_lib
    src/Account.cpp
    src/CheckingAccount.cpp
    src/Ledger.cpp
    src/SavingsAccount.cpp
)

# Add include directory
target_include_directories(bank_lib PUBLIC ${CMAKE_SOURCE_DIR}/include)

# Build the single executable from your existing file
add_executable(${PROJECT_NAME} main.cpp)

target_link_libraries(${PROJECT_NAME} PRIVATE bank_lib)

# ---- Testing ----
include(CTest)                 # defines BUILD_TESTING option and ctest integration
if (BUILD_TESTING)
  add_subdirectory(test)       # delegate to test/CMakeLists.txt
endif()

# Optional: per-config flags (tweak as you like)
if(NOT CMAKE_CONFIGURATION_TYPES)  # single-config generators
  set(CMAKE_BUILD_TYPE Debug CACHE STRING "Build type")
endif()
set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} -O3 -DNDEBUG")
set(CMAKE_CXX_FLAGS_DEBUG   "${CMAKE_CXX_FLAGS_DEBUG}   -O0 -g")