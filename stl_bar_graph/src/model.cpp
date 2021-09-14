#include <vector>
#include <map>
#include <cmath>
#include <iostream>
#include "STLTriangle.hpp"
#include "math/Plane.hpp"
#include "math/degree.hpp"
#include "model.hpp"
#include "graph/BarGraph.hpp"

namespace stl_bar_graph
{

void run(const Config& config)
{
    std::vector<STLTriangle> triangles = STLTriangle::LoadFromFile(config.FileName);
    graph::BarGraph graph = calc_graph(triangles, config.Range, config.Cells);
    
    std::cout << graph.Json();
}

graph::BarGraph calc_graph(const std::vector<STLTriangle>& triangles, math::Range range, int cells)
{
    const math::Plane xyPlane(0.0f, 0.0f, 1.0f, 0.0f);
    graph::BarGraph graph;
    std::map<int, float> cell_map;
    float step = (range.GetMax() - range.GetMin()) / cells;
    
    for (const STLTriangle& triangle : triangles)
    {
        float angle = math::degree(xyPlane.AngleBetween(triangle.Normal));
        float square = triangle.Triangle.Square();
        int cell = calc_cell(step, cells, angle);
        
        cell_map[cell] = cell_map.find(cell) == cell_map.end() ? square : cell_map[cell] + square;
    }
    
    for (auto& [cell, square] : cell_map)
    {
        graph.Push({ step * cell, square });
    }
    
    return graph;
}

int calc_cell(float step, int cells, float value)
{
    return static_cast<int>(lround(value / step));
}

}
