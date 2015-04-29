/********************************************************************* 
 * ** Program Filename: lab1_func.cpp
 * ** Author: Megan Conley
 * ** Date: 1/26/2014
 * ** Description: Contains definitions for all functions used in
 * conleyme_lab1.cpp. Declarations are in lab1_header.h
 * ** Input: n/a
 * ** Output: n/a
 * *********************************************************************/ 

#include <iostream>
#include <time.h>
#include <stdlib.h>
#include <stdio.h>
#include "lab1_header.h"

#define COL 80
#define ROW 22

/********************************************************************* 
 * ** Function: void initialize
 * ** Description: Fills an array with 0s
 * ** Parameters: 2D array
 * ** Pre-Conditions: 2D array exists and has been passed as a parameter
 * ** Post-Conditions: Every value of 2D array is 0
 * *********************************************************************/ 


void initialize(int array[ROW][COL]) {

        for (int i = 0; i < ROW; i++) {
                for (int j = 0; j < COL; j++) {
                        array[i][j] = 0;
                }
        }
}

/********************************************************************* 
 * ** Function: int count_neighbors
 * ** Description: For each position in the array, it checks all 8
 * surrounding values. If it is a 1, it is considered a live cell, so it
 * increments the number of neighbors. It wraps around if the position
 * is near an edge. It then returns the number of neighbors.
 * ** Parameters: 2D array, two ints
 * ** Pre-Conditions: 2D array is initialized and full of ints;
 * the other two ints passed as parameters are within the row/col
 * values for the 2D array.
 * ** Post-Conditions: Returns an int
 * *********************************************************************/ 


int count_neighbors(int generation[ROW][COL], int r, int c) {
        int neighbors = 0;
        if (generation[r][(c + 1) % COL ] == 1) {
                neighbors++;
        } if (generation[r][(c + COL - 1) % COL] == 1) {
                neighbors++;
        } if (generation[(r + 1) % ROW][(c + 1) % COL] == 1) {
                neighbors++;
        } if (generation[(r + 1) % ROW][(c + COL - 1) % COL] == 1) {
                neighbors++;
        } if (generation[(r + 1) % ROW][c] == 1) {
                neighbors++;
        } if (generation[(r +ROW - 1) % ROW][c] == 1) {
                neighbors++;
        } if (generation[(r +ROW - 1) % ROW][(c + COL - 1) % COL] == 1) {
                neighbors++;
        } if (generation[(r +ROW - 1) % ROW][(c + COL + 1) % COL] == 1) {
                neighbors++;
        }
        return neighbors;
}

/********************************************************************* 
 * ** Function: int calc_next
 * ** Description: Using the count_neighbors function, it determines if
 * in the next generation a cell should be live or dead based on the
 * rules for the Game of Life.
 * ** Parameters: 2D array, three ints
 * ** Pre-Conditions: 2D array is initialized; int r and int c are within
 * the bounds of the 2D array's row/col, and int neighbors has been
 * previously calculated with the above function.
 * ** Post-Conditions: Returns 0 if the cell dies, returns 1 if the cell
 * is born, and returns the current value of the array if there is no
 * change. 
 * *********************************************************************/ 


int calc_next(int generation[ROW][COL], int r, int c, int neighbors) {
        if (neighbors < 2 || neighbors > 3) {
                return 0;
        } else if (neighbors == 3 && generation[r][c] == 0) {
                return 1;
        } else {
                return generation[r][c];
        }
}

/********************************************************************* 
 * ** Function: void print_array
 * ** Description: Prints a 2D array to the console
 * ** Parameters: 2D array
 * ** Pre-Conditions: 2D array is initialized with some value
 * ** Post-Conditions: 2D array is printed to console
 * *********************************************************************/ 


void print_array(int array[ROW][COL]) {
        for (int i = 0; i < ROW; i++) {
                for (int j = 0; j < COL; j++) {
                        std::cout << array[i][j] << " ";
                }
        std::cout << std::endl;
        }
}

/********************************************************************* 
 * ** Function: void copy_array
 * ** Description: Copies the values of the second parameter into
 * the first parameter
 * ** Parameters: 2 2D arrays
 * ** Pre-Conditions: There exist 2 2D arrays with the same dimensions
 * that have been initialized
 * ** Post-Conditions: The two arrays contain the same values
 * *********************************************************************/ 


void copy_array(int array[ROW][COL], int array2[ROW][COL]) {
        for (int i = 0; i < ROW; i++) {
                for (int j = 0; j < COL; j++) {
                        array[i][j] = array2[i][j];
                }
        }
}

