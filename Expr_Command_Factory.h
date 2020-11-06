// Honor Pledge: ashstrin
// 
// I pledge that I have neither given nor received any help
// on this assignment.

#ifndef _EXPR_COMMAND_FACTORY_H_
#define _EXPR_COMMAND_FACTORY_H_

#include "Add_Command.h";
#include "Subtract_Command.h";
#include "Number_Command.h";

class Expr_Command_Factory
{
	public:
		virtual ~Expr_Command_Factory (void) = 0;
		virtual Add_Command * create_add_command (void) = 0;
		virtual Subtract_Command * create_subtract_command (void) = 0;
		virtual Number_Command * create_number_command (int operand) = 0;
		//Expr_Command_Factory(const Expr_Command_Factory &);
	private:
		//Expr_Command_Factory (const Expr_Command_Factory &);
		//Expr_Command_Factory();
		//const Expr_Command_Factory & operator = (const Expr_Command_Factory &);
};

#include "Expr_Command_Factory.cpp"
#endif
