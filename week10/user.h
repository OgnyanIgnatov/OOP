#ifndef USER_H
#define USER_H

class User
{
	char* username;

public:
	User();
	User(const char* username);
	User(const User& other);
	User(User&& otehr);
	User& operator=(const User& other);
	User& operator=(User&& other);
	~User();

};



#endif // !USER_H
