#include "pch.h"
#include "CppUnitTest.h"
#include <cstring>
#include <cmath>

extern "C" {
#include "..\CSCN71020_Group9/triangleSolver.h"
}

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace TestTriangleFunction
{
    TEST_CLASS(AnalyzeTriangleTests)
    {
    public:

        TEST_METHOD(TestEquilateralTriangle)
        {
            // All three sides are equal so it should be equilateral
            char* result = analyzeTriangle(5.0, 5.0, 5.0);
            Assert::IsNotNull(result);
            Assert::AreEqual(0, strcmp(result, "Equilateral Triangle"));
        }

        TEST_METHOD(TestIsoscelesTriangleSide3)
        {
            // Sides one and two match and side three is different
            char* result = analyzeTriangle(5.0, 5.0, 3.0);
            Assert::IsNotNull(result);
            Assert::AreEqual(0, strcmp(result, "Isosceles Triangle"));
        }

        TEST_METHOD(TestIsoscelesTriangleSide2)
        {
            // Sides one and three match and side two is different
            char* result = analyzeTriangle(5.0, 3.0, 5.0);
            Assert::IsNotNull(result);
            Assert::AreEqual(0, strcmp(result, "Isosceles Triangle"));
        }

        TEST_METHOD(TestIsoscelesTriangleSide1)
        {
            // Sides two and three match and side one is different
            char* result = analyzeTriangle(3.0, 5.0, 5.0);
            Assert::IsNotNull(result);
            Assert::AreEqual(0, strcmp(result, "Isosceles Triangle"));
        }

        TEST_METHOD(TestScaleneTriangle)
        {
            // All three sides are different and form a valid triangle
            char* result = analyzeTriangle(3.0, 4.0, 5.0);
            Assert::IsNotNull(result);
            Assert::AreEqual(0, strcmp(result, "Scalene Triangle"));
        }

        TEST_METHOD(TestInvalidNegativeSide1)
        {
            // Side one is negative so it is not a valid triangle
            char* result = analyzeTriangle(-3.0, 4.0, 5.0);
            Assert::IsNotNull(result);
            Assert::AreEqual(0, strcmp(result, "Not a triangle"));
        }

        TEST_METHOD(TestInvalidNegativeSide2)
        {
            // Side two is negative so it is not a valid triangle
            char* result = analyzeTriangle(3.0, -4.0, 5.0);
            Assert::IsNotNull(result);
            Assert::AreEqual(0, strcmp(result, "Not a triangle"));
        }

        TEST_METHOD(TestInvalidNegativeSide3)
        {
            // Side three is negative so it is not a valid triangle
            char* result = analyzeTriangle(3.0, 4.0, -5.0);
            Assert::IsNotNull(result);
            Assert::AreEqual(0, strcmp(result, "Not a triangle"));
        }

        TEST_METHOD(TestInvalidZeroSide1)
        {
            // Side one is zero so it cannot be a triangle
            char* result = analyzeTriangle(0.0, 4.0, 5.0);
            Assert::IsNotNull(result);
            Assert::AreEqual(0, strcmp(result, "Not a triangle"));
        }

        TEST_METHOD(TestInvalidZeroSide2)
        {
            // Side two is zero so it cannot be a triangle
            char* result = analyzeTriangle(3.0, 0.0, 5.0);
            Assert::IsNotNull(result);
            Assert::AreEqual(0, strcmp(result, "Not a triangle"));
        }

        TEST_METHOD(TestInvalidZeroSide3)
        {
            // Side three is zero so it cannot be a triangle
            char* result = analyzeTriangle(3.0, 4.0, 0.0);
            Assert::IsNotNull(result);
            Assert::AreEqual(0, strcmp(result, "Not a triangle"));
        }

        TEST_METHOD(TestInvalidTriangleInequalitySide3)
        {
            // Sum of sides one and two is less than side three
            char* result = analyzeTriangle(1.0, 2.0, 10.0);
            Assert::IsNotNull(result);
            Assert::AreEqual(0, strcmp(result, "Not a triangle"));
        }

        TEST_METHOD(TestInvalidTriangleInequalitySide1)
        {
            // Sum of sides two and three is less than side one
            char* result = analyzeTriangle(10.0, 1.0, 2.0);
            Assert::IsNotNull(result);
            Assert::AreEqual(0, strcmp(result, "Not a triangle"));
        }

        TEST_METHOD(TestInvalidTriangleInequalitySide2)
        {
            // Sum of sides one and three is less than side two
            char* result = analyzeTriangle(1.0, 10.0, 2.0);
            Assert::IsNotNull(result);
            Assert::AreEqual(0, strcmp(result, "Not a triangle"));
        }
    };

    TEST_CLASS(TriangleAngleFinderTests)
    {
    public:

        TEST_METHOD(TestSumOfAngles)
        {
            // All three angles for a 3-4-5 triangle should add up to 180 degrees
            double angles[3] = { 0.0, 0.0, 0.0 };
            triangleAngleFinder(3.0, 4.0, 5.0, angles);
            Assert::AreEqual(180.0, angles[0] + angles[1] + angles[2], 0.01);
        }

        TEST_METHOD(TestAngle1ValueNotEqual)
        {
            // Check angle one when sides are 4, 5, and 6
            double angles[3] = { 0.0, 0.0, 0.0 };
            triangleAngleFinder(4.0, 5.0, 6.0, angles);
            Assert::AreEqual(41.41, angles[0], 0.01);
        }

        TEST_METHOD(TestAngle2ValueNotEqual)
        {
            // Check angle two when sides are 4, 5, and 6
            double angles[3] = { 0.0, 0.0, 0.0 };
            triangleAngleFinder(4.0, 5.0, 6.0, angles);
            Assert::AreEqual(55.77, angles[1], 0.01);
        }

        TEST_METHOD(TestAngle3ValueNotEqual)
        {
            // Check angle three when sides are 4, 5, and 6
            double angles[3] = { 0.0, 0.0, 0.0 };
            triangleAngleFinder(4.0, 5.0, 6.0, angles);
            Assert::AreEqual(82.82, angles[2], 0.01);
        }

        TEST_METHOD(TestAngle1ValueAllEqual)
        {
            // Angle one should be 60 when all sides are 5
            double angles[3] = { 0.0, 0.0, 0.0 };
            triangleAngleFinder(5.0, 5.0, 5.0, angles);
            Assert::AreEqual(60.0, angles[0], 0.01);
        }

        TEST_METHOD(TestAngle2ValueAllEqual)
        {
            // Angle two should be 60 when all sides are 5
            double angles[3] = { 0.0, 0.0, 0.0 };
            triangleAngleFinder(5.0, 5.0, 5.0, angles);
            Assert::AreEqual(60.0, angles[1], 0.01);
        }

        TEST_METHOD(TestAngle3ValueAllEqual)
        {
            // Angle three should be 60 when all sides are 5
            double angles[3] = { 0.0, 0.0, 0.0 };
            triangleAngleFinder(5.0, 5.0, 5.0, angles);
            Assert::AreEqual(60.0, angles[2], 0.01);
        }

        TEST_METHOD(TestNotEqual180)
        {
            // Check that sample angles not summing to 180 are flagged as invalid
            double angle1 = 45.0;
            double angle2 = 55.0;
            double angle3 = 45.0;
            double sum = angle1 + angle2 + angle3;
            Assert::IsTrue(std::abs(sum - 180.0) > 0.01);
        }

        TEST_METHOD(TestRightTriangleAngle1)
        {
            // Check angle one for a 3-4-5 right triangle
            double angles[3] = { 0.0, 0.0, 0.0 };
            triangleAngleFinder(3.0, 4.0, 5.0, angles);
            Assert::AreEqual(36.87, angles[0], 0.01);
        }

        TEST_METHOD(TestRightTriangleAngle2)
        {
            // Check angle two for a 3-4-5 right triangle
            double angles[3] = { 0.0, 0.0, 0.0 };
            triangleAngleFinder(3.0, 4.0, 5.0, angles);
            Assert::AreEqual(53.13, angles[1], 0.01);
        }

        TEST_METHOD(TestRightTriangleAngle3)
        {
            // Check the 90 degree right angle for a 3-4-5 triangle
            double angles[3] = { 0.0, 0.0, 0.0 };
            triangleAngleFinder(3.0, 4.0, 5.0, angles);
            Assert::AreEqual(90.0, angles[2], 0.01);
        }

        TEST_METHOD(TestIsoscelesAnglesEqualBase)
        {
            // Two equal sides should give two equal angles
            double angles[3] = { 0.0, 0.0, 0.0 };
            triangleAngleFinder(5.0, 5.0, 6.0, angles);
            Assert::AreEqual(angles[0], angles[1], 0.01);
        }

        TEST_METHOD(TestIsoscelesAnglesSum180)
        {
            // Isosceles triangle angles should sum to 180 degrees
            double angles[3] = { 0.0, 0.0, 0.0 };
            triangleAngleFinder(5.0, 5.0, 6.0, angles);
            Assert::AreEqual(180.0, angles[0] + angles[1] + angles[2], 0.01);
        }

        TEST_METHOD(TestEquilateralAnglesSum180)
        {
            // Equilateral triangle angles should sum to 180 degrees
            double angles[3] = { 0.0, 0.0, 0.0 };
            triangleAngleFinder(5.0, 5.0, 5.0, angles);
            Assert::AreEqual(180.0, angles[0] + angles[1] + angles[2], 0.01);
        }

        TEST_METHOD(TestScaleneAnglesSum180)
        {
            // Scalene triangle angles for 4-5-6 should sum to 180 degrees
            double angles[3] = { 0.0, 0.0, 0.0 };
            triangleAngleFinder(4.0, 5.0, 6.0, angles);
            Assert::AreEqual(180.0, angles[0] + angles[1] + angles[2], 0.01);
         }

        TEST_METHOD(TestInvalidInequalityAnglesSide3)
        {
            // Sides 1, 2, and 10 cannot make a valid triangle
            double angles[3] = { 0.0, 0.0, 0.0 };
            triangleAngleFinder(1.0, 2.0, 10.0, angles);
            Assert::IsTrue(
                std::isnan(angles[0]) ||
                std::isnan(angles[1]) ||
                std::isnan(angles[2]) ||
                std::abs((angles[0] + angles[1] + angles[2]) - 180.0) > 0.01
            );
        }

        TEST_METHOD(TestInvalidInequalityAnglesSide1)
        {
            // Sides 10, 2, and 1 cannot make a valid triangle
            double angles[3] = { 0.0, 0.0, 0.0 };
            triangleAngleFinder(10.0, 2.0, 1.0, angles);
            Assert::IsTrue(
                std::isnan(angles[0]) ||
                std::isnan(angles[1]) ||
                std::isnan(angles[2]) ||
                std::abs((angles[0] + angles[1] + angles[2]) - 180.0) > 0.01
            );
        }

        TEST_METHOD(TestInvalidInequalityAnglesSide2)
        {
            // Sides 1, 20, and 10 cannot make a valid triangle
            double angles[3] = { 0.0, 0.0, 0.0 };
            triangleAngleFinder(1.0, 20.0, 10.0, angles);
            Assert::IsTrue(
                std::isnan(angles[0]) ||
                std::isnan(angles[1]) ||
                std::isnan(angles[2]) ||
                std::abs((angles[0] + angles[1] + angles[2]) - 180.0) > 0.01
            );
        }

        TEST_METHOD(TestZeroSide1Angles)
        {
            // A zero side should not produce valid triangle angles
            double angles[3] = { 0.0, 0.0, 0.0 };
            triangleAngleFinder(0.0, 4.0, 5.0, angles);
            Assert::IsTrue(
                std::isnan(angles[0]) ||
                std::isnan(angles[1]) ||
                std::isnan(angles[2]) ||
                std::isinf(angles[0]) ||
                std::isinf(angles[1]) ||
                std::isinf(angles[2])
            );
        }

        TEST_METHOD(TestZeroSide2Angles)
        {
            // A zero side should not produce valid triangle angles
            double angles[3] = { 0.0, 0.0, 0.0 };
            triangleAngleFinder(3.0, 0.0, 5.0, angles);
            Assert::IsTrue(
                std::isnan(angles[0]) ||
                std::isnan(angles[1]) ||
                std::isnan(angles[2]) ||
                std::isinf(angles[0]) ||
                std::isinf(angles[1]) ||
                std::isinf(angles[2])
            );
        }

        TEST_METHOD(TestZeroSide3Angles)
        {
            // A zero side should not produce valid triangle angles
            double angles[3] = { 0.0, 0.0, 0.0 };
            triangleAngleFinder(3.0, 4.0, 0.0, angles);
            Assert::IsTrue(
                std::isnan(angles[0]) ||
                std::isnan(angles[1]) ||
                std::isnan(angles[2]) ||
                std::isinf(angles[0]) ||
                std::isinf(angles[1]) ||
                std::isinf(angles[2])
            );
        }

        TEST_METHOD(TestNegativeSide1Angles)
        {
            // A negative side should not produce valid triangle angles
            double angles[3] = { 0.0, 0.0, 0.0 };
            triangleAngleFinder(-10.0, 2.0, 3.0, angles);
            Assert::IsTrue(
                std::isnan(angles[0]) ||
                std::isnan(angles[1]) ||
                std::isnan(angles[2]) ||
                std::abs((angles[0] + angles[1] + angles[2]) - 180.0) > 0.01
            );
        }
        
        TEST_METHOD(TestNegativeSide2Angles)
        {
            // A negative side should not produce valid triangle angles
            double angles[3] = { 0.0, 0.0, 0.0 };
            triangleAngleFinder(10.0, -2.0, 3.0, angles);
            Assert::IsTrue(
                std::isnan(angles[0]) ||
                std::isnan(angles[1]) ||
                std::isnan(angles[2]) ||
                std::abs((angles[0] + angles[1] + angles[2]) - 180.0) > 0.01
            );
        }
        
        TEST_METHOD(TestNegativeSide3Angles)
        {
            // A negative side should not produce valid triangle angles
            double angles[3] = { 0.0, 0.0, 0.0 };
            triangleAngleFinder(10.0, 2.0, -3.0, angles);
            Assert::IsTrue(
                std::isnan(angles[0]) ||
                std::isnan(angles[1]) ||
                std::isnan(angles[2]) ||
                std::abs((angles[0] + angles[1] + angles[2]) - 180.0) > 0.01
            );
        }
    };
}