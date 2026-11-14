#include "pch.h"
#include "CppUnitTest.h"
#include <cstring>

extern "C" {
#include "C:\Users\sumis\source\repos\CSCN71020_Group9\CSCN71020_Group9/triangleSolver.h"
}

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace TriangleSolverUnitTests
{
    TEST_CLASS(AnalyzeTriangleTests)
    {
    public:

        TEST_METHOD(TestEquilateralTriangle)
        {
            char* result = analyzeTriangle(5.0, 5.0, 5.0);
            Assert::IsNotNull(result);
            Assert::AreEqual(0, strcmp(result, "Equilateral Triangle"));
        }

        TEST_METHOD(TestIsoscelesTriangle)
        {
            char* result = analyzeTriangle(5.0, 5.0, 3.0);
            Assert::IsNotNull(result);
            Assert::AreEqual(0, strcmp(result, "Isosceles Triangle"));
        }

        TEST_METHOD(TestScaleneTriangle)
        {
            char* result = analyzeTriangle(3.0, 4.0, 5.0);
            Assert::IsNotNull(result);
            Assert::AreEqual(0, strcmp(result, "Scalene Triangle"));
        }

        TEST_METHOD(TestInvalidNegativeSide)
        {
            char* result = analyzeTriangle(-3.0, 4.0, 5.0);
            Assert::IsNotNull(result);
            Assert::AreEqual(0, strcmp(result, "Not a triangle"));
        }

        TEST_METHOD(TestInvalidZeroSide)
        {
            char* result = analyzeTriangle(0.0, 4.0, 5.0);
            Assert::IsNotNull(result);
            Assert::AreEqual(0, strcmp(result, "Not a triangle"));
        }

        TEST_METHOD(TestInvalidTriangleInequality)
        {
            char* result = analyzeTriangle(1.0, 2.0, 10.0);
            Assert::IsNotNull(result);
            Assert::AreEqual(0, strcmp(result, "Not a triangle"));
        }
    };
}