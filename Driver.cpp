#include "Calculator.h";
#include "Stack.h";
#include "Array.h";
#include <bits/stdc++.h>;
#include <iostream>;

int main(int argc, char * argv []){
	//** Calculator is not yet fully functional **	
	//Only the expression is being outputted rather than the result
	
	Calculator * calc = new Calculator();
	char input[50];
	std::string command = "";   
 
    // COMMENT Your program should loop until QUIT is entered.
    // RESPONSE This requirement is satisfied with the comparison of the command string    
	while(command.compare("QUIT") != 0){ //input[0] != 'Q'
		std::cout << "Please type in a mathematical expression." << std::endl;
		std::cin.getline(input, 50);
		std::string input_str(input);
		command = input_str;
		if(command.compare("QUIT") != 0){ //input[0] != 'Q'
			std::string expression(input);	
			calc->set_expression(expression);
			calc->run();
		}else{
			std::cout << "BYE" << std::endl;
		}
	}

	return 0;	
}
