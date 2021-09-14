#pragma once

#include <string>

namespace stl_bar_graph::math
{

class Point
{
public:
    float X;
    float Y;
    float Z;
    
    Point();
    Point(const float arr[3]);
    Point(float x, float y, float z);
    float DistanceTo(Point dest) const;
    std::string ToString();
};

}
