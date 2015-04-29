// Megan Conley
// conleyme@onid.oregonstate.edu
// 4/27/2014
// Assignment 3 - linked list implementation

#include "linkedList.h"
#include <assert.h>
#include <stdlib.h>
#include <stdio.h>


/* Double Link*/
struct DLink {
	TYPE value;
	struct DLink * next;
	struct DLink * prev;
};

/* Double Linked List with Head and Tail Sentinels  */

struct linkedList{
	int size;
	struct DLink *firstLink;
	struct DLink *lastLink;
};

/*
	initList
	param lst the linkedList
	pre: lst is not null
	post: lst size is 0
*/

void _initList (struct linkedList *lst) {
	lst->firstLink = (struct DLink *) malloc(sizeof(struct DLink));	
	assert(lst->firstLink != 0);	
	lst->lastLink = (struct DLink *) malloc(sizeof(struct DLink));	
	assert(lst->lastLink != 0);	
	lst->firstLink->next = lst->lastLink;
	lst->lastLink->prev = lst->firstLink;
	lst->size = 0;
}

/*
 createList
 param: none
 pre: none
 post: firstLink and lastLink reference sentinels
 */

struct linkedList *createLinkedList()
{
	struct linkedList *newList = malloc(sizeof(struct linkedList));
	_initList(newList);
	return(newList);
}

/*
	_addLinkBeforeBefore
	param: lst the linkedList
	param: l the  link to add before
	param: v the value to add
	pre: lst is not null
	pre: l is not null
	post: lst is not empty
*/

/* Adds Before the provided link, l */

void _addLinkBefore(struct linkedList *lst, struct DLink *l, TYPE v)
{
	assert(lst != NULL);
	assert(l != NULL);
        struct DLink *newLnk = (struct DLink *) malloc(sizeof(struct DLink));
	newLnk->value = v;

	newLnk->next = l;
	newLnk->prev = l->prev;
	l->prev = newLnk;

	lst->size++;
	
}

/*
	addFrontList
	param: lst the linkedList
	param: e the element to be added
	pre: lst is not null
	post: lst is not empty, increased size by 1
*/

void addFrontList(struct linkedList *lst, TYPE e)
{

	struct DLink * lnk = (struct DLink *) malloc(sizeof(struct DLink));
	assert(lnk != NULL);
	lnk->value = e;
	lnk->next = lst->firstLink->next;
	lnk->prev = lst->firstLink;
	lst->firstLink->next = lnk;
	lst->size++;
	
}

/*
	addBackList
	param: lst the linkedList
	param: e the element to be added
	pre: lst is not null
	post: lst is not empty, increased size by 1
*/

void addBackList(struct linkedList *lst, TYPE e) {
  
        struct DLink * lnk = (struct DLink *) malloc(sizeof(struct DLink));
        assert(lnk != NULL);
        lnk->value = e;
        lnk->next = lst->lastLink;
        lnk->prev = lst->lastLink->prev;
        lst->lastLink->prev = lnk;
	lst->size++;
}

/*
	frontList
	param: lst the linkedList
	pre: lst is not null
	pre: lst is not empty
	post: none
*/

TYPE frontList (struct linkedList *lst) {
	assert(lst != NULL);
	
	return(lst->firstLink->next->value);
}

/*
	backList
	param: lst the linkedList
	pre: lst is not null
	pre: lst is not empty
	post: lst is not empty
*/

TYPE backList(struct linkedList *lst)
{
	assert(lst != NULL);
	return(lst->lastLink->prev->value);
}

/*
	_removeLink
	param: lst the linkedList
	param: l the linke to be removed
	pre: lst is not null
	pre: l is not null
	post: lst size is reduced by 1
*/

void _removeLink(struct linkedList *lst, struct DLink *l)
{

	l->next->prev = l->prev;
	l->prev->next = l->next;
	free(l);
	lst->size--;
	
}

/*
	removeFrontList
	param: lst the linkedList
	pre:lst is not null
	pre: lst is not empty
	post: size is reduced by 1
*/

void removeFrontList(struct linkedList *lst) {
	struct DLink * temp = (struct DLink *) malloc(sizeof(struct DLink));
	temp = lst->firstLink;
	lst->firstLink = lst->firstLink->next;

	if(lst->firstLink->next == 0) {
		lst->lastLink = lst->firstLink;
	}

	free(temp);

}

/*
	removeBackList
	param: lst the linkedList
	pre: lst is not null
	pre:lst is not empty
	post: size reduced by 1
*/

void removeBackList(struct linkedList *lst)
{	
        struct DLink * temp = (struct DLink *) malloc(sizeof(struct DLink));
        temp = lst->lastLink;
	lst->lastLink = lst->lastLink->prev;
	
	if(lst->lastLink->prev == 0) {
		lst->firstLink = lst->lastLink;
	}

	free(temp);
	
}

/*
	isEmptyList
	param: lst the linkedList
	pre: lst is not null
	post: none
*/

int isEmptyList(struct linkedList *lst) {
 	if(lst->firstLink == lst->lastLink) {
		return 1;
	} else {
		return 0;
	}
}


/* Function to print list
 Pre: lst is not null
 */
void _printList(struct linkedList* lst)
{
	assert(lst != NULL);
        struct DLink * conductor = lst->firstLink;

	while(conductor->next != lst->lastLink) {
		conductor = conductor->next;
		printf("%d \n", conductor->value);
	}
}

/* 
	Add an item to the bag
	param: 	lst		pointer to the bag
	param: 	v		value to be added
	pre:	lst is not null
	post:	a link storing val is added to the bag
 */
void addList(struct linkedList *lst, TYPE v)
{
	addFrontList(lst, v);

}

/*	Returns boolean (encoded as an int) demonstrating whether or not
	the specified value is in the collection
	true = 1
	false = 0

	param:	lst		pointer to the bag
	param:	e		the value to look for in the bag
	pre:	lst is not null
	pre:	lst is not empty
	post:	no changes to the bag
*/
int containsList (struct linkedList *lst, TYPE e) {

        struct DLink * conductor = (struct DLink *) malloc(sizeof(struct DLink));
        conductor = lst->firstLink->next;

        while(conductor->next != lst->lastLink) {

		if(conductor->value == e) {
			return 1;
		}
		conductor = conductor->next;
	}
	return 0;
}

/*	Removes the first occurrence of the specified value from the collection
	if it occurs

	param:	lst		pointer to the bag
	param:	e		the value to be removed from the bag
	pre:	lst is not null
	pre:	lst is not empty
	post:	e has been removed
	post:	size of the bag is reduced by 1
*/
void removeList (struct linkedList *lst, TYPE e) {

        struct DLink * conductor = (struct DLink *) malloc(sizeof(struct DLink));
        conductor = lst->firstLink->next;

        while(conductor->next != 0) {
		if(conductor->value == e) {
			_removeLink(lst, conductor);
			
		} else {
			conductor = conductor->next;
		}
	}
}

void deleteLinkedList (struct linkedList *lst) {

        struct DLink * current = lst->firstLink;
        struct DLink * next = (struct DLink *) malloc(sizeof(struct DLink));

	while(current != 0) {
		next = current->next;
		free(current);
		current = next;
	}

	lst->firstLink = 0;
	lst->size = 0;

}
