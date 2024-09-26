cmake_minimum_required(VERSION 3.22)
project(raytracer)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR})

file(GLOB_RECURSE SOURCES "src/*.cpp")

if(APPLE)
    include_directories(/opt/homebrew/include)
    link_directories(/opt/homebrew/lib)
endif()

include_directories(include)

add_executable(raytracer ${SOURCES})
target_link_libraries(raytracer config++)
target_compile_options(raytracer PRIVATE -W -Wall -Wextra -Werror)
