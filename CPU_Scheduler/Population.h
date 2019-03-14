#pragma once
#include <vector>
#include <stdlib.h>
#include <time.h>

#include "FitnessStrategy.h"
#include "GA_Fitness.h"


class Population
{
public:
	Population(size_t ng);                                       //empty
	Population(size_t ng, size_t popsToInitialize);              //initialize x random organisms
	Population(size_t ng, std::vector<std::shared_ptr<Gene>> p);   //initialize from vector
	Population(size_t ng, FILE file);                            //initialize from file
	~Population();

	void addRandomPops(size_t numPops);
	void addRandomPops(size_t numPops, size_t min, size_t max);
	void addPop(std::vector<double> genes);
	void outputFile(FILE file);
	void runGenerations(size_t gens);

private:
	GA_Fitness gaFit = GA_Fitness();

	std::vector<std::shared_ptr<Gene>> pop = {};
	size_t numGenes;

	void getSeed();

	void testPop();
	void evolvePop();
	void kill(double percent);
	void mutation(double percent);
	void generation();

	std::shared_ptr<Gene> breed(std::vector<double> a, std::vector<double> b);
	void cross(std::vector<double> &a, std::vector<double> &b);
	void mutate(std::vector<double> a);

	bool fitSort(const std::shared_ptr<Gene> &a, const std::shared_ptr<Gene> &b);
};

