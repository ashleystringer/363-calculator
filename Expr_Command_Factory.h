// Honor Pledge: ashstrin
// 
// I pledge that I have neither given nor received any help
// on this assignment.

#ifndef _EXPR_COMMAND_FACTORY_H_
#define _EXPR_COMMAND_FACTORY_H_

#include "Add_Command.h";
#include "Subtract_Command.h";
#include "Mult_Command.h";
#include "Div_Command.h";
#include "Number_Command.h";
#include "Left_Parenth_Command.h";
#include "Right_Parenth_Command.h";

class Expr_Command_Factory
{
	public:
		virtual ~Expr_Command_Factory (void) = 0;
		virtual Add_Command * create_add_command (void) = 0;
		virtual Subtract_Command * create_subtract_command (void) = 0;
		virtual Mult_Command * create_mult_command (void) = 0;
		virtual Div_Command * create_div_command (void) = 0;
		virtual Number_Command * create_number_command (int operand) = 0;
		virtual Left_Parenth_Command * create_left_par_command() = 0;
		virtual Right_Parenth_Command * create_right_par_command() = 0;
	private:
};

#include "Expr_Command_Factory.cpp"
#endif
