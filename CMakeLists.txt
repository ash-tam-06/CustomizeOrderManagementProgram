cmake_minimum_required(VERSION 3.14)
project(Proj1)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Platform-specific settings
if(MSVC)
    # Visual Studio settings
    add_compile_options(/W4)
    # Use MultiThreaded DLL runtime
    set(CMAKE_MSVC_RUNTIME_LIBRARY "MultiThreaded$<$<CONFIG:Debug>:Debug>DLL")
else()
    # GCC/Clang settings
    add_compile_options(-Wall -Wextra)
endif()

# Fetch GoogleTest
include(FetchContent)
FetchContent_Declare(
        googletest
        URL https://github.com/google/googletest/archive/refs/tags/v1.13.0.zip
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

# Create a static library for the project
add_library(Proj1Lib STATIC
        src/addOrder.cpp
        src/deleteOrder.cpp
        src/displayOrders.cpp
        src/getValidInt.cpp
        src/getValidDouble.cpp
        src/globalVariable.cpp
        src/menu.cpp
        src/printOrders.cpp
        src/searchOrder.cpp
        src/setupCustomerFields.cpp
        src/setupProducts.cpp
)

# Set include directories
target_include_directories(Proj1Lib PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/include
)

# Main project executable
add_executable(Proj1 main.cpp)
target_link_libraries(Proj1 PRIVATE Proj1Lib)

# Testing
enable_testing()

# Test executable
add_executable(test_orders tests/orders_tests.cpp)

# Link GoogleTest and the static library to the test executable
target_link_libraries(test_orders PRIVATE
        gtest
        gtest_main
        Proj1Lib
)

include(GoogleTest)
gtest_discover_tests(test_orders)