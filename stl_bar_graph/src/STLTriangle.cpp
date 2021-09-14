#include <cmath>
#include <vector>
#include <iostream>
#include <stl_reader.h>
#include "STLTriangle.hpp"
#include "math/Point.hpp"

using namespace stl_bar_graph;

std::vector<STLTriangle> STLTriangle::LoadFromFile(const std::string& filename)
{
    stl_reader::StlMesh<float, unsigned int> mesh(filename.c_str());
    std::vector<STLTriangle> triangles;
    
    for(size_t itri = 0; itri < mesh.num_tris(); itri++) {
        std::array<math::Point, 3> points;
        
        for(size_t icorner = 0; icorner < points.size(); icorner++) {
            const float* c = mesh.tri_corner_coords(itri, icorner);
            
            math::Point point(c);
            
            points.at(icorner) = point;
        }
      
        math::Vector normal(mesh.tri_normal(itri));
        
        triangles.push_back(STLTriangle(math::Triangle(points), normal));
    }
    
    return triangles;
}

STLTriangle::STLTriangle(const math::Triangle& triangle, math::Vector normal):
    Triangle(triangle),
    Normal(normal)
{}
