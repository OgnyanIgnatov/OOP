#ifndef CALENDAR_H
#define CALENDAR_H

class User
{
	char* username;
	char* password;


public:

	User();
	User(char* username, char* password);
	User(User& other);
	~User();
	User(User&& other);
	User& operator=(User& other);
	User& operator=(User&& other);
	void addUser(char* fileName);
	User readUser(char* fileName);

};




#endif 
