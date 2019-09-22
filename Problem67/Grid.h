#ifndef GRID_H
#define GRID_H

#include <vector>
#include "Row.h"
using namespace std;

class Grid
{
public:
    Grid(vector<vector<int>> grid);

    Row &GetRow(int index);

    int FindMaxValue();

private:
    vector <Row> _grid;
};

#endif // GRID_H