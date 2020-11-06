#include <iostream>;
#include "Calculator.h";
#include <sstream>;

Calculator::Calculator(){

}

bool Calculator::infix_to_postfix(const std::string & infix, Expr_Command_Factory & factory, Array<Command *> & postfix){
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
	std::string test = "5 + 4";
	std::cout << "Testing run method " << test << std::endl;
	Stack<int> result;		
	Array<Command *> postfix;
	Stack_Expr_Command_Factory factory;	
	infix_to_postfix(test, factory, postfix);	
	/*while(postfix){ //iterate through postfix array
		
	}*/
	//int res = result.top();	

}
