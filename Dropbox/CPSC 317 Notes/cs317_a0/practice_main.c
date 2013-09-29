/*
 *  main.c
 *  Author: Jonatan Schroeder
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "map.h"
#include "map.c"

int main() {
	map_value value;
	value = "start";
	map m;
	m = map_create();
	
	printf("Insert 0: %d\n", map_insert(&m, 0, "ED", &value));	
	map_foreach(m, print_mapping);
	
	
	return 0;
	  // PERSONAL TEST
 }