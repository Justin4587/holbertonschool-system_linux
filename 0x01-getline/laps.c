#include "laps.h"
/**
* race_state - function for stuff
* @id: id
* @size: num of cars
*/

void race_state(int *id, size_t size) {

	static car_t *head;
	car_t *check_car;
	car_t *new_car;
	car_t *print_car;
	size_t i;


	if (size == 0) {
		while (head != NULL) {
			check_car = head;
			head = head->next;
			free(check_car);
		}
		return;
	}


	for (i = 0; i < size; i++) {
		check_car = head;

		while (check_car && check_car->next && check_car->next->id <= id[i])
			check_car = check_car->next;

		if (check_car && check_car->id  == id[i]) {
			check_car->laps++;
			continue;
		}

		new_car = malloc(sizeof(car_t));
		
		if (head == NULL && check_car == head) {
			new_car->next = head;
			new_car->id = id[i];
			new_car->laps = 0;
			head = new_car;
		}
		else {            
		new_car->id = id[i];
		new_car->laps = 0;
		new_car->next = check_car->next;
		check_car->next = new_car;
		}
		printf("Car %d joined the race\n", id[i]);

	}

	printf("Race state:\n");
	for (print_car = head; print_car != NULL; print_car = print_car->next)
		printf("Car %d [%lu laps]\n", print_car->id, print_car->laps);
}
