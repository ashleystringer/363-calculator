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
		virtual int evaluate (int n1, int n2) const = 0; 
		virtual char operator_type() = 0;
};
#include "Binary_Op_Command.cpp"
#endif
