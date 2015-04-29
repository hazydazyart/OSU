/********************************************************************* 
 * ** Program Filename: organism.h
 * ** Author: Megan Conley
 * ** Date: 2/24/2014
 * ** Description: Header file for conleyme_assn7.cpp
 * ** Input: n/a
 * ** Output: n/a
 * *********************************************************************/

#include<iostream>
#include<stdlib.h>

class Organism {

public:

/********************************************************************* 
 * ** Function: Organism constructors
 * ** Description: Part of my attempt to re-do this program more long
 * the lines of polymorphism; these constructors would be used by the
 * Ant/Doodlebug classes.
 * ** Parameters: Default: 2D char array, char
 * Non-default: 2d char array, int, int, char
 * ** Pre-Conditions: none
 * ** Post-Conditions: Creates an object that sets its coordinates,
 * displays a char in a 2D grid, sets its step count to 0, sets bool
 * dead to false, and the noEat variable to 0.
 * *********************************************************************/ 

/*
        Organism(char array[][20], char symbol) {
                this->x = rand() % 20;
                this->y = rand() % 20;
                array[x][y] = symbol;
                this->count = 0;
                this->dead = false;
                this->noEat = 0;
        }
        Organism(char array[][20], int itsX, int itsY, char symbol) {
                this->x = itsX;
                this->y = itsY;
                array[x][y] = symbol;
                this->count = 0;
                this->dead = false;
                this->noEat = 0;
        }
	~Organism() {}
*/

/********************************************************************* 
 * ** Function: occupied_down/up/left/right
 * ** Description: These functions check if the adjacent cells are
 * occupied (or are the edge of the grid) and returns true, otherwise
 * returns false.
 * ** Parameters: 2d char array 
 * ** Pre-Conditions: 2d char array is initialized
 * ** Post-Conditions: Returns result of logic statements
 * *********************************************************************/ 

	bool occupied_down(char array[][20]) {
        	if ((this->x) == 19 || array[x+1][y] != '.') {
                	return true;
	        }
        	return false;
	}
        bool occupied_up(char array[][20]) {
                if ((this->x) == 0 || array[x-1][y] != '.') {
                        return true;
                }
                return false;
        }
        bool occupied_left(char array[][20]) {
                if ((this->y) == 0 || array[x][y-1] != '.') {
                        return true;
                }
                return false;
        }
        bool occupied_right(char array[][20]) {
                if ((this->y) == 19 || array[x][y+1] != '.') {
                        return true;
                }
                return false;
        }

/********************************************************************* 
 * ** Function: isDead
 * ** Description: Accessor function for dead variable
 * ** Parameters: none
 * ** Pre-Conditions: dead is initialized to some value
 * ** Post-Conditions: returns bool
 * *********************************************************************/ 

	virtual bool isDead() {
		return this->dead;
	}

/********************************************************************* 
 * ** Function: die
 * ** Description: Removes an object from the char array
 * ** Parameters: 2d char array
 * ** Pre-Conditions: Object has x and y variables initialized to some value
 * within 2d char array
 * ** Post-Conditions: Object's current x and y values set to display
 * '.' in array; member bool dead is set to true.
 * *********************************************************************/ 

	virtual void die(char array[][20]) {
		array[this->x][this->y] = '.';
		dead = true;
	}

/********************************************************************* 
 * ** Function: move
 * ** Description: Direction of movement is randomly chosen, then
 * object's current location is replaced by '.' and target cell is
 * replaced by object's char symbol ('O' or 'X')
 * ** Parameters: 2d char array, char
 * ** Pre-Conditions: Object exists and has x/y coordinates initialized
 * ** Post-Conditions: Object is moved if there is an empty space in
 * the randomly chosen direction; otherwise it does nothing.
 * *********************************************************************/ 

        virtual void move(char array[][20], char symbol) {
		int direction = rand() % 4 + 1;
		if (direction == 1 && !occupied_down(array)) { // move down
			array[this->x][this->y] = '.';
			this->x += 1;
			array[this->x][this->y] = symbol;
			count++;
		}
		if (direction == 2 && !occupied_up(array)) { // move up
			array[this->x][this->y] = '.';
			this->x -= 1;
			array[this->x][this->y] = symbol;
			count++;
		}
                if (direction == 3 && !occupied_left(array)) { // move left
                        array[this->x][this->y] = '.';
                        this->y -= 1;
                        array[this->x][this->y] = symbol;
                        count++;
                }
                if (direction == 4 && !occupied_right(array)) { // move right
                        array[this->x][this->y] = '.';
                        this->y += 1;
                        array[this->x][this->y] = symbol;
                        count++;
                }
	}

/********************************************************************* 
 * ** Function: getX, getY
 * ** Description: Accessor function for x/y variable
 * ** Parameters: none
 * ** Pre-Conditions: Object exists and x/y is initialized
 * ** Post-Conditions: Returns value of x/y
 * *********************************************************************/ 

