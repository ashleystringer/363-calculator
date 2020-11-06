// Honor Pledge: ashstrin
// 
// I pledge that I have neither given nor received any help
// on this assignment.

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
	if(top_ <= 0){
		return true;
	}
	return false;
}
