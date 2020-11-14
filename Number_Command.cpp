Number_Command::Number_Command(int op){
	operand = op;
}
int Number_Command::get_operand(){
	return operand;
}
int Number_Command::precedence(){
	return (0);
}
