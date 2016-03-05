// -> COW refernce count implementation

#include "stdafx.h"
#include "String_Buffer.h"
#include <iostream>


StringBuffer::StringBuffer() // ->  default constructor
{
	_str = nullptr; // -> sets string buffer = null
}

str::str() //-> constructor
{
	_strbuf=nullptr;
	_length=0;
	_refcount=1;
}

str* StringBuffer::get_str(){
	
	// -> get string
	return _str;


}
StringBuffer::StringBuffer(const StringBuffer& obj){

	// -> shallow copying constructor 
	_str->_length = obj.length();
	_str->_strbuf= new char[_str->_length];
	for (int i = 0;i<_str->_length;i++)
	{
		_str->_strbuf[i]=obj.charAt(i);
	}
}

StringBuffer::StringBuffer(char* ptr ,int length)
{
	// ->constructor to convert a char* to StringBuffer
	_str = new str;
	_str->_strbuf= new char[length];
	_str->_length= length;
	for (int i = 0; i < length - 1; i++)
	{
		_str->_strbuf[i]=ptr[i];
	}
}

char StringBuffer::charAt (int bufferindex) const
{
	// -> returns the character at the passed index
		return *(_str->_strbuf+bufferindex);
	
}

int StringBuffer::length() const{
	// -> returns the length of the buffer
	return _str->_length;
}

void StringBuffer::reserve(int length)
{
	// -> allocates memory of character length size
	_str= new str;
	_str->_strbuf= new char[length];
}

void StringBuffer::append(char c)
{
	// -> appendingcharacter at end of string
	if(_str->_refcount>1)
	{
		str* str1 = new str;
		str1->_length =_str->_length + 1;
		str1->_strbuf= new char[str1->_length];
		for (int i = 0; i < _str->_length; i++)
		{
			str1->_strbuf[i]=_str->_strbuf[i];
		}
		str1->_strbuf[_str->_length]=c;
		_str->_refcount--;
		_str=str1;

	}
	else
	{

		char* str1= _str->_strbuf;
		_str->_length++;
		_str->_strbuf=new char [_str->_length];
		for (int i = 0; i < _str->_length - 1; i++)
		{
			_str->_strbuf[i]=str1[i];
		}
		_str->_strbuf[_str->_length - 1 ]=c ;
		delete[] str1;

	}


}


StringBuffer& StringBuffer::operator = (const StringBuffer& obj)
{
	// -> operator overloading
	_str=obj._str;
	_str->_refcount++;
	return *this;
}

StringBuffer::~StringBuffer() //  -> destructor would delete the allocated buffer
{
if(_str->_refcount==1)
	{
		delete[] _str->_strbuf;
		delete _str;
	}
	else
	{
		_str->_refcount--;
	}
}
