#include <sstream>
#include <string>
#include <iostream>
#include "CppUnitTest.h"
#include "../Lab_6.4r/Lab_6.4.cpp"

        using namespace Microsoft::VisualStudio::CppUnitTestFramework;

        void PrintArray(const int* a, int size, int i = 0);

        TEST_CLASS(UnitTest)
        {
        public:
            TEST_METHOD(TestCreateArrayRecursive)
            {
                const int size = 5;
                int a[size] = { 1, -2, 3, 4, 5 };
                std::stringstream ss;

                for (int i = 0; i < size; ++i) {
                    ss << "a[" << i << "] = " << a[i] << "; ";
                }

                std::ostringstream result;
                std::streambuf* original = std::cout.rdbuf(result.rdbuf());

                PrintArray(a, size);

                std::cout.rdbuf(original);

                std::string expected = ss.str();
                std::string actual = result.str();

                expected.erase(expected.find_last_not_of(" \n\r\t") + 1);
                actual.erase(actual.find_last_not_of(" \n\r\t") + 1);

                Assert::AreEqual(expected.c_str(), actual.c_str());
            }
        };

        void PrintArray(const int* a, int size, int i) {
            if (i < size) {
                std::cout << "a[" << i << "] = " << a[i] << "; ";
                PrintArray(a, size, i + 1);
            }
            else {
                std::cout << std::endl;
            }
        }