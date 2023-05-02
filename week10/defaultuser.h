#include "user.h"

#ifndef DEFAULTUSER_H
#define DEFAULTUSER_H

class defaultUser : protected User
{
	int id;

public:
	defaultUser(int id, const char* username);
};





#endif // !DEFAULTUSER_H

