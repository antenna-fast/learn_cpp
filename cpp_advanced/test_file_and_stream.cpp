// Created by yaohua on 2022/4/29.

#include <iostream>
#include <fstream>
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <sstream>
#include <vector>

#include <unistd.h>


using namespace std;


template <typename T>
bool read_txt(std::string file_path, vector<vector<T>>& data, size_t num_per_line)
{
    ifstream in_file;
    in_file.open(file_path);

    if(in_file.fail())
    {
        cout << "failed to open file: " << file_path << endl;
        return false;
    }

    string line;
    while (!in_file.eof())
    {
        getline(in_file, line);
        if(line.empty())
        {
            break;
        }
        // cout << "line: " << line << " : ";
        istringstream str_line(line);
        string str;

        vector<float> vLineData(num_per_line);

        for (size_t i = 0; i < num_per_line; i++)
        {
            getline(str_line, str, ' ');
            // cout << " " << str << " ";
            vLineData.at(i) = std::stof(str);
        }
        // cout << vLineData.at(0) << " " << vLineData.at(1) << endl;
        data.emplace_back(vLineData); 
    }
    return true;
}


int main(){

    // 写文件:
    // 实例化
    ofstream output_file;      
    output_file.open("test.txt");  // open file
    // output_file.open("test.txt", std::ios_base::app);  // open file

    // write to file stream

    for(size_t i = 0; i<1; i++) 
    {
        output_file << 123 << "\n";
        sleep(2);
        output_file << 456 << "\n";
        sleep(2);
        output_file << 789 << "\n";
        sleep(2);
    }
    // close file
    output_file.close();  

    // write file in the file tile 
    ofstream output_file_att;      
    output_file_att.open("test.txt", std::ios_base::app);  // open file
    output_file_att << "10 11 12" << "\n";
    output_file_att.close();

    // 读文件: 逐行读取
    // 实例化
    ifstream input_file;
    input_file.open("test.txt");  // open file, 构造函数输入文件名字符串
    if(input_file.fail()) {
        cout << "failed to open file: " << "file_name" << endl;
        return 0;
    }

    string line;
    while (!input_file.eof())
    {
        getline(input_file, line);  // read one line
        if(line.empty()) 
        {
            break;
        }
        cout << line << endl;
    }
    
    // 关闭文件
    input_file.close();

    // 矩阵读取
    string file_name = "static_to_imu.txt";
    ifstream m1(file_name);  // 构造函数输入文件名字符串
    if(!m1.is_open()) {
        cout << "field to read matrix: " << file_name << endl;
        return -1;
    };

    cout << "reading matrix: " << file_name << endl;
    int c=0;
    while (!m1.eof())
    {
        c++;
        if(c > 16 || c < 1) break;  // limit element number
        float f;
        m1 >> f;
        cout << "elem " << c << ": " << f << endl;
    }
    m1.close();

    // or
    ifstream readin("static_to_imu.txt", ios::in);
    float a = 0;
    for (size_t i = 0; i < 4; i++)
    {
        for (size_t j = 0; j < 4; j++)
        {
            readin >> a;
            cout << a << " ";
        }
        cout << endl;
    }
    readin.close();

    // split string
    ifstream readin2("string_split.txt", ios::in);
    std::string line2;
    while (!readin2.eof())
    {   
        getline(readin2, line2);
        if(line.empty()) break;  // break when meet empty line
        cout << "line: " << line2 << endl;
        
        std::istringstream str_line(line2);

        std::string str;
        for (size_t i = 0; i < 6; i++)
        {
            std::getline(str_line, str, ',');  // NOTO: use '' insted of ""
            cout << std::stod(str) << endl;
        }    
    }
    
    return 0;
}
