Flyweight_Expr_Command_Factory::Flyweight_Expr_Command_Factory(){
    this->add_ = new Add_Command();
    this->subtr_ = new Subtract_Command();
    this->mult_ = new Mult_Command();
    this->div_ = new Div_Command();
    this->left_ = new Left_Parenth_Command();
    this->right_ = new Right_Parenth_Command();
}
Flyweight_Expr_Command_Factory::~Flyweight_Expr_Command_Factory(void){
    delete this->add_;
    delete this->subtr_;
    delete this->mult_;
    delete this->div_;
    delete this->left_;
    delete this->right_;
}
Add_Command * Flyweight_Expr_Command_Factory::create_add_command(void){
    return this->add_;
}
Subtract_Command * Flyweight_Expr_Command_Factory::create_subtract_command(void){
    return this->subtr_;
}
Mult_Command * Flyweight_Expr_Command_Factory::create_mult_command(void){
    return this->mult_;
}
Div_Command * Flyweight_Expr_Command_Factory::create_div_command(void){
    return this->div_;
}
Left_Parenth_Command * Flyweight_Expr_Command_Factory::create_left_par_command(){
    return this->left_;
}
Right_Parenth_Command * Flyweight_Expr_Command_Factory::create_right_par_command(){
    return this->right_;
}
Number_Command * Flyweight_Expr_Command_Factory::create_number_command(int operand){
    Number_Command * num = new Number_Command(operand);
    return num;
}