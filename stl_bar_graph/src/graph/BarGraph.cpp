#include "BarGraph.hpp"

using namespace stl_bar_graph::graph;

BarGraph::BarGraph() {}

void BarGraph::Push(const BarPoint& point)
{
    m_points.push_back(point);
}

nlohmann::json BarGraph::Json() const
{
    nlohmann::json json = {
        { "data", nlohmann::json::array() }
    };
    
    for (auto& point : m_points)
    {
        json["data"].push_back({
            { "x", point.X },
            { "y", point.Y }
        });
    }
    
    return json;
}
