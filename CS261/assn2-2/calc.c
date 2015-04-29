// Megan Conley
// 4/20/2014
// conleyme@onid.oregonstate.edu
// Assignment 2: calc.c

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include "dynamicArray.h"

#define M_PI 3.141592654
#define M_E 2.71828

/* param: s the string
   param: num a pointer to double
   returns: true (1) if s is a number else 0 or false.
   postcondition: if it is a number, num will hold
   the value of the number
*/
int isNumber(char *s, double *num)
{
	char *end;
	double returnNum;

	if(strcmp(s, "0") == 0)
	{
		*num = 0;
		return 1;
	}
	else
	{
		returnNum = strtod(s, &end);
		/* If there's anythin in end, it's bad */
		if((returnNum != 0.0) && (strcmp(end, "") == 0))
		{
			*num = returnNum;
			return 1;
		}
	}
	return 0;  //if got here, it was not a number
}

/*	param: stack the stack being manipulated
	pre: the stack contains at least two elements
	post: the top two elements are popped and
	their sum is pushed back onto the stack.
*/
void add (struct DynArr *stack)
{
	double num_1 = topDynArr(stack);
	popDynArr(stack);
	double num_2 = topDynArr(stack);
	popDynArr(stack);
	double num_3 = num_1 + num_2;
	pushDynArr(stack, num_3);
}

/*	param: stack the stack being manipulated
	pre: the stack contains at least two elements
	post: the top two elements are popped and
	their difference is pushed back onto the stack.
*/
void subtract(struct DynArr *stack)
{
	double num_1 = topDynArr(stack);
	popDynArr(stack);
	double num_2 = topDynArr(stack);
	popDynArr(stack);
	double num_3 = num_1 - num_2;
	pushDynArr(stack, num_3);
}

/*	param: stack the stack being manipulated
	pre: the stack contains at least two elements
	post: the top two elements are popped and
	their quotient is pushed back onto the stack.
*/
void divide(struct DynArr *stack)
{
	double num_1 = topDynArr(stack);
	popDynArr(stack);
	double num_2 = topDynArr(stack);
	popDynArr(stack);
	double num_3 = num_1 / num_2;
	pushDynArr(stack, num_3);
}

/*      param: stack the stack being manipulated
        pre: the stack contains at least two elements
        post: the top two elements are popped and
        their product is pushed back onto the stack.
*/

void multiply(struct DynArr *stack)
{
	double num_1 = topDynArr(stack);
	popDynArr(stack);
	double num_2 = topDynArr(stack);
	popDynArr(stack);
	double num_3 = num_1 * num_2;
	pushDynArr(stack, num_3);
}

/*      param: stack the stack being manipulated
        pre: the stack contains at least two elements
        post: the top two elements are popped. First
	element is raised to the power of the second element.
	Result is pushed back on stack.
*/

void power(struct DynArr *stack)
{
	double num_1 = topDynArr(stack);
	popDynArr(stack);
	double num_2 = topDynArr(stack);
	popDynArr(stack);
	double num_3 = pow(num_1, num_2);
	pushDynArr(stack, num_3);
}

/*      param: stack the stack being manipulated
        pre: the stack contains at least one element
        post: the top element is popped, squared, and
	the result is pushed back onto the stack.
*/

void square(struct DynArr *stack)
{
	double num_1 = topDynArr(stack);
	popDynArr(stack);
	double num_2 = pow(num_1, 2);
	pushDynArr(stack, num_2);
}

/*      param: stack the stack being manipulated
        pre: the stack contains at least one element
        post: the top element is popped, cubed, and
	pushed back on the stack.
*/


void cube(struct DynArr *stack)
{
	double num_1 = topDynArr(stack);
	popDynArr(stack);
	double num_2 = pow(num_1, 3);
	pushDynArr(stack, num_2);
}

/*      param: stack the stack being manipulated
        pre: the stack contains at least one element
        post: the top element is popped and the absolute
	value of that element is pushed back to the stack.
*/

