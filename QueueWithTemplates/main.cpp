#include <iostream>
#include "QueueTemplates.h"
#include "QueueDynamicArray.h"

void queueWithList();
void queueWithArray(int size);

using namespace std;

int main() {
    int* selectChange = new int(0);
    cout << "Change of realization queue: 1 - with list, 2 - with dynamic array." << endl;
    cin >> *selectChange;
    if (*selectChange == 1){
        queueWithList();
    } else{
        int* size = new int(0);
        cout << "Print size of queue:" << endl;
        cin >> *size;
        queueWithArray(*size);
        delete size;
    }
    delete selectChange;
    return 0;
}


void queueWithList() {
    auto* q = new QueueTemplates<int>();
    q->push(12);
    q->push(23);
    q->push(34);
    cout << "Size of queue:" << q->size()<<"\n";
    cout << "Queue is empty? " << q->empty()<<"\n";
    cout<<q->front()<<"\n";
    cout<<q->back()<<"\n";
    for (int i = 0; i<3; i++) {
        q->pop();
    }
    cout << "Size of queue:" << q->size()<<"\n";
    cout << "Queue is empty? " << q->empty()<<"\n";
    q->pop();  // Must print "Error!.."
    q->destroy();

    auto* q1 =  new QueueTemplates<string>();
    q1->push("str");
    q1->push("trs");
    q1->push("rst");
    cout << "Size of queue:" << q1->size()<<"\n";
    cout << "Queue is empty? " << q1->empty()<<"\n";
    cout<<q1->front()<<"\n";
    cout<<q1->back()<<"\n";
    for (int i = 0; i<3; i++) {
        q1->pop();
    }
    cout << "Size of queue:" << q1->size()<<"\n";
    cout << "Queue is empty? " << q1->empty()<<"\n";
    q1->pop();  // Must print "Error!.."
    q1->destroy();
}

void queueWithArray(int size) {
    auto* q = new QueueDynamicArray<int>(size);
    q->push(12);
    q->push(23);
    q->push(34);
    cout << "Size of queue:" << q->size()<<"\n";
    cout << "Queue is empty? " << q->empty()<<"\n";
    cout<<q->front()<<"\n";
    cout<<q->back()<<"\n";
    for (int i = 0; i<3; i++) {
        q->pop();
    }
    cout << "Size of queue:" << q->size()<<"\n";
    cout << "Queue is empty? " << q->empty()<<"\n";
    q->push(22);
    cout << "Size of queue:" << q->size()<<"\n";
    cout << "Queue is empty? " << q->empty()<<"\n";
    cout<<q->front()<<"\n";
    q->pop();  // Must print "Error!.."
    q->destroy();

    auto* q1 =  new QueueDynamicArray<string>(size);
    q1->push("str");
    q1->push("trs");
    q1->push("rst");
    cout << "Size of queue:" << q1->size()<<"\n";
    cout << "Queue is empty? " << q1->empty()<<"\n";
    cout<<q1->front()<<"\n";
    cout<<q1->back()<<"\n";
    for (int i = 0; i<3; i++) {
        q1->pop();
    }
    cout << "Size of queue:" << q1->size()<<"\n";
    cout << "Queue is empty? " << q1->empty()<<"\n";
    q1->pop();  // Must print "Error!.."
    q1->destroy();
}
