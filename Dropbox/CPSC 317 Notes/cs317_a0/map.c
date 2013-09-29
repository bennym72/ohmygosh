/*
 *  map.c
 *  Author: Jonatan Schroeder
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "map.h"

/* Function used to compare two keys. It should return 0 if keys are
   the same, a negative value if the first key is smaller than the
   second key, or a positive value if the first key is larger than the
   second key. It is defined so that if the key is changed to a
   different type, the process doesn't need to be substantially
   changed. */
int map_key_cmp(map_key key1, map_key key2) {
  return key1 - key2;
}

/* Function that converts a string representation into a key. */
map_key str_to_map_key(char *s) {
  return atoi(s);
}

/* Function that converts a string representation into a value. */
map_value str_to_map_value(char *s) {
  if (!s) return s;
  map_value v = (map_value) malloc(strlen(s)+1);
  strcpy(v, s);
  return v;
}

/* Function that prints a mapping in a simple form. */
void print_mapping(map_key key, map_value value) {
  printf("\t<%d, %s>\n", key, value);
}


/* Creates a new empty map and returns the newly created map. */
map map_create(void) {
	map map_return = 0;
	return map_return;
	
}

/* Inserts a new mapping from a key to a value in the map. If there is
   already a mapping from the given key to another value, this mapping
   must be replaced with the provided value. In this case, if the
   old_value parameter is not NULL, the old value associated to the
   key should be saved in *old_value. If there is no mapping for the
   given key, a new mapping should be created. In this case, if
   old_value is not NULL, *old_value is replaced with NULL. This
   function returns 0 if there is an error, or 1 if the mapping was
   created successfully. */
int map_insert(map *m, map_key key, map_value value, map_value *old_value) {
    struct map* temp = *m;
	// base case: empty map
	if (*m == 0) {
		map_item * pair = (map_item *) malloc(sizeof(map_item));
		printf("did we call this\n %s", value);
		pair->key = key;
		pair->value = value;
		printf("what is this %s\n", pair->value);
		map new = (map) malloc(sizeof(struct map));
		*m = new;
		(*m)->map_i = pair;
		(*m)->next = 0;
		*old_value = NULL;
		printf("what\n");
		return 1;
	} 
	
	while (temp->next !=0) {
		if (temp->map_i->key == key) {
			*old_value = temp->map_i->value;
			temp->map_i->value = value;
			return 1;
		}
		temp = temp->next;
	}
	
	if (temp->next == 0) {
		if (temp->map_i->key == key) {
			*old_value = temp->map_i->value;
			temp->map_i->value = value;
			return 1;
		} else {
			*old_value = NULL;
			map_item * map_ret = (map_item*) malloc(sizeof(map_item));
			map_ret->key = key;
			map_ret->value = value;
			map map_new = (map) malloc(sizeof(struct map));
			map_new->map_i = map_ret;
			map_new->next = 0;
			temp->next = map_new;
			return 1;
		}	
	}
	return 0;
}

/* Searches for the value associated to the given key. If the key is
   found, returns 1, and, if the value parameter is not NULL, saves
   the mapped value to *value. If the key is not found in the map,
   returns 0 and keeps *value unaltered. */
int map_lookup(map m, map_key key, map_value *value) {
	while (m != 0) {
		if (m->map_i->key == key) {
			if (m->map_i->value != NULL) 
				*value = m->map_i->value;
			return 1;
		}
		m = m->next;
	}
	return 0;
}

/* Deletes an existing mapping for the given key. If the value
   parameter is not NULL, saves the existing value in *value. Returns
   1 if there was a mapping for the given key and it was successfully
   removed, or 0 otherwise. */
int map_delete(map *m, map_key key, map_value *value) {
	struct map * temp = *m;
	struct map * prev;
	int head = 1;
	int * header = &head;
	
	if (*m == 0) {
		return 0;
	}
	
	while (temp->next != 0) {
		if (temp->map_i->key == key) {
			if (*header == 1) {
				*m = temp->next;
				if (temp->map_i->value != NULL) {
					*value = temp->map_i->value;
				}
				free(temp->map_i);
				temp->map_i = NULL;
				free(temp);
				temp = NULL;
				return 1;
			}
			prev->next = temp->next;
			if (temp->map_i->value != NULL) {
				*value = temp->map_i->value;
				}
			free(temp->map_i);
			temp->map_i = NULL;
			free(temp);
			temp = NULL;
			return 1;
		}
		*header = 0;
		prev = temp;
		temp = temp->next;
	}
	
	if (temp->next == 0) {
		if (temp->map_i->key == key) {
			if (*header == 1) {
				if (temp->map_i->value != NULL) {
					*value = temp->map_i->value;
				}
				*m = 0;
				free(temp->map_i);
				temp->map_i = NULL;
				free(temp);
				temp = NULL;
				return 1;
			}
			if (temp->map_i->value != NULL) {
				*value = temp->map_i->value;
			}
			prev->next = 0;
			free(temp->map_i);
			temp->map_i = NULL;
			free(temp);
			temp = NULL;
			return 1;
		}
	}
	
	return 0;
}

/* Applies the function f to every mapping in the map. The mappings
   must be visited in increasing order of the mapping key (as defined
   by map_key_cmp), and each mapping must be visited exactly
   once. This function can be used to print the map by calling:
   map_foreach(m, print_mapping);
 */
void map_foreach(map m, void (*f)(map_key, map_value)) {
  if (m == 0) return ;
	map_item* temp = (map_item*) malloc(sizeof(map_item));
	
	int size = 0;
	map map1 = m;
	while (map1 != 0) {
		size++;
		map1 = map1->next;
		printf("SIZE: %d", size);
		
	}
	map_value * arr = (map_value*) malloc(sizeof(map_value)*size);
	
	int q;
	for (q = 0; q < size; q++) {
		arr[q] = 0xFFFFFFFF;
		printf("%d sup", arr[q]);
	}
	
	int counter = 0;
  while (counter < size) {
  
	map_value val;
	int lowest = 2000;
	map map2 = m;
	int i;
	int contained = 0;
	while (map2 != 0) {
			for (i = 0; i < size; i++) {
				if (map2->map_i->key == arr[i]) contained = 1;
			}
			if ((lowest > map2->map_i->key) && (contained != 1)) {
				printf("lowest %d", lowest);
				lowest = map2->map_i->key;
				temp->key = lowest;
				map_lookup(m, lowest, &val);
				temp->value = val;
			}
		contained = 0;
		map2 = map2->next;
	}
	(*f) (temp->key, temp->value);
	arr[counter] = lowest;
	counter++;
	
  }
  
}


/* Frees all space occupied by the map, including all mappings and
   their values if applicable. */
void map_destroy(map m) {

	if (m == 0) return;
	
	while (m->next != 0) {
		map temp = m->next;
		free(m->map_i);
		m->map_i = NULL;
		free(m);
		m = temp;
	}
  
	if (m->next == 0) {
		free(m->map_i);
		m->map_i = NULL;
		free(m);
		m = 0;
	}
}
