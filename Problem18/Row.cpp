#include "Row.h"


Row::Row(vector<int> vector)
{
    // construct the row based on size of vector passed in
    for (int i = 0; i < vector.size(); i++)
    {
        Position *current_position = new Position(vector[i]);

        _row.push_back(*current_position);
    }
}


Position &Row::GetPosition(int index)
{
    return _row[index];
}

int Row::GetSize()
{
    return _row.size();
}

void Row::FindMaxValue()
{
    // Iterate through positions of row, setting the max value for each
    for (int i = 0; i < GetSize(); i++)
    {
        Position &current_position = GetPosition(i);

        current_position.SetMaxValue(current_position.value);
    }
}

void Row::FindMaxValue(Row &row_below)
{
    // Iterate through positions of row, setting the max value for each
    for (int i = 0; i < GetSize(); i++)
    {
        Position &current_position = GetPosition(i);

        int max_value_from_below = 0;

        Position &below_to_left = row_below.GetPosition(i);
        Position &below_to_right = row_below.GetPosition(i+1);

        int max_value_from_below_left = below_to_left.GetMaxValue();
        int max_value_from_below_right = below_to_right.GetMaxValue();

        if (max_value_from_below_left > max_value_from_below_right)
        {
            max_value_from_below = max_value_from_below_left;
        }
        else
        {
            max_value_from_below = max_value_from_below_right;
        }

        current_position.SetMaxValue(max_value_from_below + current_position.value);
    }
}