#include "Fitness.h"

void Fitness::setIndiviual(float _fitness1, float _fitness2, float _fitness3, float _fitness4, float _fitness5, float _fitness6, float _fitness7, float _fitness8, float _PCWREP) {
	TotalFitness = (_fitness1 + _fitness2 + _fitness3 + _fitness4 + _fitness5 + _fitness6 + _fitness7 + _fitness8 + _PCWREP);
	individual1 = ((_fitness1 / TotalFitness) * 100);
	individual2 = (individual1 + ((_fitness2 / TotalFitness) * 100));
	individual3 = (individual2 + ((_fitness3 / TotalFitness) * 100));
	individual4 = (individual3 + ((_fitness4 / TotalFitness) * 100));
	individual5 = (individual4 + ((_fitness5 / TotalFitness) * 100));
	individual6 = (individual5 + ((_fitness6 / TotalFitness) * 100));
	individual7 = (individual6 + ((_fitness7 / TotalFitness) * 100));
	individual8 = (individual7 + ((_fitness8 / TotalFitness) * 100));
	individual9 = (individual8 + ((_PCWREP / TotalFitness) * 100));
}

void Fitness::setRandom(float _random) {
	Random = _random;
}

int Fitness::getMate1() {
	Mate = 0;
	//Choose First Chromosomes
	x = (Random * 100);
	if ((x >= 0) && (x < individual1)) {
		Mate = 1;
	}
	else if ((x >= individual1) && (x < individual2)) {
		Mate = 2;
	}
	else if ((x >= individual2) && (x < individual3)) {
		Mate = 3;
	}
	else if ((x >= individual3) && (x < individual4)) {
		Mate = 4;
	}
	else if ((x >= individual4) && (x < individual5)) {
		Mate = 5;
	}
	else if ((x >= individual5) && (x < individual6)) {
		Mate = 6;
	}
	else if ((x >= individual6) && (x < individual7)) {
		Mate = 7;
	}
	else if ((x >= individual7) && (x < individual8)) {
		Mate = 8;
	}
	else if ((x >= individual8) && (x < individual9)) {
		Mate = 9;
	}
	return Mate;
}

int Fitness::getMate2() {
	Mate = 0;
	//Choose Second Chromosomes
	x = (Random * 100);
	if ((x >= 0) && (x < individual1)) {
		Mate = 1;
	}
	else if ((x >= individual1) && (x < individual2)) {
		Mate = 2;
	}
	else if ((x >= individual2) && (x < individual3)) {
		Mate = 3;
	}
	else if ((x >= individual3) && (x < individual4)) {
		Mate = 4;
	}
	else if ((x >= individual4) && (x < individual5)) {
		Mate = 5;
	}
	else if ((x >= individual5) && (x < individual6)) {
		Mate = 6;
	}
	else if ((x >= individual6) && (x < individual7)) {
		Mate = 7;
	}
	else if ((x >= individual7) && (x < individual8)) {
		Mate = 8;
	}
	else if ((x >= individual8) && (x < individual9)) {
		Mate = 9;
	}
	return Mate;
}