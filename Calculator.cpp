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
	std::cout << "Infix" << std::endl;	
	std::istringstream input(infix);
	std::istringstream input_copy(infix);
	std::string token;
	std::string token_copy;	

	int expr_length = 0;
	while(!input_copy.eof()){
		input_copy >> token_copy;	
		expr_length++;
	}

	//Command * cmd = 0;
	Binary_Op_Command * cmd = 0;
	Stack<Command *> * temp = new Stack<Command *>(expr_length);

	int i = -1;
	while(!input.eof()){
        // COMMENT This is an incomplete submisssion. You are not
        // handling all the required operators.
        
		input >> token;
		std::cout << token << std::endl;
		if(token == "+" || token == "-" || token == "*"){
			i++;
			if(token == "+"){
				cmd = factory.create_add_command();
			}else if(token == "-"){
				std::cout << "token == '-'" << std::endl;
				cmd = factory.create_subtract_command();
			}else if(token == "*"){
				cmd = factory.create_mult_command();
			}else if(token == "/"){
				cmd = factory.create_div_command();
			}else if(token == "%"){
	
			}
			/*if(i > 0){
				temp->pop();
			}*/
			
			if(temp->is_empty() || (cmd->precedence() > temp->pop()->precedence())){
				temp->push(cmd);
			}else{
				while((cmd->precedence() <= temp->pop()->precedence()) && (!temp->is_empty())){
					Command * el = temp->pop();
					postfix.set(i, el);	
				}		
				temp->push(cmd);
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
