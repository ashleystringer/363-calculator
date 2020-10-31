#ifndef _CS507_QUEUE_H

#define _CS507_QUEUE_H

template <typename T>

class Queue : public Array_Base<T>{ 

public:

typedef T type;

//Default constructor
//
Queue (void);
//Initializing constructor

Queue (size_t length);

//Copy constructor
Queue (const Queue & q);

const Queue & operator = (const Queue & rhs);

void enqueue(T element);

T dequeue(void);

//size_t size (void) const;

T front (void) const;

T back (void) const;

bool is_empty (void) const;

void clear();

private:
size_t front_;
size_t back_;
};

#include "Queue.inl"
#include "Queue.cpp"
#endif
