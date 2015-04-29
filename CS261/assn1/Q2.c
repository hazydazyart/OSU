/* CS261- Assignment 1 - Q.2*/
/* Name:
 * Date:
 * Solution description:
 */

#include <stdio.h>
#include <stdlib.h>

int foo(int* a, int* b, int c){
    /*Set a to double its original value*/
    *a = *a * 2;

    /*Set b to half its original value*/
    *b = *b / 2;

    /*Assign a+b to c*/
    c = *a + *b;

    /*Return c*/
    return c;
}

int main(){
    /*Declare three integers x,y and z and initialize them to 5, 6, 7 respectively*/
    int x, y, z;

    x = 5;
    y = 6;
    z = 7;

    /*Print the values of x, y and z*/
    printf("X: %d, Y: %d, Z: %d\n", x, y, z);

    /*Call foo() appropriately, passing x,y,z as parameters*/
    int test = foo(&x, &y, &z);

    /*Print the value returned by foo*/
    printf("Result: %d\n", test);

    /*Print the values of x, y and z again*/
    printf("X: %d, Y: %d, Z: %d\n", x, y, z);

    /*Is the return value different than the value of z?  Why?*/
    /*The return value is different from the value of z because it was passed as a value,
    not by reference. The value of z was passed to the function foo, but any changes to it
    were local and so did not affect the value of z when it was printed again.*/
    return 0;
}


