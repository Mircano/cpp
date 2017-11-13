#ifndef INVALIDCOLOREXEPTION_H
#define INVALIDCOLOREXEPTION_H
#include "BaseException.h"

class InvalidColorException : public BaseException
{
private:
	bool _rougeValide;
	bool _vertValide;
	bool _bleuValide;

public:
	//Constructeur
	InvalidColorException();
	InvalidColorException(const char* msg);
	InvalidColorException(const char * msg, bool rougeValide, bool vertValide, bool bleuValide);
	InvalidColorException(const InvalidColorException& invalidColorException);

	//Destructeur
	~InvalidColorException();

	//Methode
	bool rougeValide() const;
	bool vertValide() const;
	bool bleuValide() const;
};

#endif 
