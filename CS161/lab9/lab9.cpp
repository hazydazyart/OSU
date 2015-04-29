
#include <iostream>
#include <stdlib.h>

struct mult_div_value {
	int mult;
	float div;
};

mult_div_value **create_table(int rows, int columns) {

	mult_div_value** table = new mult_div_value*[rows];
	for (int i = 0; i < rows; i++) {
		table[i] = new mult_div_value[columns];
	}
	return table;
}

void set_mult_values(mult_div_value **table, int rows, int columns) {
	
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < columns; j++) {
			table[i][j].mult = (i + 1) * (j + 1);
		}
	}
}

void set_div_values(mult_div_value **table, int rows, int columns) {

	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < columns; j++) {
			table[i][j].div = ((float) i + 1) / ((float) j + 1);
		}
	}
}

void print_values(mult_div_value **table, int rows, int columns) {

	std::cout << "Multiplication table: " << std::endl;

	for (int i = 0; i < rows; i ++) {
		for (int j = 0; j < columns; j++) {
			std::cout << table[i][j].mult;
			std::cout << " ";
		}
	std::cout << std::endl;
	}

	
    	std::cout.precision(2);
	std::cout << std::fixed;

	std::cout << "Division table: " << std::endl;
        for (int i = 0; i < rows; i ++) {
                for (int j = 0; j < columns; j++) {
                        std::cout << table[i][j].div;
                        std::cout << " ";
                }
        std::cout << std::endl;
	}

}

int main(int argc, char* argv[]) {

	int rows = atoi(argv[1]);
	int columns = atoi(argv[2]);

	mult_div_value **table = create_table(rows, columns);

	set_mult_values(table, rows, columns);
	set_div_values(table, rows, columns);

	print_values(table, rows, columns);

	return 0;
}
