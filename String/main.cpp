#include<iostream>
using namespace std;

class String;
String operator+(const String& left, const String& right);

class String
{
	int size;	//������ ������ � ������
	char* str;	//��������� �� ������ � ������������ ������
public:
	int get_size()const
	{
		return size;
	}
	const char* get_str()const
	{
		return str;
	}
	char* get_str()
	{
		return str;
	}

	//-------------------Contructors------------------------
	explicit String(int size = 80): size(size), str(new char[size] {})
	{
		//this->size = size;
		//this->str = new char[size] {};
		cout << "DefConstructor:\t" << this << endl;
	}
	String(const char* str): String(strlen(str)+1) //size(strlen(str) + 1), str(new char[size] {})
	{
		//this->size = strlen(str) + 1;//+1 ��� NULL-terminator
		//this->str = new char[size] {};
		for (int i = 0; str[i]; i++)this->str[i] = str[i];
		cout << "Constructor:\t" << this << endl;
	}
	//Deep copy (��������� �����������)
	//other
	//this
	//Shallow copy (������������� �����������)
	String(const String& other):String(other.str)	//size(other.size), str(new char[size]{})
	{
		//this->size = other.size;
		//Deep copy (��������� �����������):
		//this->str = new char[size] {};
		//for (int i = 0; i < size; i++)
		//	this->str[i] = other.str[i];
		//-----------------------------
		cout << "CopyConstructor:" << this << endl;
	}

	String(String&& other):size(other.size), str(other.str) //����������� �����������, ��� ����������� ������ ��������� �-������ � other �� this, ����� ��� ���� other ������
	{
		//this->size = other.size;
		//this->str = other.str;
		other.size = 0;				//���������� �������� �� ��������� �� ��������� ����������� ����������� ����������� �������(������)
		other.str = nullptr;
		cout << "MoveConstructor:" << this << endl;
	}

	~String()
	{
		delete[] this->str;
		this->str = nullptr;
		cout << "Destructor:\t" << this << endl;
		//Debug assertion failed
	}

	//------------------Operators-------------------
	String& operator=(const String& other)
	{
		/*int a = 2;
		int b = 3;
		a = b;*/

		if (this == &other)return *this;
		delete[] this->str;

		this->size = other.size;
		//Deep copy (��������� �����������):
		this->str = new char[size] {};
		for (int i = 0; i < size; i++)
			this->str[i] = other.str[i];
		//-----------------------------
		cout << "CopyAssignment:\t" << this << endl;
		return *this;
	}

	String& operator=(String&& other) noexcept
	{
		if (this != &other)
		{
			delete[] str;
			size = other.size;
			str = other.str;
			other.size = 0;
			other.str = nullptr;
		}
		return *this;
	}

	String& operator+=(const String& other)
	{
		return *this = *this + other;
	}

	char operator[](int i)const
	{
		return str[i];
	}
	char& operator[](int i)
	{
		return str[i];
	}

	//-----------------Methods--------------------------
	void print()const
	{
		cout << "Size:\t" << size << endl;
		cout << "Str:\t" << str << endl;
	}
};

String operator+(const String& left, const String& right)
{
	String cat(left.get_size() + right.get_size() - 1);
	for (int i = 0; i < left.get_size(); i++)
		cat[i] = left[i];
	//cat.get_str()[i] = left.get_str()[i];
	for (int i = 0; i < right.get_size(); i++)
		cat[i + left.get_size() - 1] = right[i];
	//cat.get_str()[i + left.get_size() - 1] = right.get_str()[i];
	return cat;

	//		l-value = r-value;
}

std::ostream& operator<<(std::ostream& os, const String& obj)
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
	str1 = str1;
	cout << str1 << endl;

	String str2 = "World";
	cout << str2 << endl;

	//String str3 = str1 + str2;	//Copy constructor
	String str3;
	str3 = str1 + str2;	//Copy assignment
	cout << str3 << endl;

	str1 += str2;
	cout << str1 << endl;
#endif // HOME_WORK

	String str4 = str1;
	cout << str4 << endl;
}
