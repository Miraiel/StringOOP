#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string>
using namespace std;

class String
{
	int size;	//размер строки в Байтах
	char* str;	//указатель на строку в динамической памяти
public:
	int get_size()const
	{
		return size;
	}
	const char* get_str()const
	{
		return str;
	}

	//--------------Contructors----------------
	String(int size = 80)
	{
		this->size = 80;
		this->str = new char[size] {};
		cout << "DefConstructor:\t" << this << endl;
	}
	
	String(const char* s)
	{
		size = strlen(s);
		str = new char[size+1];
		strcpy(str, s);
	}

	~String()
	{
		delete[] this->str;
		this->str = nullptr;
		cout << "Destructor:\t" << this << endl;
	}

	//----------------Operators-----------------

	String& operator=(const String& other)
	{
		size = other.size;
		for (int i = 0; i < size; i++)
		{
			str[i] = other.str[i];
			return *this;
		}
	}

	//-----------------Methods------------------
	void print()const
	{
		cout << "Size:\t" << size << endl;
		cout << "Str:\t" << str << endl;
	}
};


/*
String operator+(const String& slovo)
{
	
}
*/

std::ostream& operator<<(std::ostream& os, String& obj)
{
	return os << obj.get_str();
}

#define HOME_WORK

void main()
{
	setlocale(LC_ALL, "");
	/*String str;
	str.print();*/

#ifdef HOME_WORK
	String str1 = "Hello";
	cout << str1 << endl;

	String str2 = "World";
	cout << str2 << endl;

//	String str3 = str1 + str2;
//	cout << str3 << endl;
#endif // HOME_WORK

}