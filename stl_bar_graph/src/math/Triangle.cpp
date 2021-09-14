#include <cmath>
#include "Triangle.hpp"

using namespace stl_bar_graph::math;

Triangle::Triangle(std::array<Point, 3>& points): Points(points) {}

float Triangle::Square() const
{
    float a = Points[0].DistanceTo(Points[1]);
    float b = Points[1].DistanceTo(Points[2]);
    float c = Points[2].DistanceTo(Points[0]);
    
    float p = (a + b + c) / 2;
    
    return sqrt(p * (p - a) * (p - b) * (p - c));
}
