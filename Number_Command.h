#ifndef _NUMBER_COMMAND_H_
#define _NUMBER_COMMAND_H_

#include "Expr_Command.h"
class Number_Command : public Expr_Command{
	public:
		Number_Command(int operand);
		virtual int precedence();
};

#include "Number_Command.cpp";
#endif
