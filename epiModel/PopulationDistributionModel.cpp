#include "PopulationDistributionModel.h"
#include  <cstdlib>
#include "UtilFunctions.h"

PopulationDistributionModel::PopulationDistributionModel()
{
	PopulationDistributionModel(1);
}

PopulationDistributionModel::PopulationDistributionModel(int individuals)
{
	populationSize = individuals;
	for (int i = 0; i < populationSize; i++) {
		allIndividuals.push_back(new IndividualModel());
	}
	allIndividuals[0]->setExposed(true);
}

void PopulationDistributionModel::updateIndividuals()
{
	TransmissionModel transmission = TransmissionModel();
	for (IndividualModel* individual : allIndividuals) {
		individual->update();
	}
}

//Does nothing currently, population is not distributed.
void PopulationDistributionModel::updateDistribution()
{
	
}

//Naive implimentation, everyone interacts with everyone else
std::vector<IndividualPair*> PopulationDistributionModel::determineInteractionsWithinPopulation()
{	
	//clear the contents of the array so memory doesn't blow out.
	for (std::vector<IndividualPair*>::iterator i = interactionPairs.begin(); i != interactionPairs.end(); ++i) {
		delete* i;
	}
	interactionPairs.clear();

	for (int i = 0; i < allIndividuals.size() - 1; i++) {
		for (int j = i + 1; j < allIndividuals.size(); j++) {

			if (UtilFunctions::trialOutcome(interactionRate) ) {

				IndividualPair* pair = new IndividualPair(allIndividuals[i], allIndividuals[j]);
				interactionPairs.push_back(pair);
			}
		}
	}
	return interactionPairs;
}

//People who haven't come across the disease at all.
int PopulationDistributionModel::totalNonexposed()
{
	int sum = 0;
	for (IndividualModel* p : allIndividuals) if (! (p->isExposed() || p->isInfected() || p->isRecovered())) sum++;
	return sum;
}

int PopulationDistributionModel::totalExposed()
{
	int sum = 0;
	for (IndividualModel* p : allIndividuals) if (p->isExposed()) sum++;
	return sum;
}

//Get the number of infected people.
int PopulationDistributionModel::totalInfections()
{
	int sum = 0;
	for (IndividualModel* p : allIndividuals) if (p->isInfected()) sum++;
	return sum;
}

int PopulationDistributionModel::totalRecovered()
{
	int sum = 0;
	for (IndividualModel* p : allIndividuals) if (p->isRecovered()) sum++;
	return sum;
}
