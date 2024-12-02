#include "pch.h"
#include "CppUnitTest.h"
#include "../Lab_6.4r/Lab_6.4.cpp"
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		
        TEST_METHOD(TestCreateArrayRecursive)
        {
            vector<int> a = { 1, -2, 3, 4, 5 };
            stringstream ss;
            for (size_t i = 0; i < a.size(); ++i) {
                ss << "a[" << i << "] = " << a[i] << "; ";
            }

            ostringstream result;
            std::streambuf* original = std::cout.rdbuf(result.rdbuf());

            PrintArray(a); 

            std::cout.rdbuf(original); 

            string expected = ss.str();
            string actual = result.str();

            expected.erase(expected.find_last_not_of(" \n\r\t") + 1);
            actual.erase(actual.find_last_not_of(" \n\r\t") + 1);

            Assert::AreEqual(expected.c_str(), actual.c_str());
        }
	};
}
