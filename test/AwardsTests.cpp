//
// Created by Jurayev, Yuriy on 11/04/2020.
//

/*** Implementation details
 Link with details https://www.cs.sfu.ca/~wsumner/teaching/exercise-unit-tests.html
 * Create Fake objects
 	Create STUB for awards::RankList
 	Create MOCK for awards::AwardCeremonyActions
 * Set fakes behavior
 * Verify call were made
 	 1. Ensure the call order: playAnthem(), awardBronze(), awardSilver(), awardGold(), turnOffTheLightsAndGoHome()
 	 2. Validate that the methods were called,
 	 3. Validate that they were called in the right order and with the right arguments.
***/

#include <gtest/gtest.h>
#include <MockRankList.h>
#include <MockAwardCeremonyActions.h>

using namespace std;
using namespace testing;

TEST(AwardsTest, PerformsCeremonyWithStrictOrder) {
	MockRankList recipients;
	EXPECT_CALL(recipients, getNext())
			.WillOnce(Return("Peter"))
			.WillOnce(Return("Mark"))
			.WillOnce(Return("Mary"));

	MockAwardCeremonyActions actions;
	{
		InSequence ceremony;

		EXPECT_CALL(actions, playAnthem()).Times(Exactly(1));
		EXPECT_CALL(actions, awardBronze(_)).Times(Exactly(1));
		EXPECT_CALL(actions, awardSilver(_)).Times(Exactly(1));
		EXPECT_CALL(actions, awardGold(_)).Times(Exactly(1));
		EXPECT_CALL(actions, turnOffTheLightsAndGoHome()).Times(Exactly(1));
	}

	// Function dependency injection with recipients and actions mock objects
	awards::performAwardCeremony(recipients, actions);
}
