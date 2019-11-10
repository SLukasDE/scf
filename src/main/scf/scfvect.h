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

#ifndef SCF_VECTOR_H_
#define SCF_VECTOR_H_

/**
 * Implementation of a vector container as part of the simple
 * container framework (SCF)
 */

#include "scf/scfcont.h"
#include <stdlib.h>

/** type definition of vector and cursor */
#define TYPEDEF_VECTOR(CONTAINER_TYPE,VALUE_TYPE) \
    typedef VALUE_TYPE CONTAINER_TYPE##_cursor; \
    typedef struct CONTAINER_TYPE##_struct { \
        VALUE_TYPE* values; \
        unsigned int maxsize; \
        unsigned int size; \
    } CONTAINER_TYPE

/** entry point */
#define VECTOR_ENTRY(CONTAINER_TYPE) \
        CONTAINER_TYPE##_cursor

/** cursor */
#define VECTOR_CURSOR(CONTAINER_TYPE) \
        CONTAINER_CURSOR(CONTAINER_TYPE)

/** initialize vector */
#define VECTOR_INIT(CONTAINER_TYPE,container,entry_array,entries) \
        (container).values = entry_array; \
        (container).maxsize = static_cast<unsigned int>(entries); \
        CONTAINER_INIT(CONTAINER_TYPE,container)

/** get size off vector */
#define VECTOR_SIZE(container) \
        CONTAINER_SIZE(container)

#define VECTOR_MAX_SIZE(container) \
        ( (container).maxsize )

/** add element to vector */
#define VECTOR_ADD(container,value) \
        if(((container).size < (container).maxsize)) { \
            (container).values[(container).size++] = (value); \
        }

/** cursor of first element of the vector */
#define VECTOR_BEGIN(container) \
        (&(container).values[0])

/** cursor after last element of the vector */
#define VECTOR_END(container) \
        (&(container).values[(container).size])

/** iterate cursor to next element */
#define VECTOR_CURSOR_NEXT(current_cursor,next_cursor) \
        next_cursor = (current_cursor + 1)

/** iterate cursor to previous element */
#define VECTOR_CURSOR_PREV(current_cursor,prev_cursor) \
        prev_cursor = (current_cursor - 1)

/** get object of current cursor */
#define VECTOR_CURSOR_GET(cursor) \
        (*cursor)


/**
 * This is a special macro for vector container and does not exists
 * for other containers.
 * This macro is used to get access to the array of elements that is
 * used internally by a vector container.
 */
#define VECTOR_ARRAY(container) \
        (container).values

/**
 * This is a special macro for vector container and does not exists
 * for other containers.
 * This macro is used to sort the elements of the container by using
 * the C qsort function.
 * used internally by a vector container.
 */
#define VECTOR_QSORT(CONTAINER_TYPE,container,comp_fn) \
    qsort(VECTOR_ARRAY(container), \
          VECTOR_SIZE(container), \
          sizeof(CONTAINER_TYPE##_cursor), \
          comp_fn);

#endif /* SCF_VECTOR_H_ */
