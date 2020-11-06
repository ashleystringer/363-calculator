// Honor Pledge: ashstrin
//
//I pledge that I have neither given nor received any help
// on this assignment.

#include "Array.h"
#include <stdexcept>
#include <iostream>

template <typename T>
Array <T>::Array (void) : Array_Base<T>()
{

}

// Array (size_t)
//
template <typename T>
Array <T>::Array (size_t length) : Array_Base<T>(length)
{

}

//
// Array (size_t, char)
//

template <typename T>
Array <T>::Array (size_t length, T fill) : Array_Base<T> (length, fill)
{


}

//
// Array (const Array &)
//

template <typename T>
Array <T>::Array (const Array & array) : Array_Base<T> (array)
{


}

// operator =

template <typename T>
const Array <T> & Array <T>::operator = (const Array & rhs)
{
if(this != &rhs){
Array_Base<T>::~Array_Base();
Array_Base<T>::data_ = new T[rhs.max_size()];
Array_Base<T>::max_size_ = rhs.max_size();
Array_Base<T>::cur_size_ = rhs.size();
Array_Base<T>::data_ = rhs.data_;
}
return *this;
}



//
// operator []
//

template <typename T>
T & Array <T>::operator [] (size_t index)
{
if(Array_Base<T>::data_[index]){
return Array_Base<T>::data_[index];
}else{
throw std::out_of_range("Out of range");
} 
}


//
// operator [] 
//

template <typename T>
const T & Array <T>::operator [] (size_t index) const
{
if(Array_Base<T>::data_[index]){
return Array_Base<T>::data_[index];
}else{
throw std::out_of_range("Out of range");
}
}


//
// resize
//

template <typename T>
void Array <T>::resize (size_t new_size)
{
if((new_size < Array_Base<T>::cur_size_) || (new_size > Array_Base<T>::cur_size_)){
T * temp = new T[new_size];
for(int i = 0; i < new_size; i++){
temp[i] = Array_Base<T>::data_[i];
}
delete [] Array_Base<T>::data_;
Array_Base<T>::data_ = new T[new_size];
Array_Base<T>::cur_size_ = new_size;
Array_Base<T>::max_size_ = new_size;
for(int i = 0; i < Array_Base<T>::cur_size_; i++){
Array_Base<T>::data_[i] = temp[i];
}
delete [] temp;
}else if(new_size == Array_Base<T>::cur_size_){
Array_Base<T>::cur_size_ = new_size;
}
}

//
// operator ==
//
//
template <typename T>
bool Array <T>::operator == (const Array & rhs) const
{
if(Array_Base<T>::data_ == rhs.data_ && Array_Base<T>::max_size_ == rhs.max_size() && Array_Base<T>::cur_size_ == rhs.size()){
return true;
}

return false;
}



//
// operator !=
//

template <typename T>
bool Array <T>::operator != (const Array & rhs) const
{
if(Array_Base<T>::data_ != rhs.data_ && Array_Base<T>::max_size_ != rhs.max_size() && Array_Base<T>::cur_size_ != rhs.size()){
return true;
}
return false;
}



//
// shrink
//

template <typename T>
void Array<T>::shrink(){

if(Array_Base<T>::cur_size_ < Array_Base<T>::max_size_){
T *temp = new T[Array_Base<T>::cur_size_];
for(int i = 0; i < Array_Base<T>::cur_size_; i++){
temp[i] = Array_Base<T>::data_[i];
}

delete [] Array_Base<T>::data_;
Array_Base<T>::data_ = new T[Array_Base<T>::cur_size_];
for(int i = 0; i < Array_Base<T>::cur_size_; i++){
Array_Base<T>::data_[i] = temp[i];
} 
delete [] temp;

Array_Base<T>::max_size_ = Array_Base<T>::cur_size_; 
}
}
