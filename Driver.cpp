#include "Calculator.h";
#include "Stack.h";
#include <iostream>;

int main(int argc, char * argv []){
	//** Calculator is not yet fully functional **	
	//Only the expression is being outputted rather than the result
	
	Calculator * test = new Calculator();
	char input[50];
	while(input[0] != 'Q'){
		std::cout << "Please type in a mathematical expression." << std::endl;
		std::cin.getline(input, 50);
		if(input[0] != 'Q'){
			std::string expression(input);	
			test->set_expression(expression);
			test->run();
		}else{
			std::cout << "BYE" << std::endl;
		}
	}

/*	Stack<char> * st = new Stack<char>(4);
	st->push('d');
	st->push('q');
	st->push('p');
	st->push('s');
	st->pop();
	st->pop();
	st->push('u');
	st->push('9');
	st->pop();
	st->push('I');
	st->pop();
	st->pop();
	st->pop();
	st->push('n');
	std::cout << "st->top(): " << st->top() << std::endl; */
//	delete test;
	return 0;
}
