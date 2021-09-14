#include <numbers>
#include "degree.hpp"
#include "constants.hpp"

namespace stl_bar_graph::math
{

float degree(float rad)
{
    return rad * (180.0f / constants::pi);
}

}
