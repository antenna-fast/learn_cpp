#include <iostream>

using namespace std;

/**
 * nx: 矩阵的行数
 * ny：矩阵的列数
 * 行优先的存储
 * **/

// 初始化数据
void InitMat(float *A, int nxy, int val){
    for (size_t i = 0; i < nxy; i++){ 
        A[i] = i;
    }
    return;
}

// 打印矩阵
// 矩阵的尺寸： X行 Y列
template <typename T>
void printMat(const T*A, int nx, int ny){
    for (size_t i = 0; i < nx; i++)
    { 
        for (size_t j = 0; j < ny; j++)
        { 
            cout << A[j] << " ";
        }
        cout << endl;
        A += ny;  // 每一行的水平偏移量
    }
    cout << endl;

    return;
}

// C = A + B
template <typename T>
void matAdd(const T *A, const T* B, T*C, int nx, int ny){
    // cout << "Matrix size: " << nx << " x " << ny << endl;
    int nxy = nx * ny;
    for (size_t i = 0; i < nx; i++)      // 行
    {
        for (size_t i = 0; i < ny; i++)  // 列
        {
            C[i] = A[i] + B[i];
        }
        A += ny;  // 跳转一行
        B += ny;
        C += ny;
    }
    return;
}


int main(){
    int row = 10;
    int col = 5;
    int numElements = row * col;

    int nBytes = numElements * sizeof(float);

    // Malloc host memory 
    // 开数组 使用一维的数组存储二维矩阵
    float *h_A;
    float *h_B;
    float *h_C;
    
    h_A = (float *)malloc(nBytes);
    h_B = (float *)malloc(nBytes);
    h_C = (float *)malloc(nBytes);
    
    // 初始化数据
    InitMat(h_A, numElements, 1);
    InitMat(h_B, numElements, 2);

    cout << "matrix A: " << endl;
    printMat(h_A, row, col);

    cout << "matrix B: " << endl;
    printMat(h_B, row, col);
    
    matAdd(h_A, h_B, h_C, row, col);

    // Check the result
    cout << "Matrix C: " << endl;
    printMat(h_C, row, col);

    return 0;
}