//Unit tests for owned pointers

#include "stdafx.h"
#include "CppUnitTest.h"
#include "String_Buffer.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

//test
namespace Test_Owned_Pointers
{		
	TEST_CLASS(UnitTest1)
	{

	public:

		TEST_METHOD(TestMethod1) // -> test method 1 checking copied pointer implementation
		{
			char* string = new char[1]; // -> string of length 1
			*string= 'a';  // -> initializing string with a

			// TODO: Your test code here
			StringBuffer* obj = new StringBuffer(string,1); 


			Assert::IsTrue(string==NULL);
			// -> checked that string not same means copied pointer
			delete obj; // -> delete created object.
		}

		TEST_METHOD(TestMethod2){ 
			// -> test method 2 append & length functions (single append)
			// -> this method tests the character at specific index after appending to it
			// -> When the appended char matches it at the index it returns true

			StringBuffer* obj = new StringBuffer(); // -> create string
			obj->append('m');	// -> append character 'm'
			Assert::IsTrue(obj->charAt(0)== 'm');  // -> returns true if m at index 0
			Assert::IsTrue(obj->length()== 1);		// -> return true if length of string is 1 
			delete obj; // -> delete 
		}

		TEST_METHOD(TestMethod3){
			// -> test method 3 tests append & length functions
			// -> tests the character at specific index after appending to it
			// -> When the appended char matches it returns true
			// ->  checks length equals to number of character appended it returns true

			StringBuffer* obj = new StringBuffer();

			obj->append('a'); // -> append character 'a'
			obj->append('m'); // -> append character 'm'
			obj->append('a'); // -> append character 'm'
			obj->append('l'); // -> append character 'm'
			
			Assert::IsTrue(obj->length()== 4); // -> returns true and test passed as length = 4 now
			delete obj; // -> delete
		}

	};
}

		

