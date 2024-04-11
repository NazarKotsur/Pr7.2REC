#include "pch.h"
#include "CppUnitTest.h"
#include "../Pr7.2REC/Pr7.2REC.cpp"


using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace YourUnitTestNamespace
{
    TEST_CLASS(UnitTest1)
    {
    public:
        TEST_METHOD(TestCreateAndPrint)
        {
            const int n = 3;
            int** testMatrix = new int* [n];
            for (int i = 0; i < n; i++)
                testMatrix[i] = new int[n];

            Create(testMatrix, n, 0, 10);
            Print(testMatrix, n);

            for (int i = 0; i < n; i++)
                delete[] testMatrix[i];
            delete[] testMatrix;
        }

        TEST_METHOD(TestSumOfSecondaryDiagonal)
        {
            const int n = 3;
            int** testMatrix = new int* [n];
            for (int i = 0; i < n; i++)
                testMatrix[i] = new int[n];

            testMatrix[0][0] = 1;
            testMatrix[0][1] = 2;
            testMatrix[0][2] = 3;
            testMatrix[1][0] = 4;
            testMatrix[1][1] = 5;
            testMatrix[1][2] = 6;
            testMatrix[2][0] = 7;
            testMatrix[2][1] = 8;
            testMatrix[2][2] = 9;

            int expectedSum = 15;
            int actualSum = SumOfSecondaryDiagonalRec(testMatrix, n, 0);

            Assert::AreEqual(expectedSum, actualSum);

            for (int i = 0; i < n; i++)
                delete[] testMatrix[i];
            delete[] testMatrix;
        }
    };
}
