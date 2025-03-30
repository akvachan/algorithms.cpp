cmake_minimum_required(VERSION 3.30 FATAL_ERROR)

project("Algorithms" VERSION 1.0)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_BUILD_TYPE Debug)

add_compile_options(-Wall -Wextra -Wpedantic -Werror)

file(GLOB_RECURSE SOURCE_FILES "${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp" "${CMAKE_CURRENT_SOURCE_DIR}/main.cpp")
file(GLOB_RECURSE HEADER_FILES "${CMAKE_CURRENT_SOURCE_DIR}/src/*.hpp")

# Set the include directories (automatically find directories of header files)
set(INCLUDE_DIRS "")
foreach(header IN LISTS HEADER_FILES)
  get_filename_component(dir ${header} DIRECTORY)
  list(APPEND INCLUDE_DIRS ${dir})
endforeach()
list(REMOVE_DUPLICATES INCLUDE_DIRS)

# Add executable and set the include directories
add_executable(${CMAKE_PROJECT_NAME} ${SOURCE_FILES})
target_include_directories(${CMAKE_PROJECT_NAME} PRIVATE ${INCLUDE_DIRS})
