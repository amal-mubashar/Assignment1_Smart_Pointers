#include "stdafx.h"
#include <iostream>

// -> Header file for COW  linking implementation string buffer

class reflink;
class str;
class StringBuffer;

class reflink
{
public:
	StringBuffer* _address;
	reflink* next;
};

class str
{
public:
	char* _strbuf;    //buffer to store the original string
	int _length;      //length of the string
	int _refcount;		//no of references
	reflink* _reflink;	// this is head to link this with references
	str();	//constructor
};

class StringBuffer{ 
	//string buffer class

public :
	StringBuffer();  //default constructor
	~StringBuffer();                //destructor; would delete the allocated buffer
	StringBuffer(const StringBuffer&); //constructor for shallow copying
	StringBuffer(char*,int);   //constructor to convert a char* to StringBuffer
	char charAt(int) const;   //returns the character at the passed index
	int length() const;      //returns the length of the buffer
	void reserve(int);       //allocates memory for the string, according to the passed character length
	void append(char);       //appends a single character at the end
	reflink* get_link();	// -> returns linked list head
	StringBuffer& operator = (const StringBuffer&);

private:
	str*  _str;	
};

