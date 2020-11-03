#include "Calculator.h";
#include "Stack.h";
#include <iostream>;

int main(int argc, char * argv []){
	std::cout << "Testing Driver" << std::endl;
	Calculator *test = new Calculator();
	test->run();
	return 0;
}
