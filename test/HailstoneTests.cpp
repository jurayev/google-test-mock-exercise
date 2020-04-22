//
// Created by Jurayev, Yuriy on 11/04/2020.
//

#include <gtest/gtest.h>
#include <Hailstone.h>

TEST(HailstoneTest, ReturnsFalseForZero) {
	bool is_satisfies = sequence::satisfiesHailstone(0);

	EXPECT_FALSE(is_satisfies);
}

class HailstoneEvenNumbersTest: public ::testing::TestWithParam<uint64_t> {};

TEST_P(HailstoneEvenNumbersTest, ReturnsTrueForEvenNumbers) {
	//Arrange
	uint64_t startingNumber = GetParam();
	//Act
	bool is_satisfies = sequence::satisfiesHailstone(startingNumber);
	//Assert
	EXPECT_TRUE(is_satisfies);
}

INSTANTIATE_TEST_CASE_P(ReturnsTrueForEvenNumbersParameterized, HailstoneEvenNumbersTest,
		                ::testing::Values(2, 4, 66, 1440028, ULLONG_MAX-1));

class HailstoneUnevenNumbersTest: public ::testing::TestWithParam<uint64_t> {};

TEST_P(HailstoneUnevenNumbersTest, ReturnsTrueForUnevenNumbers) {
	unsigned long long startingNumber = GetParam();

	bool is_satisfies = sequence::satisfiesHailstone(startingNumber);

	EXPECT_TRUE(is_satisfies);
}

INSTANTIATE_TEST_CASE_P(ReturnsTrueForUnevenNumbersParameterized, HailstoneUnevenNumbersTest,
		                ::testing::Values(1, 3, 5, 1440027, ULLONG_MAX));

// unsigned long long = 18,446,744,073,709,551,615
