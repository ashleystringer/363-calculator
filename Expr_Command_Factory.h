#ifndef _EXPR_COMMAND_FACTORY_H_
#define _EXPR_COMMAND_FACTORY_H_

#include "Add_Command.h";

class Expr_Command_Factory
{
	public:
		//virtual ~Expr_Command_Factory (void) = 0;
		virtual Add_Command * create_add_command (void) = 0;
		//Expr_Command_Factory(const Expr_Command_Factory &);
	private:
		//Expr_Command_Factory (const Expr_Command_Factory &);
		//Expr_Command_Factory();
		//const Expr_Command_Factory & operator = (const Expr_Command_Factory &);
};

//#include "Expr_Command_Factory.cpp"
#endif
