// Honor Pledge: ashstrin
//
//I pledge that I have neither given nor received any help
//on this assignment.

#include <iostream>;
#include "Calculator.h";
#include <sstream>;

Calculator::Calculator(){

}
Calculator::~Calculator(){

}
bool Calculator::infix_to_postfix(const std::string & infix, Expr_Command_Factory & factory, Array<Command *> & postfix){
	//** Infix to Postfix conversion is not yet complete **
	
	std::istringstream input(infix);
	std::string token;
		
	std::cout << "Infix to Postfix" << std::endl;
	Command * cmd = 0;
	Stack<Command *> temp;
	int i = -1;		
	while(!input.eof()){
		input >> token;
		i++;
		std::cout << token << std::endl;
		if(token == "+"){
			if(temp.is_empty()){
				cmd = factory.create_add_command();
				//temp.push(cmd);
			}	
		}
		else if(token == "-"){
			if(temp.is_empty()){
				/*if(temp.top()){

				}*/
				cmd = factory.create_subtract_command();
				//temp.push(cmd);
			}
		}else if(token == "*"){
			
		}else if(token == "("){

		}else{
			std::cout << "operand" << std::endl;
			std::string operand = token;
			//append to postfix expression
			//cmd = factory.create_number_command(operand);
			//posfix.set(i, cmd);
		}
	}
	return true;
}
void Calculator::run(){
	// ** Evaluation of commands from infix_to_postfix() is not yet complete **

	std::cout << "this->input " << this->input<< std::endl;
	Stack<int> result;		
	Array<Command *> postfix;
	Stack_Expr_Command_Factory factory;	
	//Stack_Expr_Command_Factory factory(result);
	infix_to_postfix(this->input, factory, postfix);	
	//int posfix_el = 0;
	/*while(postfix_el < postfix->max_size()){ //iterate through commands in postfix array
		postfix_el++;	
	}*/
	//int res = result.top();	

}
void Calculator::set_expression(std::string input){
	this->input = input; 	
}
