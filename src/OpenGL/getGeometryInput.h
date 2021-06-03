#ifndef GETGI_H
#define GETGI H


#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>
#include <cstdlib>

struct vec3d
{
    double x;
    double y;
    double z;
};

class triangle
{
public:
    vec3d normal;
    vec3d point[3];
};

extern int getGeometryInput(std::vector<triangle> & facet, std::string STL_files_path, std::string STL_filename);
extern int read_binary_STL_file(std::vector<triangle> &facet, std::string STL_files_path, std::string STL_filename);

#endif // GETGI_H

