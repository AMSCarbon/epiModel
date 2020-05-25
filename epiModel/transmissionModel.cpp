#include "transmissionModel.h"
#include "UtilFunctions.h"
#include <stdio.h>


TransmissionModel::TransmissionModel()
{
}

void TransmissionModel::calculateTransmissionForPairs(std::vector<IndividualPair*> pairs)
{
	for (IndividualPair* pair : pairs) calculateTransmission(pair);
}

void TransmissionModel::calculateTransmission(IndividualPair* pair)
{
	//Transmission can't occur if neither person is infected.
	//Assumption: If someone is infected they can't be infected again until they recover.
	if (pair->firstPerson->isInfected() ^ pair->secondPerson->isInfected() && UtilFunctions::trialOutcome(transmissionRate)) {
		if (pair->firstPerson->canBeInfected()) {
			pair->firstPerson->setExposed(true);
		}
		else if (pair->secondPerson->canBeInfected()) {
			pair->secondPerson->setExposed(true);
		}
	}
}

