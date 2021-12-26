#include "Stack.h";

#ifndef _CS507_FLYWEIGHT_H
#define _CS507_FLYWEIGHT_H

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
        Add_Command * add_ = 0;
		Subtract_Command * subtr_ = 0;
		Mult_Command * mult_ = 0;
		Div_Command * div_ = 0;
		Left_Parenth_Command * left_ = 0;
		Right_Parenth_Command * right_ = 0;
		Number_Command * number = 0;
};

#include "Flyweight_Expr_Command_Factory.cpp";
#endif;