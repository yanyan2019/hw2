/* dynArray.c */
#include <assert.h>
#include <stdlib.h>
#include <stdio.h>
#include "dynArray.h"

/*
 * *****************************************
 * Dynamic Array Functions
 * *****************************************
 */

/* initialize (including allocation of data array) dynamic array.*/

void initDynArr(DynArr *v, int capacity){
	v->data = (TYPE *) malloc(sizeof(TYPE) * capacity); 
	assert(v->data != NULL);
	
	v->size = 0;
	v->capacity = capacity;
}

/* Allocate and initialize dynamic array. */
DynArr * newDynArr(int cap){
	DynArr *r = (DynArr *) malloc(sizeof(DynArr));
	assert(r != NULL);

	initDynArr(r, cap);
	return r;
}


/* Deallocate data in dynamic array. */
void freeDynArr(DynArr *v){
	if(v->data != NULL){
		free(v->data);
		v->data = NULL;
	}
	v->size = 0;
	v->capacity = 0;
} 

/* Deallocate data array and the dynamic array structure. */
void deleteDynArr(DynArr *v){
	freeDynArr(v);
	free(v);
}

/* resize the underlying array to be the size cap*/
void _dynArrSetCapacity(DynArr* v, int newCap){
	int i, oldsize;

	assert(v != NULL);

	/* save old size */
	oldsize = v->size;

	/* copy data over */
	DynArr * newarray = newDynArr(newCap);

	for(i = 0; i < v->size; i++){
		newarray->data[i] = v->data[i];
		printf("copying data ");
	}
	
	/* delete old array */
	if(v != NULL){
		freeDynArr(v);
	}
	
	/* update new array into pointer */
	v->data = newarray->data;

	v->size = oldsize;
	v->capacity = newCap;
}

/* get the size of the dynamic array */
int sizeDynArr(DynArr *v){
	return v->size;
}

/* add an element to the end of the array */
void addDynArr(DynArr *v, TYPE val){
	int i;

	/* check if empty array and capacity */
	assert(v != NULL);
	if(v->size == v->capacity){
		_dynArrSetCapacity(v, 2*v->capacity);
	}

	/* find the last element in the array and insert the value */
	v->data[v->size] = val;

	/* update info */
	v->size++;
}

/* get an element from the array from a specified position */
TYPE getDynArr(DynArr *v, int pos){
	assert((v!=NULL) && (sizeDynArr(v) > pos) && (pos >= 0));
	printf("test char :%c\n", v->data[pos]);
	return v->data[pos];
}

/*put an item into dynamic array at the specific location*/
void putDynArr(DynArr *v, int pos, TYPE val){
	assert((v!=NULL) && (sizeDynArr(v) > pos) && (pos >= 0));
	v->data[pos]=val;
}

/* swap two elements in the array */
void swapDynArr(DynArr *v, int i, int  j){
	TYPE tmp;
	assert((v!=NULL) && (sizeDynArr(v) > i) && (i>= 0)&& (sizeDynArr(v) > j) && (j>= 0));
	tmp=v->data[i];
	v->data[i]=v->data[j];
	v->data[j]=tmp;
}

/* remove element at the specific location in the array. and shift the elements to fill the gap*/
void removeAtDynArr(DynArr *v, int idx){
	int i;
	assert(v != NULL && v->size > idx);

	/* fill the gap */
	for(i = idx; i < v->size-1; i++){
		v->data[idx] = v->data[idx++];	
	}

	/*update size*/
	v->size--;
}

/*
*************************************************************
* Stack Interface Functions
* ***********************************************************
*/

/* check if array is empty*/
int isEmptyDynArr(DynArr *v){
	return sizeDynArr(v) == 0?:0;
}

/* push an element onto the top of the stack*/
void pushDynArr (DynArr *v, TYPE val){
	assert((v != NULL) && (v->capacity > 0));

	if(v->size == v->capacity){
		_dynArrSetCapacity(v, v->capacity*2);
	}	

	/* insert element at the end of the array*/
	if(v->size == 0){
		v->data[0] = val;
	}else{
		v->data[v->size] = val;
	}

	/* update size */	
	v->size ++;
}

/* return the element at the top of the stack*/
TYPE topDynArr(DynArr *v){
	assert((v != NULL) && (sizeDynArr(v) > 0));
	return v->data[v->size-1];
}

/*remove the element on top of the stack*/
void popDynArr(DynArr *v){
	assert(v != NULL && v->size > 0);
	removeAtDynArr(v, v->size-1);
}

/* 
***************************************************************
* Bag Interface Functions
* *************************************************************
*/

/* check if specified value is in the collection*/
int containsDynArr(DynArr *v, TYPE val){
	/* variables */
	int i;

	/* loop to check for value */
	for(i = 0; i < v->size; i++){
		if(v->data[i] == val){
			return i;
		}
	}		

	/* return -1 if no value matched */
	return -1;
}

/* removes the first occurrence of the specified value from the collection */
void removeDynArr(DynArr *v, TYPE val){
	/* declare variables */
	int i;

	/* check if any value match val */
	if(containsDynArr(v, val) != -1){

		/* remove that element if true */
		removeAtDynArr(v, val);
	}
}
