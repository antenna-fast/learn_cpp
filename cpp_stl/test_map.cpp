//
// Created by yaohua on 2022/5/11.
//

#include <iostream>
#include <map>
#include <unordered_map>
#include <string>

using namespace std;


int main(){
    // 声明map
    // 1. 默认构造函数
    map<string, string> var_map;

    // 2. 构建时初始化
    map<string, string> map_2{{"1", "2"}, {"3", "4"}};

    // 3. 移动构造函数
    map<string, int> map_3{make_pair("99", 81)};

    // 4. 复制构造函数
    map<string, string> map_4(map_2);

    // 向map添加元素
    var_map["789"] = "999";
    var_map["123"] = "456";


    // 访问map元素
    // 1. 迭代器
    auto iter_var_map = var_map.begin();
    while (iter_var_map!=var_map.end()){
        cout << "first: " << iter_var_map->first << " second: " << iter_var_map->second << endl;
        iter_var_map ++;
    }

    // 2. []
    // cout << "get: " << var_map["1"] << endl;  // 如果不存在给定的key 会创建一个key
    // .at()
    // cout << "get: " << var_map.at("1") << endl;  // 如果不存在，会抛出异常
    // .find()  返回迭代器，如果没有，则返回的是end

    // 插入 除了[]之外
    // insert


    // multimap
    multimap<string, string> mmap_1{{"99", "81"},
                                    {"66", "36"},
                                    {"99", "999"}};

    // 访问：不提供[]以及at
    auto iter_mmap = mmap_1.begin();
    while (iter_mmap != mmap_1.end()){
        cout << "key: " << iter_mmap->first << "  val: " << iter_mmap->second << endl;
        iter_mmap ++;
    }
    return 0;

}