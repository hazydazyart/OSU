
#include <iostream>

int user_input();
void recursive_func(int input);

int main() {

        int input = user_input();
        
	recursive_func(input);

        return 0;
}

int user_input() {
        int input;
        std::cout << "Please input an integer between 1 and 10: ";
        std::cin >> input;
        while(!std::cin || input > 10 || input < 1) {
                std::cout << "Please input an integer between 1 and 10: ";
                std::cin >> input;
        }

        return input;
}

void recursive_func(int input) {
	int count = 1;
	try {
	if (count < input) {
	        recursive_func(input);
		count++;
	} else {
		throw input;
	}
	}
	catch (int input) {
		std::cout << "Error: Depth of " << input << " reached." << std::endl;
	}
}


