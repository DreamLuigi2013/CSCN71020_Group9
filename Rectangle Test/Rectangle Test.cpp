#include "pch.h"
#include "CppUnitTest.h"

extern "C" {
#include "..\CSCN71020_Group9/rectangleSolver.h"
}

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace TestTriangleFunction
{
    TEST_CLASS(RectangleSolverTests)
    {
    public:

        TEST_METHOD(TestFindHypotenuseMaxSide)
        {
            // Largest side should be returned as the hypotenuse
            double result = findHypotenuse(3.0, 5.0, 4.0);
            Assert::AreEqual(5.0, result, 0.01);
        }

        TEST_METHOD(TestFindHypotenuseEqualSides)
        {
            // Equal sides should return that shared value
            double result = findHypotenuse(6.0, 6.0, 6.0);
            Assert::AreEqual(6.0, result, 0.01);
        }

        TEST_METHOD(TestFindHypotenuseWithZeroOrNegative)
        {
            // Hypotenuse check should still pick the largest value among inputs
            double result = findHypotenuse(-2.0, 0.0, 4.0);
            Assert::AreEqual(4.0, result, 0.01);
        }

        TEST_METHOD(TestIsARectangleValidPoints)
        {
            // Four points forming a valid rectangle should return true
            double sides[6] = { 3.0, 4.0, 5.0, 3.0, 4.0, 5.0 };
            bool result = isARectangle(sides);
            Assert::IsTrue(result);
        }

        TEST_METHOD(TestIsARectangleInvalidSides)
        {
            // Non-right side lengths should not be treated as a rectangle
            double sides[6] = { 2.0, 3.0, 4.0, 2.0, 3.0, 4.0 };
            bool result = isARectangle(sides);
            Assert::IsFalse(result);
        }

        TEST_METHOD(TestIsARectangleZeroInput)
        {
            // Zero side lengths should return false
            double sides[6] = { 0.0, 0.0, 0.0, 0.0, 0.0, 0.0 };
            bool result = isARectangle(sides);
            Assert::IsFalse(result);
        }
    };
}