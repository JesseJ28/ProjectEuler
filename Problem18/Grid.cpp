#include "Grid.h"


Grid::Grid(vector<vector<int>> grid)
{
    for (int i = 0; i < grid.size(); i++)
    {
        Row *current_row = new Row(grid[i]);

        _grid.push_back(*current_row);
    }
}


Row &Grid::GetRow(int index)
{
    return _grid[index];
}


int Grid::FindMaxValue()
{
    // Find max value for bottommost row
    _grid[_grid.size() - 1].FindMaxValue();

    // Find max value of all rows
    for (int i = _grid.size() - 2; i >= 0; i--)
    {
        Row &current_row = GetRow(i);
        Row &previous_row = GetRow(i+1);

        current_row.FindMaxValue(previous_row);
    }

    Row &top_row = GetRow(0);

    Position &top_position = top_row.GetPosition(0);

    return top_position.GetMaxValue();
}