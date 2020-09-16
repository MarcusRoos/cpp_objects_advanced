//
// Created by Marcus Roos on 2020-09-09.
// Mittuniversitet
// StudentID: Maro1904
//

#include "QueueQ.h"
#include <iostream>
#include <algorithm>

QueueQ::QueueQ(int n)
:my_ptr(new Type[n])
{
    head=0; // index in array for head
    tail=0; // index in array for tail
    nElem=0; // nr of items in queue
    maxElem=n; // max capacity of queue
}

int QueueQ::capacity() const{
    return maxElem;
}

bool QueueQ::empty() const {
    return nElem == 0;
}

bool QueueQ::full() const {
    return nElem == capacity();
}

int QueueQ::length() const {
    return nElem;
}

void QueueQ::dequeue(Type &elem) {
    if (tail == capacity()){
        tail=0;
    }
    std::cout << "Deleting element: " << my_ptr[tail] << std::endl;
    nElem--;
    tail++;
}

void QueueQ::enqueue(Type elem) {
    if (head == capacity()){
        head=0;
    }
    my_ptr[head]=elem;
    std::cout << "ptr: " << my_ptr[head] << std::endl;
        head++;
        nElem++;
}