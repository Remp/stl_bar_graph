#pragma once

#include <vector>
#include <string>
#include <map>
#include <iostream>
#include <nlohmann/json.hpp>

namespace stl_bar_graph::graph
{

class BarGraph
{
public:
    struct BarPoint {
        float X;
        float Y;
    };
    
    BarGraph();
    void Push(const BarPoint& point);
    nlohmann::json Json() const;
    
private:
    std::vector<BarPoint> m_points;
};

}
