#include "pch.h"
#include "CppUnitTest.h"
#include "../lab7.3_rec/lab7_3_rec.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest73rec
{
	TEST_CLASS(UnitTest73rec)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			int t = 0;
			const int rowCount = 3;
			const int colCount = 3;

			int** a = new int* [rowCount];
			for (int i = 0; i < colCount; i++)
				a[i] = new int[colCount];

			for (int i = 0; i < rowCount; i++)
				for (int j = 0; j < colCount; j++)
					a[i][j] = 0;


			t = Part1_Count(a, rowCount, colCount,1,1,0);
			Assert::AreEqual(t, 3);

			for (int i = 0; i < rowCount; i++)
				delete[] a[i];
			delete[] a;

		}
	};
}
