#pragma once// Деректива компоновщика, которая говорит что данный файл нужно включить в сборку 
			//один раз не зависимо от количества #includov

#include<iostream>
using namespace std;

class String;
String operator+(const String& left, const String& right);// прототип оператора +
std::ostream& operator<<(std::ostream& os, const String& obj);

////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////ОБЯВЛЕНИЕ КЛАССА (CLASS DECLARETION)//////////////////////////////

class String
{
	int size;	//размер строки в Байтах
	char* str;	//указатель на строку в динамической памяти
public:
	int get_size()const;
	const char* get_str()const;
	char* get_str();

	//-------------------Contructors------------------------

	explicit String(int size = 80);
	String(const char* str);
	String(const String& other);
	String(String&& other);
	~String();

	//------------------Operators-------------------
	String& operator=(const String& other);
	String& operator=(String&& other)noexcept;
	String& operator+=(const String& other);
	char operator[](int i)const;
	char& operator[](int i);

	//-----------------Methods--------------------------
	void print()const;
};
////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////КОНЕЦ ОБЯВЛЕНИЕ КЛАССА (CLASS DECLARETION END)/////////////////////