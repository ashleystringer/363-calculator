// Honor Pledge: ashstrin
// I pledge that I have neither given nor received any help
// on this assignment.

#include "Stack.h";
#include <stdexcept>
#include <cstddef>
#include <iostream>

 template <typename T>
Stack <T>::Stack (void) : Array_Base<T>()
{
}
template <typename T>
Stack <T>::Stack(size_t length) : Array_Base<T>(length), top_(-1) //-1
{

}

//Stack
template <typename T>
Stack <T>::Stack (const Stack & stack) : Array_Base<T>(stack)
{
}

//push
template <typename T>
void Stack <T>::push (T element)
{
	//std::cout << "top_ " << top_ << std::endl;
	int test = ((top_ + 1) % Stack<T>::max_size_);
	std::cout << "top_ in push : " << top_ << std::endl;
	top_++;
 	if(top_ < Stack<T>::max_size_){
		Array_Base<T>::set(test, element); //top_
		
	 }else{	
		std::cout << "Stack is full" << std::endl;
		top_--;
		// throw std::overflow_error("Error - Stack is full");
 	}
//	std::cout << "top_ in push(): " << top_ << std::endl;
 }

// pop
template <typename T>
T Stack <T>::pop (void)
{
	int test = ((top_ + 1) % Stack<T>::max_size_);
	//top_--;
	if(!is_empty()){ //top_ >= 0
		top_--;
		std::cout << "data_[top_] " << Stack<T>::data_[top_] << std::endl;
		test = ((top_) % Stack<T>::max_size_);		
	}else{
		top_++;
		throw std::underflow_error("Error - Stack is empty");
 	}
//	std::cout << "top_ in pop(): " << top_ << std::endl;
	return Array_Base<T>::data_[test]; //top_
}

// operator =
 template <typename T>
 const Stack <T> & Stack <T>::operator = (const Stack & rhs)
 {
	 if(this != &rhs){
	Array_Base<T>::~Array_Base();
 	Array_Base<T>::data_ = new T[rhs.max_size()];
	Array_Base<T>::max_size_ = rhs.max_size();
	Array_Base<T>::cur_size_ = rhs.size();
	Array_Base<T>::data_ = rhs.data_; 
	top_ = rhs.top();
}
return *this;
}

// clear


template <typename T>
void Stack <T>::clear (void)
{
 	top_ = 0;
	Array_Base<T>::cur_size_ = 0;
	 delete [] Array_Base<T>::data_;
	Array_Base<T>::data_ = new T[Array_Base<T>::max_size_]; 
}
