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
	Stack<Command *> * temp = new Stack<Command *>(expr_length);
	int i = -1;
	while(!input.eof()){
        // COMMENT This is an incomplete submisssion. You are not
        // handling all the required operators.
        	//i++;
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
				//cmd = factory.create_mod_command();	
			}
			if(temp->is_empty() || (cmd->precedence() > temp->top()->precedence())){
				temp->push(cmd);
			}else{
				while((!temp->is_empty()) && (cmd->precedence() <= temp->top()->precedence())){
					i++;
					Command * el = temp->pop();
					std::cout << "i: " << i << " postfix for while" << std::endl;
					postfix_temp->set(i, el);
				}		
				temp->push(cmd);
			}
		}else if(token == "(" || token == ")"){

		}else{
			i++;
			int operand = std::stoi(token);
			num_cmd = factory.create_number_command(operand);
			//std::cout << "i: " << i << " postfix for numbers" << std::endl;
			postfix_temp->set(i, num_cmd);
		}
		//std::cout << "(i + 1): " << (i + 1) << " (expr_length - 1): "<< (expr_length - 1) << std::endl;
		if((i + 1) == (expr_length - 1) && !temp->is_empty()){
			/*i++;
			std::cout << "i: "<< i << " testing if statement" << std::endl;
			Command * el = temp->pop();
			postfix_temp->set(i, el);*/
			while(!temp->is_empty()){
				i++;
				Command * el = temp->pop();
				postfix_temp->set(i, el);
			}
		}
	}
	postfix = *postfix_temp;
	for(int i = 0; i < expr_length; i++){
		//std::cout << "postfix_temp: " << postfix_temp->get(expr_length) << std::endl;
		//std::cout << "postfix: " << postfix.get(expr_length) << std::endl;
	}	
	return true;
}
void Calculator::run(){
	// ** Evaluation of commands from infix_to_postfix() is not yet complete **
	Array<Command *> postfix;
	Stack_Expr_Command_Factory factory;	
	infix_to_postfix(this->input, factory, postfix);

	std::cout << "run" << std::endl;	

	std::cout << "max_size: " << postfix.max_size() << std::endl;
	
	size_t array_size = postfix.max_size();	

	Stack<int> * result = new Stack<int>(array_size);


	for(int i = 0; i < array_size; i++){
		if(postfix.get(i)->precedence() == 0){
			Number_Command * operand = static_cast<Number_Command*>(postfix.get(i));
			std::cout << "i: " << i << " Number_Command: " << operand->get_operand() << std::endl;
			int number = operand->get_operand();
			//std::cout << "number: " << number << std::endl;
			result->push(number);
		}else{
			Binary_Op_Command * op = static_cast<Binary_Op_Command*>(postfix.get(i));
		//	std::cout << "op->operator_type(): " << op->operator_type() << std::endl;
			char op_type = op->operator_type();
			int num1 = result->pop();
			std::cout << "num1: " << num1 << std::endl;
			if(op_type == '+'){
				std::cout << "...." << std::endl;
				Add_Command * Add = static_cast<Add_Command*>(postfix.get(i));
				int num2 = result->pop();
				std::cout << "num2: " << num2<< std::endl;
				int res = Add->evaluate(num1, num2);
				result->push(res);
			}else if(op_type == '-'){

			}else if(op_type == '*'){

			}else if(op_type == '/'){

			}
		}
	}
	
	std::cout << "result->top(): " << result->top() << std::endl;	
}
void Calculator::set_expression(std::string input){
	this->input = input; 	
}
