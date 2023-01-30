//
// Created by yaohua on 2022/5/11.
//

#include <iostream>
#include <map>
#include <unordered_map>
#include <string>

using namespace std;


int main(){    
    // 1. 默认构造函数
    map<string, string> var_map;

    // 2. 构建时初始化
    map<string, string> map_2{{"1", "2"}, {"3", "4"}};

    // 3. 移动构造函数
    map<string, int>    map_3{make_pair("99", 81)};

    // 4. copy constructor
    map<string, string> map_4(map_2);

    // add element to map
    var_map["789"] = "999";
    var_map["123"] = "456";

    // 访问map元素
    // 1. 迭代器 while
    auto iter_var_map = var_map.begin();  // sorted
    while (iter_var_map != var_map.end()){
        cout << "first: " << iter_var_map->first << " second: " << iter_var_map->second << endl;
        iter_var_map ++;
    }
    
    // for
    for(auto const& mtmp : var_map){
        cout << "auto first: " << mtmp.first << "  auto second: " << mtmp.second << endl;
    }

    // <float, int> 
    map<float, int> fimap;
    for (size_t i = 5; i > 0; i--)
    {
        fimap.insert(make_pair(i+0.001, i*10));
    }

    auto fimap_iter = fimap.begin();
    while (fimap_iter != fimap.end())
    {
        cout << "fimap_iter: " << fimap_iter->first << " : " << fimap_iter->second << endl;
        fimap_iter ++;
    }
    
    // check the exist  

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
                                    {"100", "999"}};

    // 访问：不提供[]以及at
    auto iter_mmap = mmap_1.begin();
    while (iter_mmap != mmap_1.end()){
        cout << "key: " << iter_mmap->first << "  val: " << iter_mmap->second << endl;
        iter_mmap ++;
    }
    
    // test erase
    map<int, string> m_erase;
    // insert some sample
    for (size_t i = 0; i < 5; i++)
    {
        m_erase.insert(make_pair(i, to_string(i)));
    }
    // erase    
    auto m_erase_iter = m_erase.begin();
    while (m_erase_iter != m_erase.end())
    {
        cout << "m_erase_iter: key " << m_erase_iter->first << " " << m_erase_iter->second << endl;
        if(m_erase_iter->first == 0){
            m_erase.erase(0);
        }
        m_erase_iter++;
    }
    
    m_erase_iter = m_erase.begin();
    while (m_erase_iter != m_erase.end())
    {
        cout << "m_erase_iter2: key " << m_erase_iter->first << " " << m_erase_iter->second << endl;
        m_erase_iter ++;
    }
    return 0;

}