/********************************************************************* 
 * ** Program Filename: lab1_header.h
 * ** Author: Megan Conley
 * ** Date: 1/26/2014
 * ** Description: Declares all functions for conleyme_lab1.cpp
 * ** Input: n/a
 * ** Output: n/a
 * *********************************************************************/ 

#define COL 80
#define ROW 22

int count_neighbors(int generation[ROW][COL], int r, int c);
int calc_next(int generation[ROW][COL], int r, int c, int neighbors);
void initialize(int array[ROW][COL]);
void print_array(int array[ROW][COL]);
void copy_array(int array[ROW][COL], int array2[ROW][COL]);
void next_gen(int array[ROW][COL], int array2[ROW][COL]);
void blinker(int gen[ROW][COL]);
void random(int gen[ROW][COL]);
void glider_gun(int gen[ROW][COL]);
void big_glider(int gen[ROW][COL]);
int choice_1();
int choice_2();
