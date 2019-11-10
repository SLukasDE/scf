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

#ifndef SCF_LIST_H_
#define SCF_LIST_H_

/**
 * Implementation of a list container as part of the
 * simple container framework (SCF)
 */

#include "scf/scfcont.h"

/** type definition of list and cursor */
#define TYPEDEF_LIST(CONTAINER_TYPE,VALUE_TYPE) \
    struct CONTAINER_TYPE##_struct; \
    struct CONTAINER_TYPE##_cursor_struct { \
        VALUE_TYPE value; \
        struct CONTAINER_TYPE##_struct *container; \
        struct CONTAINER_TYPE##_cursor_struct *prev; \
        struct CONTAINER_TYPE##_cursor_struct *next; \
    }; \
    typedef struct CONTAINER_TYPE##_cursor_struct \
        CONTAINER_TYPE##_cursor; \
    struct CONTAINER_TYPE##_struct { \
        CONTAINER_TYPE##_cursor *first; \
        CONTAINER_TYPE##_cursor *last; \
        unsigned int size; \
    }; \
    typedef struct CONTAINER_TYPE##_struct CONTAINER_TYPE \

/** entry point */
#define LIST_ENTRY(CONTAINER_TYPE) \
        CONTAINER_TYPE##_cursor

/** cursor */
#define LIST_CURSOR(CONTAINER_TYPE) \
        CONTAINER_CURSOR(CONTAINER_TYPE)

/** initialize list */
#define LIST_INIT(CONTAINER_TYPE,list) \
        (list).first = 0; \
        (list).last = 0; \
        CONTAINER_INIT(CONTAINER_TYPE,list)

/** size of list */
#define LIST_SIZE(container) \
        CONTAINER_SIZE(container)

/** add element to list */
#define LIST_ADD(list,val,entry_ptr) \
        (entry_ptr)->value = (val); \
        (entry_ptr)->container = &(list); \
        (entry_ptr)->prev = (list).last; \
        (entry_ptr)->next = 0; \
        if((list).first == 0) { \
            (list).first = entry_ptr; \
        } \
        else { \
            (list).last->next = (entry_ptr); \
        } \
        if((entry_ptr)->prev != 0) { \
            (entry_ptr)->prev->next = (entry_ptr); \
        } \
        (list).last = entry_ptr; \
        ++(list).size

/** remove entry of list */
#define LIST_REMOVE(list,cursor,old_entry_ptr) \
        if((cursor)->prev != 0) { \
            (cursor)->prev->next = (cursor)->next; \
        } \
        if((cursor)->next != 0) { \
            (cursor)->next->prev = (cursor)->prev; \
        } \
        if((list).first == (cursor)) { \
            (list).first = (cursor)->next; \
        } \
        if((list).last == (cursor)) { \
            (list).last = (cursor)->prev; \
        } \
        --(list).size; \
        old_entry_ptr = (cursor)


/** cursor of first element of the list */
#define LIST_BEGIN(container) \
        ((container).first)

/** cursor after last element of the list */
#define LIST_END(container) \
        0

/** iterate cursor to next element */
#define LIST_CURSOR_NEXT(current_cursor,next_cursor) \
        next_cursor = (current_cursor->next)

/** iterate cursor to previous element */
#define LIST_CURSOR_PREV(current_cursor,prev_cursor) \
        prev_cursor = current_cursor == 0 ? \
                (current_cursor->container->last) : \
                (current_cursor->prev)

/** get object of current cursor */
#define LIST_CURSOR_GET(cursor) \
        (cursor->value)

#endif /* SCF_LIST_H_ */
