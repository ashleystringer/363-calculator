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

	std::istringstream input(infix);
	std::istringstream input_copy(infix);
	std::string token;
	std::string token_copy;	

	int expr_length = 0;
	while(!input_copy.eof()){
		input_copy >> token_copy;	
		std::string token_cmpr(token_copy);
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
	//RESPONSE All operations except '%', '(', and ')' function as intended
	//The code for '(' and ')' does work, but I can't yet resolve the issue with blank spots
	//at the end of the postfix array that occur after parsing through '(' and ')'         
	
		input >> token;
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
				std::cout << "Cannot yet read '%'" << std::endl;
				//cmd = factory.create_mod_command();	
			}
			if(temp->is_empty() || (cmd->precedence() > temp->top()->precedence())){
		
				temp->push(cmd);
				
				stack_length++;

			}else{
				while((!temp->is_empty()) && (cmd->precedence() <= temp->top()->precedence())){
					i++;
					Command * el = temp->pop();
					stack_length--;
					postfix_temp->set(i, el);
				}		
				temp->push(cmd);
				stack_length++;
			}
		}else if(token == "(" || token == ")"){
			std::cout << "Cannot yet read '(' or ')'" << std::endl;
			/*if(token == "("){
				Left_Parenth_Command * par_cmd = factory.create_left_par_command();		
				temp->push(par_cmd);
			}else{
				while(temp->top()->precedence() != -1){
					i++;
					Command * el = temp->top();	
					postfix_temp->set(i, el);	
					temp->pop();
				}
				temp->pop();
			}*/
		}else{
			i++;
			int operand = std::stoi(token);
			num_cmd = factory.create_number_command(operand);
			postfix_temp->set(i, num_cmd);
		}
		if((i + stack_length) == (expr_length - 1) && !temp->is_empty()){
			while(!temp->is_empty()){
				i++;
				Command * el = temp->pop();
				postfix_temp->set(i, el);
			}
		}
	}
	postfix = *postfix_temp;
	for(int i = 0; i < expr_length; i++){
	}	
	return true;
}
void Calculator::run(){
	Array<Command *> postfix;
	Stack_Expr_Command_Factory factory;	
	infix_to_postfix(this->input, factory, postfix);

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
			int num1 = result->pop(); 
			
			int num2 = result->pop();
			int res = 0;
			
			if(op_type == '+'){
				Add_Command * Add = static_cast<Add_Command*>(postfix.get(i));
				res = Add->evaluate(num2, num1);
			}else if(op_type == '-'){
				Subtract_Command * Sub = static_cast<Subtract_Command*>(postfix.get(i));
				res = Sub->evaluate(num2, num1);
			}else if(op_type == '*'){
				Mult_Command * Mult = static_cast<Mult_Command*>(postfix.get(i));	
				res = Mult->evaluate(num2, num1);
			}else if(op_type == '/'){
				Div_Command * Div = static_cast<Div_Command*>(postfix.get(i));
				res = Div->evaluate(num2, num1);	
			}else if(op_type == '%'){

			}
		
			result->push(res);	
		}	
	}
	
	std::cout << "Result:  " << result->top() << std::endl;	
}
void Calculator::set_expression(std::string input){
	this->input = input; 	
}
