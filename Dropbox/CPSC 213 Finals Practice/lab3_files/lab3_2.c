#include <stdlib.h>

typedef struct {
  int size;
  int * arr;
} Tuple;

Tuple* ituple;

void foo () {
  /* ... */ 
  ituple = (Tuple*) malloc (sizeof(Tuple));
  
  ituple->arr = (int*) malloc (5*sizeof(int));
  /* ... */

  /* TRANSLATE THE FOLLOWING 3 STATEMENTS */ 
  ituple->size = 5;

  ituple->arr[3] = ituple->arr[4];

  ituple->arr[ituple->size - 3] = ituple->arr[ituple->size - 1];
  
  /* END OF TRANSLATION */ 
	
  /* ... */
}
