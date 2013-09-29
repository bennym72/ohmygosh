#include <stdlib.h>

typedef struct {
  int x;
  int y;
} Pair;

Pair* parray;
int i ;
void foo () {
   /* ... */
  parray = (Pair*) malloc (8*sizeof(Pair));
   /* ... */

  /* TRANSLATE THE FOLLOWING 3 STATEMENTS */ 

  parray[6].x = parray[3].y;
  
  parray[i].x = parray[i].y;

  parray[i].x = parray[i-1].y + parray[i+1].y ;

  /* END OF TRANSLATION */ 

   /* ... */ 
}
