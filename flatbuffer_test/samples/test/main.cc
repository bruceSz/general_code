/***************************************************************************
 * 
 * Copyright (c) 2016 Baidu.com, Inc. All Rights Reserved
 * $Id$ 
 * 
 **************************************************************************/
 
 /**
 * @file test_main.cc
 * @author brucesz(brucesz@baidu.com)
 * @date 2016/05/24 22:46:03
 * @version $Revision$ 
 * @brief 
 *  
 **/

/* vim: set ts=4 sw=4 sts=4 tw=100 */
#include "test_generated.h"
#include <vector>
#include <iostream>

using namespace std;
using namespace TestApp;

int main(){
    flatbuffers::FlatBufferBuilder builder;

    std::vector<uint64_t> vec;
    for(size_t i=0; i<10; i++) {
        vec.push_back(i);
    }
    auto id = 123;
    auto name = builder.CreateString("name");
    auto list = builder.CreateVector(vec);
    auto flag = 1;
    auto kv = KV(1, 1.0);
    auto mloc = CreateTestObj(builder, id, name, flag, list, &kv);
    builder.Finish(mloc);
    char* ptr = (char *)builder.GetBufferPointer();
    uint64_t size = builder.GetSize();

    auto obj = GetTestObj((uint8_t* )ptr);
    cout << obj->id() << endl;
    cout << obj->name() << endl;
    cout << obj->flag() << endl;
    for(size_t i=0; i< obj->list()->size(); i++ ) {
        cout << obj->list()->Get(i)<< endl;
    }
    cout << obj->kv()->key() << endl;
    cout << obj->kv()->value() << endl;

}
