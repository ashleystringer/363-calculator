#ifndef _DIV_COMMAND_H_
#define _DIV_COMMAND_H_

#include "Binary_Op_Command.h"

class Div_Command : public Binary_Op_Command{
	public:
		Div_Command();
		virtual int precedence();
};

#include "Div_Command.cpp";
#endif
