#pragma once

#include <array>
#include "Point.hpp"

namespace stl_bar_graph::math {

class Triangle
{
public:
    std::array<Point, 3> Points;
    
    Triangle(std::array<Point, 3>& points);
    float Square() const;
};

}