/********************************************************************* 
 * ** Function: void next_gen
 * ** Description: Calls int count_neighbors and int calc_next to
 * fill an array with the values for the next generation of life.
 * ** Parameters: 2 2D arrays
 * ** Pre-Conditions: 2 2D arrays exist and have valid input;
 * int count_neighbors and int calc_next return valid ints
 * ** Post-Conditions: The second 2D array parameter containes the
 * next generation of values; the first remains the same
 * *********************************************************************/ 


void next_gen(int array[ROW][COL], int array2[ROW][COL]) {
        for (int i = 0; i < ROW; i++) {
                for (int j = 0; j < COL; j++) {
                        int neighbors = count_neighbors(array, i, j);
                        int next = calc_next(array, i, j, neighbors);
                        array2[i][j] = next;
                }
        }
}

/********************************************************************* 
 * ** Function: int choice_1
 * ** Description: Displays first menu for user to start the game,
 * offering different options for what the starting configuration will
 * be. Checks if the input is valid, then returns the user's choice.
 * ** Parameters: n/a
 * ** Pre-Conditions: n/a 
 * ** Post-Conditions: Returns an int
 * *********************************************************************/ 


int choice_1() {

        int i;

        std::cout << "What pattern would you like to start with?" << std::endl;
        std::cout << "1. Blinker" << std::endl;
        std::cout << "2. Gosper Glider Gun" << std::endl;
        std::cout << "3. Big Glider" << std::endl;
        std::cout << "4. Random" << std::endl;

        std::cin >> i;

        while(!std::cin || i < 1 || i > 4) {
                std::cin.clear();
                std::cin.ignore(9999, '\n');
                std::cout << "Please enter a number between 1 and 4: ";
                std::cin >> i;
        }
        return i;
}

/********************************************************************* 
 * ** Function: int choice_2
 * ** Description: Displayed at the end of every generation, checks
 * if the user wants to continue or exit the program
 * ** Parameters: n/a
 * ** Pre-Conditions: n/a 
 * ** Post-Conditions: Returns an int
 * *********************************************************************/ 


int choice_2() {

        int i;

        std::cout << "1. Continue" << std::endl;
        std::cout << "2. Quit." << std::endl;

        std::cin >> i;

        while(!std::cin || i < 1 || i > 2) {
                std::cin.clear();
                std::cin.ignore(9999, '\n');
                std::cout << "Please enter either 1 or 2: ";
                std::cin >> i;
        }
        return i;
}

/********************************************************************* 
 * ** Function: void blinker
 * ** Description: Fills an array with a variety of blinker patterns
 * as an option for the first configuration. Patterns from:
 * http://www536.pair.com/bgw/applets/1.02/Life/blinkers.html
 * ** Parameters: 2D array
 * ** Pre-Conditions: 2D array is initalized
 * ** Post-Conditions: 2D array values are changed to the below
 * specifications
 * *********************************************************************/ 

void blinker(int gen[ROW][COL]) {

	// Simple 2 period blinker
        gen[0][0] = 1;
        gen[0][1] = 1;
        gen[0][2] = 1;

	// Grows into 4 bliners
        gen[5][45] = 1;
        gen[5][46] = 1;
        gen[5][47] = 1;
        gen[4][45] = 1;
        gen[6][45] = 1;

	// "beacon" 2 period blinker
        gen[10][10] = 1;
        gen[11][10] = 1;
        gen[10][11] = 1;
        gen[10][12] = 1;
        gen[10][13] = 1;
        gen[10][14] = 1;
        gen[11][14] = 1;

	// Multi-period blinker
        gen[15][25] = 1;
        gen[15][26] = 1;
        gen[16][25] = 1;
        gen[18][28] = 1;
        gen[18][29] = 1;
        gen[17][29] = 1;


}

/********************************************************************* 
 * ** Function: void random
 * ** Description: Fills a 2D array with either a 1 or a 0 based on a
 * random value - if it's even, 1, if odd, 0.
 * ** Parameters: 2D array
 * ** Pre-Conditions: 2D array is initialized
 * ** Post-Conditions: 2D array is filled with a randomized assortment
 * of 1s and 0s
 * *********************************************************************/ 


void random(int gen[ROW][COL]) {

        srand(time(NULL));

        for (int i = 0; i < ROW; i++) {
                for (int j = 0; j < COL; j++) {
                        int a = rand() % 100;
                        if (a % 2 == 0) {
                                gen[i][j] = 1;
                        } else {
                                gen[i][j] = 0;
                        }
                }
        }
}

