#include "UtilFunctions.h"
namespace UtilFunctions {

	std::random_device rd;
	std::mt19937 gen = std::mt19937(rd());

	bool trialOutcome(float likelihood) {
		std::bernoulli_distribution d(likelihood);
		return 	d(gen);
	}

	float averageDuration(float recoveryRate) {
		int days = 100;
		float total = 0;
		float likelihoodTotal = 0;
		for (int i = 1; i <= days; i++) {
			likelihoodTotal += powf((1 - recoveryRate), i);
			total += (float)i * powf((1 - recoveryRate), i);
		}
		return total / likelihoodTotal;
	}
};