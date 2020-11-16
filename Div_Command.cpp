Div_Command::Div_Command(){

}
int Div_Command::evaluate(int n1, int n2) const{
	return (n1 / n2);
}
int Div_Command::precedence(){
	return(2);
}
char Div_Command::operator_type(){
	return '/';
}
