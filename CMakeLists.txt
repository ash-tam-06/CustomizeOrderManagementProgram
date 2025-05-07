cmake_minimum_required(VERSION 3.24)
project(Proj1)

set(CMAKE_CXX_STANDARD 20)

# Check the platform for any specific configurations
if(WIN32)
    # Any Windows-specific setup
    add_definitions(-D_CRT_SECURE_NO_WARNINGS)  # Disable specific warnings for MSVC
endif()

if(APPLE OR UNIX)
    # Any macOS/Linux-specific setup
endif()

# Fetch GoogleTest with a specific release version
include(FetchContent)
FetchContent_Declare(
        googletest
        URL https://github.com/google/googletest/archive/refs/tags/release-1.11.0.zip
)
FetchContent_MakeAvailable(googletest)

# Create a static library for the project
add_library(Proj1Lib STATIC
        src/addOrder.cpp
        include/addOrder.hpp
        src/deleteOrder.cpp
        include/deleteOrder.hpp
        src/displayOrders.cpp
        include/displayOrders.hpp
        src/getValidInt.cpp
        include/getValidInt.hpp
        src/getValidDouble.cpp
        include/getValidDouble.hpp
        src/globalVariable.cpp
        include/globalVariable.hpp
        src/menu.cpp
        include/menu.hpp
        src/printOrders.cpp
        include/printOrders.hpp
        src/searchOrder.cpp
        include/searchOrder.hpp
        src/setupCustomerFields.cpp
        include/setupCustomerFields.hpp
        src/setupProducts.cpp
        include/setupProducts.hpp
)

# Main project executable
add_executable(Proj1 main.cpp)
target_link_libraries(Proj1 PRIVATE Proj1Lib)

# Enable testing
enable_testing()

# Test executable
add_executable(test_orders tests/orders_tests.cpp)

# Link GoogleTest and the static library (Proj1Lib) to the test executable
target_link_libraries(test_orders PRIVATE gtest gtest_main Proj1Lib)

# Discover GoogleTest tests
include(GoogleTest)
gtest_discover_tests(test_orders)
