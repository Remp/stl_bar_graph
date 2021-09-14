#pragma once

#include <vector>
#include <array>
#include <string>
#include "math/Vector.hpp"
#include "math/Point.hpp"
#include "math/Triangle.hpp"

namespace stl_bar_graph
{

class STLTriangle
{
public:
    static std::vector<STLTriangle> LoadFromFile(const std::string& fileName);
    
    math::Triangle Triangle;
    math::Vector Normal;
    
    STLTriangle(const math::Triangle& triangle, math::Vector normal);
};

}
