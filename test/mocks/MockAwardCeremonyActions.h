//
// Created by Jurayev, Yuriy on 11/04/2020.
//

#include <gmock/gmock.h>
#include <Awards.h>

using namespace std;

class MockAwardCeremonyActions : public awards::AwardCeremonyActions {
public:
	MOCK_METHOD0(playAnthem, void());
	MOCK_METHOD0(turnOffTheLightsAndGoHome, void());
	MOCK_METHOD1(awardBronze, void(string recipient));
	MOCK_METHOD1(awardSilver, void(string recipient));
	MOCK_METHOD1(awardGold, void(string recipient));
};
