#ifndef _MULT_COMMAND_H_
#define _MULT_COMMAND_H_

#include "Binary_Op_Command.h";

class Mult_Command : public Binary_Op_Command{
	public:
		Mult_Command();
		virtual int precedence();
		virtual int evaluate(int n1, int n2) const;
		virtual char operator_type();
};

#include "Mult_Command.cpp";
#endif
