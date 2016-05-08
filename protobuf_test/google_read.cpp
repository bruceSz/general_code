/***************************************************************************
 * 
 * Copyright (c) 2016 Baidu.com, Inc. All Rights Reserved
 * $Id$ 
 * 
 **************************************************************************/
 
 /**
 * @file google_read.cpp
 * @author brucesz(brucesz@baidu.com)
 * @date 2016/05/08 09:07:29
 * @version $Revision$ 
 * @brief 
 *  
 **/

/* vim: set ts=4 sw=4 sts=4 tw=100 */

#include <iostream>
#include <fstream>
#include <sstream>
#include <random>
#include <algorithm>

#include <string>
#include <google/protobuf/io/coded_stream.h>
#include "addr-cpp/addr.pb.h"

using namespace std;
using namespace google::protobuf::io;

int g_size = 0;
string EXAMPLE_ADDR_FILE_NAME("addr-book.bin");

void listPeople(const addr::AddrBook& addr_book ) {
    for(int i= 0;i< addr_book.persion_size();i++){
        const addr::Person& p = addr_book.persion(i);
        cout << "Person id:" << p.id()<< endl;
        cout << "Person name:" << p.name() << endl;
    }
}

string get_random_string(int size) {
    random_device rd;
    default_random_engine e(rd());
    uniform_int_distribution<> dist(0,25);
    stringstream ss;
    for(int i = 0; i< size; i++){
        char t = 'A' + dist(e);
        ss << t;
    }
    assert(ss.str().size() == 8);
    return ss.str();
}

void dump_example_ab(){
    random_device rd;
    default_random_engine e(rd());
    addr::AddrBook* ab = new addr::AddrBook();
    addr::Person * person = ab->add_persion();
    person->set_name(get_random_string(8));
    person->set_id(e());
    ::google::protobuf::uint8* serialize  = new ::google::protobuf::uint8[ab->ByteSize()];
    int size = ab->ByteSize();
    if(!ab->SerializeWithCachedSizesToArray(serialize))
    {
        cout << "serialize failed" << std::endl;
    }

    ofstream os(EXAMPLE_ADDR_FILE_NAME, ios::out|ios::binary);
    os.write((char *)serialize, size);
}

void read_example_from_file(){
    ifstream is(EXAMPLE_ADDR_FILE_NAME, ios::in|ios::binary);
    is.seekg(0, is.end);
    long size = is.tellg();
    cout << "size of example file is " << size << endl;
    ::google::protobuf::uint8 * buf = new ::google::protobuf::uint8[size];
    is.seekg(0, is.beg);
    is.read((char *)buf, size);
    addr::AddrBook* ab = new addr::AddrBook();
    ::google::protobuf::io::CodedInputStream input(buf, size);
    if(! ab->MergePartialFromCodedStream(&input)) {
        cout << "parse from code stream failed" << endl;
    }
    listPeople(*ab);

}

const ::google::protobuf::uint8* get_test_coded_string(){
    addr::AddrBook* ab = new addr::AddrBook();
    addr::Person * person = ab->add_persion();
    string name("zs");
    person->set_name(name);
    ::google::protobuf::int32 id;
    id = 29;
    person->set_id(id);
    std::stringstream ss;
    ss << "person name:" << person->name() << "person id" <<
        person->id();
    ::google::protobuf::uint8* serialize  = new ::google::protobuf::uint8[ab->ByteSize()];
    g_size = ab->ByteSize();

    if(!ab->SerializeWithCachedSizesToArray(serialize))
    {
        cout << "serialize failed" << std::endl;
    }
    delete ab;
    return serialize;
}

void decode(const ::google::protobuf::uint8* buf,int size){
    addr::AddrBook* ab = new addr::AddrBook();
    //addr::Person* person = ab->add_persion();
    ::google::protobuf::io::CodedInputStream input(buf, g_size );
    if(! ab->MergePartialFromCodedStream(&input)) {
        cout << "parse from code stream failed" << endl;
    }
    listPeople(*ab);
}


int main(int argc, char * argv[]){
    //GOOGLE_PROTOBUF_VERSION;
    if (argc != 2) {
        cerr << "Usage:" << argv[0] << "addr_book" << endl;
        return -1;
    }
    /*const ::google::protobuf::uint8 * ret = get_test_coded_string();
    decode(ret, 100);*/
    dump_example_ab();
    read_example_from_file();

}
