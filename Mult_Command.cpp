Mult_Command::Mult_Command(){

}
int Mult_Command::evaluate(int n1, int n2) const{
	return (n1 * n2);
}
int Mult_Command::precedence(){
	return(2);
}
char Mult_Command::operator_type(){
	return '*';
}
