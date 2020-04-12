//
// Created by Jurayev, Yuriy on 11/04/2020.
//

#include <gmock/gmock.h>
#include <Awards.h>

using namespace std;

class MockRankList : public awards::RankList {
public:
	MOCK_METHOD0(getNext, string());
};
