#include <iostream>
#include <cassert>
#include "MyVector.h"
using namespace std;
int main() {
    MyVector v1;
    assert(v1.size()==0);
    v1.push_back(10);
    v1.push_back(20);
    v1.push_back(30);
    assert(v1.size()==3);
    MyVector v2;
    v2.push_back(78);
    v2.push_back(67);
    v2.push_back(57);
    v2.push_back(50);
    v2.push_back(90);
    MyVector v3= v1 + v2;
    int total =0;
    for (int i=0;i<v1.size();++i)
        total+=v1[i];
    v2.erase(3);
    assert(total==60);
    string resultado;
    try{
        v1.insert(10,10);
    }
    catch (const exception &e){
        resultado= e.what();
    }
    assert(resultado=="fuera de limite");
    return 0;
}