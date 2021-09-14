#include <cmath>
#include "Vector.hpp"

using namespace stl_bar_graph::math;

Vector::Vector(const float arr[3]): X(arr[0]), Y(arr[1]), Z(arr[2]) {}
Vector::Vector(float x, float y, float z): X(x), Y(y), Z(z) {}
