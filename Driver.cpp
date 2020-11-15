#include "Calculator.h";
#include "Stack.h";
#include "Array.h";
#include <iostream>;

int main(int argc, char * argv []){
	//** Calculator is not yet fully functional **	
	//Only the expression is being outputted rather than the result
	
	Calculator * test = new Calculator();
	char input[50];
    
    // COMMENT Your program should loop until QUIT is entered.
    
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
	

	/*Stack<char> * st = new Stack<char>(4);
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
	st->pop();
	st->pop();
	st->pop();
	st->pop();
	st->push('r');
	std::cout << "st->top(): " << st->top() << std::endl;*/
	return 0;
}
