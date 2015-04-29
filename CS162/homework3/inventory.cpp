/********************************************************************* 
 * ** Program Filename: conleyme_assn_3-1.cpp
 * ** Author: Megan Conley
 * ** Date: 1/24/2014
 * ** Description: Assignment 3, program 1
 * ** Input: none
 * ** Output: none
 * *********************************************************************/


#include <iostream>
#include <string>

/********************************************************************* 
 * ** Function: class Item constructors
 * ** Description: 8 constructors for an object of the Item class were
 * created to handle every possible combination of user input - every
 * constructor requires at least one string and one double for name and
 * selling price. The rest cover every combination of other input, with
 * any not required given a default argument.
 * ** Parameters: 2 strings, 2 doubles, 1 int
 * ** Pre-Conditions: User has input all known variables and they
 * are stored for passing
 * ** Post-Conditions: Creates an object of the Item class when called
 * *********************************************************************/ 


class Item {

public:

	Item(std::string name, double price, int age = 0, double p_price = 0.0, std::string color = "beige") {
		this->name = name;
		this->sale_price = price;
		this->age = age;
		this->p_price = p_price;
		this->color = color;
	}
        Item(double p_price, std::string name, double price, std::string color = "beige", int age = 0) {
                this->name = name;
                this->sale_price = price;
                this->age = age;
                this->p_price = p_price;
                this->color = color;
        }
        Item(std::string color, std::string name, double price, double p_price, int age = 0)  {
                this->name = name;
                this->sale_price = price;
                this->age = age;
                this->p_price = p_price;
                this->color = color;
        }

        Item(std::string name, double price, std::string color, int age, double p_price = 0.0) {
                this->name = name;
                this->sale_price = price;
                this->age = age;
                this->p_price = p_price;
                this->color = color;
        }

        Item(int age, std::string name, double price, double p_price, std::string color = "beige") {
                this->name = name;
                this->sale_price = price;
                this->age = age;
                this->p_price = p_price;
                this->color = color;
        }

        Item(double price, std::string color, std::string name, double p_price = 0.0, int age = 0)  {
                this->name = name;
                this->sale_price = price;
                this->age = age;
                this->p_price = p_price;
                this->color = color;
        }

        Item(std::string color, int age, std::string name, double price, double p_price)  {
                this->name = name;
                this->sale_price = price;
                this->age = age;
                this->p_price = p_price;
                this->color = color;
        }

	Item(int age, std::string name, std::string color, double price, double p_price = 0.0)  {
                this->name = name;
                this->sale_price = price;
                this->age = age;
                this->p_price = p_price;
                this->color = color;
        }

/********************************************************************* 
 * ** Function: class Item accessors
 * ** Description: Because the variables are private, these functions
 * are required to access the values. Each one simply returns the
 * relevant value, so the value can be assigned to a variable in main.
 * ** Parameters: None
 * ** Pre-Conditions: Values have already been assigned within the object
 * ** Post-Conditions: Returns a value 
 * *********************************************************************/ 

	double get_s_price() {
                return this->sale_price;
        }

        std::string get_color() {
                return this->color;
        }

        double get_p_price() {
                return this->p_price;
        }

        int get_age() {
                return this->age;
        }

        std::string get_name() {
                return this->name;
	}

	void set_name(std::string name);
	void set_age(int age);
	void set_p_price(double p);
	void set_s_price(double s);
	void set_color(std::string color);

private:

	std::string name;
	std::string color;
	double sale_price;
	double p_price;
	int age;

};

int enter_age();
double enter_p_price();
std::string enter_color();
void print_item(Item i);

// The main function was used to test the class functions;
// It has been left behind in case the grader would like to
// test the functions.

int main() {

/*
	std::string name;
	double price;
	int choice;

        std::cout << "Please enter the name of the item: ";
        std::cin >> name;
        std::cout << "Please enter the asking price: ";
        std::cin >> price;

        std::cout << "What other information do you know?" << std::endl;
	std::cout << "1. Color 2. Age 3. Purchase Price " << std::endl;
	std::cout << "4. Color and age 5. Color and Purchase Price " << std::endl;
	std::cout << "6. Age and purchase price 7. All of the above" << std::endl;
	std::cout << "8. Nothing else" << std::endl;

        std::cin >> choice;

        if (choice == 1) {
		std::string color = enter_color();
		Item i(price, color, name);
	        print_item(i);
	} else if (choice == 2) {
		int age = enter_age();
		Item i(age, name, price);
        print_item(i);
	} else if (choice == 3) {
		double p = enter_p_price();
		Item i(p, name, price);
        print_item(i);
	} else if (choice == 4) {
                std::string color = enter_color();
                int age = enter_age();
		Item i(name, price, color, age);
        print_item(i);
	} else if (choice == 5) {
                std::string color = enter_color();
                double p = enter_p_price();
                Item i(color, name, price, p);
        print_item(i);
	} else if (choice == 6) { 
                int age = enter_age();
                double p = enter_p_price();
		Item i(age, name, price, p);
        print_item(i);
	} else if (choice == 7) {
                int age = enter_age();
                double p = enter_p_price();
                std::string color = enter_color();
		Item i(color, age, name, price, p);
        print_item(i);
	} else {
		Item i(name, price);
        print_item(i);
	}
*/

	return 0;
}

/********************************************************************* 
 * ** Function: string enter_color, double enter_p_price, int enter_age
 * ** Description: Prompts user for a string, double, int
 * ** Parameters: n/a
 * ** Pre-Conditions: n/a
 * ** Post-Conditions: Returns a string, double, int
 * ** Notes: Combining this into one header because it was used for
 * testing; I've left them here in case the full program is run to
 * test it during grading as well.
 * *********************************************************************/ 

std::string enter_color() {
	std::string color;
	std::cout << "Enter the color: ";
	std::cin >> color;
	return color;
}

double enter_p_price() {
	double p;
	std::cout << "Enter the purchase price: ";
	std::cin >> p;
	return p;
}

int enter_age() {
	int age;
	std::cout << "Enter the age: ";
	std::cin >> age;
	return age;
}

/********************************************************************* 
 * ** Function: void print_item
 * ** Description: Prints the members of the object
 * ** Parameters: one Item object
 * ** Pre-Conditions: There exists an Item object with all values
 * defined
 * ** Post-Conditions: Prints the values of each variable
 * *********************************************************************/ 


void print_item(Item i) {

        std::cout << "Name: " << i.get_name() << std::endl;
        std::cout << "Age: " << i.get_age() << std::endl;
        std::cout << "Color: " << i.get_color() << std::endl;
        std::cout << "Sale price: " << i.get_s_price() << std::endl;
        std::cout << "Purchase price: " << i.get_p_price() << std::endl;
}


/*********************************************************************
 * ** Function: class Item mutators
 * ** Description: Initialized here and defined below. These allow the
 * user to alter the values for each variable.
 * ** Parameters: 1 variable
 * ** Pre-Conditions: An object is already constructed with all variables
 * having a value
 * ** Post-Conditions: Object's value for the specified variable becomes
 * the value passed in the parameters
 * *********************************************************************/

void Item::set_name(std::string name) {
	this->name = name;
}

void Item::set_age(int age) {
	this->age = age;
}

void Item::set_p_price(double p) {
	this->p_price = p;
}

void Item::set_s_price(double s) {
	this->sale_price = s;
}

void Item::set_color(std::string color) {
	this->color = color;
}
