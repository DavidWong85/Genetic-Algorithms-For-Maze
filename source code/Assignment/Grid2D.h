#pragma once

#include <iostream>

#ifndef _GRID2D_H_
#define _GRID2D_H_

class Grid2D {
public:
	void SetGrid(int _row, int _col, int _maparray[], int _startx, int _starty, int _endx, int _endy);
	int getGrid();
	void CallGrid(int _row, int _col, int _maparray[], int _startx, int _starty, int _endx, int _endy);

private:
	int row, col;
	int Grid[200][200];
};

#endif 