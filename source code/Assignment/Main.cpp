#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>
#include <chrono> 

#include "Maze.h"
#include "Chromosomes.h"
#include "Explorer.h"
#include "Mating.h"
#include "Random.h"
#include "Fitness.h"

int main() {
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

	MAZE map = MAZE();
	Chromosomes chromosomes1 = Chromosomes();
	Chromosomes chromosomes2 = Chromosomes();
	Chromosomes chromosomes3 = Chromosomes();
	Chromosomes chromosomes4 = Chromosomes();
	Chromosomes chromosomes5 = Chromosomes();
	Chromosomes chromosomes6 = Chromosomes();
	Chromosomes chromosomes7 = Chromosomes();
	Chromosomes chromosomes8 = Chromosomes();
	Chromosomes PCWREP = Chromosomes();
	Chromosomes Mate1 = Chromosomes();
	Chromosomes Mate2 = Chromosomes();
	Chromosomes tempchromosomes1 = Chromosomes();
	Chromosomes tempchromosomes2 = Chromosomes();
	Chromosomes tempchromosomes3 = Chromosomes();
	Chromosomes tempchromosomes4 = Chromosomes();
	Chromosomes tempchromosomes5 = Chromosomes();
	Chromosomes tempchromosomes6 = Chromosomes();
	Chromosomes tempchromosomes7 = Chromosomes();
	Chromosomes tempchromosomes8 = Chromosomes();
	Explorer explorer = Explorer();
	Fitness fit = Fitness();
	Mating mate = Mating();
	Random random = Random();
	std::string String, chrostring1, chrostring2, chrostring3, chrostring4, chrostring5, chrostring6, chrostring7, chrostring8, PCWREPstring;
	std::chrono::time_point<std::chrono::steady_clock> StartTime, EndTime;
	float RunTime;
	
	bool isRunning = true;
	while (isRunning == true) {
		system("CLS");
		map = {};
		chromosomes1 = {};
		chromosomes2 = {};
		chromosomes3 = {};
		chromosomes4 = {};
		chromosomes5 = {};
		chromosomes6 = {};
		chromosomes7 = {};
		chromosomes8 = {};
		PCWREP = {};
		Mate1 = {};
		Mate2 = {};
		tempchromosomes1 = {};
		tempchromosomes2 = {};
		tempchromosomes3 = {};
		tempchromosomes4 = {};
		tempchromosomes5 = {};
		tempchromosomes6 = {};
		tempchromosomes7 = {};
		tempchromosomes8 = {};
		
		explorer = {};
		fit = {};
		mate = {};
		random = {};
		int mapinput;
		int stucktime = 0;
		int choice = 0;
		int choice2 = 0;
		std::cout << "\n 1. Map1.txt \n 2. Map2.txt \n 3. Map3.txt \n Pick 1, 2 or 3 : ";
		std::cin >> mapinput;
		std::cout << "\n";
		bool possible = false;
		int possiblenum = 0;
		explorer.setReachEnd(false);
		explorer.setperfecttime(0);
		bool maptrue = false;
		StartTime = {};
		EndTime = {};
		RunTime = 0;

		switch (mapinput) {
		case 1:
			if (map.ReadMap("Map1.txt") == true) {
				maptrue = true;
				StartTime = std::chrono::steady_clock::now();
				break;
			}
			else {
				std::cout << "\n\n 1. Back to Choose Map \n 2. Exit Program \n Pick 1 or 2 : ";
				std::cin >> choice;
				switch (choice) {
				case 1:
					break;
				case 2:
					isRunning = false;
				default:
					break;
				}
				break;
			}
		case 2:
			if (map.ReadMap("Map2.txt") == true) {
				maptrue = true;
				StartTime = std::chrono::steady_clock::now();
				break;
			}
			else {
				std::cout << "\n\n 1. Back to Choose Map \n 2. Exit Program \n Pick 1 or 2 : ";
				std::cin >> choice;
				switch (choice) {
				case 1:
					break;
				case 2:
					isRunning = false;
				default:
					break;
				}
				break;
			}
		case 3:
			if (map.ReadMap("Map3.txt") == true) {
				maptrue = true;
				StartTime = std::chrono::steady_clock::now();
				break;
			}
			else {
				std::cout << "\n\n 1. Back to Choose Map \n 2. Exit Program \n Pick 1 or 2 : ";
				std::cin >> choice;
				switch (choice) {
				case 1:
					break;
				case 2:
					isRunning = false;
				default:
					break;
				}
				break;
			}
		default:
			std::cout << "\n\n 1. Back to Choose Map \n 2. Exit Program \n Pick 1 or 2 : ";
			int choice;
			std::cin >> choice;
			switch (choice) {
			case 1:
				break;
			case 2:
				isRunning = false;
			default:
				break;
			}
		}

		if (!(maptrue == false)) {
			std::cout << "\n";
			for (int i = 0; i < map.getRow(); i++) {
				for (int j = 0; j < map.getCol(); j++) {
					std::cout << "    " << map.showGrid(map.getRow(), map.getCol(), i, j);
				}
				std::cout << "\n\n";
			}

			//GA
			explorer.setRowCol(map.getRow(), map.getCol());
			explorer.setStart(map.getStart());
			explorer.setEnd(map.getEnd());
			explorer.setGridV(map.getGrid(), map.gethitGrid());

			chromosomes1.GenerateChromosomes(map.getMapSize() * 10);
			chromosomes2.GenerateChromosomes(map.getMapSize() * 10);
			chromosomes3.GenerateChromosomes(map.getMapSize() * 10);
			chromosomes4.GenerateChromosomes(map.getMapSize() * 10);
			chromosomes5.GenerateChromosomes(map.getMapSize() * 10);
			chromosomes6.GenerateChromosomes(map.getMapSize() * 10);
			chromosomes7.GenerateChromosomes(map.getMapSize() * 10);
			chromosomes8.GenerateChromosomes(map.getMapSize() * 10);

			std::cout << "\n\n\n Searching";

			explorer.setReachEndLegnth(chromosomes1.getChromosomes().length());
			std::string chroString = {};

			int FinalLength = chromosomes1.getChromosomes().length();

			while ((explorer.getReachEnd() == false) && (!((explorer.getperfecttime() == pow((map.getRow() * map.getCol()), 2))))) {

				explorer.setMutation(mate.getMutationRate());

				map.resethitgird();
				explorer.resethitmap();

				explorer.setChromosomes(chromosomes1.getChromosomes());
				explorer.Walk();
				map.sethitGrid(explorer.gethitgrid());
				explorer.setFitness();
				chromosomes1.setFitness(explorer.getFitness());
				if (explorer.getReachEnd() == true) {
					possible = true;
					PCWREP = chromosomes1;
					if (explorer.getReachEndLength() == explorer.getEndChromoLength()) {
						explorer.getEndChromo();
						explorer.setReachEnd(false);
					}
					else {
						stucktime = 0;
						mate.setMutationRate(0.001f);
						std::string chrostring1 = chromosomes1.getChromosomes();
						for (int j = 0; j < FinalLength; j++) {
							chroString.push_back(chrostring1[j]);
						}
						chromosomes1.ResetChroString();
						chromosomes1.setChromosomes(chroString);
						chroString = {};
						if (explorer.getReachEndLength() >= explorer.getEndChromoLength())
						{
							explorer.setReachEndLegnth(explorer.getEndChromoLength());
							FinalLength = explorer.getReachEndLength();
						}
						explorer.setReachEnd(false);
					}
				}

				stucktime++;

				explorer.setChromosomes(chromosomes2.getChromosomes());
				explorer.Walk();
				map.sethitGrid(explorer.gethitgrid());
				explorer.setFitness();
				chromosomes2.setFitness(explorer.getFitness());
				if (explorer.getReachEnd() == true) {
					possible = true;
					PCWREP = chromosomes2;
					if (explorer.getReachEndLength() == explorer.getEndChromoLength()) {
						explorer.getEndChromo();
						explorer.setReachEnd(false);
					}
					else {
						stucktime = 0;
						mate.setMutationRate(0.001f);
						std::string chrostring2 = chromosomes2.getChromosomes();
						for (int j = 0; j < FinalLength; j++) {
							chroString.push_back(chrostring2[j]);
						}
						chromosomes2.ResetChroString();
						chromosomes2.setChromosomes(chroString);
						chroString = {};
						if (explorer.getReachEndLength() >= explorer.getEndChromoLength())
						{
							explorer.setReachEndLegnth(explorer.getEndChromoLength());
							FinalLength = explorer.getReachEndLength();
						}
						explorer.setReachEnd(false);
					}
				}

				stucktime++;

				explorer.setChromosomes(chromosomes3.getChromosomes());
				explorer.Walk();
				map.sethitGrid(explorer.gethitgrid());
				explorer.setFitness();
				chromosomes3.setFitness(explorer.getFitness());
				if (explorer.getReachEnd() == true) {
					possible = true;
					PCWREP = chromosomes3;
					if (explorer.getReachEndLength() == explorer.getEndChromoLength()) {
						explorer.getEndChromo();
						explorer.setReachEnd(false);
					}
					else {
						stucktime = 0;
						mate.setMutationRate(0.001f);
						std::string chrostring3 = chromosomes3.getChromosomes();
						for (int j = 0; j < FinalLength; j++) {
							chroString.push_back(chrostring3[j]);
						}
						chromosomes3.ResetChroString();
						chromosomes3.setChromosomes(chroString);
						chroString = {};
						if (explorer.getReachEndLength() >= explorer.getEndChromoLength())
						{
							explorer.setReachEndLegnth(explorer.getEndChromoLength());
							FinalLength = explorer.getReachEndLength();
						}
						explorer.setReachEnd(false);
					}
				}

				stucktime++;

				explorer.setChromosomes(chromosomes4.getChromosomes());
				explorer.Walk();
				map.sethitGrid(explorer.gethitgrid());
				explorer.setFitness();
				chromosomes4.setFitness(explorer.getFitness());
				if (explorer.getReachEnd() == true) {
					possible = true;
					PCWREP = chromosomes4;
					if (explorer.getReachEndLength() == explorer.getEndChromoLength()) {
						explorer.getEndChromo();
						explorer.setReachEnd(false);
					}
					else {
						stucktime = 0;
						mate.setMutationRate(0.001f);
						std::string chrostring4 = chromosomes4.getChromosomes();
						for (int j = 0; j < FinalLength; j++) {
							chroString.push_back(chrostring4[j]);
						}
						chromosomes4.ResetChroString();
						chromosomes4.setChromosomes(chroString);
						chroString = {};
						if (explorer.getReachEndLength() >= explorer.getEndChromoLength())
						{
							explorer.setReachEndLegnth(explorer.getEndChromoLength());
							FinalLength = explorer.getReachEndLength();
						}
						explorer.setReachEnd(false);
					}
				}

				stucktime++;

				explorer.setChromosomes(chromosomes5.getChromosomes());
				explorer.Walk();
				map.sethitGrid(explorer.gethitgrid());
				explorer.setFitness();
				chromosomes5.setFitness(explorer.getFitness());
				if (explorer.getReachEnd() == true) {
					possible = true;
					PCWREP = chromosomes5;
					if (explorer.getReachEndLength() == explorer.getEndChromoLength()) {
						explorer.getEndChromo();
						explorer.setReachEnd(false);
					}
					else {
						stucktime = 0;
						mate.setMutationRate(0.001f);
						std::string chrostring5 = chromosomes5.getChromosomes();
						for (int j = 0; j < FinalLength; j++) {
							chroString.push_back(chrostring5[j]);
						}
						chromosomes5.ResetChroString();
						chromosomes5.setChromosomes(chroString);
						chroString = {};
						if (explorer.getReachEndLength() >= explorer.getEndChromoLength())
						{
							explorer.setReachEndLegnth(explorer.getEndChromoLength());
							FinalLength = explorer.getReachEndLength();
						}
						explorer.setReachEnd(false);
					}
				}

				stucktime++;

				explorer.setChromosomes(chromosomes6.getChromosomes());
				explorer.Walk();
				map.sethitGrid(explorer.gethitgrid());
				explorer.setFitness();
				chromosomes6.setFitness(explorer.getFitness());
				if (explorer.getReachEnd() == true) {
					possible = true;
					PCWREP = chromosomes6;
					if (explorer.getReachEndLength() == explorer.getEndChromoLength()) {
						explorer.getEndChromo();
						explorer.setReachEnd(false);
					}
					else {
						stucktime = 0;
						mate.setMutationRate(0.001f);
						std::string chrostring6 = chromosomes6.getChromosomes();
						for (int j = 0; j < FinalLength; j++) {
							chroString.push_back(chrostring6[j]);
						}
						chromosomes6.ResetChroString();
						chromosomes6.setChromosomes(chroString);
						chroString = {};
						if (explorer.getReachEndLength() >= explorer.getEndChromoLength())
						{
							explorer.setReachEndLegnth(explorer.getEndChromoLength());
							FinalLength = explorer.getReachEndLength();
						}
						explorer.setReachEnd(false);
					}
				}

				stucktime++;

				explorer.setChromosomes(chromosomes7.getChromosomes());
				explorer.Walk();
				map.sethitGrid(explorer.gethitgrid());
				explorer.setFitness();
				chromosomes7.setFitness(explorer.getFitness());
				if (explorer.getReachEnd() == true) {
					possible = true;
					PCWREP = chromosomes7;
					if (explorer.getReachEndLength() == explorer.getEndChromoLength()) {
						explorer.getEndChromo();
						explorer.setReachEnd(false);
					}
					else {
						stucktime = 0;
						mate.setMutationRate(0.001f);
						std::string chrostring7 = chromosomes7.getChromosomes();
						for (int j = 0; j < FinalLength; j++) {
							chroString.push_back(chrostring7[j]);
						}
						chromosomes7.ResetChroString();
						chromosomes7.setChromosomes(chroString);
						chroString = {};
						if (explorer.getReachEndLength() >= explorer.getEndChromoLength())
						{
							explorer.setReachEndLegnth(explorer.getEndChromoLength());
							FinalLength = explorer.getReachEndLength();
						}
						explorer.setReachEnd(false);
					}
				}

				stucktime++;

				explorer.setChromosomes(chromosomes8.getChromosomes());
				explorer.Walk();
				map.sethitGrid(explorer.gethitgrid());
				explorer.setFitness();
				chromosomes8.setFitness(explorer.getFitness());
				if (explorer.getReachEnd() == true) {
					possible = true;
					PCWREP = chromosomes8;
					if (explorer.getReachEndLength() == explorer.getEndChromoLength()) {
						explorer.getEndChromo();
						explorer.setReachEnd(false);
					}
					else {
						stucktime = 0;
						mate.setMutationRate(0.001f);
						std::string chrostring8 = chromosomes8.getChromosomes();
						for (int j = 0; j < FinalLength; j++) {
							chroString.push_back(chrostring8[j]);

						}
						chromosomes8.ResetChroString();
						chromosomes8.setChromosomes(chroString);
						chroString = {};
						if (explorer.getReachEndLength() >= explorer.getEndChromoLength())
						{
							explorer.setReachEndLegnth(explorer.getEndChromoLength());
							FinalLength = explorer.getReachEndLength();
						}
						explorer.setReachEnd(false);
					}
				}

				stucktime++;

				//check is map possible to solve
				if (possible == false) {
					possiblenum++;
				}
				
				if (possiblenum >= 10000) {
					system("CLS");
					std::cout << "\n .Generation : " << explorer.gettrytime() << std::endl;
					std::cout << "\n\n Reach End : False ";
					std::cout << "\n Steps : " << (explorer.getEndChromoLength() / 2) << "\n";
					std::cout << "\n Current Chromosomes : \n " << explorer.getEndChromo() << "\n";

					std::cout << "\n\n";
					for (int i = 0; i < map.getRow(); i++) {
						for (int j = 0; j < map.getCol(); j++) {
							std::cout << "    " << map.showhitGrid(map.getRow(), map.getCol(), i, j);
						}
						std::cout << "\n\n";
					}
					std::cout << " This map is impossible to solve. " << std::endl;
					break;
				}
				
				//Dynamic Mutation Rate
				if ((stucktime >= 1000) && (mate.getMutationRate() <= 0.01f)) {
					stucktime = 0;
					mate.setMutationRate((mate.getMutationRate() + 0.001f));
				}

				fit.setIndiviual(chromosomes1.getFitness(), chromosomes2.getFitness(), chromosomes3.getFitness(), chromosomes4.getFitness(), chromosomes5.getFitness(), chromosomes6.getFitness(), chromosomes7.getFitness(), chromosomes8.getFitness(), PCWREP.getFitness());

				//Resize
				for (int i = 1; i <= 9; i++) {
					switch (i) {
					case 1:
						chrostring1 = chromosomes1.getChromosomes();
						for (int j = 0; j < FinalLength; j++)
						{
							String.push_back(chrostring1[j]);
						}
						chromosomes1.ResetChroString();
						chromosomes1.setChromosomes(String);
						String = {};
						break;
					case 2:
						chrostring2 = chromosomes2.getChromosomes();
						for (int j = 0; j < FinalLength; j++)
						{
							String.push_back(chrostring2[j]);
						}
						chromosomes2.ResetChroString();
						chromosomes2.setChromosomes(String);
						String = {};
						break;
					case 3:
						chrostring3 = chromosomes3.getChromosomes();
						for (int j = 0; j < FinalLength; j++)
						{
							String.push_back(chrostring3[j]);
						}
						chromosomes3.ResetChroString();
						chromosomes3.setChromosomes(String);
						String = {};
						break;
					case 4:
						chrostring4 = chromosomes4.getChromosomes();
						for (int j = 0; j < FinalLength; j++)
						{
							String.push_back(chrostring4[j]);
						}
						chromosomes4.ResetChroString();
						chromosomes4.setChromosomes(String);
						String = {};
						break;
					case 5:
						chrostring5 = chromosomes5.getChromosomes();
						for (int j = 0; j < FinalLength; j++)
						{
							String.push_back(chrostring5[j]);
						}
						chromosomes5.ResetChroString();
						chromosomes5.setChromosomes(String);
						String = {};
						break;
					case 6:
						chrostring6 = chromosomes6.getChromosomes();
						for (int j = 0; j < FinalLength; j++)
						{
							String.push_back(chrostring6[j]);
						}
						chromosomes6.ResetChroString();
						chromosomes6.setChromosomes(String);
						String = {};
						break;
					case 7:
						chrostring7 = chromosomes7.getChromosomes();
						for (int j = 0; j < FinalLength; j++)
						{
							String.push_back(chrostring7[j]);
						}
						chromosomes7.ResetChroString();
						chromosomes7.setChromosomes(String);
						String = {};
						break;
					case 8:
						chrostring8 = chromosomes8.getChromosomes();
						for (int j = 0; j < FinalLength; j++)
						{
							String.push_back(chrostring8[j]);
						}
						chromosomes8.ResetChroString();
						chromosomes8.setChromosomes(String);
						String = {};
						break;
					case 9:
						if (possible == true) {
							PCWREPstring = PCWREP.getChromosomes();
							for (int j = 0; j < FinalLength; j++)
							{
								String.push_back(PCWREPstring[j]);
							}
							PCWREP.ResetChroString();
							PCWREP.setChromosomes(String);
							String = {};
						}
						break;
					}
				}

				//get Parent
				for (int i = 1; i <= 4; i++) {
					//get fiirst parent
					fit.setRandom(random.setRandom());
					switch (fit.getMate1()) {
					case 1:
						Mate1 = chromosomes1;
						break;
					case 2:
						Mate1 = chromosomes2;
						break;
					case 3:
						Mate1 = chromosomes3;
						break;
					case 4:
						Mate1 = chromosomes4;
						break;
					case 5:
						Mate1 = chromosomes5;
						break;
					case 6:
						Mate1 = chromosomes6;
						break;
					case 7:
						Mate1 = chromosomes7;
						break;
					case 8:
						Mate1 = chromosomes8;
						break;
					case 9:
						Mate1 = PCWREP;
						break;
					}

					//get second parent
					fit.setRandom(random.setRandom());
					switch (fit.getMate2()) {
					case 1:
						Mate2 = chromosomes1;
						break;
					case 2:
						Mate2 = chromosomes2;
						break;
					case 3:
						Mate2 = chromosomes3;
						break;
					case 4:
						Mate2 = chromosomes4;
						break;
					case 5:
						Mate2 = chromosomes5;
						break;
					case 6:
						Mate2 = chromosomes6;
						break;
					case 7:
						Mate2 = chromosomes7;
						break;
					case 8:
						Mate2 = chromosomes8;
						break;
					case 9:
						Mate2 = PCWREP;
						break;
					}

					mate.setChromosomes1(Mate1.getChromosomes());
					mate.setChromosomes2(Mate2.getChromosomes());
					mate.setChroLength();
					mate.Mate();

					//set temp chromosomes
					switch (i) {
					case 1:
						tempchromosomes1.setChromosomes(mate.getNewChro1());
						tempchromosomes2.setChromosomes(mate.getNewChro2());
						break;
					case 2:
						tempchromosomes3.setChromosomes(mate.getNewChro1());
						tempchromosomes4.setChromosomes(mate.getNewChro2());
						break;
					case 3:
						tempchromosomes5.setChromosomes(mate.getNewChro1());
						tempchromosomes6.setChromosomes(mate.getNewChro2());
						break;
					case 4:
						tempchromosomes7.setChromosomes(mate.getNewChro1());
						tempchromosomes8.setChromosomes(mate.getNewChro2());
						break;
					}
				}

				chromosomes1 = tempchromosomes1;
				chromosomes2 = tempchromosomes2;
				chromosomes3 = tempchromosomes3;
				chromosomes4 = tempchromosomes4;
				chromosomes5 = tempchromosomes5;
				chromosomes6 = tempchromosomes6;
				chromosomes7 = tempchromosomes7;
				chromosomes8 = tempchromosomes8;

				tempchromosomes1 = {};
				tempchromosomes2 = {};
				tempchromosomes3 = {};
				tempchromosomes4 = {};
				tempchromosomes5 = {};
				tempchromosomes6 = {};
				tempchromosomes7 = {};
				tempchromosomes8 = {};

				explorer.setEndChromoLength();

				if (explorer.getperfect() == true) {
					explorer.setperfect(false);
				}
				else {
					if (explorer.getperfect() > 0) {
						explorer.setperfecttime(explorer.getperfect() - 1);
					}
				}
			}

			if (possible == true) {
				explorer.resetChromosomes();
				explorer.setChromosomes(PCWREP.getChromosomes());
				explorer.Walk();
				map.resethitgird();
				map.sethitGrid(explorer.gethitgrid());

				system("CLS");
				std::cout << "\n .Generation : " << explorer.gettrytime() << std::endl;
				std::cout << "\n\n Current Mutation Rate : " << mate.getMutationRate() << std::endl;
				std::cout << "\n\n Reach End : True ";
				std::cout << "\n Steps : " << (explorer.getEndChromoLength() / 2) << "\n";
				std::cout << "\n Invalid Moves : " << explorer.gethitWallFitness() << "\n";
				std::cout << "\n Current Chromosomes : \n " << explorer.getEndChromo() << "\n";

				std::cout << "\n\n";
				for (int i = 0; i < map.getRow(); i++) {
					for (int j = 0; j < map.getCol(); j++) {
						std::cout << "    " << map.showhitGrid(map.getRow(), map.getCol(), i, j);
					}
					std::cout << "\n\n";
				}

				EndTime = std::chrono::steady_clock::now();
				RunTime = std::chrono::duration_cast<std::chrono::microseconds>(EndTime - StartTime).count();

				std::cout << "\n Run Time : " << RunTime * (1e-6) << " Seconds. \n\n";
				std::cout << "\n\n 1. Back to Choose Map \n 2. Exit Program \n Pick 1 or 2 : ";
				std::cin >> choice2;
				switch (choice2) {
				case 1:
					break;
				case 2:
					isRunning = false;
				default:
					break;
				}
			}
		}

	}
}