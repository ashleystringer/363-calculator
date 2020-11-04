#include <iostream>;
#include "Calculator.h";
#include <sstream>;
//#include "Stack_Expr_Command_Factory.h":

Calculator::Calculator(){

}

bool Calculator::infix_to_postfix(const std::string & infix, Expr_Command_Factory & factory, Array<Command *> & postfix){
	std::istringstream input(infix);
	std::string token;
	std::cout << "Infix to Postfix" << std::endl;
	Command * cmd = 0;
	Stack<Command *> temp;
	/*while(!input.eof()){
		input >> token;
		std::cout << "Testing input.eof" << std::endl;
		if(token == "+"){
			//cmd = factory.create_add_command();	
		}
	}*/
	/*std::istringstream input(infix); //Error
	std::string token;
	Command * cmd = 0;
	Stack<Command *> temp;
	while(!input.eof){
		input >> token;
		if(token == "+"){
			std::cout << "+" << std::endl;
			//cmd = factory.create_add_command();
		}else if(token == "-"){
			std::cout << "" << std::endl;
			//cmd = factory.create_subtract_command();
		}
	}*/
	return true;
}
void Calculator::run(){
	std::string test = "5 + 4";
	std::cout << "Testing run method " << test << std::endl;
	Stack<int> result;		
	Array<Command *> postfix;
	Stack_Expr_Command_Factory factory;	
	infix_to_postfix(test, factory, postfix);	
	/*infix_to_postfix (infix, factory, postfix);
	*/
	/*while(postfix){ //iterate through postfix array
		
	}*/
	//int res = result.top();	

}
