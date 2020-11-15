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
	int stack_length = 0;
	while(!input.eof()){
        // COMMENT This is an incomplete submisssion. You are not
        // handling all the required operators.
        	
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
				std::cout << "If statement" << std::endl;
				std::cout << "temp->top: " << temp->top()<< std::endl;
				temp->push(cmd);
				std::cout << "temp->top: " << temp->top() << std::endl;
				stack_length++;

			}else{
				while((!temp->is_empty()) && (cmd->precedence() <= temp->top()->precedence())){
					i++;
					Command * el = temp->pop();
					stack_length--;
					std::cout << "i: " << i << " postfix for while" << std::endl;
					postfix_temp->set(i, el);
					//std::cout << "temp->top(): " << temp->top() << std::endl;	
			}		
			//	std::cout << "temp->top(): " << temp->top() << std::endl;
				temp->push(cmd);
				stack_length++;
			}
		}else if(token == "(" || token == ")"){
			if(token == "("){
				
			}else{

			}
		}else{
			i++;
			int operand = std::stoi(token);
			num_cmd = factory.create_number_command(operand);
			//std::cout << "i: " << i << " postfix for numbers" << std::endl;
			postfix_temp->set(i, num_cmd);
		}
		//std::cout << "(i + stack_length): " << (i + stack_length) << " (expr_length - 1): "<< (expr_length - 1) << std::endl;
		if((i + stack_length) == (expr_length - 1) && !temp->is_empty()){
			std::cout << "testing if statement" << std::endl;
			while(!temp->is_empty()){
				i++;
				std::cout << "temp->top(): " << temp->top() << std::endl;
				Command * el = temp->pop();
				std::cout << "el: " << el << std::endl;
				std::cout << "temp->top(): " << temp->top() << std::endl;
				postfix_temp->set(i, el);
			}
		}
	}
	postfix = *postfix_temp;
	for(int i = 0; i < expr_length; i++){
		std::cout << "postfix_temp: " << postfix_temp->get(i) << std::endl;
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
	std::cout << "" << std::endl;
	std::cout << "" << std::endl;

	size_t array_size = postfix.max_size();	
	Stack<int> * result = new Stack<int>(array_size);


	for(int i = 0; i < array_size; i++){
		if(postfix.get(i)->precedence() == 0){
			Number_Command * operand = static_cast<Number_Command*>(postfix.get(i));
			int number = operand->get_operand();
			result->push(number);
		}else{
			Binary_Op_Command * op = static_cast<Binary_Op_Command*>(postfix.get(i));
			char op_type = op->operator_type();
			int num1 = result->pop(); //result->top()
			//result->pop();
			int num2 = result->pop(); //result->top()
			int res = 0;
			std::cout << "num1: " << num1 << " num2: "<< num2 << std::endl;
			if(op_type == '+'){
				std::cout << "+" << std::endl; 
				Add_Command * Add = static_cast<Add_Command*>(postfix.get(i));
				res = Add->evaluate(num2, num1);
			}else if(op_type == '-'){
				std::cout << "-" << std::endl;
				Subtract_Command * Sub = static_cast<Subtract_Command*>(postfix.get(i));
				res = Sub->evaluate(num2, num1);
			}else if(op_type == '*'){
				std::cout << "*" << std::endl;
				Mult_Command * Mult = static_cast<Mult_Command*>(postfix.get(i));	
				res = Mult->evaluate(num2, num1);
			}else if(op_type == '/'){
				std::cout << "/" << std::endl;
				Div_Command * Div = static_cast<Div_Command*>(postfix.get(i));
				res = Div->evaluate(num2, num1);	
			}
			std::cout << "result->top(): " << result->top() << std::endl;
			result->push(res);	
			std::cout << "result->top(): " << result->top() << std::endl;
		}
	}
	
	std::cout << "result->top(): " << result->top() << std::endl;	
}
void Calculator::set_expression(std::string input){
	this->input = input; 	
}
