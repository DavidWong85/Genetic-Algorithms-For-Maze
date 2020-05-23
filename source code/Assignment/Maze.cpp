#include "MAZE.h"

#include <sstream>

bool MAZE::ReadMap(std::string _name) {
	inFile.open(_name);
	while (!inFile.eof()) 
	{
		std::getline(inFile, map);
	}

	inFile.close();

	std::stringstream strStream(map);

	strStream >> columns;
	strStream >> row;

	for (int i = 0; i < (columns * row); i++)
	{
		int input = 0;
		strStream >> input;
		Grid.push_back(input);
		hitGrid.push_back(input);
	}

	//Start Point
	std::vector<int>::iterator start = std::find(Grid.begin(), Grid.end(), 2);
	
	if (start != Grid.end()) {
	}
	else { std::cout << "This map has no start point" << std::endl; return false; }
	
	StartPoint = std::distance(Grid.begin(), start);

	//End Point
	std::vector<int>::iterator end = std::find(Grid.begin(), Grid.end(), 3);
	
	if (end != Grid.end()) {
	}
	else { std::cout << "This Map has no end point" << std::endl; return false; }
	
	EndPoint = std::distance(Grid.begin(), end);
	return true;
}

int MAZE::showGrid(int _maxrow, int _maxcol, int _row, int _col) {
	if (((_col >= 0) && (_col < _maxcol)) && ((_row >= 0) && (_row < _maxrow))) {
		return Grid[_col + _row * _maxcol];
	}
}

int MAZE::showhitGrid(int _maxrow, int _maxcol, int _row, int _col) {
	if (((_col >= 0) && (_col < _maxcol)) && ((_row >= 0) && (_row < _maxrow))) {
		return hitGrid[_col + _row * _maxcol];
	}
}

int MAZE::getMapSize() {
	return (columns * row);
}

int MAZE::getStart() {
	return StartPoint;
}

int MAZE::getEnd() {
	return EndPoint;
}

std::vector<int> MAZE::getGrid() {
	return Grid;
}

std::vector<int> MAZE::gethitGrid() {
	return hitGrid;
}

void MAZE::resethitgird() {
	for (int i = 0; i < (columns * row); i++)
	{
		hitGrid[i] = Grid[i];
	}
}

void MAZE::sethitGrid(std::vector<int> _hit) {
	hitGrid = _hit;
}

int MAZE::getRow() {
	return row;
}

int MAZE::getCol() {
	return columns;
}