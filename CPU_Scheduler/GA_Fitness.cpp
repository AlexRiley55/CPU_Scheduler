#include "GA_Fitness.h"
#include <vector>

#include "Scheduler.h"
#include "Perceptron_FitnessStrategy.h"
#include "GeneticOrganism_Strategy.h"

GA_Fitness::GA_Fitness() {
	schedule = std::make_shared<Scheduler>();	
}

double GA_Fitness::fitness(std::shared_ptr<Gene> in) {
	pFit = std::make_shared<Perceptron_FitnessStrategy>(in->genes);
	schedule->setStrat(std::make_shared<GeneticOrganism_Strategy>(pFit, timeQuantum));
	for (size_t i = 0; i < dataSet.size(); i++) { //input data
		schedule->addNewThread(std::vector<size_t>{ dataSet });
	}

	while (!schedule->isFinished()) {
		schedule->run();
		//std::cout << s->numFinished() << "\n";
	}

	double out = schedule->getMeanWaitTime();
	//double out = schedule->getMeanSquaredWaitTime();

	schedule->reset();

	return out;
}

/*
void GA_Fitness::inputData(std::vector<std::vector<size_t>> dataSet) { //TODO: actually use vectors
	for (int i = 0; i < dataSet.size(); i++) {
		schedule->addNewThread(dataSet[i]);
	}
}
*/

void GA_Fitness::inputData(std::vector<size_t> ds) {
	dataSet = ds;
}