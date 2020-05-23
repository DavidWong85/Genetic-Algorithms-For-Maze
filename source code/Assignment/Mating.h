#pragma once

#include <string>
#include <iostream>
#include "Random.h"

#ifndef _MATING_H_
#define _MATING_H_

class Mating {
public:
	void setChromosomes1(std::string _chrstring1);
	void setChromosomes2(std::string _chrstring2);
	void setChroLength();
	std::string getNewChro1();
	std::string getNewChro2();
	void setMutationRate(float _mutation);
	float getMutationRate();
	void Mate();
	void SetTemp(float _temp);

private:
	std::string chrostring1, chrostring2, tempChroString1, tempChroString2;
	int ChroLength;
	int chromosomes1[1000], chromosomes2[1000], tempChro1[1000], tempChro2[1000];
	float CrossoverRate = 0.7f;
	float MutationRate = 0.001f;
	float temp;
};

#endif
