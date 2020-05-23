#pragma once

#include <string>
#include <vector>
#include <iostream>
#include <cstdlib>

#ifndef _EXPLORER_H_
#define _EXPLORER_H_

class Explorer {
public:
	void resetChromosomes();
	bool getReachEnd();
	void setReachEnd(bool _reachend);
	void setReachEndLegnth(int _endLength);
	int getReachEndLength();
	std::string getEndChromo();
	void setStart(int _start);
	void setEnd(int _end);
	void setRowCol(int _row, int _columns);
	void setChromosomes(std::string _chromosomes);
	void setGridV(std::vector<int> _grid, std::vector<int> _hitgrid);
	void resethitmap();
	std::vector<int> gethitgrid();
	void Walk();
	int getEndChromoLength();
	void setEndChromoLength();
	void setFitness();
	float getFitness();
	bool getperfect();
	void setperfect(bool _perfect);
	int getperfecttime();
	void setperfecttime(int _perfecttime);
	void setMutation(float _mutation);
	int gettrytime();
	float gethitWallFitness();
private:
	float Mutation;
	std::string chromosomes, EndChromo = {};
	int EndChromoLength;
	int ReachEndLength;
	int ChroPosition;
	int row, columns;
	std::vector<int> Grid, hitGrid = {};
	int start, end, current;
	bool ReachEnd = false;
	int trytime = 0;
	int currentx, currenty, endx, endy;
	float fitness;
	float ReachEndFitness;
	float hitWallFitness;
	bool perfectpath = false;
	int perfecttime = 0;
};

#endif