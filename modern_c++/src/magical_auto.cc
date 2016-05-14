/***************************************************************************
 * 
 * Copyright (c) 2016 Baidu.com, Inc. All Rights Reserved
 * $Id$ 
 * 
 **************************************************************************/
 
 /**
 * @file src/magical_auto.cc
 * @author brucesz(brucesz@baidu.com)
 * @date 2016/05/14 08:59:45
 * @version $Revision$ 
 * @brief 
 *  
 **/

/* vim: set ts=4 sw=4 sts=4 tw=100 */
#include <iostream>
#include <vector>

struct A{
    A(int x): x_(x) {}
    int x_;
};

auto get_greeting()  {
    std::string s("hello from auto return type.");
    return s;
}
int main() {
    auto s = get_greeting();
    std::cout << s << std::endl;
    std::vector<A> v;
    for(int i = 1; i <= 3; i++){
        v.emplace_back(i);
    }
    auto a_by_value = v[0];
    a_by_value.x_ = 100;
    std::cout << "By value: \n";
    for(auto it = v.begin(); it != v.end(); ++it){
        std::cout << it->x_ << std::endl;
    }

    auto & a_by_ref = v[0];
    a_by_ref = 1000;
    for(auto it = v.begin(); it != v.end(); it++){
        std::cout << it->x_ <<  std::endl;
    }
    return 0;
}
