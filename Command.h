// Honor Pledge: ashstrin
//
// I pledge that I have neither given nor received any help
// on this assignment.

#ifndef _COMMAND_H_
#define _COMMAND_H_

class Command{
	public:
		virtual int precedence() = 0;
};

#include "Command.cpp"
#endif
