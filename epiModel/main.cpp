#include <iostream>
#include "EpidemicModel.h"
int main()
{
	EpidemicModel mainModel;
	std::cout << "Model started running.\n";
	mainModel.init(2500);
	mainModel.run(10000);
	mainModel.finish();
	std::cout << "Model finished running.\n";
}
