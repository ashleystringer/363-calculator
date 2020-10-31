// Honor Pledge: ashstrin
//I pledge that I have neither given nor received any help
//on this assignment.

#include "Queue.h";
#include <stdexcept>;
#include <iostream>;

template <typename T>
Queue <T>::Queue (void) : Array_Base<T>()
{}

template <typename T>
Queue<T>::Queue(const Queue & q) : Array_Base<T>(q) 
{
}
template <typename T>
Queue<T>::Queue(size_t length) : Array_Base<T>(length), front_(0), back_(-1){

}

template <typename T>
const Queue <T> & Queue <T>::operator = (const Queue & rhs){
	if(this != &rhs){
		Array_Base<T>::~Array_Base();
		Array_Base<T>::data_ = new T[rhs.max_size()];
		Array_Base<T>::max_size_ = rhs.max_size();
		Array_Base<T>::cur_size_ = rhs.size();
		Array_Base<T>::data_ = rhs.data_; 
		front_ = rhs.front_;
		back_ = rhs.back_;
		}
}

template <typename T>
void Queue<T>::enqueue(T element){
	back_++;
	if(back_ < Array_Base<T>::max_size_){
		Array_Base<T>::data_[back_] = element;
		}else{
		throw std::overflow_error("Error - Queue is full");
		back_--; 
		}
}
template <typename T>
T Queue<T>::dequeue(void){
	if(front_ < 0 || front_ > back_){
	throw std::underflow_error("Error - Queue is empty")
	 }else{
 	front_++;
	}
 return Array_Base<T>::data_[front_];
}

template <typename T>
void Queue<T>::clear(){
	Array_Base<T>::cur_size_ = 0;
	front_ = 0;
	back_ = -1;
	delete [] Array_Base<T>::data_;
	Array_Base<T>::data_ = new T[Array_Base<T>::max_size_];
}
