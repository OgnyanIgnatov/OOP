#include "defaultuser.h"

int ID = 0;

defaultUser::defaultUser(int id, const char* username) : User(username)
{
	if (id <= 0)
	{
		id = 0;
	}
	this->id = id;
}