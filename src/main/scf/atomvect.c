#include "scf/atomvect.h"
#include <stdlib.h>

void intVectorInit(IntVector* cont, size_t size) {
    VECTOR_ENTRY(IntVector)* entryPtr;

    entryPtr = (VECTOR_ENTRY(IntVector)*) malloc(sizeof(VECTOR_ENTRY(IntVector)) * size);
    VECTOR_INIT(IntVector, *cont, entryPtr, size);
}

void intVectorAdd(IntVector* cont, int value) {
    VECTOR_ADD(*cont, value);
}

size_t intVectorSize(IntVector* cont) {
    return CONTAINER_SIZE(*cont);
}

IntVectorCursor intVectorBegin(IntVector* cont) {
    return VECTOR_BEGIN(*cont);
}

IntVectorCursor intVectorEnd(IntVector* cont) {
    return VECTOR_END(*cont);
}

IntVectorCursor intVectorCursorNext(IntVectorCursor cursor) {
    IntVectorCursor newCursor;
    VECTOR_CURSOR_NEXT(cursor,newCursor);
    return newCursor;
}

IntVectorCursor intVectorFindIf(
    IntVectorCursor begin, IntVectorCursor end,
    int (*condition)(int value, void*), void* data) {

    while(begin != end) {
        if(condition(intVectorCursorGet(begin), data)) {
            break;
        }
        begin = intVectorCursorNext(begin);
    }

    return begin;
}

int intVectorCursorGet(IntVectorCursor cursor) {
    return VECTOR_CURSOR_GET(cursor);
}

double* doubleVectorAt(DoubleVector* cont, int index) {
    if(index < 0 || index >= static_cast<int>(doubleVectorSize(cont))) {
        return 0;
    }
    return &(VECTOR_ARRAY(*cont))[index];
}

static int intVectorCmp(const void *first, const void *second) {
    const int firstVal  = *((const int*) first);
    const int secondVal = *((const int*) second);

    if(firstVal > secondVal) {
        return 1;
    }
    if(firstVal < secondVal) {
        return -1;
    }
    return 0;
}

void intVectorSort(IntVector* cont) {
    VECTOR_QSORT(IntVector, *cont, intVectorCmp);
}

void copyIntListToIntVector(IntVector *dest, IntList *src)
{
    IntListCursor cursor;

    intVectorInit(dest, intListSize(src));

    for( cursor = intListBegin(src); cursor != intListEnd(src); cursor = intListCursorNext(cursor) ) {
        int element;

        element = intListCursorGet(cursor);

        intVectorAdd(dest, element);
    }
}


void copyIntVectorToIntList(IntList *dest, IntVector *src) {
    IntVectorCursor cursor;

    intListInit(dest);

    for(cursor = intVectorBegin(src); cursor != intVectorEnd(src); cursor = intVectorCursorNext(cursor) ) {
        int element;

        element = intVectorCursorGet(cursor);

        intListAdd(dest, element);
    }
}



/********************************************************************/

void doubleVectorInit(DoubleVector* cont, size_t size) {
    VECTOR_ENTRY(DoubleVector)* entryPtr;

    entryPtr = (VECTOR_ENTRY(DoubleVector)*) malloc(sizeof(VECTOR_ENTRY(DoubleVector)) * size);
    VECTOR_INIT(DoubleVector, *cont, entryPtr, size);
}

void doubleVectorAdd(DoubleVector* cont, double value) {
    VECTOR_ADD(*cont, value);
}

size_t doubleVectorSize(DoubleVector* cont) {
    return CONTAINER_SIZE(*cont);
}

size_t doubleVectorMaxSize(DoubleVector* cont) {
    return VECTOR_MAX_SIZE(*cont);
}

DoubleVectorCursor doubleVectorBegin(DoubleVector* cont) {
    return VECTOR_BEGIN(*cont);
}

DoubleVectorCursor doubleVectorEnd(DoubleVector* cont) {
    return VECTOR_END(*cont);
}

DoubleVectorCursor doubleVectorCursorNext(DoubleVectorCursor cursor) {
    DoubleVectorCursor newCursor;
    VECTOR_CURSOR_NEXT(cursor,newCursor);
    return newCursor;
}

DoubleVectorCursor doubleVectorFindIf(DoubleVectorCursor begin, DoubleVectorCursor end,
    int (*condition)(double value, void*), void* data) {

    while(begin != end) {
        if(condition(doubleVectorCursorGet(begin), data)) {
            break;
        }
        begin = doubleVectorCursorNext(begin);
    }

    return begin;
}

double doubleVectorCursorGet(DoubleVectorCursor cursor) {
    return VECTOR_CURSOR_GET(cursor);
}

