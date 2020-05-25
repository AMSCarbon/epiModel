#include "IndividualModel.h"
#include "UtilFunctions.h"


void IndividualModel::setExposed(bool state)
{
	exposed = state;
}

bool IndividualModel::isExposed()
{
	return exposed;
}

bool IndividualModel::isInfected()
{
	return infected;
}

bool IndividualModel::isRecovered()
{
	return recovered;
}

void IndividualModel::update()
{
	if (exposed && UtilFunctions::trialOutcome(progressionRate)) {
		exposed = false; 
		infected = true;
		return;
	}

	if (infected && UtilFunctions::trialOutcome(recoveryRate)) {
		exposed = false;
		infected = false;
		recovered = true;
		return;
	}
}

bool IndividualModel::canBeInfected()
{
	return !(exposed || infected || recovered); // can't be infected if the person has had the disease.
}
