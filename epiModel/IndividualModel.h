#pragma once
class IndividualModel
{
	private: 
		bool exposed = false; //Just because they're exposed doesn't mean they'll be infected.
		bool infected = false; 
		bool recovered = false;
		float progressionRate = 0.142; //Takes roughly a week from exposure to develop symptoms. 
		float recoveryRate = 0.071; // On average 2 weeks til recovery. 

	public: 
		IndividualModel() {};
		
		void setExposed(bool state);
		bool isExposed();
		bool isInfected();
		bool isRecovered();
		void update();
		bool canBeInfected();

};
