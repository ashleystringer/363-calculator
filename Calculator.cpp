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
	Array<Command *> * postfix_temp = new Array<Command *>(expr_length);
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
				cmd = factory.create_subtract_command();
			}else if(token == "*"){
				cmd = factory.create_mult_command();
			}else if(token == "/"){
				cmd = factory.create_div_command();
			}else if(token == "%"){
	
			}
			if(temp->is_empty() || (cmd->precedence() > temp->top()->precedence())){
				std::cout << "temp->is_empty(): " << temp->is_empty() << std::endl;
				temp->push(cmd);
                                std::cout << "temp->is_empty(): " << temp->is_empty() << std::endl;
				//std::cout << "cmd->precedence(): " << cmd->precedence()<<std::endl;
				//std::cout << "temp->top()->precedence(): " << temp->top()->precedence() << std::endl;
			}else{
				while((cmd->precedence() <= temp->top()->precedence()) && (!temp->is_empty())){
					std::cout << "while loop" << std::endl;
					Command * el = temp->pop();
					postfix.set(i, el);	
					postfix_temp->set(i, el);
				}		
				temp->push(cmd);
			}

		}else if(token == "(" || token == ")"){

		}else{
			//cmd = factory.create_number_command(token);
			//append cmd to postfix
		}
	}
	postfix = *postfix_temp;
	std::cout << "temp->top(): " << temp->top() << std::endl;
	//std::cout << "postfix_temp->get(0): " << postfix_temp->get(0)<< std::endl;
	//std::cout << "postfix.get(0): " << postfix.get(0) << std::endl;
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
	//std::cout << postfix.get(0) << std::endl;
}
void Calculator::set_expression(std::string input){
	this->input = input; 	
}
