cmake_minimum_required(VERSION 2.9)

IF(UNIX)
#Install VCPKG
execute_process(COMMAND ../vcpkg/bootstrap-vcpkg.sh -disableMetrics)
#Install the required libraries with vcpkg
execute_process(COMMAND ../vcpkg/vcpkg install glew:x64-linux glfw3:x64-linux catch2:x64-linux)
message("Running on Linux")
ELSE()
execute_process(COMMAND cmd /c "cd .. && .\\vcpkg\\bootstrap-vcpkg.bat -disableMetrics")
execute_process(COMMAND cmd /c "cd .. && .\\vcpkg\\vcpkg install glew:x64-windows glfw3:x64-windows catch2:x64-windows")
message("Running on Windows")
ENDIF()

set(CMAKE_TOOLCHAIN_FILE ${CMAKE_SOURCE_DIR}/vcpkg/scripts/buildsystems/vcpkg.cmake)
message(TOOLCHAIN FILE:)
message(${CMAKE_TOOLCHAIN_FILE})

#Decide to run in test mode
OPTION(RUN_TESTS "Run unit tests" OFF)
IF(RUN_TESTS)
    message("Running With Unit Tests...")
    ADD_DEFINITIONS(-DRUN_TESTS)
ENDIF()

project(main)
file(GLOB_RECURSE SRC
    "src/*.h"
    "src/*.cpp"
)
add_executable(main ${SRC})



find_package(GLEW REQUIRED)
target_link_libraries(main PRIVATE GLEW::GLEW)

find_package(glfw3 CONFIG REQUIRED)
target_link_libraries(main PRIVATE glfw)

find_package(Catch2 CONFIG REQUIRED)
target_link_libraries(main PRIVATE Catch2::Catch2)


