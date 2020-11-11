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
	//Command * cmd = 0;
	Binary_Op_Command * cmd = 0;
	Stack<Command *> * temp = new Stack<Command *>(4);
	int i = -1;		
	while(!input.eof()){
        // COMMENT This is an incomplete submisssion. You are not
        // handling all the required operators.
        
		input >> token;
		i++;
		std::cout << token << std::endl;
		if(token == "+" || token == "-" || token == "*"){
			if(token == "+"){
				cmd = factory.create_add_command();
			}else if(token == "-"){
				std::cout << "token == '-'" << std::endl;
				cmd = factory.create_subtract_command();
			}
			if(temp->is_empty()){
				std::cout << "is empty" << std::endl;
			}	
			std::cout << "cmd->precedence(): " << cmd->precedence() << std::endl;
			temp->push(cmd);
			std::cout << "temp->top()->precedence(): " << temp->top()->precedence() << std::endl;	
			if(temp->is_empty() && (cmd->precedence() > temp->top()->precedence())){
					//temp->push(cmd);
			}else{
				/*while((cmd->precedence() > temp->top()->precedence()) || temp->is_empty()){
					Command * el = temp.pop();
					//append el to postfix
				}*/
				//temp->push(cmd);
			}		
		}else if(token == "(" || token == ")"){

		}else{
			//cmd = factory.create_number_command(token);
			//append cmd to postfix
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
