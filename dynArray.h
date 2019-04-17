// dynArray.h

#include <stdio.h>
#include <stdlib.h>

#ifndef DYNAMIC_ARRAY_INCLUDED
#define DYNAMIC_ARRAY_INCLUDED

#ifndef __TYPE
#define __TYPE
# define TYPE double
# define TYPE_SIZE sizeof(TYPE)
#endif

# ifndef LT
# define LT(A, B) ((A) < (B))
# endif

# ifndef EQ
# define EQ(A, B) ((A) == (B))
# endif

struct DynArr{
	TYPE *data;
	int size;
	int capacity;
};

typedef struct DynArr DynArr;

void initDynArr(DynArr *v, int capacity);
DynArr *newDynArr(int cap);
void freeDynArr(DynArr *v);
void deleteDynArr(DynArr *v);
int sizeDynArr(DynArr *v);
void addDynArr(DynArr *v, TYPE val);
TYPE getDynArr(DynArr *v, int pos);
void putDynArr(DynArr *v, int pos, TYPE val);
void swapDynArr(DynArr *v, int i, int j);
void removeAtDynArr(DynArr *v, int idx);
void _dynArrSetCapacity(DynArr *v, itn newCap);


/*stack */
int isEmptyDynArr(DynArr *v);
void pushDynArr(DynArr *v, TYPE val);
TYPE topDynArr(DynArr *v);
void popDynArr(DynArr *v);

/* bag */
int containsDynArr(DynArr *v, TYPE val);
void removeDynArr(DynArr *v, TYPE val);

/* bag2 */
void bag2set(struct DynArr *da);

#endif
