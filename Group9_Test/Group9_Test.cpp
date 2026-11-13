#include "CppUnitTest.h"

//extern "C" {
//#include "../CSCN71020_Group9/main.h"
#include "../CSCN71020_Group9/triangleSolver.h"
//#include "../CSCN71020_Group9/rectangle.h"v
//}

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace Group9Test {
	TEST_CLASS(Group9Test) {
	public:
		// 
		TEST_METHOD(TestMethod1) {
			double side1 = 1;
			double side2 = 1;
			double side3 = 1;

			char* expected_result = analyzeTriangle(side1,side2,side3);
			char* result = "Equilateral Triangle";

			Assert::AreEqual(expected_result, result);
		}
	};
}
