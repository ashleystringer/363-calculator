#ifndef _CS507_ARRAY_BASE_H_
#define _CS507_ARRAY_BASE_H_

#include <cstring>

template <typename T>
class Array_Base{
	public:
		typedef T type;
		Array_Base(void);
		Array_Base(size_t length);
		Array_Base(size_t length, T fill);
		Array_Base(const Array_Base & arr);
		~Array_Base(void);
		const Array_Base & operator = (const Array_Base & rhs);
		size_t size(void) const;
		size_t max_size(void) const;
		T & operator [] (size_t index);
		const T & operator [] (size_t index) const;
		T get(size_t index) const;
		void set(size_t index, T value);
		int find(T element) const;
		int find(T element, size_t start) const;
		bool operator == (const Array_Base & rhs) const;
		bool operator != (const Array_Base & rhs) const;
		void fill(T element);
		void reverse(void);

	protected:
		void swap(int index1, int index2);
		T * data_;
		size_t cur_size_;
		size_t max_size_;
}

#include "Array_Base.inl";
#include "Array_Base.cpp";

#endif
