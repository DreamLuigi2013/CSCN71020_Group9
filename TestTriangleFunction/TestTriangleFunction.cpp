#include "pch.h"
#include "CppUnitTest.h"
#include <cstring>

extern "C" {
#include "..\CSCN71020_Group9/triangleSolver.h"
}

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace TriangleSolverUnitTests
{
    TEST_CLASS(AnalyzeTriangleTests)
    {
    public:

        TEST_METHOD(TestEquilateralTriangle)
        {
            // Make sure 3 equal sides correctly return equilateral
            char* result = analyzeTriangle(5.0, 5.0, 5.0);
            Assert::IsNotNull(result);
            Assert::AreEqual(0, strcmp(result, "Equilateral Triangle"));
        }

        TEST_METHOD(TestIsoscelesTriangleSide3)
        {
            // Check that 2 equal sides and 1 different return isosceles
            char* result = analyzeTriangle(5.0, 5.0, 3.0);
            Assert::IsNotNull(result);
            Assert::AreEqual(0, strcmp(result, "Isosceles Triangle"));
        }
        TEST_METHOD(TestIsoscelesTriangleSide2)
        {
            // Check that 2 equal sides and 1 different return isosceles
            char* result = analyzeTriangle(5.0, 3.0, 5.0);
            Assert::IsNotNull(result);
            Assert::AreEqual(0, strcmp(result, "Isosceles Triangle"));
        }
        TEST_METHOD(TestIsoscelesTriangleSide1)
        {
            // Check that 2 equal sides and 1 different return isosceles
            char* result = analyzeTriangle(3.0, 5.0, 5.0);
            Assert::IsNotNull(result);
            Assert::AreEqual(0, strcmp(result, "Isosceles Triangle"));
        }

        TEST_METHOD(TestScaleneTriangle)
        {
            // Verify 3 different valid sides return scalene
            char* result = analyzeTriangle(3.0, 4.0, 5.0);
            Assert::IsNotNull(result);
            Assert::AreEqual(0, strcmp(result, "Scalene Triangle"));
        }

        TEST_METHOD(TestInvalidNegativeSide1)
        {
            // Negative side lengths shouldn't work as a triangle
            char* result = analyzeTriangle(-3.0, 4.0, 5.0);
            Assert::IsNotNull(result);
            Assert::AreEqual(0, strcmp(result, "Not a triangle"));
        }
        
        TEST_METHOD(TestInvalidNegativeSide2)
        {
            // Negative side lengths shouldn't work as a triangle
            char* result = analyzeTriangle(3.0, -4.0, 5.0);
            Assert::IsNotNull(result);
            Assert::AreEqual(0, strcmp(result, "Not a triangle"));
        }
        
        TEST_METHOD(TestInvalidNegativeSide3)
        {
            // Negative side lengths shouldn't work as a triangle
            char* result = analyzeTriangle(3.0, 4.0, -5.0);
            Assert::IsNotNull(result);
            Assert::AreEqual(0, strcmp(result, "Not a triangle"));
        }

        TEST_METHOD(TestInvalidZeroSide1)
        {
            // Side length of zero should be invalid
            char* result = analyzeTriangle(0.0, 4.0, 5.0);
            Assert::IsNotNull(result);
            Assert::AreEqual(0, strcmp(result, "Not a triangle"));
        }
        
        TEST_METHOD(TestInvalidZeroSide2)
        {
            // Side length of zero should be invalid
            char* result = analyzeTriangle(3.0, 0.0, 5.0);
            Assert::IsNotNull(result);
            Assert::AreEqual(0, strcmp(result, "Not a triangle"));
        }
        
        TEST_METHOD(TestInvalidZeroSide3)
        {
            // Side length of zero should be invalid
            char* result = analyzeTriangle(3.0, 4.0, 0.0);
            Assert::IsNotNull(result);
            Assert::AreEqual(0, strcmp(result, "Not a triangle"));
        }

        TEST_METHOD(TestInvalidTriangleInequalitySide3)
        {
            // Tests the rule where sum of two sides must be greater than the third
            char* result = analyzeTriangle(1.0, 2.0, 10.0);
            Assert::IsNotNull(result);
            Assert::AreEqual(0, strcmp(result, "Not a triangle"));
        }
        TEST_METHOD(TestInvalidTriangleInequalitySide1)
        {
            // Tests the rule where sum of two sides must be greater than the third
            char* result = analyzeTriangle(10.0, 1.0, 2.0);
            Assert::IsNotNull(result);
            Assert::AreEqual(0, strcmp(result, "Not a triangle"));
        }
        TEST_METHOD(TestInvalidTriangleInequalitySide2)
        {
            // Tests the rule where sum of two sides must be greater than the third
            char* result = analyzeTriangle(1.0, 10.0, 2.0);
            Assert::IsNotNull(result);
            Assert::AreEqual(0, strcmp(result, "Not a triangle"));
        }
    };
}