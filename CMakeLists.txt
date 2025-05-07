cmake_minimum_required(VERSION 3.14)
cmake_policy(VERSION 3.14)

project(Proj1)

set(CMAKE_CXX_STANDARD 20)

# Check the platform for any specific configurations
if(WIN32)
    add_definitions(-D_CRT_SECURE_NO_WARNINGS)
endif()

if(APPLE OR UNIX)
    # macOS/Linux-specific setup if needed
endif()

# Include GoogleTest from extern folder
add_subdirectory(extern/googletest)

# Create static library for project
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

# Main executable
add_executable(Proj1 main.cpp)
target_link_libraries(Proj1 PRIVATE Proj1Lib)

# Tests
enable_testing()
add_executable(test_orders tests/orders_tests.cpp)
target_link_libraries(test_orders PRIVATE gtest gtest_main Proj1Lib)

include(GoogleTest)
gtest_discover_tests(test_orders)
