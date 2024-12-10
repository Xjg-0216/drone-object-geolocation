#include <stdlib.h>
#include <stdio.h>

#include <iostream>
#include <vector>
#include "geolocation/drone_objlocation.h"

using namespace std;

DroneObjlocation geo_location = DroneObjlocation();

void test01()
{
    std::map<std::string, std::vector<float>> result;

    std::vector<int> uv = {533, 371};
    float focal = 4.3;
    float distance = 88.4570007324;
    int   distance_type = 0; //不使用激光测距，假设大地水平，根据无人机距离起飞点高度作为该垂直高度的估计值

    std::vector<float> euler_camera   = {0.262, 1.309, 0.0};
    std::vector<float> euler_drone    = {1.827, -0.031, 0.157};
    std::vector<float> position_drone = {38.1368980408, 116.2943725586, 88.4570007324};

    geo_location.set_parameter((uint16_t)640, (uint16_t)480, 1, 640, 640, 300, 240); // img_width, img_height, focal, fx, fy, cx, cy
    result = geo_location.get_target_location(uv, focal, distance, euler_camera, euler_drone, position_drone, distance_type); 

    printf("p_b: %f, %f, %f\n", result["p_b"][0], result["p_b"][1], result["p_b"][2]);
    printf("p_e: %f, %f, %f\n", result["p_e"][0], result["p_e"][1], result["p_e"][2]);
    printf("gps: %f, %f, %f\n", result["gps"][0], result["gps"][1], result["gps"][2]);
    
}
int main(int argc, char *argv[])
{
    test01();
    return 0;
}