// -> unit test for COW reference linking
#include "stdafx.h"
#include "CppUnitTest.h"
#include "String_Buffer.h"


using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace Test_Copy_On_Write_Linking
{		
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(TestMethod1)// test1
		{
			// TODO: Your test code here
			char* obj= "amal";

			StringBuffer* obj1 = new StringBuffer(obj,4);		
			StringBuffer* obj2 = new StringBuffer();

			*obj2 = *obj1;

			int i = 0; // flag for checking the list , if address is equal it will change to 1

			reflink* j = obj1->get_link(); 
			// iterates through strings associated with obj1 and sets i to one if obj2 also found 
			while(j){
			
				if(j->_address == obj2){
						i= 1;
						break;
				}
				j = j->next;
			
			}

			Assert::IsTrue(i == 1); // True if obj2 in ref list of the obj1'string
			obj1->append('M');
			Assert::IsTrue (obj1->charAt(4) == 'M');

			// appends and checks if last char is the one appended
			Assert::IsFalse(obj1->length() == obj2->length());
			//checks that length changes after appending to one string


		}

	};
}