static int doubleVectorCmp(const void *first, const void *second) {
    const double firstVal  = *((const double*) first);
    const double secondVal = *((const double*) second);

    if(firstVal > secondVal) {
        return 1;
    }
    if(firstVal < secondVal) {
        return -1;
    }
    return 0;
}

void doubleVectorSort(DoubleVector* cont) {
    VECTOR_QSORT(DoubleVector, *cont, doubleVectorCmp);
}

/********************************************************************/

void intObjectPairVectorInit(IntObjectPairVector* cont, size_t size) {
    VECTOR_ENTRY(IntObjectPairVector)* entryPtr;

    entryPtr = (VECTOR_ENTRY(IntObjectPairVector)*) malloc(sizeof(VECTOR_ENTRY(IntObjectPairVector)) * size);
    VECTOR_INIT(IntObjectPairVector, *cont, entryPtr, size);
}

void intObjectPairVectorAdd(IntObjectPairVector* cont, IntObjectPair value) {
    VECTOR_ADD(*cont, value);
}

size_t intObjectPairVectorSize(IntObjectPairVector* cont) {
    return CONTAINER_SIZE(*cont);
}

IntObjectPairVectorCursor intObjectPairVectorBegin(IntObjectPairVector* cont) {
    return VECTOR_BEGIN(*cont);
}

IntObjectPairVectorCursor intObjectPairVectorEnd(IntObjectPairVector* cont) {
    return VECTOR_END(*cont);
}

IntObjectPairVectorCursor intObjectPairVectorCursorNext(IntObjectPairVectorCursor cursor) {
    IntObjectPairVectorCursor newCursor;
    VECTOR_CURSOR_NEXT(cursor,newCursor);
    return newCursor;
}

IntObjectPairVectorCursor intObjectPairVectorFindIf(IntObjectPairVectorCursor begin, IntObjectPairVectorCursor end,
    int (*condition)(IntObjectPair value, void*), void* data) {

    while(begin != end) {
        if(condition(intObjectPairVectorCursorGet(begin), data)) {
            break;
        }
        begin = intObjectPairVectorCursorNext(begin);
    }

    return begin;
}

IntObjectPair intObjectPairVectorCursorGet(IntObjectPairVectorCursor cursor) {
    return VECTOR_CURSOR_GET(cursor);
}

static int intObjectPairVectorCmp(const void *first, const void *second) {
    const IntObjectPair firstVal  = *((const IntObjectPair*) first);
    const IntObjectPair secondVal = *((const IntObjectPair*) second);

    if(firstVal.key > secondVal.key) {
        return 1;
    }
    if(firstVal.key < secondVal.key) {
        return -1;
    }
    return 0;
}

void intObjectPairVectorSort(IntObjectPairVector* cont) {
    VECTOR_QSORT(IntObjectPairVector, *cont, intObjectPairVectorCmp);
}

/********************************************************************/

void objectVectorInit(ObjectVector* cont, size_t size) {
    VECTOR_ENTRY(ObjectVector)* entryPtr;

    entryPtr = (VECTOR_ENTRY(ObjectVector)*) malloc(sizeof(VECTOR_ENTRY(ObjectVector)) * size);
    VECTOR_INIT(ObjectVector, *cont, entryPtr, size);
}

void objectVectorAdd(ObjectVector* cont, void* value) {
    VECTOR_ADD(*cont, value);
}

size_t objectVectorSize(ObjectVector* cont) {
    return CONTAINER_SIZE(*cont);
}

ObjectVectorCursor objectVectorBegin(ObjectVector* cont) {
    return VECTOR_BEGIN(*cont);
}

ObjectVectorCursor objectVectorEnd(ObjectVector* cont) {
    return VECTOR_END(*cont);
}

ObjectVectorCursor objectVectorCursorNext(ObjectVectorCursor cursor) {
    ObjectVectorCursor newCursor;
    VECTOR_CURSOR_NEXT(cursor,newCursor);
    return newCursor;
}

ObjectVectorCursor objectVectorFindIf(
    ObjectVectorCursor begin, ObjectVectorCursor end,
    int (*condition)(void*, void*), void* data) {

    while(begin != end) {
        if(condition(objectVectorCursorGet(begin), data)) {
            break;
        }
        begin = objectVectorCursorNext(begin);
    }

    return begin;
}

void* objectVectorCursorGet(ObjectVectorCursor cursor) {
    return VECTOR_CURSOR_GET(cursor);
}

void objectVectorSort(ObjectVector* cont, int (*objectVectorComp)(const void* first, const void* second)) {
    VECTOR_QSORT(ObjectVector, *cont, objectVectorComp);
}
