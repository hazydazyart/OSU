

#include <iostream>

using std::cout;
using std::cin;
using std::endl;

void countFromZero(int firstInput);
void countToZero(int firstInput);
void countBetween(int firstInput, int secondInput);

int main()
{
	//initialize input variables
	int firstInput;
	int secondInput;

	//Ask the user for the two values
	cout<< "Please enter 2 positive ints.\n" << endl;
	cin>> firstInput;
	cout<< " ";
	cin>> secondInput;

	countFromZero(firstInput);
	countToZero(firstInput);
	countBetween(firstInput, secondInput);

	return 0;

}



void countFromZero(firstInput)
{
	for(int i = 0; i <= firstInput; i++) {
		cout<< i << " " << endl;
	}
}

void countToZero(firstInput)
{
	for(int i = input; i >= 0; i--) {
		cout<< i << " " << endl;
	}
}

void countBetween(firstInput, secondInput)
{
	if(secondInput > firstInput) {
		for(int i = firstInput; i <= secondInput; i++) {
			cout<< i << " " << endl;
		}
	} else {
		for(int i = secondInput; i >= secondInput; i--) {
			cout<< i << " " << endl;
		}
	}
}
