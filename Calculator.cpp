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

	Number_Command * num_cmd = 0;
	Binary_Op_Command * cmd = 0;
	Array<Command *> * postfix_temp = new Array<Command *>(expr_length);
	//postfix = new Array<Command *>(expr_length);
	Stack<Command *> * temp = new Stack<Command *>(expr_length);
	int i = -1;
	while(!input.eof()){
        // COMMENT This is an incomplete submisssion. You are not
        // handling all the required operators.
        	i++;
		input >> token;
		std::cout << token << std::endl;
		if(token == "+" || token == "-" || token == "*" || token == "/" || token == "%"){
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
				temp->push(cmd);
			}else{
				while((cmd->precedence() <= temp->top()->precedence()) && (!temp->is_empty())){
					Command * el = temp->pop();
					postfix_temp->set(i, el);
				}		
				temp->push(cmd);
			}

		}else if(token == "(" || token == ")"){

		}else{
			std::cout << "i: " << i << std::endl;
			int operand = std::stoi(token);
			num_cmd = factory.create_number_command(operand);
			//std::cout << num_cmd << std::endl;
			postfix_temp->set(i, num_cmd);	
		}
	}
	postfix = *postfix_temp;
	for(int i = 0; i < expr_length; i++){
		Command * cmd_test = postfix_temp->get(expr_length);
		//postfix.set(expr_length, cmd_test);		
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

	std::cout << "run" << std::endl;	
	int postfix_el = 0;
	while(postfix_el < postfix.max_size()){ //iterate through commands in postfix array
		postfix_el++;	
		//std::cout << "postfix_el: " << postfix_el<< std::endl; 
		std::cout << postfix.get(postfix_el)<< std::endl;	
	}
	//int res = result.top();	
	//std::cout << postfix.get(1) << std::endl;
}
void Calculator::set_expression(std::string input){
	this->input = input; 	
}
