#include "InvalidColorException.h"
#include <stdlib.h>

InvalidColorException::InvalidColorException() : BaseException() 
{
	_rougeValide = true;
	_vertValide = true;
	_bleuValide = true;
}

InvalidColorException::InvalidColorException(const char * msg) : BaseException(msg) 
{
	_rougeValide = true;
	_vertValide = true;
	_bleuValide = true;
}

InvalidColorException::InvalidColorException(const char * msg, bool rougeValide, bool vertValide, bool bleuValide) : BaseException(msg)
{
	_rougeValide = rougeValide;
	_vertValide = vertValide;
	_bleuValide = bleuValide;
}

InvalidColorException::InvalidColorException(const InvalidColorException& invalidColorException) : BaseException(invalidColorException)
{

	_rougeValide = invalidColorException.rougeValide();
	_vertValide = invalidColorException.vertValide();
	_bleuValide = invalidColorException.bleuValide();
}

InvalidColorException::~InvalidColorException() {}

//Methode
bool InvalidColorException::rougeValide() const
{
	return _rougeValide;
}

bool InvalidColorException::vertValide() const
{
	return _vertValide;
}

bool InvalidColorException::bleuValide() const
{
	return _bleuValide;
}
