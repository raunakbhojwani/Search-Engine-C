/* 
 * hashtable.c - simple hashtable module
 *
 * Raunak Bhojwani, April 2016
 */


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "list.h"
#include "jhash.c"
#include "hashtable.h"


/**************** local types ****************/
typedef struct hashtable {
  	int num_slots;     // number of slots in the hastable
    list_t **slots;     // double pointer to list of list modules
} hashtable_t;

/**************** hashtable_new() ****************/
// create new hashtable, return pointer to the new hashtable
hashtable_t *hashtable_new(const int num_slots)
{
  if (num_slots <= 0) {         // catch error if num slots is too small
    printf("%s\n", "Error: please enter a num_slots that is greater than 0");
    exit(1);
  }
  hashtable_t *hashtable;

  // allocate memory for the hashtable and all its slots
  if ((hashtable = malloc(5 * sizeof(hashtable_t))) == NULL) {
    free(hashtable);
    return NULL;
  }

  if ((hashtable->slots = (malloc(sizeof(list_t*) * num_slots))) == NULL) {
    free(hashtable->slots);
    free(hashtable);
    return NULL;
  }         

  for (int i = 0; i < num_slots; i++) {               // create new empty lists in each slot
    // hashtable->slots[i] = malloc(sizeof(list_t));
    hashtable->slots[i] = list_new();
  }

  hashtable->num_slots = num_slots;

	return hashtable;
}

/**************** hashtable_insert() ****************/
/* 
 * If key exists, return false;
 * If key does not exist, insert new item and return true
 * If ht is NULL, or you encounter other error, return false.
 * Copy the key string
 */
bool hashtable_insert(hashtable_t *ht, char *key, void *data)
{
  if (ht == NULL) {
    return false;
  }

  int slot = JenkinsHash(key, ht->num_slots);             // use hash function to get slot number, and insert item there
  if (list_insert(ht->slots[slot], key, data)) { 
    return true;
  }
  return false;
}

/**************** hashtable_find() ****************/
// find the item associate with the k=given key, return data associated with item if successful
// return null otherwise

void *hashtable_find(hashtable_t *ht, char *key)
{
  int slot = JenkinsHash(key, ht->num_slots);           // use the hash function and list_find to find the key, returning data, data will be null if key not found
  void * data = list_find(ht->slots[slot], key);
  return data;
}

/* Iterate over all items in hashtable (in undefined order):
 * call itemfunc for each item, with (arg, key, data).
 */
void hashtable_iterate(hashtable_t *ht, void (itemfunc)(void *arg, char *key, void *data), void *arg)
{
  if (ht == NULL || itemfunc == NULL) {
    return; // bad bag or null function
  } else {
    // scan the bag
    for (int i = 0; i < ht->num_slots; i++) {
      list_t* current = ht->slots[i];
      list_iterate(current, itemfunc, arg);         // iterate over each list in the hashtable, passing to it itemfunc

    }
  }
  return;
}


/**************** hashtable_delete() ****************/
/* Iterate over all items in the hashtable
 * freeing all the lists and then the hashtable itself.
 * uses list_delete()
 */
void hashtable_delete(hashtable_t *ht) 
{
  if (ht != NULL) {
    for (int i = 0; i < ht->num_slots; i++) {
      list_t* current = ht->slots[i];
      list_delete(current);
    }
    free(ht->slots);
  }
  free(ht);
}
