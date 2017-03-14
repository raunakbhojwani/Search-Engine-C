/* 
 * list.h - header file for list module
 *
 * Raunak Bhojwani, April 2016
 */

#ifndef __COUNTERS_H
#define __COUNTERS_H

/**************** global types ****************/
typedef struct counters counters_t;  // opaque to users of the module

/**************** functions ****************/

/* Create a new (empty) counters data structure; 
 */
counters_t *counters_new(void);

/* If key exists, increment counter;
 * If key does not exist, add key and set counter to 1
 */
void counters_add(counters_t *ctrs, int key);

/* Return the current value associated with the given key;
 * return 0 if key is not found.
 */
int counters_get(counters_t *ctrs, int key);

/* Set value of the counter indicated by key.
 * If the key does not yet exist, create a counter for it
 * and initialize its counter value to 'count'.
 * NULL counters is ignored.
 */
void counters_set(counters_t *ctrs, int key, int count);

/* Iterate over all counters in the set (in undefined order):
 * call itemfunc for each item, with (arg, key, count).
 */
void counters_iterate(counters_t *ctrs, void (itemfunc)(void *arg, int key, int count), void *arg);

/* Delete the whole data structure
 */
void counters_delete(counters_t *ctrs);

#endif // __COUNTERS_H
