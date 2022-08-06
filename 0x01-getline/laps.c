#include "laps.h"
/**
 * cars_update - updating cars
 * @cars: array of cars
 * @laps: array of laps
 * @counter: number of cars in the race
 * Return : void
 */

void cars_update(int *cars, int *laps, size_t counter)
{
	int tmp;
	size_t i = counter;

	while (i > 0)
	{
		if (cars[i] < cars[i - 1])
		{
			tmp = cars[i - 1];
			cars[i - 1] = cars[i];
			cars[i] = tmp;
			tmp = laps[i - 1];
			laps[i - 1] = laps[i];
			laps[i] = tmp;
		}
		--i;
	}
}
/**
 * race_state - keeps track of the number of laps
 * made by several cars in a race.
 * @id : array of int (cars)
 * @size  : size of array (number of laps)
 * Return : void
 */
void race_state(int *id, size_t size)
{
	static int cars[64];
	static int laps[64];
	static size_t counter;
	int first;
	size_t i, j;

	if (!size)
		return;
	for (i = 0; i < size; ++i)
	{
		first = 0;
		for (j = 0; j < counter; ++j)
		{
			if (id[i] == cars[j])
			{
				first = 1;
				laps[j] += 1;
				break;
			}
		}
		if (first == 0)
		{
			cars[counter] = id[i];
			cars_update(cars, laps, counter);
			++counter;
			printf("Car %d joined the race\n", id[i]);
		}
	}
	printf("Race state:\n");
	for (j = 0; j < counter; ++j)
	{
		printf("Car %d [%d laps]\n", cars[j], laps[j]);
	}
}
