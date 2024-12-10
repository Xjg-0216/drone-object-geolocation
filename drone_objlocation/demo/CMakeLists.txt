cmake_minimum_required(VERSION 3.5)
set(CMAKE_BUILD_TYPE Debug)
find_package(DroneObjlocation REQUIRED)
include_directories(
    "/usr/include/eigen3"
    "${CMAKE_CURRENT_LIST_DIR}"
)
add_executable(demo_geolocation demo_geolocation.cpp drone_objlocation.cpp)
target_link_libraries(demo_geolocation ${DroneObjlocation_LIBS})