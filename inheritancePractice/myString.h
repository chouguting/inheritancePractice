#ifndef MYSTRING_H
#define MYSTRING_H
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using std::ostream;
using std::istream;



class MyString {
private:
	char* _data{};
	int  _len{};
	static int _total_MyString;

public:

	/////////////////////////////////////////////////////////
		// 把σ strlen strcpy
	MyString();									// _data = NULL		len=0		total_MyString++
	MyString(const char* s);						// strlen strcpy _total_MyString++ 
	MyString(const MyString& s);					// strcpy _total_MyString++
	~MyString();									// _total_MyString--

/////////////////////////////////////////////////////////
	static int total_MyString();					// return _total_MyString
/////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////
// 把σ strcpy
	MyString& operator=(const MyString& rhs);

	/////////////////////////////////////////////////////////
	// 把σ strcat
	MyString& operator+=(const MyString& rhs);

	/////////////////////////////////////////////////////////
	char& operator[](const int pos) const;		// 

/////////////////////////////////////////////////////////
// 把σ strlen
	unsigned length() const;

	/////////////////////////////////////////////////////////
	friend ostream& operator<<(ostream&, const MyString&);
	friend istream& operator>>(istream&, MyString&);
	/////////////////////////////////////////////////////////
	// 把σ strcmp
	bool operator==(const MyString&) const;
	friend bool operator!=(const MyString&, const MyString&);
};







class MyString_Derived :public MyString{
public:
	MyString_Derived(const char* str);
};


#endif // MYSTRING_H
