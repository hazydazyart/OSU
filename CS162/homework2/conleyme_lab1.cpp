
#include <iostream>
#include "lab1_header.h"

#define COL 80 
#define ROW 22 

int main() {

	int generation[ROW][COL];
	int generation2[ROW][COL];

	initialize(generation);
	initialize(generation2);

	int c1 = choice_1();

	int c2 = 0;

	if (c1 == 1) {
		blinker(generation);
	} else if (c1 == 2) {
                glider_gun(generation);
	} else if (c1 == 3) {
               	big_glider(generation);
	} else {
                random(generation);
	}

	print_array(generation);
	c2 = choice_2();

	while (c2 != 2) {
                next_gen(generation, generation2);
                copy_array(generation, generation2);
                print_array(generation2);
                c2 = choice_2();
	}

	return 0;

}




