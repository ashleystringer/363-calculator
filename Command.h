#ifndef _COMMAND_H_
#define _COMMAND_H_

class Command{
	virtual bool execute() = 0;
	virtual void evaluate() = 0;
};

#include "Command.cpp"
#endif
