#include "Calculator.h";
#include "Stack.h";
#include <iostream>;

int main(int argc, char * argv []){
	
	Calculator * test = new Calculator();
	char input[50];
	while(input[0] != 'Q'){
		std::cout << "Please type in a mathematical expression." << std::endl;
		std::cin.getline(input, 50);
		if(input[0] != 'Q'){
			std::string expression(input);	
			//std::cout << "Expression: " << input << std::endl;	
			test->set_expression(expression);
			test->run();
		}else{
			std::cout << "BYE" << std::endl;
		}
	}

//	Calculator *test = new Calculator();
//	test->set_expression(expression);
//	test->run();
//	delete test;
	return 0;
}
