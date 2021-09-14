#include <cmath> // for size_t
#include <optional>
#include <stdexcept>
#include "Config.hpp"

using namespace stl_bar_graph;

Config::Config(const char** begin, const char** end):
    FileName(CalcFileName(begin, end)),
    Range(CalcRange(begin, end)),
    Cells(CalcCells(begin, end))
{}

std::optional<std::string> Config::GetFlagValue(std::string flag, const char** begin, const char** end)
{
    std::string full_flag = flag + '=';
    auto iter = std::find_if(begin, end, [&full_flag](const char* str) {
        return std::string(str).rfind(full_flag, 0) == 0;
    });
    
    if (iter == end) return std::nullopt;
    
    std::string value = std::string(*iter).substr(full_flag.size());
    
    if (value.size() == 0) return std::nullopt;
    
    return std::move(value);
}

std::optional<std::string> Config::GetFirstNoFlag(const char** begin, const char** end)
{
    auto iter = std::find_if(begin, end, [](const char* str) {
        return std::string(str).rfind("--", 0) != 0;
    });
    
    if (iter == end) return std::nullopt;
    
    std::string value(*iter);
    
    return std::move(value);
}

int Config::CalcMin(const char** begin, const char** end)
{
    try
    {
        std::optional<std::string> min_str_opt = GetFlagValue("--min", begin, end);
        
        return min_str_opt.has_value() ? std::atoi(min_str_opt.value().c_str()) : s_default_min;
    }
    catch (const std::invalid_argument& error)
    {
        throw std::runtime_error("--min is not valid");
    }
    catch (const std::out_of_range& error)
    {
        throw std::runtime_error("--min is out of range");
    }
}

int Config::CalcMax(const char** begin, const char** end)
{
    try
    {
        std::optional<std::string> max_str_opt = GetFlagValue("--max", begin, end);
        
        return max_str_opt.has_value() ? std::atoi(max_str_opt.value().c_str()) : s_default_max;
    }
    catch (const std::invalid_argument& error)
    {
        throw std::runtime_error("--max is not valid");
    }
    catch (const std::out_of_range& error)
    {
        throw std::runtime_error("--max is out of range");
    }
}

std::string Config::CalcFileName(const char** begin, const char** end)
{
    std::optional<std::string> filename_opt = GetFirstNoFlag(begin, end);
    
    if (filename_opt.has_value()) return std::move(filename_opt.value());
    
    throw std::runtime_error("no file provided");
}

math::Range Config::CalcRange(const char** begin, const char** end)
{
    return math::Range(CalcMin(begin, end), CalcMax(begin, end));
}

int Config::CalcCells(const char** begin, const char** end)
{
    try
    {
        std::optional<std::string> cells_str_opt = GetFlagValue("--cells", begin, end);
        
        return cells_str_opt.has_value() ? std::atoi(cells_str_opt.value().c_str()) : s_default_cells;
    }
    catch (const std::invalid_argument& error)
    {
        throw std::runtime_error("--cells is not valid");
    }
    catch (const std::out_of_range& error)
    {
        throw std::runtime_error("--cells is out of range");
    }
}
