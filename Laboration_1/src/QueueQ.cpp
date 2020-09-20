//
// Created by Marcus Roos on 2020-09-09.
// Mittuniversitet
// StudentID: Maro1904
//

#include "QueueQ.h"
#include <algorithm>

/**
The QueueQ constructor, will accept an integer as parameter and use this value
 to create a queue of said size. It will use the size 10 by default if user
 somehow does not input a value, which would otherwise end up in a crash.
 It will also set default values for the head, tail, number of elements
 and maximum capacity.
*/
QueueQ::QueueQ(int n)
:my_ptr(new Type[n])
{
    head=0; // index in array for head
    tail=0; // index in array for tail
    nElem=0; // nr of items in queue
    maxElem=n; // max capacity of queue
}

/**
The capacity function, will return the maxElem variable as to indicate the
 maximum size of the queue.
*/
int QueueQ::capacity() const{
    return maxElem;
}

/**
The empty function, will return true/false depending on if the nElem variable
 is zero or not.
*/
bool QueueQ::empty() const {
    return nElem == 0;
}

/**
The full function, will return true/false depending on if the nElem variable
 is the same as maxElem variable or not, by using the earlier capacity function
*/
bool QueueQ::full() const {
    return nElem == capacity();
}

/**
The length function, will return the amount of elements currently in the queue,
 will do this by returning the nElem variable
*/
int QueueQ::length() const {
    return nElem;
}

/**
The dequeue function, will accept an integer (Type) to use as a reference,
 this input element will be referring to the element which will be
 removed. The dequeue will remove the value currently at the head and adjust
 the variable values.
*/
void QueueQ::dequeue(Type &elem) {
    if (head == capacity()){
        head=0;
    }
    elem = my_ptr[elem];
    nElem--;
    head++;
}

/**
The enqueue function, will accept an integer (Type) to use as an input,
 this input element will be added as an element to the queue which will be.
 The enqueue will put the said element at the top of the queue, where tail
 is currently at.
*/
void QueueQ::enqueue(Type elem) {
    if (tail == capacity()){
        tail=0;
    }
    my_ptr[tail]=elem;
    tail++;
        nElem++;
}