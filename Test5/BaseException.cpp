#include "BaseException.h"
#include <string.h>
#include <stdlib.h>

//Constructeur
BaseException::BaseException()
{
	_msg = NULL;
}

BaseException::BaseException(const char* msg)
{
	_msg = NULL;
	setMsg(msg);
}

BaseException::BaseException(const BaseException& baseException)
{
	_msg = NULL;
	setMsg(baseException.getMsg());
}

//Destructeur
BaseException::~BaseException()
{
	if (_msg)
		delete[] _msg;
}

//Setteur
void BaseException::setMsg(const char * msg)
{
	if (_msg)
		delete[] _msg;

	if (!msg)
	{
		_msg = NULL;
	}
	else
	{
		_msg = new char[strlen(msg) + 1];
		strcpy(_msg, msg);
	}
}

//Getteur
const char* BaseException::getMsg() const
{
	return _msg;
}
