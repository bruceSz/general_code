/***************************************************************************
 * 
 * Copyright (c) 2016 Baidu.com, Inc. All Rights Reserved
 * $Id$ 
 * 
 **************************************************************************/
 
 /**
 * @file src/vector_bool_magic.cc
 * @author brucesz(brucesz@baidu.com)
 * @date 2016/05/14 08:44:43
 * @version $Revision$ 
 * @brief 
 *  
 **/

/* vim: set ts=4 sw=4 sts=4 tw=100 */
#include <iostream>
#include <vector>

int main(){
    std::vector<bool> b(10);
    std::cout << "Bool size is: " << b.size()<< "capacity is :" << b.capacity()<< std::endl;
    std::vector<int> i(10);
    std::cout << "Int size is: " << i.size()<< "capacity is :" << i.capacity()<< std::endl;
}
