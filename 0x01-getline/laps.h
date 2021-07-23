#ifndef LAPS_H
#define LAPS_H

#include <stdio.h>
#include <stdlib.h>

/**
* struct car - lets see if it compiles
* @id: num
* @laps: args
* @next: num
*
*/

typedef struct car {
	int id;
	size_t laps;
	struct car *next;
} car_t;

void race_state(int *id, size_t size);

#endif /* LAPS_H */
