//
// Created by Jurayev, Yuriy on 09/04/2020.
//

#include <gtest/gtest.h>
#include <Triangle.h>
#include <iostream>

using ::shapes::Triangle;


TEST(TriangleTest, HandlesTriangleConstructor) {
	EXPECT_NO_THROW(Triangle triangle(9, 6, 4));
	EXPECT_EQ(typeid(Triangle), typeid(Triangle(9, 6, 4)));
}

struct TriangleBaseInput {
	int side1, side2, side3;

	TriangleBaseInput(int side1, int side2, int side3)
		: side1(side1), side2(side2), side3(side3) {}
};

struct TrianglePerimeterInput: public TriangleBaseInput {
	int expected_perimeter;

	TrianglePerimeterInput(int side1, int side2, int side3, int expected_perimeter)
		: TriangleBaseInput(side1, side2, side3), expected_perimeter(expected_perimeter) {}
};

::std::ostream& operator<<(::std::ostream& os, const TrianglePerimeterInput& row) {
	return os << "side1: " << row.side1 << ", side2: "<< row.side2 << ", side3: "
	<< row.side3 << ", expected result: " << row.expected_perimeter;
}

class TrianglePerimeterTest: public testing::TestWithParam<TrianglePerimeterInput> {};

TEST_P(TrianglePerimeterTest, HandlesTrianglePerimeter) {
	//Arrange
	auto input = GetParam();
	Triangle triangle(input.side1, input.side2, input.side3);
	//Act
	int actual_perimeter = triangle.getPerimeter();
	//Assert
	EXPECT_EQ(input.expected_perimeter, actual_perimeter);
}

INSTANTIATE_TEST_CASE_P(HandlesTrianglePerimeterParameterized, TrianglePerimeterTest,
		                ::testing::Values(
							TrianglePerimeterInput(3, 2, 2, 7), // isosceles
							TrianglePerimeterInput(INT_MAX/3, INT_MAX/3, INT_MAX/3, INT_MAX), // equilateral with max boundary // bug found
							TrianglePerimeterInput(1, 1, 1, 3), // equilateral
							TrianglePerimeterInput(10, 8, 6, 24) // scalene // bug found
		                ));

struct TriangleAreaInput: public TriangleBaseInput {
	double expected_area;

	TriangleAreaInput(int side1, int side2, int side3, double expected_area)
		: TriangleBaseInput(side1, side2, side3), expected_area(expected_area) {}
};

class TriangleAreaTest: public ::testing::TestWithParam<TriangleAreaInput> {};

TEST_P(TriangleAreaTest, HandlesTriangleArea) {
	auto input = GetParam();
	Triangle triangle(input.side1, input.side2, input.side3);

	double actual_area = triangle.getArea();

	EXPECT_DOUBLE_EQ(input.expected_area, actual_area);
}

INSTANTIATE_TEST_CASE_P(HandlesTriangleAreaParameterized, TriangleAreaTest,
		                testing::Values(
		                	TriangleAreaInput(30, 25, 25, 300), // isosceles area
		                	TriangleAreaInput(INT_MAX-2, INT_MAX/2, INT_MAX/2, 78674647837022.906), // isosceles area with large inputs
		                	TriangleAreaInput(5, 5, 5, 10.825317547305483), // equilateral area
		                	TriangleAreaInput(5, 3, 4, 6) // scalene area // bug found
		                ));

TEST(TriangleTest, ReturnsTrueIfIsoscelesTriangle) {
	Triangle isosceles(10, 10, 9);

	bool isIsosceles = isosceles.isIsosceles();

	EXPECT_TRUE(isIsosceles);
}

class IsIsoscelesForNonIsoscelesTriangleTest: public ::testing::TestWithParam<TriangleBaseInput> {};

TEST_P(IsIsoscelesForNonIsoscelesTriangleTest, ReturnsFalseIfNonIsoscelesTriangle) {
	auto input = GetParam();
	Triangle triangle(input.side1, input.side2, input.side3);

	bool is_isosceles = triangle.isIsosceles();

	EXPECT_FALSE(is_isosceles);
}

INSTANTIATE_TEST_CASE_P(ReturnsFalseIfNonIsoscelesTriangleParameterized,
		                IsIsoscelesForNonIsoscelesTriangleTest,
		                ::testing::Values(
		                	TriangleBaseInput(50, 49, 25), // scalene
		                	TriangleBaseInput(333, 333, 333) // equilateral // bug found
		                ));

TEST(TriangleTest, ReturnsTrueIfEquilateralTriangle) {
	Triangle equilateral(1, 1, 1);

	bool is_equilateral = equilateral.isEquilateral();

	EXPECT_TRUE(is_equilateral);
}

class IsEquilateralForNonEquilateralTriangleTest: public ::testing::TestWithParam<TriangleBaseInput> {};

TEST_P(IsEquilateralForNonEquilateralTriangleTest, ReturnsFalseIfNonEquilateralTriangle) {
	auto input = GetParam();
	Triangle triangle(input.side1, input.side2, input.side3);

	bool is_equilateral = triangle.isEquilateral();

	EXPECT_FALSE(is_equilateral);
}

INSTANTIATE_TEST_CASE_P(ReturnsFalseIfNonEquilateralTriangleParameterized,
		                IsEquilateralForNonEquilateralTriangleTest,
		                ::testing::Values(
		                	TriangleBaseInput(INT_MAX-2, INT_MAX/2, INT_MAX/2), // isosceles
		                 	TriangleBaseInput(1200, 1000, 300) // scalene
						));

struct TriangleKindInput: public TriangleBaseInput {
	Triangle::Kind expected_kind;

	TriangleKindInput(int side1, int side2, int side3, Triangle::Kind expected_kind)
		: TriangleBaseInput(side1, side2, side3), expected_kind(expected_kind) {}
};

class TriangleKindTest: public ::testing::TestWithParam<TriangleKindInput> {};

TEST_P(TriangleKindTest, HandlesTriangleKind) {
	auto input = GetParam();
	Triangle triangle(input.side1, input.side2, input.side3);

	Triangle::Kind actual_kind = triangle.getKind();

	EXPECT_EQ(input.expected_kind, actual_kind);
}

INSTANTIATE_TEST_CASE_P(HandlesTriangleKindParameterized, TriangleKindTest,
		                ::testing::Values(
		                	TriangleKindInput(40, 21, 21, Triangle::Kind::ISOSCELES),
		                	TriangleKindInput(2, 2, 2, Triangle::Kind::EQUILATERAL), // bug found
		                	TriangleKindInput(33, 15, 20, Triangle::Kind::SCALENE)
		                ));
