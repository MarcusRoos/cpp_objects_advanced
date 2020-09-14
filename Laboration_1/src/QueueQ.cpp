//
// Created by Marcus Roos on 2020-09-09.
// Mittuniversitet
// StudentID: Maro1904
//

#include "QueueQ.h"
#include <iostream>
#include <algorithm>

QueueQ::QueueQ(int n)
{
    my_ptr = std::unique_ptr<Type>(new Type[n]);
    head=0; // index in array for head
    tail=-1; // index in array for tail
    nElem=0; // nr of items in queue
    maxElem=n; // max capacity of queue
}

int QueueQ::capacity() const{
    return maxElem;
}

bool QueueQ::empty() const {
    return nElem != 0;
}

bool QueueQ::full() const {
    return nElem != 0;
}

int QueueQ::length() const {
    return nElem;
}

void QueueQ::dequeue(Type &elem) {
    tail++;
    nElem--;
}

void QueueQ::enqueue(Type elem) {
        head++;
        nElem++;
        my_ptr[head];
}