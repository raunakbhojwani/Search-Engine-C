/* 
 * hashtable.h - header file for hashtable module
 *
 * Raunak Bhojwani, April 2016
 */

#ifndef __HASHTABLE_H
#define __HASHTABLE_H

/**************** global types ****************/
typedef struct hashtable hashtable_t;  // opaque to users of the module

/**************** functions ****************/

/* Create a new (empty) chashtable data structure; 
 */
hashtable_t *hashtable_new(const int num_slots);

/* 
 * If key exists, return false;
 * If key does not exist, insert new item and return true
 * If ht is NULL, or you encounter other error, return false.
 * Copy the key string
 */
bool hashtable_insert(hashtable_t *ht, char *key, void *data);

/* Return the data associated with the given key;
 * return NULL if key is not found.
 */
void *hashtable_find(hashtable_t *ht, char *key);

/* Iterate over all items in hashtable (in undefined order):
 * call itemfunc for each item, with (arg, key, data).
 */
void hashtable_iterate(hashtable_t *ht, void (itemfunc)(void *arg, char *key, void *data), void *arg);

/* Iterate over all items in the hashtable
 * freeing all the lists and then the hashtable itself.
 * uses list_delete()
 */
void hashtable_delete(hashtable_t *ht);

#endif // __HASHTABLE_H
