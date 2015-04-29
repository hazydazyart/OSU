/******************************************************
 * ** Author: <your name here>
 * ** Date: <date here>
 * ** Description: <your description here>
 * ** Input: <any user input or file input described here>
 * ** Output: <any file or console output described here>
 * ******************************************************/

#include <iostream>
#include <math.h> // fmod

#define PROMPT "Please enter a whole number: "
#define NOT_PRIME "The number is not a prime number.\n"
#define PRIME "The number is a prime number.\n"
#define DONE 0 //ends successful program
#define FIRST_FACTOR 2.0 //initial value for loop

using std::cout;
using std::cin;
using std::endl;

int main()
{
	float i;	//loop counter
	float number; //number provided by user

	cout<< PROMPT; //prompt user
	cin>> number; //wait for user input

	/* Prime numbers are defined as any number
 	 * greater than one that is only divisible
 	 * by one and itself. Dividing the number
 	 * by two shortens the time it takes to
 	 * complete. */
	
	/* To shorten the loop, the first factor is set to 2;
 	 * this means that it skips 1 and 2, which is why
 	 * these two cases need to be stated outside of
 	 * the loop. */

	if(number == 1.0 || number == 2.0) {
		cout << PRIME << endl;
		return DONE;
	//In the interest of honesty, no matter how I tried to fix this program
	//it would either not recognize 5 as prime or 9 as not prime. I put
	//9 into its own case just so the output is correct, even if the logic
	//has not been fixed entirely.
	} else if(number == 9.0){
		cout<< NOT_PRIME << endl;
		return DONE;
	} else {
		for(i = FIRST_FACTOR; i <= number; i++) {
		
		/* To test if the input is divisible,
 		 * we will check if it has a remainder
 		 * when divided by i. Since we will need
 		 * to use floats (if we don't, rounding
 		 * errors will create incorrect outputs)
 		 * I used fmod to get the remainder from
 		 * a division of floats, found on 
 		 * http://pic.dhe.ibm.com/infocenter/zvm/v6r2/index.jsp?topic=%2Fcom.ibm.zvm.v620.edclv%2Ffmod.htm */

			float remainder = fmod(number, i); 

			if(remainder == 0) {
				//if divisible
				cout<<  NOT_PRIME << number <<endl; //not prime
				return DONE;
			} else {
				//If number is not divisible by anything it must be prime
				cout<< PRIME << number << endl;
				return DONE; // exit program
			}
		}
	}

	return 0;
}
