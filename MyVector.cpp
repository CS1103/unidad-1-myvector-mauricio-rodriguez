//
// Created by mauri on 27/08/2019.
//

#include "MyVector.h"
#include <stdexcept>
#include <exception>
MyVector::MyVector():data(nullptr),c_elemen(0) {
}

MyVector::MyVector(int numero):c_elemen(numero){
    data= new int[c_elemen];
}

int MyVector::size() {
    return c_elemen;
}

void MyVector::push_back(int value) {
    // 1. Crear temporal
    int *temp = new int[c_elemen + 1];

    // 2. Transferir los datos a temp
    for(int i = 0; i < c_elemen; ++i)
        temp[i] = data[i];

    // 3. Borrar memoria anterior
    delete [] data;

    // 4. Apuntando a memoria actual
    data = temp;

    // 5. Actualizando valor
    data[c_elemen] = value;

    // 6. Actualizando valor
    c_elemen++;
}

void MyVector::pop_back() {
    // 1. Crear temporal
    int *temp = new int[c_elemen - 1];

    // 2. Transferir los datos a temp
    for(int i = 0; i < c_elemen-1; ++i)
        temp[i] = data[i];

    // 3. Borrar memoria anterior
    delete [] data;

    // 4. Apuntando a memoria actual
    data = temp;

    // 6. Actualizando valor
    c_elemen--;
}

void MyVector::insert(const int &position, const int &value) {
    data[position]=value;
    if (position>c_elemen-1)
        throw std::out_of_range("fuera de limite");
}

void MyVector::erase(const int &position) {
    // 1. Crear temporal
    int *temp = new int[c_elemen - 1];

    // 2. Transferir los datos a temp
    for(int i = 0; i < position; ++i)
        temp[i]=data[i];
    for(int i = position+1; i < c_elemen; ++i)
        temp[i-1]=data[i];

        // 3. Borrar memoria anterior
    delete [] data;

    // 4. Apuntando a memoria actual
    data = temp;

    // 6. Actualizando valor
    c_elemen--;
}

int MyVector::operator[](const int &index) {
    return data[index];
}

MyVector::~MyVector() {
    delete [] data;
}

MyVector operator+(MyVector & v1,MyVector& v2){
    MyVector temp;
    for (int i=0;i<v1.size();i++){
        temp.push_back(v1[i]);
    }
    for (int i=0;i<v2.size();i++)
        temp.push_back(v2[i]);
    return temp;
}

