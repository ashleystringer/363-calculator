bool Binary_Op_Command::execute(void){
	int n2 = s_.pop();
	int n1 = s_.pop();
	int result = this->evaluate(n1, n2);
	s_.push(result);
}

