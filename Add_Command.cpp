// Honor Pledge: ashstrin
//
// I pledge that I have neither given nor receieved any help
// on this assignment.
Add_Command::Add_Command(){

}
bool Add_Command::execute(void){
	return true;
}
int Add_Command::evaluate(int n1, int n2) const{
	return n1;
}

int Add_Command::precedence(){
	return(1);
}
