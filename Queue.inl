//Honor Pledge: ashstrin
//I pledge that I have neither given nor received any help
//on this assignment.

template <typename T>
inline
T Queue<T>::front (void) const
{
   return Array_Base<T>::data_[front_];
}

template <typename T>
inline
T Queue<T>::back (void) const
{
	return Array_Base<T>::data_[back_];
}

template <typename T>
inline 
bool Queue <T>::is_empty (void) const
{
	if(front_ < 0 || front_ > back_){
		return true;
		}
	return false;
}
