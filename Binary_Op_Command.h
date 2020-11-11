//Honor Pledge: ashstrin
//
//I pledge that I have neither given nor received any help
//on this assignment.

#ifndef _BINARY_OP_COMMAND_H_
#define _BINARY_OP_COMMAND_H_

#include "Expr_Command.h"
#include "Stack.h"

class Binary_Op_Command : public Expr_Command{
	public:
		bool execute(void);
		//virtual int precedence() = 0;
	private:
		Stack<int> s_;
		//int precedence_number; 
};
#include "Binary_Op_Command.cpp"
#endif
