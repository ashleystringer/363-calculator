// Honor Pledge: ashstrin
//
//I pledge that I have neither given nor receieved any help
//on this assignment.

#ifndef _ADD_COMMAND_H_
#define _ADD_COMMAND_H_

#include "Binary_Op_Command.h";

class Add_Command : public Binary_Op_Command{
	public:
		Add_Command();
		virtual int precedence();
		virtual bool execute(void);
		virtual int evaluate(int n1, int n2) const;
};

#include "Add_Command.cpp";
#endif

