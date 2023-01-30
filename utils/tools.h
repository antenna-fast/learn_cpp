#ifndef TOOLS_H
#define TOOLS_H

#include <iostream>
#include <string>
#include <stdio.h>
#include <fstream>
#include <stdlib.h>

#include <Eigen/Core>
#include <Eigen/Geometry>

//! Print text in color in the console. Only works in Linux.
/*!
  Ref: https://misc.flogisoft.com/bash/tip_colors_and_formatting
*/
#define PRINT_RED(...)        \
    {                         \
        printf("\033[1;31m"); \
        printf(__VA_ARGS__);  \
        printf("\033[0m\n");    \
    }

#define PRINT_GREEN(...)      \
    {                         \
        printf("\033[1;32m"); \
        printf(__VA_ARGS__);  \
        printf("\033[0m\n");    \
    }

#define PRINT_YELLOW(...)     \
    {                         \
        printf("\033[1;33m"); \
        printf(__VA_ARGS__);  \
        printf("\033[0m\n");    \
    }

#define PRINT_BLUE(...)       \
    {                         \
        printf("\033[1;34m"); \
        printf(__VA_ARGS__);  \
        printf("\033[0m\n");    \
    }
#define PRINT_MAGENTA(...)    \
    {                         \
        printf("\033[1;35m"); \
        printf(__VA_ARGS__);  \
        printf("\033[0m\n");    \
    }

#define PRINT_CYAN(...)       \
    {                         \
        printf("\033[1;36m"); \
        printf(__VA_ARGS__);  \
        printf("\033[0m\n");    \
    }

//! Print a progress bar with given progress. Remember to print a new line after progress reaches 1.0
inline void printProgressBar(float progress)
{
    int bar_width = 70;
    std::cout << "\r[";
    int pos = static_cast<int>(bar_width * progress);
    for (int i = 0; i < bar_width; ++i)
    {
        if (i < pos)
            std::cout << "=";
        else if (i == pos)
            std::cout << ">";
        else
            std::cout << " ";
    }
    std::cout << "] " << int(progress * 100.0) << " %" << std::flush;
    if (progress == 1.0)
        std::cout << std::endl;
}


inline void SavePlySimpy(const float* vertices, 
                         const float* vert_normals, 
                         const unsigned char* vert_colors, 
			             const int vert_size, 
                         const std::string save_path,
                         const bool one_color)
{
	std::ofstream out(save_path);
	out << "ply\n";
	out << "format ascii 1.0\n";
	out << "element vertex " << vert_size << "\n";
	out << "property float x\n";
	out << "property float y\n";
	out << "property float z\n";
	if(vert_normals != nullptr) 
    {
		out << "property float nx\n";
		out << "property float ny\n";
		out << "property float nz\n";
	}
	if(vert_colors != nullptr) {
		out << "property uchar red\n";
		out << "property uchar green\n";
		out << "property uchar blue\n";
	}
	out << "end_header\n";

	for(int i = 0; i < vert_size; ++i) 
    {
		out << vertices[3 * i] << ' ' << vertices[3 * i + 1] << ' ' << vertices[3 * i + 2];
		if(vert_normals != nullptr) out << ' ' << vert_normals[3 * i] << ' ' << vert_normals[3 * i + 1] << ' ' << vert_normals[3 * i + 2];
		if(one_color)
        { 
            if(vert_colors != nullptr) out << ' ' << int(vert_colors[2]) << ' ' << int(vert_colors[1]) << ' ' << int(vert_colors[0]); 
        } else
        {
            if(vert_colors != nullptr) out << ' ' << int(vert_colors[3 * i + 2]) << ' ' << int(vert_colors[3 * i + 1]) << ' ' << int(vert_colors[3 * i]);
        }
		out << '\n';
	}
	out.close();
}


enum INTR
{
    FX = 0, CX, FY, CY
};

inline bool getIntrParam(const std::string para_path, std::vector<Eigen::Vector4f>& intr_vects,
                         int& imWidth, int& imHeight)
{
    std::vector<Eigen::Matrix3f> intr_mats;
    for(int i = 0; i < 4; i++) 
    {
        std::string file_path = para_path + "/pano/k_" + std::to_string(i) + ".txt";
        std::ifstream file;
        file.open(file_path.c_str());
        if(file.fail()) 
        {
            PRINT_RED("ERROR in reading camera intrinsic %s", file_path.c_str());
            return false;
        }
        while(!file.eof()) 
        {
            std::string line;
            std::getline(file, line);
            if(file.eof()) break;

            std::istringstream istr(line);
            std::string::size_type sz;
            std::string str;
            Eigen::Matrix3f intr = Eigen::Matrix3f::Identity();
            for(int m = 0; m < 3; m++)
                for(int n = 0; n < 3; n++) 
                {
                    getline(istr, str, ';');
                    intr(m, n) = std::stod(str, &sz);
                }
            intr_mats.push_back(intr);
            // std::cout << std::setprecision(8) << intr_mats[i] << std::endl;

            getline(istr, str, ';'); imWidth  = std::stod(str, &sz);
            getline(istr, str, ';'); imHeight = std::stod(str, &sz);
            // cout << "imWidth: " << imWidth << " imHeight: " << imHeight << std::endl;
        }
    }

    for(auto intr_mat : intr_mats) 
    {
        // fx, fy, cx, cy
        Eigen::Vector4f intr_vect(intr_mat(0, 0), intr_mat(0, 2), intr_mat(1, 1), intr_mat(1, 2));
        intr_vect = intr_vect / 4.0;  // resize
        intr_vects.push_back(intr_vect);
    }
    
    assert(imWidth % 4 == 0 && imHeight % 4 == 0);
    imWidth = imWidth / 4;
    imHeight = imHeight / 4;
    
    return true;
}


#endif
