#include "stdafx.h"
#include <iostream>

// -> Header file for COW  refernce count implementation string buffer

class str
{
public:
	char* _strbuf;  //buffer string
	int _length;    //length of the string
	int _refcount;	//no of references
	str();			//constructor
};
class StringBuffer{

public :
	StringBuffer();  //default constructor
	~StringBuffer();				 //destructor; would delete the allocated buffer
	StringBuffer(const StringBuffer&); //constructor for shallow copying
	StringBuffer(char*,int);   //constructor to convert a char* to StringBuffer
	char charAt(int) const;   //returns the character at the passed index
	int length() const;       //returns the length of the buffer
	void reserve(int);        //allocates memory for the string, according to the passed character length
	void append(char);        //appends a single character at the end
	str* get_str();
	StringBuffer& operator = (const StringBuffer&);

private:
	str*  _str;	
};
