#ifndef ROW_H
#define ROW_H

#include <vector>
#include "Position.h"
using namespace std;

class Row
{
public:
    Row(vector<int> row);

    Position &GetPosition(int index);
    int GetSize();

    void FindMaxValue();
    void FindMaxValue(Row &row_below);

private:
    vector <Position> _row;
};

#endif // ROW_H