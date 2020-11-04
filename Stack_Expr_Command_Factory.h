#ifndef _STACK_EXPR_COMMAND_FACTORY_H_
#define _STACK_EXPR_COMMAND_FACTORY_H_

class Stack_Expr_Command_Factory : public Expr_Command_Factory {
	public: 
		virtual ~Stack_Expr_Command_Factory (void); 
		virtual Add_Command * create_add_command(void);	
		Stack_Expr_Command_Factory();
		//Stack_Expr_Command_Factory(const Expr_Command_Factory &) : Expr_Command_Factory();
	private:
		//Stack_Expr_Command_Factory();
};

#include "Stack_Expr_Command_Factory.cpp";
#endif
