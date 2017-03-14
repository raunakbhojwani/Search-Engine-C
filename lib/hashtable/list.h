/* 
 * list.h - header file for list module
 *
 * Raunak Bhojwani, April 2016
 */

#ifndef __LIST_H
#define __LIST_H

/**************** global types ****************/
typedef struct list list_t;  // opaque to users of the module

/**************** functions ****************/

/* Create a new (empty) list; 
 */
list_t *list_new(void);

/* 
 * Insert item into the given list;
 * return false if key already exists, and true if new item was inserted.
 * If list is NULL, or you encounter other error, return false.
 * Copy the key string
 */
bool list_insert(list_t *list, char *key, void *data);

/* Return the data associated with the given key;
 * return NULL if key is not found.
 */
void *list_find(list_t *list, char *key);


/* Iterate over all items in list (in undefined order):
 * call itemfunc for each item, passing (arg, key, data).
 */
void list_iterate(list_t *list, void (itemfunc)(void *arg, char *key, void *data), void *arg);

/* Iterate over all items in list
 * freeing all the keys and then the items , and then the list itself
 */
void list_delete(list_t *list);

#endif // __LIST_H
