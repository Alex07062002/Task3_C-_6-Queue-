//
// Created by Alexey on 11.04.2023.
//
#include <list>
#ifndef QUEUEWITHTEMPLATES_QUEUETEMPLATES_H
#define QUEUEWITHTEMPLATES_QUEUETEMPLATES_H
using namespace std;

template<class X>
class QueueTemplates {
private:
    list<X>* queue;
protected:
    int* capacity;
public:
    QueueTemplates():queue(new list<X>),capacity(new int(0)){};

    bool empty(){
        if (queue->empty()) {
            return true;
        }
        return false;
    }

    int size(){
        return *capacity;
    }
    X back(){
        if (!empty()) {
            return queue->back();
        } else{
            cout<<"Error! Queue is empty..."<<"\n";
        }
    }
    X front(){
        if (!empty()) {
            return queue->front();
        } else{
            cout<<"Error! Queue is empty..."<<"\n";
        }
    }
    void pop(){
        if (!empty()) {
            queue->pop_front();
            *capacity = *capacity-1;
        } else{
            cout<<"Error! Queue is empty..."<<"\n";
        }
    }
    void push(X element){
        queue->push_front(element);
        *capacity = *capacity+1;
    };
    void destroy(){
        delete queue;
        delete capacity;
    }
};

#endif
