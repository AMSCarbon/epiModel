#pragma once
#include"PopulationDistributionModel.h"
#include "TransmissionModel.h"

class EpidemicModel
{
private: 
	PopulationDistributionModel* populationModel; 
	TransmissionModel* transmissionModel;

public: 
	void init(int populationSize);
	void run(int steps);
	void finish();

};

