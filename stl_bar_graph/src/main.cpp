#include <iostream>
#include <exception>
#include "model.hpp"
#include "Config.hpp"

int main(int argc, const char* argv[])
{
    try
    {
        stl_bar_graph::Config config(argv + 1, argv + argc);
        stl_bar_graph::run(config);
        
        return 0;
    }
    catch (const std::exception& exception)
    {
        std::cerr << exception.what() << '\n';
        return 1;
    }
}
