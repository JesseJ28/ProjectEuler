#ifndef POSITION_H
#define POSITION_H

#include <vector>
using namespace std;


class Position
{
public:
    Position(int value);

    const int value;     // Value at this position

    void SetMaxValue(int max_value);
    int GetMaxValue();

private:
    int _max_value; // Max value you could have at this position
};


#endif // POSITION_H