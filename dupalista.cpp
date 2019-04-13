#pragma once
#include <cstring>
#include<iostream>
template<typename T>
class Vector {

public :
    Vector() : _size(0){
        initializeArray(2);
    }

    Vector(int size) : _size(0), _allocatedSize(size){
        initializeArray(size);
    }

    const int getSize(){
        return this->_size;
    }

    void push(T val){
        validateArray();
        push_b(val);
    }

    void clear(){
        delete[] this->arr;
    }

    int getAllocatedSize(){
        return _allocatedSize;
    }

    int& operator [] (int i){return arr[i];}

private:
    void initializeArray(int size) {
        this->arr = new T[size];
    }

    void validateArray(){
        if(_size == _allocatedSize){
            extendArray();
        }
    }

    void extendArray(){
        std::cout << "ROZSZERZAM\n";
        T* t = createExtendedArray();
        deleteArray();
        initializeArray(_size * 2);
        this->arr = t;
    }

    T*  createExtendedArray(){
        T* tmp = new T[_size * 2];
        std::memcpy(tmp, arr, _size);
        return tmp;
    }

    void push_b(T val){
        arr[_size] = val;
        _size++;
        std::cout << "EL " << _size << " " << arr[_size - 1] << std::endl;
    }

    void deleteArray(){
        delete[] this->arr;
    }

private:
    int _size;
    int _allocatedSize;
    T* arr;
};
