#ifndef _MOD_COMMAND_H_
#define _MOD_COMMAND_H_

#include "Binary_Op_Command.h";

class Mod_Command : public Binary_Op_Command{
	public:
		Mod_Command();
		virtual int precedence();
		virtual bool execute(void);
		virtual int evaluate(int n1, int n2) const;
		virtual char operator_type(); 
};

#include "Mod_Command.cpp";
#endif
