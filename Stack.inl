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
	//std::cout << "top_ in is_empty(): " << top_ << std::endl;
	int top_local = top_;
	bool isempty = top_local <= -1 ? 1 : 0;	
	//std::cout << "top_local: " << top_local << std::endl;
	//std::cout << "isempty " << isempty << std::endl;
	if(top_local <= 0){ //top_ <= 0 
		return true;
	}
	return false;
}
