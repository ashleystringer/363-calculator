#include <string>
#include "Array_Base.h";
#include "Command.h";
#include "Expr_Command_Factory.h"; 

class Calculator{
	public:
		bool infix_to_postfix(const std::string & infix, Expr_Command_Factory & factory, Array_Base <Command *> & postfix);
};
