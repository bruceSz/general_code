/***************************************************************************
 * 
 * Copyright (c) 2016 Baidu.com, Inc. All Rights Reserved
 * $Id$ 
 * 
 **************************************************************************/
 
 /**
 * @file three_level_inherit.cc
 * @author brucesz(brucesz@baidu.com)
 * @date 2016/05/14 18:15:20
 * @version $Revision$ 
 * @brief 
 *  
 **/

/* vim: set ts=4 sw=4 sts=4 tw=100 */

#include <iostream>

class GrandPa
{
    public:
    GrandPa(){ std::cout << "GrandPa construct." << std::endl;}
    virtual ~GrandPa(){std::cout << "GrandPa descontruct." << std::endl;}
};

class Father: public GrandPa
{
    public:
    Father(){std::cout << "Father construct" << std::endl;}
    ~Father(){std::cout << "Father descontruct" << std::endl;}
};

class Son:public Father
{
    public:
    Son(){std::cout << "Son construct" << std::endl;}
    ~Son(){std::cout << "Son descontruct" << std::endl;}
};

int main(){
    std::cout << "test1 " << std::endl;
    GrandPa * base;
    base = new Father(); 
    delete base;

    std::cout << "test2 " << std::endl;
    base = new Son;
    delete base;
}
