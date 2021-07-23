#include "laps.h"

/**
 * main - entry point.
 *
 * Return: always 0.
 */
int main()
{

    int ids[1] = {89};
    int i;
    
    for (i = 0 ; i < 10 ; i ++) 
    {
      race_state(ids, 1);
    }
    race_state(NULL, 0);
    return (0);
}
