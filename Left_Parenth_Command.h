#ifndef _LEFT_PARENTH_COMMAND_H_
#define _LEFT_PARENTH_COMMAND_H_

#include "Command.h";

class Left_Parenth_Command : public Command{
        public:
                Left_Parenth_Command();
                virtual int precedence();
};

#include "Left_Parenth_Command.cpp";
#endif
