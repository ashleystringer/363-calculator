#include "Number_Command.h"; 
#include "Add_Command.h";
#include "Subtract_Command.h";

class Expr_Command_Factory{
	public:
		virtual ~Expr_Command_Factory (void) = 0;
		virtual Number_Command * create_number_command (int num) = 0;
		virtual Add_Command * create_add_command (void) = 0;
		virtual Subtract_Command * create_subtract_command (void) = 0;
	protected:
	private:
		Expr_Command_Factory (const Expr_Command_Factory &);
		const Expr_Command_Factory & operator = (const Expr_Command_Factory &);
};
