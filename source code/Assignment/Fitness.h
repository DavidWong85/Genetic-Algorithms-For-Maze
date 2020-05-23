#pragma once

#ifndef _FITNESS_H_
#define _FITNESS_H_

class Fitness {
public:
	void setIndiviual(float _fitness1, float _fitness2, float _fitness3, float _fitness4, float _fitness5, float _fitness6, float _fitness7, float _fitness8, float _PCWREP);
	void setRandom(float _random);
	int getMate1();
	int getMate2();
private:
	float x;
	float TotalFitness;
	float individual1, individual2, individual3, individual4, individual5, individual6, individual7, individual8, individual9;
	float Random;
	int Mate;
};

#endif