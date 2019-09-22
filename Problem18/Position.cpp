#include "Position.h"



Position::Position(int init_value) :
value(init_value),
_max_value(-1)
{

}


void Position::SetMaxValue(int max_value)
{
    _max_value = max_value;
}


int Position::GetMaxValue()
{
    return _max_value;
}