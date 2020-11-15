Div_Command::Div_Command(){

}
bool Div_Command::execute(void){
	return true;
}
int Div_Command::evaluate(int n1, int n2) const{
	return (n1 / n2);
}
int Div_Command::precedence(){
	return(2);
}
