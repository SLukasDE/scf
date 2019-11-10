/*
MIT License

Copyright (c) 2004 Sven Lukas

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
*/

#ifndef SCF_HASHMAP_H_
#define SCF_HASHMAP_H_

/**
 * Implementation of a hashmap container as part of the
 * simple container framework (SCF)
 */

#include "scf/scfcont.h"
#include <string.h>

/** type definitionen of hashmap und cursor */
#define TYPEDEF_HASHMAP(CONTAINER_TYPE,VALUE_TYPE,SIZE) \
    static const unsigned int CONTAINER_TYPE##_max_size = SIZE;\
    struct CONTAINER_TYPE##_struct; \
    struct CONTAINER_TYPE##_cursor_struct { \
        VALUE_TYPE value; \
        unsigned int index; \
        struct CONTAINER_TYPE##_struct *hashmap; \
        struct CONTAINER_TYPE##_cursor_struct *next; \
    }; \
    typedef struct CONTAINER_TYPE##_cursor_struct \
        CONTAINER_TYPE##_cursor; \
    typedef struct CONTAINER_TYPE##_struct { \
        CONTAINER_TYPE##_cursor* hash_tbl[(SIZE)]; \
        unsigned int (*hash_fn)(VALUE_TYPE) ; \
        int (*equal_fn)(VALUE_TYPE, VALUE_TYPE) ; \
        CONTAINER_TYPE##_cursor* first; \
        CONTAINER_TYPE##_cursor* tmp_cur; \
        unsigned int tmp_int; \
        unsigned int size; \
        unsigned int maxsize; \
        unsigned int collisions; \
    } CONTAINER_TYPE

/** entry point */
#define HASHMAP_ENTRY(CONTAINER_TYPE) \
        CONTAINER_TYPE##_cursor

/** cursor */
#define HASHMAP_CURSOR(CONTAINER_TYPE) \
        CONTAINER_CURSOR(CONTAINER_TYPE)

/** initialize the hashmap */
#define HASHMAP_INIT(CONTAINER_TYPE,container,hashfunc,eqfunc) \
        memset((container).hash_tbl,0,sizeof((container).hash_tbl));\
        (container).hash_fn = hashfunc; \
        (container).equal_fn = eqfunc; \
        (container).first = 0; \
        (container).collisions = 0; \
        (container).maxsize = CONTAINER_TYPE##_max_size; \
        CONTAINER_INIT(CONTAINER_TYPE,container)

/** size of hashmap */
#define HASHMAP_SIZE(container) \
        CONTAINER_SIZE(container)

/** add element to hashmap */
#define HASHMAP_ADD(hmap,val,entry_ptr) \
        (entry_ptr)->value = val; \
        (entry_ptr)->index =(hmap).hash_fn(val)%(hmap).maxsize; \
        (entry_ptr)->hashmap = &(hmap); \
        (entry_ptr)->next = (hmap).hash_tbl[(entry_ptr)->index]; \
        if((entry_ptr)->next != 0) { \
            ++(entry_ptr)->hashmap->collisions; \
        } \
        if( (hmap).first == 0 ) { \
            (hmap).first = (entry_ptr); \
        } else if((hmap).first->index >= (entry_ptr)->index) { \
            (hmap).first = (entry_ptr); \
        } \
        (hmap).hash_tbl[(entry_ptr)->index] = (entry_ptr); \
        ++(hmap).size

/** cursor of first element of the hashmap */
#define HASHMAP_BEGIN(container) \
        (container).first

/** cursor after last element of the hashmap */
#define HASHMAP_END(container) \
        0

/** iterate cursor to next element */
#define HASHMAP_CURSOR_NEXT(old_cur,next_cur) \
        (old_cur)->hashmap->tmp_cur = (old_cur)->next; \
        if( (old_cur)->hashmap->tmp_cur == 0 ) { \
            for((old_cur)->hashmap->tmp_int = (old_cur)->index + 1; \
                (old_cur)->hashmap->tmp_int < (old_cur)->hashmap-> \
                                                             maxsize; \
                   ++(old_cur)->hashmap->tmp_int) { \
                (old_cur)->hashmap->tmp_cur = (old_cur)->hashmap-> \
                hash_tbl[(old_cur)->hashmap->tmp_int]; \
                   if((old_cur)->hashmap->tmp_cur != 0) { \
                       break; \
                   } \
               } \
        } \
        next_cur = (old_cur)->hashmap->tmp_cur

/** get object of current cursor */
#define HASHMAP_CURSOR_GET(cursor) \
        (cursor->value)

/** find element in hashmap */
#define HASHMAP_FIND(hashmap,val,cursor) \
    for((hashmap).tmp_cur \
               = (hashmap).hash_tbl[(hashmap).hash_fn(val) \
                                    %(hashmap).maxsize]; \
        (hashmap).tmp_cur != 0; \
        (hashmap).tmp_cur = (hashmap).tmp_cur->next) { \
        if((hashmap).equal_fn((hashmap).tmp_cur->value,val)){ \
            break; \
        } \
    } \
    cursor = (hashmap).tmp_cur;

/** iterate to next found element in hashmap */
#define HASHMAP_CURSOR_FIND_NEXT(next_cur,old_cur,val) \
    for(next_cur = (old_cur)->next; \
        next_cur != 0; \
        next_cur = next_cur->next) { \
        if(next_cur->hashmap->equal_fn(next_cur->value,val)) { \
            break; \
        } \
    }

/** collision */
#define HASHMAP_COLLISION(hashmap) \
        (hashmap).collisions


/** remove element */
#define HASHMAP_REMOVE(cursor) \
    (cursor)->hashmap->tmp_cur = \
      (cursor)->hashmap->hash_tbl[(cursor)->index]; \
    if((cursor)->hashmap->tmp_cur != (cursor)) { \
        while((cursor)->hashmap->tmp_cur->next != cursor) { \
            (cursor)->hashmap->tmp_cur = \
              (cursor)->hashmap->tmp_cur->next; \
        } \
        (cursor)->hashmap->tmp_cur->next = \
            (cursor)->next; \
    } \
    else { \
        (cursor)->hashmap->hash_tbl[(cursor)->index] = \
            (cursor)->next; \
    } \
    --(cursor)->hashmap->size; \
    if((cursor)->hashmap->first->index >= (cursor)->index) { \
        (cursor)->hashmap->first = 0; \
        for((cursor)->hashmap->tmp_int = (cursor)->index; \
            (cursor)->hashmap->tmp_int < (cursor)->hashmap->maxsize; \
            ++(cursor)->hashmap->tmp_int) { \
            if((cursor)->hashmap->hash_tbl[(cursor)->hashmap->tmp_int] \
              != 0) { \
                (cursor)->hashmap->first = (cursor)->hashmap-> \
                  hash_tbl[(cursor)->hashmap->tmp_int]; \
                break; \
            } \
        } \
    }

#endif /* SCF_HASHMAP_H_ */
