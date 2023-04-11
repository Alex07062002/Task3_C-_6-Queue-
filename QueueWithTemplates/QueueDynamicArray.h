//
// Created by Alexey on 11.04.2023.
//

#ifndef QUEUEWITHTEMPLATES_QUEUEDYNAMICARRAY_H
#define QUEUEWITHTEMPLATES_QUEUEDYNAMICARRAY_H
#include "iostream"
using namespace std;

template<class X>
class QueueDynamicArray {
private:
    int* countOfElement;
    X* dynamicArray;
protected:
    int* start;
    int* end;
    int* capacity;
public:
    explicit QueueDynamicArray(int size):countOfElement(new int(size)),dynamicArray(new X[size]),start(new int(size)),
    end(new int(size)),capacity(new int(0)){};
    bool empty(){
        if (*start == *end){
            return true;
        }
        return false;
    }
    bool isFull(){
        if (*capacity == *countOfElement){
            return true;
        }
        return false;
    }
    int size(){
        return *end-*start;
    }
    X back(){
        return dynamicArray[*end-1];
    }
    X front(){
        return dynamicArray[*start];
    }
    void pop(){
        if (!empty()){
            //dynamicArray[*start] = 0;
            *start = *start+1;
            *capacity = *capacity-1;
        } else{
            cout<<"Error!!! Queue is empty..."<<"\n";
        }
    }
    void push(X element){
        if (!isFull()){
            *start = *start-1;
            dynamicArray[*start] = element;
            *capacity = *capacity+1;
        } else{
            cout<<"Error! Queue is Full..."<<"\n";
        }
    }
    void destroy(){
        delete countOfElement;
        delete dynamicArray;
        delete start;
        delete end;
        delete capacity;
    }
};


#endif //QUEUEWITHTEMPLATES_QUEUEDYNAMICARRAY_H
