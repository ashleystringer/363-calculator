// Honor Pledge: ashstrin
// 
// I pledge that I have neither given nor received any help
// on this assignment.

#include <iostream>

template <typename T>
inline
T Stack <T>::top (void) const
{
	return Array_Base<T>::data_[top_];
}

template <typename T>
inline
bool Stack <T>::is_empty (void) const
{
	int top_local = top_;
	if(top_local <= -1){ 
		return true;
	}
	return false;
}
