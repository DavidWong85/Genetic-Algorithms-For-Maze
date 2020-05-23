#include "Chromosomes.h"

void Chromosomes::SetTemp(float _temp) {
	temp = _temp;
}

void Chromosomes::GenerateChromosomes(int _chromoLength) {
	Random random = Random();

	int* num = NULL;
	int* Chromosomes = NULL;

	num = new int[_chromoLength];
	Chromosomes = new int[_chromoLength];

	for (int i = 0; i < _chromoLength; i++) {
		this->SetTemp(random.setRandom());
		if (temp < 0.5) {
			num[i] = 0;
		}
		else if (temp >= 0.5) {
			num[i] = 1;
		}
		Chromosomes[i] = num[i];
		chroString.push_back('0' + Chromosomes[i]);
	}

	//clean
	delete[] num;
	num = NULL;
	delete[] Chromosomes;
	Chromosomes = NULL;
}

std::string Chromosomes::getChromosomes() {
	return chroString;
}

void Chromosomes::setChromosomes(std::string _chrostring) {
	chroString = _chrostring;
}

void Chromosomes::ResetChroString() {
	chroString = {};
}

void Chromosomes::setFitness(float _fitness) {
	fitness = _fitness;
}

float Chromosomes::getFitness() {
	return fitness;
}