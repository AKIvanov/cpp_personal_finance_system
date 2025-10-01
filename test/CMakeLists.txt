# test/CMakeLists.txt
cmake_minimum_required(VERSION 3.16)

include(FetchContent)

FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/refs/tags/v1.14.0.zip
  DOWNLOAD_EXTRACT_TIMESTAMP TRUE   # silence CMP0135 warning
)
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

enable_testing()

# 1) Create the test executable (make sure the file exists)
add_executable(money_tests
  MoneyTests.cpp
)

# 2) Link against your library and gtest main
target_link_libraries(money_tests
  PRIVATE
    bank_lib
    GTest::gtest_main
)

# 3) Headers for tests
target_include_directories(money_tests PRIVATE ${CMAKE_SOURCE_DIR}/include)

# 4) Register tests with CTest
include(GoogleTest)
gtest_discover_tests(money_tests)
