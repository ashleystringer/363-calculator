#ifndef _NUMBER_COMMAND_H_
#define _NUMBER_COMMAND_H_

#include "Expr_Command.h"
class Number_Command : public Expr_Command{
	public:
		Number_Command(int op);
		int get_operand();
		virtual int precedence();
	private:
		int operand;
};

#include "Number_Command.cpp";
#endif
