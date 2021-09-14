#include <stdexcept>
#include "Range.hpp"

using namespace stl_bar_graph::math;

Range::Range(float min, float max): m_min(min), m_max(max)
{
    if (min >= max) throw std::runtime_error("[ERROR] min should be less then max");
    if (max <= min) throw std::runtime_error("[ERROR] max should be greater then min");
}
