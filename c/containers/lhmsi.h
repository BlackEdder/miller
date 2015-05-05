#ifndef LHMSI_H
#define LHMSI_H

#include "containers/sllv.h"

// ================================================================
// Array-only (open addressing) string-to-int linked hash map with linear
// probing for collisions.
//
// John Kerl 2012-08-13
//
// Notes:
// * null key is not supported.
// * null value is supported.
//
// See also:
// * http://en.wikipedia.org/wiki/Hash_table
// * http://docs.oracle.com/javase/6/docs/api/java/util/Map.html
// ================================================================

// ----------------------------------------------------------------
typedef struct _lhmsie_t {
	int   ideal_index;
	char* key;
	int   value;
	struct _lhmsie_t *pprev;
	struct _lhmsie_t *pnext;
} lhmsie_t;

typedef unsigned char lhmsie_state_t;

typedef struct _lhmsi_t {
	int             num_occupied;
	int             num_freed;
	int             array_length;
	lhmsie_t*       entries;
	lhmsie_state_t* states;
	lhmsie_t*       phead;
	lhmsie_t*       ptail;
} lhmsi_t;

// ----------------------------------------------------------------
lhmsi_t* lhmsi_alloc();
lhmsi_t* lhmsi_copy(lhmsi_t* pmap);
void  lhmsi_free(lhmsi_t* pmap);
void  lhmsi_put(lhmsi_t* pmap, char* key, int value);
int   lhmsi_get(lhmsi_t* pmap, char* key);
int   lhmsi_has_key(lhmsi_t* pmap, char* key);
void  lhmsi_remove(lhmsi_t* pmap, char* key);

#endif // LHMSI_H