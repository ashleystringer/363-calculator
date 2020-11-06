// Honor Pledge: ashstrin
//
//I pledge that I have neither given nor received any help
//on this assignment.

#ifndef _ARRAY_H_
#define _ARRAY_H_

#include <cstring>
#include "Array_Base.h"

template <typename T>
class Array : public Array_Base<T>{
	public:
		typedef T type;

		Array (void);

		Array (size_t length);

		Array (size_t length, T fill);

		Array (const Array & arr);

		const Array & operator = (const Array & rhs);

		T & operator [] (size_t index);

		const T & operator [] (size_t index) const;

		void resize(size_t new_size);

		bool operator == (const Array & rhs) const;

		bool operator != (const Array & rhs) const;

		void shrink();
	private:
};

#include "Array.cpp"

#endif
