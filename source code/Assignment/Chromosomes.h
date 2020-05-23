#pragma once

#include <string>
#include <iostream>
#include "Random.h"

#ifndef _CHROMOSOMES_H_
#define _CHROMOSOMES_H_

class Chromosomes {
public:
	void GenerateChromosomes(int _chromoLength);
	void SetTemp(float _temp);
	std::string getChromosomes();
	void setChromosomes(std::string _chrostring);
	void ResetChroString();
	void setFitness(float _fitness);
	float getFitness();
private:
	float temp;
	int num[1000];
	int Chromosomes[1000];
	std::string chroString;
	Random* random;
	float fitness = 0;
};

#endif