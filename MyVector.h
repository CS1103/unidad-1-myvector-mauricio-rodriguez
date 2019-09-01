//
// Created by mauri on 27/08/2019.
//

#ifndef MYVECTOR_MYVECTOR_H
#define MYVECTOR_MYVECTOR_H


class MyVector {
private:
    int *data;
    int c_elemen;
public:
    MyVector();
    explicit MyVector(int);
    int size();
    void push_back(int);
    void pop_back();
    void insert(const int &,const int &);
    void erase(const int &);
    int operator[](const int &);
    friend MyVector operator+(MyVector &,MyVector &);
    virtual ~MyVector();

};


#endif //MYVECTOR_MYVECTOR_H
