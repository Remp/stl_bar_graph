#pragma once

#include "Vector.hpp"

namespace stl_bar_graph::math {

class Plane
{
public:
    float A;
    float B;
    float C;
    float D;
    
    Plane(float a, float b, float c, float d);
    
    float AngleBetween(Vector vector) const;
};

}
