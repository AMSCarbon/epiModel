#pragma once
#include <vector>
#include "IndividualModel.h"
#include "TransmissionModel.h"
#include "IndividualPair.h"
class PopulationDistributionModel
{
private:  
	int populationSize=0; 
	float interactionRate = 1.0; // everyone meets.
	std::vector<IndividualModel*> allIndividuals;
	std::vector<IndividualPair*> interactionPairs;
public: 
	PopulationDistributionModel();
	PopulationDistributionModel(int individuals);
	
	void updateIndividuals();
	void updateDistribution();
	std::vector<IndividualPair*> determineInteractionsWithinPopulation();
	int totalNonexposed();
	int totalExposed();
	int totalInfections();
	int totalRecovered();
};

