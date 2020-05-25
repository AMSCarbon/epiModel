#pragma once
#include<iostream>
#include "IndividualModel.h"
//Just a helper class to hold two peeps. I don't wanna import random libraries.
class IndividualPair
{
public:
	IndividualModel *firstPerson;
	IndividualModel *secondPerson;
	
	IndividualPair(IndividualModel *one, IndividualModel *two) {
		firstPerson = one; 
		secondPerson = two;
	}

	void inspect() {
		
	}
};

