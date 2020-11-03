#ifndef _CS507_STACK_H_
#define _CS507_STACK_H_

#include <exception>

template <typename T>
class Stack : public Array_Base<T>{
	public:
		typedef T type;
		Stack (void);
		Stack (size_t length);
		Stack (const Stack & s);
		const Stack & operator = (const Stack & rhs);
		void push (T element);
		void pop ();
		T top (void) const;
		bool is_empty (void) const;
		size_t size (void) const;
		void clear (void);
	private:
		size_t top_;
		size_t testSize;
};
#include "Stack.inl"
#include "Stack.cpp"
#endif
