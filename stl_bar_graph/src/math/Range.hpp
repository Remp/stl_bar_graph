#pragma once

namespace stl_bar_graph::math {

class Range
{
public:
    Range(float min, float max);
    
    inline float GetMin() const  { return m_min; };
    inline float GetMax() const  { return m_max; };
private:
    float m_min;
    float m_max;
};

}
