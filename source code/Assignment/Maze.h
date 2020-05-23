#pragma once

#ifndef _MAZE_H_
#define _MAZE_H_

#include <iostream>
#include <string>
#include <fstream>
#include <vector>

class MAZE {
public:
	bool ReadMap(std::string _name);
	void sethitMap();
	int showGrid(int _maxrow, int _maxcol, int _row, int _col);
	int showhitGrid(int _maxrow, int _maxcol, int _row, int _col);
	int getMapSize();
	int getStart();
	int getEnd();
	std::vector<int> getGrid();
	std::vector<int> gethitGrid();
	void sethitGrid(std::vector<int> _hit);
	void resethitgird();
	int getRow();
	int getCol();
private:
	std::ifstream inFile;
	std::string map;
	int row;
	int columns;
	std::vector<int> Grid, hitGrid = {};
	int StartPoint, EndPoint;
};

#endif