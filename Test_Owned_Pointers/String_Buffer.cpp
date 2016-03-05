// -> cpp implementation for owned pointer
#include "stdafx.h"
#include "String_Buffer.h"
#include <iostream>

StringBuffer::StringBuffer() // ->  default constructor
{
	_strbuf=nullptr;	// -> sets string buffer = null
	_length = 0;		// -> initializes length to zero
}

StringBuffer::~StringBuffer() //  -> destructor
{
	delete[] _strbuf;  // -> simple deleting the allocated buffer
}

StringBuffer::StringBuffer(const StringBuffer& obj){
	// -> shallow copying constructor 

	_length = obj.length();  
	_strbuf= new char[_length];

	for (int i = 0;i<_length;i++)
	{
		_strbuf[i]=obj.charAt(i);
	}
}

StringBuffer::StringBuffer(char* &ptr ,int length)
{
	// -> constructor to convert a char* to StringBuffer
	_strbuf= ptr;
	ptr = NULL; //-> setting null so that cant be modified by others
	_length= length;
	
}

char StringBuffer::charAt (int bufferindex) const
{
		// -> simply returns the character at the passed index of that buffer string	
		return *(_strbuf+bufferindex);
	
}

int StringBuffer::length() const{

	// -> returns the length of the buffer string
	return _length;
}

void StringBuffer::reserve(int length)
{
	// -> allocates memory of character length size
	_strbuf= new char[length];
	
}

void StringBuffer::append(char c)
{
	// -> appendingcharacter at end of string
	char* temp= _strbuf;
	_length++;
	_strbuf=new char [_length];

	for (int i = 0; i < _length - 1; i++)
	{
		_strbuf[i]=temp[i];
	}

	_strbuf[_length - 1 ]=c ;
	delete[] temp;
}