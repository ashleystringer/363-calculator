// Honor Pledge: ashstrin
//
// I pledge that I have neither given nor receieved any help
// on this assignment.

template <typename T>
inline
size_t Array_Base<T>::size (void) const
{
	return cur_size_;
}

template <typename T>
inline
size_t Array_Base<T>::max_size (void) const

{
	return max_size_;
}
