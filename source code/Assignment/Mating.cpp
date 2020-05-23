#include "Mating.h"

Random random = Random();

void Mating::SetTemp(float _temp) {
	temp = _temp;
}

void Mating::setChromosomes1(std::string _chrostring1) {
	int* Chromosomes1 = NULL;
	Chromosomes1 = new int[_chrostring1.length()];
	for (int i = 0; i < _chrostring1.length(); i++) {
		chromosomes1[i] = _chrostring1[i] - '0';
	}
	chrostring1 = _chrostring1;
	delete[] Chromosomes1;
}

void Mating::setChromosomes2(std::string _chrostring2) {
	int* Chromosomes2 = NULL;
	Chromosomes2 = new int[_chrostring2.length()];
	for (int i = 0; i < _chrostring2.length(); i++) {
		chromosomes2[i] = _chrostring2[i] - '0';
	}
	chrostring2 = _chrostring2;
	delete[] Chromosomes2;
}

void Mating::setChroLength() {
	ChroLength = chrostring1.length();
}

void Mating::Mate() {
	int* tempChro1 = NULL;
	int* tempChro2 = NULL;
	tempChro1 = new int[ChroLength];
	tempChro2 = new int[ChroLength];
	//crossover
	for (int i = 0; i < ChroLength; i++) {
		this->SetTemp(random.setRandom());
		if (temp <= CrossoverRate) {
			tempChro1[i] = chromosomes2[i];
			tempChro2[i] = chromosomes1[i];
		}
		else {
			tempChro1[i] = chromosomes1[i];
			tempChro2[i] = chromosomes2[i];
		}
	}

	//Mutation Chromosomes 1
	for (int i = 0; i < ChroLength; i++) {
		this->SetTemp(random.setRandom());
		if (temp <= MutationRate) {
			if (tempChro1[i] == 0) {
				tempChro1[i] = 1;
			}
			else if (tempChro1[i] == 1) {
				tempChro1[i] = 0;
			}
		}
	}
	//Mutation Chromosomes 2
	for (int i = 0; i < ChroLength; i++) {
		this->SetTemp(random.setRandom());
		if (temp <= MutationRate) {
			if (tempChro2[i] == 0) {
				tempChro2[i] = 1;
			}
			else if (tempChro2[i] == 1) {
				tempChro2[i] = 0;
			}
		}
	}

	for (int i = 0; i < ChroLength; i++) {
		tempChroString1.push_back('0' + tempChro1[i]);
		tempChroString2.push_back('0' + tempChro2[i]);
	}
	chrostring1 = tempChroString1;
	chrostring2 = tempChroString2;

	tempChroString1 = {};
	tempChroString2 = {};

	//clean
	delete[] tempChro1;
	tempChro1 = NULL;
	delete[] tempChro2;
	tempChro2 = NULL;
}

void Mating::setMutationRate(float _mutation) {
	MutationRate = _mutation;
}

float Mating::getMutationRate() {
	return MutationRate;
}

std::string Mating::getNewChro1() { return chrostring1; }
std::string Mating::getNewChro2() { return chrostring2; }

