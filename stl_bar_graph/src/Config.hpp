#pragma once

#include <string>
#include <optional>
#include "math/Range.hpp"

namespace stl_bar_graph
{

class Config
{
public:
    std::string FileName;
    math::Range Range;
    int Cells;
    
    Config(const char** begin, const char** end);
    
private:
    static constexpr int s_default_cells = 100;
    static constexpr int s_default_min = -90;
    static constexpr int s_default_max = 90;
    
    static std::optional<std::string> GetFlagValue(std::string flag, const char** begin, const char** end);
    static std::string CalcFileName(const char** begin, const char** end);
    static int CalcMin(const char** begin, const char** end);
    static int CalcMax(const char** begin, const char** end);
    static math::Range CalcRange(const char** begin, const char** end);
    static std::optional<std::string> GetFirstNoFlag(const char** begin, const char** end);
    static int CalcCells(const char** begin, const char** end);
};

}
