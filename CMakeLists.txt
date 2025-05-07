cmake_minimum_required(VERSION 3.14)
cmake_policy(VERSION 3.14)

project(Proj1 VERSION 1.0 LANGUAGES CXX)

# Set C++ standard to 20 as required
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Platform-specific configurations
if(WIN32)
    add_definitions(-D_CRT_SECURE_NO_WARNINGS)
    # Add MSVC runtime library configuration if needed
    if(MSVC)
        set(CMAKE_MSVC_RUNTIME_LIBRARY "MultiThreaded$<$<CONFIG:Debug>:Debug>")
    endif()
endif()

# Fetch GoogleTest if it's not present
include(FetchContent)
FetchContent_Declare(
        googletest
        GIT_REPOSITORY https://github.com/google/googletest.git
        GIT_TAG v1.14.0
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

# Include directories
include_directories(${PROJECT_SOURCE_DIR}/include)

# Create static library for project
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

# Main executable
add_executable(Proj1 main.cpp)
target_link_libraries(Proj1 PRIVATE Proj1Lib)

# Tests configuration
enable_testing()
add_executable(test_orders tests/orders_tests.cpp)
target_link_libraries(test_orders PRIVATE gtest gtest_main Proj1Lib)

# Discover and run the tests with CTest
include(GoogleTest)
gtest_discover_tests(test_orders)