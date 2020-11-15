#ifndef _RIGHT_PARENTH_COMMAND_H_
#define _RIGHT_PARENTH_COMMAND_H_

#include "Command.h";

class Right_Parenth_Command : public Command{
        public:
                Right_Parenth_Command();
                virtual int precedence();
};

#include "Right_Parenth_Command.cpp";
#endif
