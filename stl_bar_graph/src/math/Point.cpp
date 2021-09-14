#include <cmath>
#include "Point.hpp"

using namespace stl_bar_graph::math;

Point::Point(): X(0.0f), Y(0.0f), Z(0.0f) {}
Point::Point(const float arr[3]): X(arr[0]), Y(arr[1]), Z(arr[2]) {}
Point::Point(float x, float y, float z): X(x), Y(y), Z(z) {}

float Point::DistanceTo(Point dest) const
{
    float dx = dest.X - X;
    float dy = dest.Y - Y;
    float dz = dest.Z - Z;
    
    return sqrt(dx * dx + dy * dy + dz * dz);
}

std::string Point::ToString() // DELETE IT
{
    return "Point { X: " + std::to_string(X) + ", Y: " + std::to_string(Y) + ", Z: " + std::to_string(Z) + " }\n";
}
