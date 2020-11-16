// Honor Pledge: ashstrin
//
// I pledge that I have neither given nor receieved any help
// on this assignment.
Add_Command::Add_Command(){

}
int Add_Command::evaluate(int n1, int n2) const{
	return (n1 + n2);
}
char Add_Command::operator_type(){
	return '+';
}
int Add_Command::precedence(){
	return(1);
}
