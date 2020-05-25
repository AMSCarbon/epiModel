#pragma once
#include <vector>
#include"IndividualPair.h"
#include "IndividualModel.h"

static class TransmissionModel
{
private:
	float transmissionRate = 0.0001f;
public: 
	TransmissionModel();
	void calculateTransmissionForPairs(std::vector<IndividualPair*> pairs);
	void calculateTransmission(IndividualPair* pair);
};

