class Flyweight_Expr_Command_Factory : public Expr_Command_Factory{
    public: 
    	Flyweight_Expr_Command_Factory();
		virtual ~Flyweight_Expr_Command_Factory (void); 
		virtual Add_Command * create_add_command(void);	
		virtual Subtract_Command * create_subtract_command(void);
		virtual Mult_Command * create_mult_command(void);
		virtual Div_Command * create_div_command(void);
		virtual Number_Command * create_number_command(int operand);
		virtual Left_Parenth_Command * create_left_par_command();
		virtual Right_Parenth_Command * create_right_par_command();
    private:
        Add_Command * add_;
};