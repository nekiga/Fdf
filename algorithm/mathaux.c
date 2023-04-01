#include "../fdf.h"

// swaps two numbers
void swap(int* a , int*b)
{
    int temp;

    temp = *a;
    *a = *b;
    *b = temp;
}
  
// returns absolute value of number
float     m_abs(float x)
{
    if (x < 0)
        x *= -1;
    return (x);
}
  
//returns integer part of a floating point number
int iPartOfNumber(float x)
{
    return ((int)x);
}
  
//rounds off a number
int roundNumber(float x)
{
    return (iPartOfNumber(x + 0.5)) ;
}
  
//returns fractional part of a number
float fPartOfNumber(float x)
{
    if (x > 0)
     return (x - iPartOfNumber(x));
    else
     return (x - (iPartOfNumber(x)+1));
  
}
  
//returns 1 - fractional part of number
float rfPartOfNumber(float x)
{
    return 
    (1 - fPartOfNumber(x));
}