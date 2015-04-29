/* CS261- Assignment 1 - Q.4*/
/* Name: Megan Conley
 * Date: 4/6/2014
 * Solution description: Uses code from Q1 to create an array of 20
 student structs, assigns random ID and scores, then sorts them
 with a bubble sort algorithm in ascending order.
 */

#include <stdio.h>
#include <stdlib.h>

struct student{
	int id;
	int score;
};

void sort(struct student* students, int n){
     /*Sort the n students based on their score*/
     int temp = 0;
     for(int i = 0; i < n; i++){
        for(int j = 0; j < n-1; j++){
            if(students[j].score > students[i].score){
                temp = students[i].score;
                students[i].score = students[j].score;
                students[j].score = temp;
            }
        }
     }
}

int main(){
    /*Declare an integer n and assign it a value.*/
    int n = 20;

    /*Allocate memory for n students using malloc.*/
    struct student* stud = malloc(n * sizeof(struct student));

    /*Generate random IDs and scores for the n students, using rand().*/
    for(int i = 0; i < n; i++) {
        int rand_id = rand() % 10 + 1;
        int rand_score = rand() % 100 + 1;
        stud[i].id = rand_id;
        stud[i].score = rand_score;
     }

    /*Print the contents of the array of n students.*/
    for(int i = 0; i < n; i++) {
        printf("ID%d: Score %d\n", stud[i].id, stud[i].score);
    }
    printf("\n");

    /*Pass this array along with n to the sort() function*/
    sort(stud, n);

    /*Print the contents of the array of n students.*/
    for(int i = 0; i < n; i++) {
        printf("ID%d: Score %d\n", stud[i].id, stud[i].score);
    }

    return 0;
}
