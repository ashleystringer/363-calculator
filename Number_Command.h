#ifndef NUM_COMMAND_H_
#define NUM_COMMAND_H_

#include "Expr_Command.h"

class Number_Command : public Expr_Command{
	public:
		Number_Command(int operand);
};

#include "Number_Command.cpp";
#endif
