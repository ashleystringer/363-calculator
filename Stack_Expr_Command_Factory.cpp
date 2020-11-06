Stack_Expr_Command_Factory::~Stack_Expr_Command_Factory(){

}

Stack_Expr_Command_Factory::Stack_Expr_Command_Factory(){
	
}

Add_Command * Stack_Expr_Command_Factory::create_add_command(void){
	//Add_Command * add = new Add_Command(); //Error - "Cannot allocate an object of abstract type ‘Add_Command’"
	Add_Command * add;
	return add;
}

Subtract_Command * Stack_Expr_Command_Factory::create_subtract_command(void){
	Subtract_Command * sub;
	return sub;
}

Number_Command * Stack_Expr_Command_Factory::create_number_command(int operand){
	Number_Command * num;
	return num;
}
