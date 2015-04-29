/*	dynamicArray.c: Dynamic Array implementation. */
// Megan Conley
// 4/20/2014
// conleyme@oregonstate.edu
// Assignment 2: dynamicArray.c

#include <assert.h>
#include <stdlib.h>
#include <stdio.h>
#include "dynamicArray.h"

struct DynArr
{
	TYPE *data;		/* pointer to the data array */
	int size;		/* Number of elements in the array */
	int capacity;	/* capacity ofthe array */
};


/* ************************************************************************
	Dynamic Array Functions
************************************************************************ */

/* Initialize (including allocation of data array) dynamic array.

	param: 	v		pointer to the dynamic array
	param:	cap 	capacity of the dynamic array
	pre:	v is not null
	post:	internal data array can hold cap elements
	post:	v->data is not null
*/
void initDynArr(DynArr *v, int capacity)
{
	assert(capacity > 0);
	assert(v!= 0);
	v->data = (TYPE *) malloc(sizeof(TYPE) * capacity);
	assert(v->data != 0);
	v->size = 0;
	v->capacity = capacity;
}

/* Allocate and initialize dynamic array.

	param:	cap 	desired capacity for the dyn array
	pre:	none
	post:	none
	ret:	a non-null pointer to a dynArr of cap capacity
			and 0 elements in it.
*/
DynArr* createDynArr(int cap)
{
	assert(cap > 0);
	DynArr *r = (DynArr *)malloc(sizeof( DynArr));
	assert(r != 0);
	initDynArr(r,cap);
	return r;
}

/* Deallocate data array in dynamic array.

	param: 	v		pointer to the dynamic array
	pre:	none
	post:	d.data points to null
	post:	size and capacity are 0
	post:	the memory used by v->data is freed
*/
void freeDynArr(DynArr *v)
{
	if(v->data != 0)
	{
		free(v->data); 	/* free the space on the heap */
		v->data = 0;   	/* make it point to null */
	}
	v->size = 0;
	v->capacity = 0;
}

/* Deallocate data array and the dynamic array ure.

	param: 	v		pointer to the dynamic array
	pre:	none
	post:	the memory used by v->data is freed
	post:	the memory used by d is freed
*/
void deleteDynArr(DynArr *v)
{
	freeDynArr(v);
	free(v);
}

/* Resizes the underlying array to be the size cap

	param: 	v		pointer to the dynamic array
	param:	cap		the new desired capacity
	pre:	v is not null
	post:	v has capacity newCap
*/
void _dynArrSetCapacity(DynArr *v, int newCap)
{
	DynArr *temp = (DynArr *)malloc(sizeof( DynArr));


	temp->data = (TYPE *) malloc(sizeof(TYPE) * newCap);


	assert(temp->data != 0);

	temp->size = v->size;


	temp->capacity = newCap;

	for (int i = 0; i < temp->size; i++) {
		temp->data[i] = v->data[i];
	}

	v = temp;
	v->data = temp->data;
	v->capacity = temp->capacity;

	freeDynArr(temp);

}

/* Get the size of the dynamic array

	param: 	v		pointer to the dynamic array
	pre:	v is not null
	post:	none
	ret:	the size of the dynamic array
*/
int sizeDynArr(DynArr *v)
{
	return v->size;
}

/* 	Adds an element to the end of the dynamic array

	param: 	v		pointer to the dynamic array
	param:	val		the value to add to the end of the dynamic array
	pre:	the dynArry is not null
	post:	size increases by 1
	post:	if reached capacity, capacity is doubled
	post:	val is in the last utilized position in the array
*/
void addDynArr(DynArr *v, TYPE val){
    assert(v != 0);
    if (v->size + 1 > v->capacity) {
        _dynArrSetCapacity(v, 2 * v->size);
	}

    v->data[v->size] = val;

    v->size++;
}

/*	Get an element from the dynamic array from a specified position

	param: 	v		pointer to the dynamic array
	param:	pos		integer index to get the element from
	pre:	v is not null
	pre:	v is not empty
	pre:	pos < size of the dyn array and >= 0
	post:	no changes to the dyn Array
	ret:	value stored at index pos
*/

