#ifndef BASEEXCEPTION_H
#define BASEEXCEPTION_H

class BaseException
{
protected:
	char* _msg;

public:
	//Constructeur
	BaseException();
	BaseException(const char* message);
	BaseException(const BaseException& baseException);

	//Destructeur
	virtual ~BaseException();
	
	//Setteur
	void setMsg(const char* msg);

	//Getteur
	const char* getMsg() const;
};

#endif
