//
// Created by yaohua on 2022/4/28.
//

#include <iostream>
#include <cstring>


using namespace std;

typedef struct Student{
    string name;
    int age;
    float score;
} Student;

// 等效：
//typedef struct Student Student;


int main(){
    // 声明结构体变量
    struct Student s_1, s_2;

    string my_name = "yaohua";
    s_1.name = my_name;
    s_1.age = 25;
    s_1.score = 99;

    // 结构体指针
    struct Student *p_s_1;
    p_s_1 = &s_1;
    cout << "s_1 score: " << p_s_1->score << endl;

    p_s_1 -> score += 1;
    cout << "s_1 score: " << s_1.score << endl;

    // 使用typedefine之后的Student
    Student s_3;
    s_3.name = "ANTenna";
    s_3.age = 25;
    s_3.score = 100;

    return 0;
}