#pragma once

#include <map>
#include <vector>
#include "Config.hpp"
#include "STLTriangle.hpp"
#include "graph/BarGraph.hpp"
#include "math/Range.hpp"

namespace stl_bar_graph
{

void run(const Config& config);
graph::BarGraph calc_graph(const std::vector<STLTriangle>& triangles, math::Range range, int cells);
int calc_cell(float step, int cells, float value);

}
