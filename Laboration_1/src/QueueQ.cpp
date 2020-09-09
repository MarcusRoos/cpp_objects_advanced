//
// Created by Marcus Roos on 2020-09-09.
// Mittuniversitet
// StudentID: Maro1904
//

#include "QueueQ.h"
#include <iostream>

void QueueQ::TESTPOST() {
    int size=0;
    std::cout << "Enter size of queue: " << std::endl;
    std::cin >> size;
    my_ptr[size];
}

QueueQ::QueueQ(int n) {
    my_ptr[n];
    head=0; // index in array for head
    tail=0; // index in array for tail
    nElem=0; // nr of items in queue
    maxElem=n; // max capacity of queue
}
