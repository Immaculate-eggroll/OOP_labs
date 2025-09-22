cmake_minimum_required(VERSION 3.14)
project(to24 LANGUAGES CXX)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)


add_library(to24 STATIC src/to24.cpp)
target_include_directories(to24 PUBLIC ${CMAKE_SOURCE_DIR}/include)


add_executable(to24_main src/main.cpp)
target_link_libraries(to24_main PRIVATE to24)


include(FetchContent)
FetchContent_Declare(
googletest
URL https://github.com/google/googletest/archive/refs/heads/main.zip
)
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)


add_executable(tests tests/to24_tests.cpp)
target_link_libraries(tests PRIVATE to24 GTest::gtest_main)


include(GoogleTest)
gtest_discover_tests(tests)
