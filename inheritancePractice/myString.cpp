#include "myString.h"
#include <string>
using namespace std;
int MyString::total_MyString()
{
	return _total_MyString;
}

MyString& MyString::operator=(const MyString& rhs)
{
	_len = rhs._len;
	_data = new char[_len];
	strcpy(_data, rhs._data);
	return *this;
}

MyString& MyString::operator+=(const MyString& rhs)
{
	char* temp = new char[_len+ rhs.length()];
	strcpy(temp, this->_data);
	strcat(temp, rhs._data);
	
	_data = new char[_len + rhs.length()];
	_len = _len + rhs.length();
	strcpy(this->_data, temp);
	return *this;
}

char& MyString::operator[](const int pos) const
{
	return this->_data[pos];
}

unsigned MyString::length() const
{
	return _len;
}

bool MyString::operator==(const MyString& b) const
{
	if(strcmp(this->_data,b._data)==0)
	{
		return true;
	}
	return false;
}


MyString::MyString()
{
	_total_MyString++;
	_data = nullptr;
	_len = 0;
}

MyString::MyString(const char* s)
{
	_total_MyString++;
	_len=strlen(s);
	_data = new char[_len];
	strcpy(_data, s);
	
}

MyString::MyString(const MyString& s)
{
	_total_MyString++;
	_len = s._len;
	_data = new char[_len];
	strcpy(_data, s._data);
	
}

MyString::~MyString()
{
	_total_MyString--;
}

ostream& operator<<(ostream& out, const MyString& s)
{
	std::cout << s._data;
	return out;
}

istream& operator>>(istream& in, MyString& is)
{
	in >> is._data;
	is._len = strlen(is._data);
	
	
	return in;
}

bool operator!=(const MyString& a, const MyString& b)
{
	if(a==b)
	{
		return false;
	}
	return true;
}


//////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	// MyString_Derived
	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////
MyString_Derived::MyString_Derived(const char* str)
	:MyString(str)
{
	
}