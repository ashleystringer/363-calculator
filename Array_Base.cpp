// Honor Pledge: ashstrin
//
// I pledge that I have neither given nor receieved any help
//on this assignment.

#include "Array_Base.h"

#include <stdexcept>

#include <iostream>



template <typename T>
Array_Base<T>::Array_Base (void) : cur_size_(0), max_size_(0), data_()
{}

template <typename T>
Array_Base<T>::Array_Base (size_t length) : cur_size_(length), max_size_(length), data_(new T[length])
{}

template <typename T>
Array_Base<T>::Array_Base (size_t length, T fill) : cur_size_(length), max_size_(length), data_(new T[length])
{
	for(int i = 0; i < length; i++){	
		data_[i] = fill;
	}
}

template <typename T>
Array_Base<T>::Array_Base (const Array_Base & arr) : cur_size_(arr.size()), max_size_(arr.max_size()), data_(arr.data_)
{



}

template <typename T>
Array_Base<T>::~Array_Base (void)
{
	delete [] data_;
}


template <typename T>
const Array_Base<T> & Array_Base<T>::operator = (const Array_Base & rhs)
{

}

template <typename T>
T & Array_Base<T>::operator [] (size_t index)
{

}

template <typename T>
const T & Array_Base<T>::operator [] (size_t index) const
{

}

template <typename T>
T Array_Base<T>::get (size_t index) const
{
	if(index <= cur_size_){
		std::cout << "cur_size_: " << cur_size_ << std::endl;
		std::cout << "data_[index]: " << data_[index] << std::endl;
		return data_[index];
	}else{
		throw std::out_of_range("Out of range");
	}
}



template <typename T>
void Array_Base<T>::set (size_t index, T value)
{
	if(index <= (cur_size_ - 1)){
		data_[index] = value;
		std::cout << "cur_size_: " << cur_size_ << " data_[0]: "<< data_[0] << " data_[index]: " << data_[index] <<std::endl;
	}else{
		throw std::out_of_range("Out of range");
	}
}

template <typename T>
int Array_Base<T>::find (T value) const
{
	for(int i = 0; i < cur_size_; i++){
		if(data_[i] == value){
			return i;
		}
	}
	return -1;
}



template <typename T>
int Array_Base<T>::find (T value, size_t start) const
{
if(start >= 0 && start <= cur_size_){
	for(int i = start; i < cur_size_; i++){
	if(data_[i] == value){
		return i;
		}
	}
	return -1;
	}else{
	throw std::out_of_range("Out of range");
	}
}

template <typename T>
bool Array_Base<T>::operator == (const Array_Base & rhs) const
{}

template <typename T>
bool Array_Base<T>::operator != (const Array_Base & rhs) const
{}

template <typename T>
void Array_Base<T>::fill (T value)
{
	for(int i = 0; i < cur_size_; i++){
	data_[i] = value;
	}

}



template <typename T>
void Array_Base<T>::reverse (void)
{
	int lengthIndex = cur_size_ - 1;
	int arrayHalf = cur_size_ / 2;
	for(int i = 0, j = lengthIndex; i < j; i++, j--){
		swap(i, j);
	}
}


template <typename T>
void Array_Base<T>::swap (int index1, int index2)
{
	T temp = data_[index1];
	data_[index1] = data_[index2];
	data_[index2] = temp;
}
