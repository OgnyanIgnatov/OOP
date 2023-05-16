#pragma once

class User
{

private:
	static int id;
	int user_id;
	char* name;
	char* password;

	void free();
	void copy(const User& other);
	void move(User&& other);
	

public:

	User(const char* name, const char* password);
	User(const User& other);
	User& operator=(const User& other);
	~User();
	User& operator=(User&& other);
	User(User&& other);
	char* getName();
	char* getPassword();
	char* encrypt(const char* password);
};
