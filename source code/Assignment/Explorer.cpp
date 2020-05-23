#include "Explorer.h"

bool Explorer::getReachEnd() {
	return ReachEnd;
}

void Explorer::setReachEnd(bool _reachend) {
	ReachEnd = _reachend;
}

void Explorer::setReachEndLegnth(int _endlength) {
	ReachEndLength = _endlength;
}

int Explorer::getReachEndLength() {
	return ReachEndLength;
}

std::string Explorer::getEndChromo() {
	return EndChromo;
}

void Explorer::setStart(int _start) {
	start = _start;
}

void Explorer::setEnd(int _end) {
	endx = _end % columns;
	endy = (_end - (_end % columns) / columns);
	end = _end;
}

void Explorer::setRowCol(int _row, int _columns) {
	row = _row;
	columns = _columns;
}

void Explorer::setChromosomes(std::string _chromosomes) {
	chromosomes = _chromosomes;
}

void Explorer::setGridV(std::vector<int> _grid, std::vector<int> _hitgrid) {
	Grid = _grid;
	hitGrid = _hitgrid;
}

void Explorer::resethitmap() {
	for (int i = 0; i < (row*columns); i++)
	{
		if (!((hitGrid[i] >= 1) && (hitGrid[i] <= 3)))
		{
			hitGrid[i] = 0;
		}
	}
}

void Explorer::Walk() {
	current = start;
	ChroPosition = 0;
	EndChromoLength = chromosomes.length();
	ReachEndFitness = (row * columns);
	hitWallFitness = 0;
	resethitmap();

	while ((ChroPosition <= chromosomes.length()) && (ReachEnd == false)) {

		if (hitGrid.at(current) == 0) {
			hitGrid.at(current) = 4;
		}

		//move up
		if (((chromosomes[ChroPosition] - '0') == 0) && ((chromosomes[ChroPosition + 1] - '0') == 0)) {
			//not out of boundary
			if (!(current <= (columns - 1))) {
				current = current - columns;
				//hit wall
				if (Grid.at(current) == 1) {
					current = current + columns;
					hitWallFitness++;
				}
				//reach end
				else if (current == end) {
					EndChromo = chromosomes;
					//system("CLS");
					ReachEnd = true;
					//std::cout << "\n . Current Try Times : " << trytime << std::endl;
					EndChromoLength = 0;
					for (int i = 0; i <= (ChroPosition + 1); i++)
					{
						//std::cout << chromosomes[i];
						EndChromoLength++;
						ReachEndFitness = 0;
					}
					if (hitWallFitness == 0) {
						perfectpath = true;
					}
					
				}
			}
			else { hitWallFitness++; }
		}

		//move down
		if (((chromosomes[ChroPosition] - '0') == 1) && ((chromosomes[ChroPosition + 1] - '0') == 0)) {
			//not out of boundary
			if (!(current >= (Grid.size() - columns))) {
				current = current + columns;
				//hit wall
				if (Grid.at(current) == 1) {
					current = current - columns;
					hitWallFitness++;
				}
				//reach end
				else if (current == end) {
					EndChromo = chromosomes;
					ReachEnd = true;
					EndChromoLength = 0;
					for (int i = 0; i <= (ChroPosition + 1); i++)
					{
						EndChromoLength++;
						ReachEndFitness = 0;
					}
					if (hitWallFitness == 0) {
						perfectpath = true;
					}
					
				}
			}
			else { hitWallFitness++; }
		}

		//move left
		if (((chromosomes[ChroPosition] - '0') == 1) && ((chromosomes[ChroPosition + 1] - '0') == 1)) {
			//not out of boundary
			if ((!current == 0)) {
				if (!((current % columns) == 0)) {
					current = current - 1;
					//hit wall
					if (Grid.at(current) == 1) {
						current = current + 1;
						hitWallFitness++;
					}
					//reach end
					else if (current == end) {
						EndChromo = chromosomes;
						ReachEnd = true;
						EndChromoLength = 0;
						for (int i = 0; i <= (ChroPosition + 1); i++)
						{
							EndChromoLength++;
							ReachEndFitness = 0;
						}
						if (hitWallFitness == 0) {
							perfectpath = true;
						}
					}
				}
				else { hitWallFitness++; }
			}
			else { hitWallFitness++; }
		}

		//move right
		if (((chromosomes[ChroPosition] - '0') == 0) && ((chromosomes[ChroPosition + 1] - '0') == 1)) {
			//out of boundary
			if (!(((current + 1) % columns) == 0)) {
				current = current + 1;
				//hit wall
				if (Grid.at(current) == 1) {
					current = current - 1;
					hitWallFitness++;
				}
				//reach end
				else if (current == end) {
					EndChromo = chromosomes;
					//system("CLS");
					ReachEnd = true;
					EndChromoLength = 0;
					for (int i = 0; i <= (ChroPosition + 1); i++)
					{
						EndChromoLength++;
						ReachEndFitness = 0;
					}
					if (hitWallFitness == 0) {
						perfectpath = true;
					}
				}
			}
			else { hitWallFitness++; }
		}
		ChroPosition = ChroPosition + 2;
	}

	//check how many try
	trytime++;
	
	if (trytime % 50000 == 0) {
		system("CLS");
		std::cout << "\n .Generation : " << trytime << std::endl;
		std::cout << "\n\n Current Mutation Rate : " << Mutation << std::endl;
		std::cout << "\n\n Reach End : False ";
		std::cout << "\n Steps : " << EndChromoLength / 2 << "\n";
		std::cout << "\n Invalid Moves : " << hitWallFitness << "\n";
		std::cout << "\n Current Chromosomes : \n " << chromosomes << "\n\n\n\n\n";
		std::cout << " Searching";
	}
	if (trytime % 10000 == 0) {
		std::cout << " .";
	}
	
}

int Explorer::getEndChromoLength() {
	return EndChromoLength;
}

void Explorer::setEndChromoLength() {
	EndChromo.length();
}

void Explorer::resetChromosomes() {
	chromosomes = {};
}

void Explorer::setFitness() {
	float over = (pow(EndChromoLength,2) + ((pow(hitWallFitness,2) * ReachEndFitness) / EndChromoLength));
	fitness = (1 / over);
	if (!(hitWallFitness == 0)) {
		hitWallFitness = 0;
	}
}

float Explorer::getFitness() {
	return fitness;
}

std::vector<int> Explorer::gethitgrid() {
	return hitGrid;
}

bool Explorer::getperfect() {
	return perfectpath;
}

void Explorer::setperfect(bool _perfect) {
	perfectpath = _perfect;
	perfecttime++;
}

int Explorer::getperfecttime() {
	return perfecttime;
}

void Explorer::setperfecttime(int _perfecttime) {
	perfecttime = _perfecttime;
}

void Explorer::setMutation(float _mutation) {
	Mutation = _mutation;
}

int Explorer::gettrytime() {
	return trytime;
}

float Explorer::gethitWallFitness() {
	return hitWallFitness;
}