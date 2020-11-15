// Honor Pledge: ashstrin
// 
// I pledge that I have neither given nor received any help
// on this assignment.

#ifndef _STACK_EXPR_COMMAND_FACTORY_H_
#define _STACK_EXPR_COMMAND_FACTORY_H_

class Stack_Expr_Command_Factory : public Expr_Command_Factory {
	public: 
		virtual ~Stack_Expr_Command_Factory (void); 
		virtual Add_Command * create_add_command(void);	
		virtual Subtract_Command * create_subtract_command(void);
		virtual Mult_Command * create_mult_command(void);
		virtual Div_Command * create_div_command(void);
		virtual Number_Command * create_number_command(int operand);
		Stack_Expr_Command_Factory();
		//Stack_Expr_Command_Factory(size_t test);
		Stack_Expr_Command_Factory(Stack<int> &s);
		//Stack_Expr_Command_Factory(const Expr_Command_Factory &) : Expr_Command_Factory();
	private:
		Stack<int> stack;
		Stack_Expr_Command_Factory(const Stack_Expr_Command_Factory &);
};

#include "Stack_Expr_Command_Factory.cpp";
#endif
