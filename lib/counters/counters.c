/* 
 * counters.c - simple counters module
 *
 * Raunak Bhojwani, April 2016
 */


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "counters.h"

/**************** local types ****************/
typedef struct countersItem {
  	int key;                   // the key
    int counter;		           // the counting variable
    struct countersItem *next;  // pointer to the next counter item
} countersItem_t;

/**************** global types ****************/
typedef struct counters {
	struct countersItem *head;                     // the start item in the counter
} counters_t;

/**************** global functions ****************/
/* that is, visible outside this file */
/* see counters.h for comments about exported functions */

/**************** local functions ****************/
/* not visible outside this file */
static countersItem_t *newItem(counters_t *ctrs, int key);


/**************** counters_new() ****************/
// creates an empty counter data structure, returns the counter
counters_t *
counters_new(void)
{
	counters_t * counter = malloc(sizeof(counters_t));

	
	counter->head = NULL;                                                      // allocate memory for the counter and set its head to NULL to begin

	return counter;
}

/**************** counters_add() ****************/
// adds a key to the counter, increments counter if key already exists
void counters_add(counters_t *ctrs, int key)
{
  bool isNew = true;                                                          // boolean to keep a track of whether key exists or not

  if ((!(ctrs == NULL)) && ctrs->head == NULL) {                              // if the counter exists and is empty, add the key and make it the head
		countersItem_t * item = newItem(ctrs, key);
    if (item == NULL) {
      return;
    }
    ctrs->head = item;
    item->next = NULL;
  }
  else if ((!(ctrs == NULL)) && ctrs->head != NULL) {                         // if the counter exists and is not empty, add the key checking for whether it 
    countersItem_t *current = ctrs->head;                                     // exists. if it does, increment the counter
    while (current->next != NULL) {
      if (current->key == key) {
        isNew = false;
        current->counter++;
      }
      current = current->next;
    }
    if (current->key == key) {
      isNew = false;
      current->counter++;
    }
    if (isNew) {                                                              // if it is a new key, add it to the data structure
      countersItem_t *item = newItem(ctrs, key);
      if (item == NULL) {
        return;
      }
      item->next = current->next;
      current->next = item;
    }
  }
}


/**************** newItem() ****************/
// newItem: create a new item to store in the counters data structure
// returns pointer to new item, if successful,
// else returns NULL.

countersItem_t *newItem(counters_t *ctrs, int key)
{
  // allocate memory for the new node
  countersItem_t * item = malloc(sizeof(countersItem_t));                     // allocate memory for the new item and set its internal variables appropriately

  if (item == NULL)
    return NULL;
  else {
    // initialize bag contents
    // item->next = malloc(sizeof(countersItem_t));
    item->next = NULL;
    item->key = key;
    if (item->key == '\0') {
      // clean up and return failure
      free(item);
      return NULL;
    }
    item->counter = 1;
    return item;
  }
}

/**************** counters_get() ****************/
// returns the count of a key if it exists in the counter
// else returns 0.

int counters_get(counters_t *ctrs, int key)
{
  if (ctrs != NULL) { //check if ctrs is null
    countersItem_t *current = ctrs->head;                                         // loop through all keys in the counter and check if the key exists
    
    if (current != NULL) {
      while (current->next != NULL) {                                               // if it doesn, return the count of that key, else return 0
        if (current->key == key) {
          return current->counter;
        }
        current = current->next;
      }
      if (current->key == key) {
        return current->counter;
      }
      return 0;
    }
    return 0;
  }
  return 0;
}


/* Set value of the counter indicated by key.
 * If the key does not yet exist, create a counter for it
 * and initialize its counter value to 'count'.
 * NULL counters is ignored.
 */
void counters_set(counters_t *ctrs, int key, int count)
{
  bool isNew = true;                                                          // boolean to keep a track of whether key exists or not

  if ((!(ctrs == NULL)) && ctrs->head == NULL) {                              // if the counter exists and is empty, add the key and make it the head
    countersItem_t * item = newItem(ctrs, key);
    if (item == NULL) {
      return;
    }
    ctrs->head = item;
    item->counter = count;                                                    // set the new item's counter ot count
    item->next = NULL;
  }
  else if ((!(ctrs == NULL)) && ctrs->head != NULL) {                         // if the counter exists and is not empty, add the key checking for whether it 
    countersItem_t *current = ctrs->head;                                     // exists. if it does, increment the counter
    while (current->next != NULL) {
      if (current->key == key) {
        isNew = false;
        current->counter = count;                                              // set the item's counter ot count
      }
      current = current->next;
    }
    if (current->key == key) {
      isNew = false;
      current->counter = count;                                                // set the item's counter ot count
    }
    if (isNew) {                                                              // if it is a new key, add it to the data structure
      countersItem_t *item = newItem(ctrs, key);                              // set the new item's counter ot count
      if (item == NULL) {
        return;
      }
      item->next = current->next;
      item->counter = count;
      current->next = item;
    }
  }
}


/* Iterate over all counters in the set (in undefined order):
 * call itemfunc for each item, with (arg, key, count).
 */
void counters_iterate(counters_t *ctrs, void (itemfunc)(void *arg, int key, int count), void *arg)
{
  if (ctrs == NULL || itemfunc == NULL) {
    return; // bad bag or null function
  } else {
    // scan the counters set
    for (countersItem_t *current = ctrs->head; current != NULL; current = current->next) {
      (itemfunc)(arg, current->key, current->counter);                      // call item func with relevant parameters
    }
  }
  return;
}



/**************** counters_delete() ****************/
// deletes the counter and all its contents
void counters_delete(counters_t *ctrs)
{
  if (ctrs != NULL) {
    countersItem_t *current = ctrs->head;                                        // free all items in the counter then free the counter itself
    while (current != NULL) {    
      countersItem_t *removed = current;
      current = current->next;
      free(removed);
    }
    free(ctrs);
  }
  
}


