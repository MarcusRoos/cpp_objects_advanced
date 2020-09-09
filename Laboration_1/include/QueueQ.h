//
// Created by Marcus Roos on 2020-09-09.
// Mittuniversitet
// StudentID: Maro1904
//

#ifndef DT060G_QUEUEQ_H
#define DT060G_QUEUEQ_H
#include <memory>

typedef int Type; // Make Type an alias for int
const int QSIZE = 10; // Default Queue size
class QueueQ {
private:
    std::unique_ptr<Type[]> my_ptr;
    int head; // index in array for head
    int tail; // index in array for tail
    int nElem; // nr of items in queue
    int maxElem; // max capacity of queue

public:
    void TESTPOST();
    QueueQ(int n = QSIZE); // n = max capacity of queue
    // /* Pre: -
    // Post: A Queue object with capacity for n data- items is created. */
    void enqueue(Type elem);
    /* Pre: The Queue has not reached its maximum capacity.
     * Post: elem is inserted as the newest element in Queue. */
    void dequeue(Type &elem);
    /* Pre: The Queue is not empty.
     * Post: elem contains the oldest element in Queue- pre and elem is not contained in Queue. */
    int length() const;
    /* Pre: -
     * Post: Number of elements in Queue is returned. */
    bool full() const;
    /* Pre: -
     * Post: If Queue has reached its maximum capacity true is returned, else false is returned. */
    bool empty() const;
    /* Pre: -
     * Post: If Queue is true is returned, else false is returned. */
    int capacity() const;
    /* Pre: -
     * Post: Maximal number of elements that the Queue can hold Queue is returned. */ };

#endif //DT060G_QUEUEQ_H
