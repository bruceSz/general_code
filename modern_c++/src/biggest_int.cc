/***************************************************************************
 * 
 * Copyright (c) 2016 Baidu.com, Inc. All Rights Reserved
 * $Id$ 
 * 
 **************************************************************************/
 
 /**
 * @file biggest_int.cc
 * @author brucesz(brucesz@baidu.com)
 * @date 2016/05/14 08:13:16
 * @version $Revision$ 
 * @brief 
 *  
 **/

/* vim: set ts=4 sw=4 sts=4 tw=100 */

#include <iostream>

int main() {
    int size = 2147483647;
    size++;
    std::cout << size << std::endl;
    return 0;
}
