#pragma once
#include <cstdlib>
#include <random>

//Collection of common misc functions used everywhere but not specific to anything. 
//Saves having to trawl through and redo things on big changes. 
namespace UtilFunctions{
	bool trialOutcome(float likelihood);
	float averageDuration(float recoveryRate);
};