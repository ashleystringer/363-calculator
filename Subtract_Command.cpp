// Honor Pledge: ashstrin
// 
// I pledge that I have neither given nor received any help
// on this assignment.

int Subtract_Command::evaluate(int n1, int n2) const{
	return n1 - n2;
}
int Subtract_Command::precedence(){
	return (1);
}
char Subtract_Command::operator_type(){
	return '-';
}
