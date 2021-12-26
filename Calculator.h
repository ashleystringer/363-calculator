// Honor Pledge: ashstrin
//
//I pledge that I have neither given nor received any help
//on this assignment.

#include <string>
//#include "Array_Base.h";
#include "Array.h";
#include "Stack.h";
#include "Command.h";
#include "Binary_Op_Command.h";
#include "Expr_Command_Factory.h"; 
#include "Stack_Expr_Command_Factory.h";
#include "Flyweight_Expr_Command_Factory.h";

#ifndef _CS507_CALCULATOR_H
#define _CS507_CALCULATOR_H

class Calculator{
	public:
		Calculator();
		~Calculator();
		bool infix_to_postfix(const std::string & infix, Expr_Command_Factory & factory, Array <Command *> & postfix);
		void run();
		void set_expression(std::string input);
	private:
		std::string input;
		
};

#include "Calculator.cpp";

#endif;
