#define _CRT_SECURE_NO_WARNINGS
#include "pch.h"
#include "CppUnitTest.h"
#include "../Lab_08.1.it/Lab_08.1.it.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest81
{
	TEST_CLASS(UnitTest81)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
            Assert::AreEqual(4, Count("nono on"));
            Assert::AreEqual(0, Count("test"));
            Assert::AreEqual(0, Count(nullptr));
		}
		TEST_METHOD(TestMethod2)
		{
			const char* input1 = "no";
			char* result1 = Replace(input1);
			Assert::AreEqual("***", result1);
			delete[] result1;

			const char* input2 = "onion";
			char* result2 = Replace(input2);
			Assert::AreEqual("onion", result2);
			delete[] result2;

			const char* input3 = "";
			char* result3 = Replace(input3);
			Assert::AreEqual("", result3);
			delete[] result3;
		}
	};
}
