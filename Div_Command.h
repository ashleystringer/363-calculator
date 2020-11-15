#ifndef _DIV_COMMAND_H_
#define _DIV_COMMAND_H_

#include "Binary_Op_Command.h"

class Div_Command : public Binary_Op_Command{
	public:
		Div_Command();
		virtual int precedence();
		virtual bool execute(void);
		virtual int evaluate(int n1, int n2) const;
};

#include "Div_Command.cpp";
#endif