void absolute(struct DynArr *stack)
{
	double num_1 = topDynArr(stack);
	popDynArr(stack);
	double num_2 = abs(num_1);
	pushDynArr(stack, num_2);
}

/*      param: stack the stack being manipulated
        pre: the stack contains at least one element
        post: the top element is popped and
        the square root of that element is pushed
	onto the stack.
*/

void sqroot(struct DynArr *stack)
{
	double num_1 = topDynArr(stack);
	popDynArr(stack);
	double num_2 = sqrt(num_1);
	pushDynArr(stack, num_2);
}

/*      param: stack the stack being manipulated
        pre: the stack contains at least one element
        post: the top element is popped and
        e times the value is pushed back onto the stack.
*/

void exponential(struct DynArr *stack)
{
    double num_1 = topDynArr(stack);
	popDynArr(stack);
	double num_2 = M_E * num_1;
	pushDynArr(stack, num_2);
}

/*      param: stack the stack being manipulated
        pre: the stack contains at least one element
        post: the top element is popped and
        the natural log of the element is pushed
	onto the stack.
*/

void nat_log(struct DynArr *stack)
{
    double num_1 = topDynArr(stack);
	popDynArr(stack);
	double num_2 = log(num_1);
	pushDynArr(stack, num_2);
}

/*      param: stack the stack being manipulated
        pre: the stack contains at least one element
        post: the top element is popped and
        the log of the element is pushed onto the stack.
*/

void log_10(struct DynArr *stack)
{
    double num_1 = topDynArr(stack);
	popDynArr(stack);
	double num_2 = log10(num_1);
	pushDynArr(stack, num_2);
}

/*      param: argc, argv
        pre: commandline contains arguments
        post: elements are parsed and pushed
	onto a stack which is passed to functions.
*/

double calculate(int numInputTokens, char **inputString)
{

	int i;
	double result = 0.0;
	char *s;
	struct DynArr *stack;
	double digit = 0;
	int error = 0;

	//set up the stack
	stack = createDynArr(20);

	// start at 1 to skip the name of the calculator calc
	for(i=1;i < numInputTokens;i++)
	{
		s = inputString[i];

		// Hint: General algorithm:
		// (1) Check if the string s is in the list of operators.
		//   (1a) If it is, perform corresponding operations.
		//   (1b) Otherwise, check if s is a number.
		//     (1b - I) If s is not a number, produce an error.
		//     (1b - II) If s is a number, push it onto the stack

		if(strcmp(s, "+") == 0) 
			add(stack);
		else if(strcmp(s,"-") == 0)
			subtract(stack);
		else if(strcmp(s, "/") == 0)
			divide(stack);
		else if(strcmp(s, "x") == 0)
			multiply(stack);
		else if(strcmp(s, "^") == 0)
			power(stack);
		else if(strcmp(s, "^2") == 0)
			square(stack);
		else if(strcmp(s, "^3") == 0)
			cube(stack);
		else if(strcmp(s, "abs") == 0)
			absolute(stack);
		else if(strcmp(s, "sqrt") == 0)
			sqroot(stack);
		else if(strcmp(s, "exp") == 0)
			exponential(stack);
		else if(strcmp(s, "ln") == 0)
			nat_log(stack);
		else if(strcmp(s, "log") == 0)
			log_10(stack);
		else
		{
			if (strcmp(s, "pi") == 0) {
                		pushDynArr(stack, M_PI);
			} else if (strcmp(s, "e") == 0) {
                		pushDynArr(stack, M_E);
			} else if (strcmp(s, "exp") == 0) {
				exponential(stack);
			} else if (isNumber(s, &digit) == 1) {
                    			pushDynArr(stack, digit);
                	} else {
				error = 1;
			}
	
		}
	}	//end for

    if (error == 1) {
	printf("Error: Input invalid.\n");
	return 0;
    } else {    
        result = topDynArr(stack);
	printf("Result: %f\n", result);
	return result;
    }
}

int main(int argc , char** argv)
{
	// assume each argument is contained in the argv array
	// argc-1 determines the number of operands + operators
	if (argc == 1)
		return 0;

	calculate(argc,argv);
	return 0;
}

