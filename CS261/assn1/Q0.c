/* CS261- Assignment 1 - Q. 0*/
/* Name: Megan Conley
 * Date: 4/3/2014
 * Solution description: Prints addresses and values of pointer/variable
 */

#include <stdio.h>
#include <stdlib.h>

void fooA(int* iptr){
     /*Print the value pointed to by iptr*/
     printf("Value pointed to by parameter: %d\n", *iptr);

     /*Print the address pointed to by iptr*/
     printf("Address pointed to by parameter: %d\n", &(*iptr));

     /*Print the address of iptr itself*/
     printf("Address of parameter: %d\n", &iptr);
}

int main(){

    /*declare an integer x*/
    int x = 0;

    /*print the address of x*/
    printf("Address of x: %d\n", &x);

    /*Call fooA() with the address of x*/
    fooA(&x);

    /*print the value of x*/
    printf("Value of x: %d\n", x);

    return 0;
}
