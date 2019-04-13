#pragma once
#include <cstring>

template<typename T>
class Vector {

public :
    Vector() : _size(0){
        initializeArray(2);
    }

    void push(T val){
        validateArray();
        push_b(val);
    }

    int& operator [] (int i){return arr[i];}

private:
    void initializeArray(int size) {
        this->arr = new T[size];
    }

    void validateArray(){
        if(_size == getSize()){
            extendArray();
        }
    }

    void extendArray(){
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
    }

    int getSize(){
        return sizeof(arr) / sizeof(T);
    }

    void deleteArray(){
        delete[] this->arr;
    }

private:
    int _size;
    T* arr;
};
