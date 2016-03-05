// -> unit test for copied pointers

#include "stdafx.h"
#include "CppUnitTest.h"
#include "String_Buffer.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace Test_Copied_Pointers
{		
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(TestMethod1) // -> test 1
		{
			// TODO: Your test code here
			char string[] = {'a' , 'm' , 'a' , 'l'}; // -> initializing string
			StringBuffer* obj = new StringBuffer(string,4); // -> buffer of same length

			string[3] = 's' ; //  -> s at index 3

			Assert::IsFalse(string[3] == obj->charAt(3)); // -> checks charAt func here
			//  -> checked that string not same means copied pointer
			delete obj; // -> delete
		}

		TEST_METHOD(TestMethod2){ //-> test2

			// -> tests the character at specific index after appending to it
			// -> When the appended char matches it returns true

			StringBuffer* obj = new StringBuffer();

			obj->append('a');
			obj->append('m');
			obj->append('a');
			obj->append('l');

			Assert::IsTrue(obj->charAt(1)== 'm'); // -> char at index 1 = m so returns true 
			Assert::IsTrue(obj->length()== 4);	// -> buffer of length 4 so returns true
			delete obj;
		}

		TEST_METHOD(TestMethod3){
			//  -> test3
			//  -> tests the character at specific index after appending to it
			//  -> When the appended char matches it returns true

			StringBuffer* obj = new StringBuffer();

			obj->append('a');
			obj->append('a');
			
			Assert::IsTrue(obj->length()== 2);
			delete obj; // -> delete 
		}
	};
}