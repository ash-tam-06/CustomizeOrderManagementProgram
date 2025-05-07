cmake_minimum_required(VERSION 3.31)
project(Proj1)

set(CMAKE_CXX_STANDARD 20)

# Fetch GoogleTest
include(FetchContent)
FetchContent_Declare(
        googletest
        URL https://github.com/google/googletest/archive/refs/heads/main.zip
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
target_link_libraries(Proj1 Proj1Lib)

# Enable testing
enable_testing()

# Test executable
add_executable(test_orders tests/orders_tests.cpp)

# Link GoogleTest and the static library (Proj1Lib) to the test executable
target_link_libraries(test_orders gtest gtest_main Proj1Lib)

include(GoogleTest)
gtest_discover_tests(test_orders)
