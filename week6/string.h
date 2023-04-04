



class String
{
	char* str;


public:
	int getLenght();
	bool empty();
	const char* c_str();
	String();
	String(const char* other);
	String(String const& other);
	String(String&& other);
	~String();
	String& operator=(const char* other);
	String& operator=(String const& other);
	String& operator=(String&& other);
	char operator[](int index);
	String operator+(String& const other);
	String operator+(const char* other);
	bool operator==(const String& other);
	bool operator==(const char* arr);
	bool operator!=(String const& other);
	bool operator!=(const char* other);
};

class Error
{
	unsigned int id;
	String arr;

public:

	Error();
	Error(unsigned int id, String& arr);
	Error& operator=(Error const& other);
	~Error();

};






