#include <cmath>
#include "Plane.hpp"

using namespace stl_bar_graph::math;

Plane::Plane(float a, float b, float c, float d): A(a), B(b), C(c), D(d) {};

float Plane::AngleBetween(Vector vector) const
{
    float sinFi = A * vector.X + B * vector.Y + C * vector.Z / (sqrt(A * A + B * B + C * C) * sqrt(vector.X * vector.X + vector.Y * vector.Y + vector.Z * vector.Z));
    
    return asin(sinFi);
}
