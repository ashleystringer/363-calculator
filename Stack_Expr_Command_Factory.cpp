// Honor Pledge: ashstrin
// 
// I pledge that I have neither given nor received any help
// on this assignment.

Stack_Expr_Command_Factory::~Stack_Expr_Command_Factory(){

}

Stack_Expr_Command_Factory::Stack_Expr_Command_Factory(){
	
}

Add_Command * Stack_Expr_Command_Factory::create_add_command(void){
	//Add_Command * add = new Add_Command(); //Error - "Cannot allocate an object of abstract type ‘Add_Command’"
	Add_Command * add = new Add_Command();
	//Add_Command * add;
	return add;
}

Subtract_Command * Stack_Expr_Command_Factory::create_subtract_command(void){
	Subtract_Command * sub = new Subtract_Command();
	return sub;
}
Mult_Command * Stack_Expr_Command_Factory::create_mult_command(void){
	Mult_Command * mult = new Mult_Command();
	return mult;
}
Div_Command * Stack_Expr_Command_Factory::create_div_command(void){
	Div_Command * div = new Div_Command();
	return div;
}
Number_Command * Stack_Expr_Command_Factory::create_number_command(int operand){
	Number_Command * num;
	return num;
}