TYPE getDynArr(DynArr *v, int pos)
{
	/* Check position is within size of array and that v is not empty */
	assert(pos <= v->size && pos >= 0 && v != 0);

	return v->data[pos];

}

/*	Put an item into the dynamic array at the specified location,
	overwriting the element that was there

	param: 	v		pointer to the dynamic array
	param:	pos		the index to put the value into
	param:	val		the value to insert
	pre:	v is not null
	pre:	v is not empty
	pre:	pos >= 0 and pos < size of the array
	post:	index pos contains new value, val
*/
void putDynArr(DynArr *v, int pos, TYPE val)
{
    assert(pos >= 0 && pos < v->size && v != 0);

	v->data[pos] = val;
}

/*	Swap two specified elements in the dynamic array

	param: 	v		pointer to the dynamic array
	param:	i,j		the elements to be swapped
	pre:	v is not null
	pre:	v is not empty
	pre:	i, j >= 0 and i,j < size of the dynamic array
	post:	index i now holds the value at j and index j now holds the value at i
*/
void swapDynArr(DynArr *v, int i, int  j)
{
	TYPE temp = v->data[i];
	v->data[i] = v->data[j];
	v->data[j] = temp;
}

/*	Remove the element at the specified location from the array,
	shifts other elements back one to fill the gap

	param: 	v		pointer to the dynamic array
	param:	idx		location of element to remove
	pre:	v is not null
	pre:	v is not empty
	pre:	idx < size and idx >= 0
	post:	the element at idx is removed
	post:	the elements past idx are moved back one
*/


void removeAtDynArr(DynArr *v, int idx)
{
    /* Check that index is within bounds */
	assert(idx < v->size && idx >= 0 && v != 0);

/* Copy values to the left by one space */
	for(int i = idx; i < v->size; i++) {
		v->data[i] = v->data[i+1];
	}
	v->size--;
}

/* ************************************************************************
	Stack Interface Functions
************************************************************************ */

/*	Returns boolean (encoded in an int) demonstrating whether or not the
	dynamic array stack has an item on it.

	param:	v		pointer to the dynamic array
	pre:	the dynArr is not null
	post:	none
	ret:	1 if empty, otherwise 0
*/
int isEmptyDynArr(DynArr *v)
{
	if(v == 0) {
        return 1;
	}
	return 0;
}

/* 	Push an element onto the top of the stack

	param:	v		pointer to the dynamic array
	param:	val		the value to push onto the stack
	pre:	v is not null
	post:	size increases by 1
			if reached capacity, capacity is doubled
			val is on the top of the stack
*/

void pushDynArr(DynArr *v, TYPE val)
{
	assert(v != 0);

    if(v->size + 1 > v->capacity) {
        _dynArrSetCapacity(v, 2 * v->size);
	}

    v->size++;
    v->data[v->size-1] = val;
}

/*	Returns the element at the top of the stack

	param:	v		pointer to the dynamic array
	pre:	v is not null
	pre:	v is not empty
	post:	no changes to the stack
*/

TYPE topDynArr(DynArr *v)
{
    assert(v != 0 && v->size > 0);

    return v->data[v->size-1];
}

/* Removes the element on top of the stack

	param:	v		pointer to the dynamic array
	pre:	v is not null
	pre:	v is not empty
	post:	size is decremented by 1
			the top has been removed
*/

void popDynArr(DynArr *v)
{
	assert(v != 0);

	removeAtDynArr(v, v->size-1);
}

/* ************************************************************************
	Bag Interface Functions
************************************************************************ */

/*	Returns boolean (encoded as an int) demonstrating whether or not
	the specified value is in the collection
	true = 1
	false = 0

	param:	v		pointer to the dynamic array
	param:	val		the value to look for in the bag
	pre:	v is not null
	pre:	v is not empty
	post:	no changes to the bag
*/
int containsDynArr(DynArr *v, TYPE val)
{
	for(int i = 0; i < v->size; i++) {
        if(v->data[i] == val) {
            return 1;
        }
	}
	return 0;

}

/*	Removes the first occurrence of the specified value from the collection
	if it occurs

	param:	v		pointer to the dynamic array
	param:	val		the value to remove from the array
	pre:	v is not null
	pre:	v is not empty
	post:	val has been removed
	post:	size of the bag is reduced by 1
*/

