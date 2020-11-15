Mod_Command::Mod_Command(){

}
bool Mod_Command::execute(void){
	return true;
}
int Mod_Command::evaluate(int n1, int n2) const{
	return (n1 % n2);
}
char Mod_Command::operator_type(){
	return '%';
}
