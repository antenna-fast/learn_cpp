//
// Created by yaohua on 2022/4/27.
//

#include <iostream>


using namespace std;


typedef struct Node{
    int a=1;
    int b=2;
}Node;


int main(){
    cout << "Pointer Test " << endl;

    int var_1 = 0;
    int var_2[10];

    cout << "position of var_1: " << &var_1 << endl;
    cout << "position of var_2: " << &var_2 << endl;

    //
    int var_3 = 666;
    int *p_var_1;
    p_var_1 = &var_3;
    cout << "var_3: " << var_3
    << " p_var: " << p_var_1
    << "  v_p_var: " << *p_var_1 << endl;

    cout << "var_1 :" << var_1 << "var_3: " << var_3 << endl;
    int *p_var_8 = &var_1;
    int *p_var_9 = p_var_8;
    p_var_9 = &var_3;  // 改变了p_var_9的，看是否会影响p_var_8的value
    cout << "p_var_8: " << *p_var_8 << endl;  // 不会

    // test free space
    Node *head = new Node;
    head -> a = 999;
    head -> b = 666;

    Node *fp_2 = head;

//    free(fp_1);  // int报错(为什么？), struct不报错?
//    delete fp_2;
    delete head;
//    head = nullptr;

    if (head){
        cout << "head not empty: " << head->b << endl;
    }

    return 0;
}
