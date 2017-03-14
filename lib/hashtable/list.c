/* 
 * list.c - simple list module
 *
 * Raunak Bhojwani, April 2016
 */


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "list.h"

/**************** local types ****************/
typedef struct listItem {
  	char *key;               // the key for this list item
    void *data;		           // pointer to data for this list item
    struct listItem *next;   // pointer to next item in list
} listItem_t;

/**************** global types ****************/
typedef struct list {
	struct listItem *head;     // start item for this list
} list_t;

/**************** global functions ****************/
/* that is, visible outside this file */
/* see list.h for comments about exported functions */

/**************** local functions ****************/
/* not visible outside this file */
static listItem_t *newListItem(list_t *list, char *key, void *data);


/**************** list_new() ****************/
// create new empty lists, return the pointer to the list
list_t *list_new(void)
{
  list_t *newList;  // allocate memory for the list
	if ((newList = malloc(5 * sizeof(list_t))) == NULL) {
    return NULL;
  }              


	// initialize contents of bag structure
	newList->head = NULL;
	return newList;
}

/**************** list_insert() ****************/
// insert a new item into the list, with key and data
// return true if item inserter
// return fals if key already exists or any other problems
bool list_insert(list_t *list, char *key, void *data)
{
  if (list == NULL) {                                 // return false if list is null
    return false;
  }
  else if (list->head == NULL) {                      // is the list is empty, add item as the head
		listItem_t *item;
    if ((item = newListItem(list, key, data)) == NULL) {
      return false;
    }
    list->head = item;
    item->next = NULL;
    return true;
  }
  
  else {                                              // if list not empty, check if key exists. if it does, return false
    listItem_t *current = list->head;
    if (current != NULL) {

      if (strcmp(key, current->key) == 0) {
        return false;
      }

      while (current->next != NULL) {
        current = current->next;
        if (strcmp(key, current->key) == 0) {
          return false;
        }
      }
      
      listItem_t *item;
      if ((item = newListItem(list, key, data)) == NULL) {
        return false;
      }    
                                               // if key does not exist, add the item and return true
      item->next = current->next;
      current->next = item;
      return true;
    }
    else {
      return false;
    }
  }
}

/**************** newListItem() ****************/
// newListItem: create a new item to store in the list
// returns pointer to new item, if successful,
// else returns false.

listItem_t *newListItem(list_t *list, char *key, void *data)
{
  // allocate memory for the new node
  listItem_t *item;
  if ((item = malloc(sizeof(listItem_t))) == NULL) {
    return NULL;
  }
  // initialize list contents
  item->next = NULL;                                  // allocate memory for the new item and store its information and then return item
  item->data = data;
  // if ((item->key = malloc(sizeof(key))) == NULL) {
  //   free(item);
  //   return NULL;
  // }
  item->key = key;
  return item;
}

/**************** list_find() ****************/
// finds an item in the list looking for its key
// returns data of said item if successful
// else returns NULL.

void *list_find(list_t *list, char *key)
{
  listItem_t *current = list->head;                         // loop through all items in the list, searching for the key

  if (current != NULL) {
    if (strcmp(key, current->key) == 0) {
      void *data = current->data;                          // if key is found, return the corresponding data
      return data;
    }

    while (current->next != NULL) {
      current = current->next;
      if (strcmp(key, current->key) == 0) {
        void * data = current->data;
        return data;
      }
    }
  }
  return NULL;                                              // else return null
}


/* Iterate over all items in list (in undefined order):
 * call itemfunc for each item, passing (arg, key, data).
 */
void list_iterate(list_t *list, void (itemfunc)(void *arg, char *key, void *data), void *arg)
{
  if (list == NULL || itemfunc == NULL) {
    return; // bad bag or null function
  } else {
    // scan the bag
    for (listItem_t *current = list->head; current != NULL; current = current->next) {
      (itemfunc)(arg, current->key, current->data);           // call itemfunc with the relevant parameters
    }
  }
  return;
}

/**************** list_delete ****************/
/* Iterate over all items in list
 * freeing all the keys and then the items , and then the list itself
 */
void list_delete(list_t *list)
{
  if (list != NULL) {
    listItem_t *current = list->head;
    listItem_t *next;

    while (current != NULL) {
      next = current->next;
      free(current->key);            
      free(current);
      current = next;
    }
  }
  free(list);
}



