#pragma once

namespace stl_bar_graph::math
{

class Vector
{
public:
    float X;
    float Y;
    float Z;
    
    Vector(const float arr[3]);
    Vector(float x, float y, float z);
};

}