/********************************************************************* 
 * ** Function: void glider_gun
 * ** Description: Fills a 2D array with the gosper glider gun pattern, found
 * here: http://www.conwaylife.com/wiki/Gosper_glider_gun
 * ** Parameters: 2D array
 * ** Pre-Conditions: 2D array is initialized
 * ** Post-Conditions: 2D array contains the initial starting configuration
 * to create a glider gun
 * *********************************************************************/ 

void glider_gun(int gen[ROW][COL]) {

        gen[6][2] = 1;
        gen[6][3] = 1;
        gen[7][2] = 1;
        gen[7][3] = 1;

        gen[4][13] = 1;
        gen[4][14] = 1;
        gen[5][12] = 1;
        gen[6][11] = 1;
        gen[7][11] = 1;
        gen[8][11] = 1;
        gen[9][12] = 1;
        gen[10][13] = 1;
        gen[10][14] = 1;

        gen[7][15] = 1;
        gen[5][16] = 1;
        gen[6][17] = 1;
        gen[7][17] = 1;
        gen[8][17] = 1;
        gen[7][18] = 1;
        gen[9][16] = 1;

        gen[4][21] = 1;
        gen[4][22] = 1;
        gen[5][21] = 1;
        gen[5][22] = 1;
        gen[6][21] = 1;
        gen[6][22] = 1;
        gen[7][23] = 1;
        gen[3][23] = 1;

        gen[2][25] = 1;
        gen[3][25] = 1;
        gen[7][25] = 1;
        gen[8][25] = 1;

        gen[4][35] = 1;
        gen[5][35] = 1;
        gen[4][36] = 1;
        gen[5][36] = 1;

}

/********************************************************************* 
 * ** Function: void big_glider
 * ** Description: Fills a 2D array with the starting configuration
 * for the big glider, a pattern that travels diagonally. Found here:
 * http://www.conwaylife.com/wiki/Big_glider
 * ** Parameters: 2D array
 * ** Pre-Conditions: 2D array is initalized
 * ** Post-Conditions: 2D array contains starting configuration for
 * big glider.
 * *********************************************************************/ 


void big_glider(int gen[ROW][COL]) {

        gen[2][5] = 1;
        gen[3][5] = 1;
        gen[4][6] = 1;
        gen[2][6] = 1;
        gen[2][7] = 1;

        gen[3][8] = 1;
        gen[4][8] = 1;
        gen[3][9] = 1;
        gen[3][10] = 1;

        gen[5][2] = 1;
        gen[5][3] = 1;
        gen[6][2] = 1;
        gen[7][2] = 1;
        gen[6][4] = 1;

        gen[8][3] = 1;
        gen[8][4] = 1;
        gen[9][3] = 1;
        gen[10][3] = 1;

        gen[9][6] = 1;
        gen[11][5] = 1;
        gen[12][6] = 1;
        gen[12][6] = 1;
        gen[11][7] = 1;

        gen[6][9] = 1;
        gen[5][11] = 1;
        gen[6][12] = 1;
        gen[6][12] = 1;
        gen[7][11] = 1;

        gen[12][9] = 1;
        gen[13][10] = 1;
        gen[14][9] = 1;
        gen[14][10] = 1;
        gen[14][11] = 1;
        gen[14][12] = 1;
        gen[15][9] = 1;
        gen[15][11] = 1;
        gen[15][12] = 1;
        gen[16][10] = 1;

        gen[9][12] = 1;
        gen[10][13] = 1;
        gen[9][14] = 1;
        gen[10][14] = 1;
        gen[11][14] = 1;
        gen[12][14] = 1;
        gen[9][15] = 1;
        gen[11][15] = 1;
        gen[12][15] = 1;
        gen[10][16] = 1;

        gen[16][14] = 1;
        gen[16][15] = 1;
        gen[17][15] = 1;
        gen[17][16] = 1;
        gen[18][11] = 1;
        gen[18][13] = 1;
        gen[18][14] = 1;
        gen[18][15] = 1;
        gen[19][12] = 1;
        gen[19][15] = 1;

        gen[14][16] = 1;
        gen[15][16] = 1;
        gen[17][15] = 1;
        gen[16][17] = 1;
        gen[11][18] = 1;
        gen[13][18] = 1;
        gen[14][18] = 1;
        gen[15][18] = 1;
        gen[12][19] = 1;
        gen[15][19] = 1;

}
