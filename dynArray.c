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
	assert(v->data != 0);
	
	v->size = 0;
	v->capacity = capacity;
}

/* Allocate and initialize dynamic array. */
DynArr * newDynArr(int cap){
	DynArr *r = (DynArr *) malloc(sizeof(DynArr));
	assert(r != 0);

	initDynArr(r, cap):
	return r;
}


/* Deallocate data in dynamic array. */
void freeDynArr(DynArr *v){
	if(v->data != 0){
		free(v->data);
		v->data = 0;
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
void _dynArrSetCapacity(DynArr *v, int newCap){
	int i, oldsize;

	assert(v != NULL);

	/* save old size */
	oldsize = v->size;

	/* copy data over */
	DynArr * newarray = newDynArr(newCap);
	for(i = 0; i < v->size; i++){
		newarray[i] = v->data[i];
	}
	
	/* delete old array */
	freeDynArr(v);
	
	/* update new array into pointer */
	v = newarray;
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
	return v->data[pos];
}

/*put an item into dynamic array at the specific location*/
void putDynArr(DynArr *v, int pos, TYPE val){
	assert((v!=NULL) && (sizeDynArr(v) > pos) && (pos >= 0));
	v->data[pos]=val;
}

/* swap two elements in he array */
void swapDynArr(DynArr *v, int i, int  j){
	TYPE tmp;
	assert((v!=NULL) && (sizeDynArr(v) > i) && (i>= 0)&& (sizeDynArr(v) > j) && (j>= 0));
	tmp=v->data[i];
	v->data[i]=v->data[j];
	v->data[j]=tmp;
}