void removeDynArr(DynArr *v, TYPE val)
{
    int pos;
	for(int i = 0; i < v->size; i++) {
        if(v->data[i] == val) {
            pos = i;
            }
	}

	removeAtDynArr(v, pos);
}
/*
void assertTrue(int predicate, char *message)
{
	printf("%s: ", message);
	if (predicate)
		printf("PASSED\n");
	else
		printf("FAILED\n");
}


// this main function contains some

int main(int argc, char* argv[]){

	DynArr *dyn;
	dyn = createDynArr(2);

	printf("\n\nTesting addDynArr...\n");
	addDynArr(dyn, 3);
	addDynArr(dyn, 4);
	addDynArr(dyn, 10);
	addDynArr(dyn, 5);
	addDynArr(dyn, 6);

	printf("The array's content: [3,4,10,5,6]\n");
	assertTrue(EQ(getDynArr(dyn, 0), 3), "Test 1st element == 3\n");
	assertTrue(EQ(getDynArr(dyn, 1), 4), "Test 2nd element == 4\n");
	assertTrue(EQ(getDynArr(dyn, 2), 10), "Test 3rd element == 10\n");
	assertTrue(EQ(getDynArr(dyn, 3), 5), "Test 4th element == 5\n");
	assertTrue(EQ(getDynArr(dyn, 4), 6), "Test 5th element == 6\n");
	assertTrue(sizeDynArr(dyn) == 5, "Test size = 5\n");


	printf("\n\nTesting putDynArr...\nCalling putDynArr(dyn, 2, 7)\n");
	putDynArr(dyn, 2, 7);
	printf("The array's content: [3,4,7,5,6]\n");
	assertTrue(EQ(getDynArr(dyn, 2), 7), "Test 3rd element == 7");
	assertTrue(sizeDynArr(dyn) == 5, "Test size = 5");

	printf("\n\nTesting swapDynArr...\nCalling swapDynArr(dyn, 2, 4)\n");
	swapDynArr(dyn, 2, 4);
	printf("The array's content: [3,4,6,5,7]\n");
	assertTrue(EQ(getDynArr(dyn, 2), 6), "Test 3rd element == 6");
	assertTrue(EQ(getDynArr(dyn, 4), 7), "Test 5th element == 7");

	printf("\n\nTesting removeAtDynArr...\nCalling removeAtDynArr(dyn, 1)\n");
	removeAtDynArr(dyn, 1);
	printf("The array's content: [3,6,5,7]\n");
	assertTrue(EQ(getDynArr(dyn, 0), 3), "Test 1st element == 3");
	assertTrue(EQ(getDynArr(dyn, 3), 7), "Test 4th element == 7");
	assertTrue(sizeDynArr(dyn) == 4, "Test size = 4");

	printf("\n\nTesting stack interface...\n");
	printf("The stack's content: [3,6,5,7] <- top\n");
	assertTrue(!isEmptyDynArr(dyn), "Testing isEmptyDynArr");
	assertTrue(EQ(topDynArr(dyn), 7), "Test topDynArr == 7");

	popDynArr(dyn);
	printf("Poping...\nThe stack's content: [3,6,5] <- top\n");
	assertTrue(EQ(topDynArr(dyn), 5), "Test topDynArr == 5");

	pushDynArr(dyn, 9);
	printf("Pushing 9...\nThe stack's content: [3,6,5,9] <- top\n");
	assertTrue(EQ(topDynArr(dyn), 9), "Test topDynArr == 9");

	printf("\n\nTesting bag interface...\n");
	printf("The bag's content: [3,6,5,9]\n");
	assertTrue(containsDynArr(dyn, 3), "Test containing 3");
	assertTrue(containsDynArr(dyn, 6), "Test containing 6");
	assertTrue(containsDynArr(dyn, 5), "Test containing 5");
	assertTrue(containsDynArr(dyn, 9), "Test containing 9");
	assertTrue(!containsDynArr(dyn, 7), "Test not containing 7");

	removeDynArr(dyn, 3);
	printf("Removing 3...\nThe stack's content: [6,5,9]\n");
	assertTrue(!containsDynArr(dyn, 3), "Test not containing 3");

	return 0;
}
*/
