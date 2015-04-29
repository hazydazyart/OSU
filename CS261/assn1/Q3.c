/* CS261- Assignment 1 - Q.3*/
/* Name: Megan Conley
 * Date: 4/5/2014
 * Solution description: This solution uses a bubble sort algorithm to
 sort an array of n ints.
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void sort(int* number, int n){
    int temp = 0;
     /*Sort the given array number , of length n*/
     for(int i = 0; i < n; i++){
        for(int j = 0; j < n-1; j++){
            if(number[j] < number[i]){
                temp = number[i];
                number[i] = number[j];
                number[j] = temp;
            }
        }
     }
}

int main(){
    /*Declare an integer n and assign it a value of 20.*/
    int n = 20;

    /*Allocate memory for an array of n integers using malloc.*/
    int *array;

    array = malloc(n*sizeof(int));

    /*Fill this array with random numbers, using rand().*/
    srand(time(NULL));

    for(int i = 0; i < 20; i++) {
        array[i] = rand() % 20 + 1;
    }

    /*Print the contents of the array.*/
    for(int i = 0; i < 20; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");

    /*Pass this array along with n to the sort() function of part a.*/
    sort(array, n);

    /*Print the contents of the array.*/
    for(int i = 0; i < 20; i++) {
        printf("%d ", array[i]);
    }

    printf("\n");

    return 0;
}
