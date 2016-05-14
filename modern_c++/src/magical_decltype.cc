/***************************************************************************
 * 
 * Copyright (c) 2016 Baidu.com, Inc. All Rights Reserved
 * $Id$ 
 * 
 **************************************************************************/
 
 /**
 * @file src/magical_decltype.cc
 * @author brucesz(brucesz@baidu.com)
 * @date 2016/05/14 09:16:15
 * @version $Revision$ 
 * @brief 
 *  
 **/

/* vim: set ts=4 sw=4 sts=4 tw=100 */
#include <iostream>
#include <string>

template <typename T, typename U>
auto add(T t, U u) -> decltype(t + u) {
    return t + u;
}

int main() {
    std::string s1("hello, "), s2("world");
    auto x = add(1,2.3);
    auto y = add(s1, s2);
    std::cout << x << std::endl;
    std::cout << y << std::endl;
    return 0;
}
