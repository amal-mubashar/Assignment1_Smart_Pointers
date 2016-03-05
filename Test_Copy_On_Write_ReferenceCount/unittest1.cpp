#include "stdafx.h"
#include "CppUnitTest.h"
#include "String_Buffer.h"


using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace Test_Copy_On_Write_ReferenceCount
{		
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(TestMethod1) //test1
		{
			
			// TODO: Your test code here
			//to check if ref count being maintained

			char* abc = "ama";
			StringBuffer* obj = new StringBuffer(abc,4);
			StringBuffer* obj2 = new StringBuffer();
			
			*obj2 = *obj;
			Assert::IsTrue(obj->get_str()->_refcount == 2);
			
			obj2 -> append('l');
			Assert::IsTrue(obj-> get_str()->_refcount==1);
			Assert::IsTrue(obj2->charAt(4)=='l'); // checking append function

		}

		TEST_METHOD(TestMethod2) //test2
		{
			
			// TODO: Your test code here
			//to check if ref count being maintained

			char* abc = "ama";
			StringBuffer* obj = new StringBuffer(abc,5);
			StringBuffer* obj2 = new StringBuffer();
			
			*obj2 = *obj;
			obj2 -> append('l');
			obj2 -> append('m'); // checking append function
			Assert::IsFalse(obj->length() == obj2->length());
			//checking length function returns false as values not same
		}


				TEST_METHOD(TestMethod3) //test3
		{
			
			// TODO: Your test code here
			//to check if ref count being maintained
			char* abc = "ama";
			StringBuffer* obj = new StringBuffer(abc,4);
			StringBuffer* obj2 = new StringBuffer();
			
			*obj2 = *obj;
			obj2 -> append('l');

			Assert::IsTrue(obj2->charAt(4)=='l');
		}

	};
}