	virtual int getX() {
		return this->x;
	}
	virtual int getY() {
		return this->y;
	}

protected:
	bool dead;
        int count;
	int x;
	int y;
	int noEat;
};

class Ant : public Organism {

public:

/********************************************************************* 
 * ** Function: Ant 
 * ** Description: Constructors for Ant object, same as the constructors
 * for the base clase
 * ** Parameters: Default: 2d char array
 * Non-default: 2d char array, int, int
 * ** Pre-Conditions: none
 * ** Post-Conditions: Ant object is initialized
 * *********************************************************************/ 

        Ant(char array[][20]) {
		this->x = rand() % 20;
		this->y = rand() % 20;
		array[x][y] = 'O';
		this->count = 0;
		this->dead = false;
	}
	Ant(char array[][20], int itsX, int itsY) {
		this->x = itsX;
		this->y = itsY;
                array[x][y] = 'O';
                this->count = 0;
		this->dead = false;
	}
        ~Ant() {}

/********************************************************************* 
 * ** Function: getX, getY
 * ** Description: Accessor functions for x/y variables, calls base
 * class version of function
 * ** Parameters: None
 * ** Pre-Conditions: Object's x/y variables are initialized
 * ** Post-Conditions: returns x/y as int
 * *********************************************************************/ 

	int getX() {
		return Organism::getX();
	}
	int getY() {
		return Organism::getY();
	}

/********************************************************************* 
 * ** Function: move
 * ** Description: Ant class override for virtual move function
 * ** Parameters: 2d char array, char
 * ** Pre-Conditions: Ant object is initialized
 * ** Post-Conditions: Calls base class move function
 * *********************************************************************/ 

        void move(char array[][20], char symbol) {
		Organism::move(array, 'O');
	}
/********************************************************************* 
 * ** Function: breed
 * ** Description: Once the object takes its 3rd step, it attempts to
 * push back a new object into the Ant vector with the coordinates set
 * to an empty, adjacent cell. If none exist, the step counter resets
 * with no new object spawned.
 * ** Parameters: 2d char array, Ant vector
 * ** Pre-Conditions: Ant vector has at least one object that has been
 * initialized
 * ** Post-Conditions: If conditions are met, a new object is created
 * and pushed to the end of the Ant vector
 * *********************************************************************/ 

	void breed(char array[][20], std::vector<Ant>& colony) {
		if (this->count == 2) {
        		if(!occupied_down(array)) {
                		Ant temp(array, x+1, y);
	              		colony.push_back(temp);
        		} else if(!occupied_up(array)) {
                		Ant temp(array, x-1, y);
	                	colony.push_back(temp);
        		} else if(!occupied_right(array)) {
                		Ant temp(array, x, y+1);
	                	colony.push_back(temp);
	        	} else if(!occupied_left(array)) {
        	        	Ant temp(array, x, y-1);
	        	        colony.push_back(temp);
			}
			this->count = 0;
		}
		
	}

/********************************************************************* 
 * ** Function: die
 * ** Description: Removes Ant object from array
 * ** Parameters: 2d char array
 * ** Pre-Conditions: Ant object is initialized
 * ** Post-Conditions: Calls base class die function
 * *********************************************************************/ 
	void die(char array[][20]) {
		Organism::die(array);
	}
};

class Doodlebug : public Organism {
 
public:

/********************************************************************* 
 * ** Function: Doodlebug 
 * ** Description: Constructors for Doodlebug class
 * ** Parameters: Default: 2d char array
 * Non-default: 2d char array, int, int
 * ** Pre-Conditions: None
 * ** Post-Conditions: Doodlebug object is initialized
 * *********************************************************************/ 

