#include <iostream>
#include <math.h>
#include "EpidemicModel.h"
#include "PopulationDistributionModel.h"
#include <time.h>
void EpidemicModel::init(int populationSize)
{
	populationModel = new PopulationDistributionModel(populationSize);
	transmissionModel = new TransmissionModel();
}

void EpidemicModel::run(int steps)
{
	for (int i = 0; i < steps; i++) {
		int totalExposed = populationModel->totalExposed();
		int totalInfectuous = populationModel->totalInfections();
		if (totalExposed + totalInfectuous == 0) break; // if there's no active infections, end the simuat
		std::cout << i  << " " << populationModel->totalNonexposed() << " "
							   << totalExposed << " "
							   << totalInfectuous << " "
							   << populationModel->totalRecovered() << " " << "\n";
		populationModel->updateIndividuals();
		populationModel->updateDistribution();
		transmissionModel->calculateTransmissionForPairs(populationModel->determineInteractionsWithinPopulation());
	}	
}


void EpidemicModel::finish()
{

}
