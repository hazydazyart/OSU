/* CS261- Assignment 1 - Q.1*/
/* Name: Megan Conley
 * Date: 4/3/2014
 * Solution description: Allocates memory for 10 structs, generates ids
 and scores, calculates average, min, and max scores.
 */

#include <stdio.h>
#include<stdlib.h>
#include<math.h>
#include<time.h>
#include<assert.h>

struct student{
	int id;
	int score;
};

struct student* allocate(){
     /*Allocate memory for ten students*/
     struct student* temp = malloc(10 * sizeof(struct student));
     /*return the pointer*/
     return temp;
}

void generate(struct student* students){
     /*Generate random ID and scores for ten students, ID being between 1 and 10, scores between 0 and 100*/

     for(int i = 0; i < 10; i++) {
        int rand_id = rand() % 10 + 1;
        int rand_score = rand() % 100 + 1;
        students[i].id = rand_id;
        students[i].score = rand_score;
     }
}

void output(struct student* students){
     /*Output information about the ten students*/
    for(int i = 0; i < 10; i++) {
        printf("ID%d %d\n", students[i].id, students[i].score);
    }
}

void summary(struct student* students){
     /*Compute and print the minimum, maximum and average scores of the ten students*/
    int min = 100;
    int max = 0;
    int avg = 0;
    for(int i = 0; i < 10; i++) {
        avg += students[i].score;
        if(students[i].score > max) {
            max = students[i].score;
        }
        if (students[i].score < min) {
            min = students[i].score;
        }
    }
    avg = avg / 10;

    printf("Average: %d; Minimum: %d; Maximum: %d\n", avg, min, max);
}

void deallocate(struct student* stud){
     /*Deallocate memory from stud*/
     assert(stud != NULL);

     free(stud);
}

int main(){
    struct student* stud = NULL;

    srand(time(NULL));

    /*call allocate*/
    stud = allocate();

    /*call generate*/
    generate(stud);

    /*call output*/
    output(stud);

    /*call summary*/
    summary(stud);

    /*call deallocate*/
    deallocate(stud);
    return 0;
}