        Doodlebug(char array[][20]) {
                this->x = rand() % 20;
                this->y = rand() % 20;
                array[x][y] = 'X';
                this->count = 0;
		this->dead = false;
		this->noEat = 0;
	}
        Doodlebug(char array[][20], int itsX, int itsY) {
                this->x = itsX;
                this->y = itsY;
                array[x][y] = 'X';
                this->count = 0;
		this->dead = false;
                this->noEat = 0;
	}
	~Doodlebug() {}

/********************************************************************* 
 * ** Function: move
 * ** Description: Doodlebug override of base class virtual function
 * ** Parameters: 2d char array, char
 * ** Pre-Conditions: Doodlebug object has been initialized
 * ** Post-Conditions: Calls base class move function; increases the
 * number of steps taken without calling the eat function
 * *********************************************************************/ 

	void move(char array[][20], char symbol) {
		Organism::move(array, symbol);
		this->noEat++;
	}

/********************************************************************* 
 * ** Function: breed
 * ** Description: Creates a new Doodlebug object if a current Doodlebug 
 * object has  taken 7 steps and there is an empty adjacent cell.
 * ** Parameters: 2d char array, Doodlebug vector
 * ** Pre-Conditions: Doodlebug vector has at least one object
 * ** Post-Conditions: Pushes back a new object to the vector if conditions
 * are met.
 * *********************************************************************/ 

        void breed(char array[][20], std::vector<Doodlebug>& dbugs) {
                if (this->count == 7) {
                        if(!occupied_down(array)) {
                                Doodlebug temp(array, x+1, y);
                                dbugs.push_back(temp);
                        } else if(!occupied_up(array)) {
                                Doodlebug temp(array, x-1, y);
                                dbugs.push_back(temp);
                        } else if(!occupied_right(array)) {
                                Doodlebug temp(array, x, y+1);
                                dbugs.push_back(temp);
                        } else if(!occupied_left(array)) {
                                Doodlebug temp(array, x, y-1);
                                dbugs.push_back(temp);
			}
			this->count = 0;
                }

        }

/********************************************************************* 
 * ** Function: die
 * ** Description: Removes a Doodlebug from the 2d char array after the
 * third step taken without calling the eat function
 * ** Parameters: 2d char array
 * ** Pre-Conditions: Doodlebug object has been initialized
 * ** Post-Conditions: Doodlebug object removed from 2d char array
 * *********************************************************************/ 

        void die(char array[][20]) {
		if (this->noEat == 2) {
        	        Organism::die(array);
		}
        }

/********************************************************************* 
 * ** Function: eat
 * ** Description: If there is an Ant object in an adjacent cell, it
 * calls the Ant::die function on it, resets the Doodlebug variable noEat
 * to 0, and moves the Doodlebug object to the cell that used to hold the
 * Ant object. If there are no Ant objects, it calls the move function.
 * ** Parameters: 2d char array, Ant vector
 * ** Pre-Conditions: Doodlebug object has been initialized
 * ** Post-Conditions: If conditions are met, adjacent Ant object
 * is removed.
 * *********************************************************************/ 

	void eat(char array[][20], std::vector<Ant>& colony) {
		if (array[this->x+1][y] == 'O') {
			for(std::size_t i = 0; i < colony.size(); ++i) {
				if (colony[i].getX() == this->x+1 && colony[i].getY() == this->y) {
					colony[i].die(array);
				}
			}
                        array[this->x][this->y] = '.';
                        this->x += 1;
                        array[this->x][this->y] = 'X';
                        this->noEat = 0;
			this->count++;
		} else if (array[x-1][y] == 'O') {
                        for(std::size_t i = 0; i < colony.size(); ++i) {
                                if (colony[i].getX() == this->x-1 && colony[i].getY() == this->y) {
                                        colony[i].die(array);
                                }
			}
                        array[this->x][this->y] = '.';
                        this->x -= 1;
                        array[this->x][this->y] = 'X';
                        this->noEat = 0;
			this->count++;
                } else if (array[x][y+1] == 'O') {
                        for(std::size_t i = 0; i < colony.size(); ++i) {
                                if (colony[i].getX() == this->x && colony[i].getY() == this->y+1) {
                                        colony[i].die(array);
                                }
			}
                        array[this->x][this->y] = '.';
                        this->y += 1;
                        array[this->x][this->y] = 'X';
                        this->noEat = 0;
			this->count++;
                } else if (array[x][y-1] == 'O') {
                        for(std::size_t i = 0; i < colony.size(); ++i) {
                                if (colony[i].getX() == this->x && colony[i].getY() == this->y-1) {
                                        colony[i].die(array);
                                }
			}
                        array[this->x][this->y] = '.';
                        this->y -= 1;
                        array[this->x][this->y] = 'X';
                        this->noEat = 0;
			this->count++;
		} else {
			move(array, 'X');
		}
	}
};
