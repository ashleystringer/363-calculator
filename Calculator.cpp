Calculator::infix_to_postfix(const std::string & infix, Expr_Command_Factory & factory, Array<Command *> & postfix){
	std::istringstream input(infix);
	std::string token;
	Command * cmd = 0;
	Stack<Command *> temp;
	while(!input.eof){
		input >> token;
		if(token == "+"){
			//cmd = factory.create_add_command();
		}else if(token == "-"){
			//cmd = factory.create_subtract_command();
		}
	}
}
