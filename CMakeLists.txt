cmake_minimum_required(VERSION 3.14)

project(screencontrol)

if(NOT CMAKE_BUILD_TYPE)
  set(CMAKE_BUILD_TYPE Release)
endif()
include_directories("/usr/local/include")
add_subdirectory(Catch2)
find_library(COCOA_LIBRARY Cocoa)
find_library(CORE_GRAPHICS_LIBRARY CoreGraphics)
find_library(QUARTZ_CORE_LIBRARY QuartzCore)
find_library(IOKIT_LIBRARY IOKit)

add_library(${PROJECT_NAME} INTERFACE)
target_include_directories(${PROJECT_NAME} INTERFACE ${CMAKE_CURRENT_SOURCE_DIR}/src)
target_compile_features(${PROJECT_NAME} INTERFACE cxx_std_17)
target_link_libraries(${PROJECT_NAME} INTERFACE ${COCOA_LIBRARY}
                                                ${CORE_GRAPHICS_LIBRARY}
                                                ${QUARTZ_CORE_LIBRARY}
                                                ${IOKIT_LIBRARY})

include(CTest)
enable_testing()

add_executable(${PROJECT_NAME}-test tests/test.cpp)
target_link_libraries(${PROJECT_NAME}-test ${PROJECT_NAME} Catch2)
catch_discover_tests(${PROJECT_NAME}-test)
