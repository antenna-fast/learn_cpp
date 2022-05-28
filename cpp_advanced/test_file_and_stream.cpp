//
// Created by yaohua on 2022/4/29.
//

#include <iostream>
#include <fstream>


using namespace std;

int main(){

    // 写文件
    ofstream output_file;  // 实例化
    output_file.open("test.txt");  // 打开
    // 写入
    output_file << 123 << "\n"
                << 456 << "\n";
    output_file.close();  // 关闭文件

    // 读文件
    ifstream input_file;
    input_file.open("test.txt");

    string data;

    input_file >> data;
    cout << data << endl;

    input_file >> data;
    cout << data << endl;

    input_file.close();

    return 0;
}
