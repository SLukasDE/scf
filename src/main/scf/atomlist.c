#include "scf/atomlist.h"


/* *******************************************************************/
/* PtrList-Methoden
 */
void ptrListInit(PtrList* list) {
    LIST_INIT(PtrList, *list);
}

void ptrListAdd(PtrList* list, void* value) {
    LIST_ENTRY(PtrList)* entryPtr;

    entryPtr = (LIST_ENTRY(PtrList) *) malloc(sizeof (LIST_ENTRY(PtrList)));
    LIST_ADD(*list, value, entryPtr);
}

PtrListCursor ptrListCursorRemove(PtrList* list, PtrListCursor cursor) {
    PtrListCursor nextCursor;
    LIST_ENTRY(PtrList)* entryPtr;
    nextCursor = ptrListCursorNext(cursor);
    LIST_REMOVE(*list,cursor,entryPtr);
    return nextCursor;
}



unsigned long ptrListSize(const PtrList* list) {
    return CONTAINER_SIZE(*list);
}

PtrListCursor ptrListBegin(const PtrList* list) {
    return LIST_BEGIN(*list);
}

PtrListCursor ptrListEnd(const PtrList* list) {
    return LIST_END(*list);
}

PtrListCursor ptrListCursorNext(PtrListCursor cursor) {
    PtrListCursor newCursor;
    LIST_CURSOR_NEXT(cursor,newCursor);
    return newCursor;
}

void* ptrListCursorGet(PtrListCursor cursor) {
    return LIST_CURSOR_GET(cursor);
}

/* *******************************************************************/
/* IntList-Methoden
 */
void intListInit(IntList* list) {
    LIST_INIT(IntList, *list);
}

void intListAdd(IntList* list, int value) {
    LIST_ENTRY(IntList) *entry_ptr;

    entry_ptr = (LIST_ENTRY(IntList) *) malloc(sizeof (LIST_ENTRY(IntList)));
    LIST_ADD(*list, value, entry_ptr);
}

size_t intListSize(IntList* list) {
    return CONTAINER_SIZE(*list);
}

IntListCursor intListBegin(IntList* list) {
    return LIST_BEGIN(*list);
}

IntListCursor intListEnd(IntList* list) {
    return LIST_END(*list);
}

IntListCursor intListCursorNext(IntListCursor cursor) {
    IntListCursor newCursor;
    LIST_CURSOR_NEXT(cursor,newCursor);
    return newCursor;
}

int intListCursorGet(IntListCursor cursor) {
    return LIST_CURSOR_GET(cursor);
}

IntListCursor intListCursorRemove(IntList* list, IntListCursor cursor) {
    IntListCursor nextCursor;
    LIST_ENTRY(IntList)* entry_ptr;
    nextCursor = intListCursorNext(cursor);
    LIST_REMOVE(*list,cursor,entry_ptr);
    return nextCursor;
}

IntListCursor intListFind(IntList* list, IntListCursor first, IntListCursor last, int value){
    IntListCursor cursor;

    cursor = first;
    while( cursor !=last && cursor != LIST_END(*list) ) {
        if( LIST_CURSOR_GET(cursor) == value ){
            return cursor;
        }
        LIST_CURSOR_NEXT(cursor, cursor);
    }
    return last;
}


/* *******************************************************************/
/* DoubleList-Methoden
 */
void doubleListInit(DoubleList *list) {
    LIST_INIT(DoubleList, *list);
}

void doubleListAdd(DoubleList* list, double value) {
    LIST_ENTRY(DoubleList)* entry_ptr;

    entry_ptr = (LIST_ENTRY(DoubleList)*) malloc(sizeof (LIST_ENTRY(DoubleList)));
    LIST_ADD(*list, value, entry_ptr);
}

size_t doubleListSize(DoubleList* list) {
    return CONTAINER_SIZE(*list);
}

DoubleListCursor doubleListBegin(DoubleList* list) {
    return LIST_BEGIN(*list);
}

DoubleListCursor doubleListEnd(DoubleList* list) {
    return LIST_END(*list);
}

DoubleListCursor doubleListCursorNext(DoubleListCursor cursor) {
    DoubleListCursor newCursor;
    LIST_CURSOR_NEXT(cursor,newCursor);
    return newCursor;
}

double doubleListCursorGet(DoubleListCursor cursor) {
    return LIST_CURSOR_GET(cursor);
}

/* *******************************************************************/
/* IntObjectPairList-Methoden
 */
void intObjectPairListInit(IntObjectPairList* list) {
    LIST_INIT(IntObjectPairList, *list);
}

void intObjectPairListAdd(IntObjectPairList* list, IntObjectPair value) {
    LIST_ENTRY(IntObjectPairList)* entryPtr;

    entryPtr = (LIST_ENTRY(IntObjectPairList)*) malloc(sizeof (LIST_ENTRY(IntObjectPairList)));
    LIST_ADD(*list, value, entryPtr);
}

size_t intObjectPairListSize(IntObjectPairList* list) {
    return CONTAINER_SIZE(*list);
}

IntObjectPairListCursor intObjectPairListBegin(IntObjectPairList* list)
{
    return LIST_BEGIN(*list);
}

IntObjectPairListCursor intObjectPairListEnd(IntObjectPairList* list) {
    return LIST_END(*list);
}

IntObjectPairListCursor intObjectPairListCursorNext(IntObjectPairListCursor cursor) {
    IntObjectPairListCursor newCursor;
    LIST_CURSOR_NEXT(cursor,newCursor);
    return newCursor;
}

IntObjectPair intObjectPairListCursorGet(IntObjectPairListCursor cursor) {
    return LIST_CURSOR_GET(cursor);
}

/* *******************************************************************/
/* IntIntPairList-Methoden
 */
void intIntPairListInit(IntIntPairList* list) {
    LIST_INIT(IntIntPairList, *list);
}

void intIntPairListAdd(IntIntPairList* list, IntIntPair value) {
    LIST_ENTRY(IntIntPairList) *entryPtr;

    entryPtr = (LIST_ENTRY(IntIntPairList)*) malloc(sizeof (LIST_ENTRY(IntIntPairList)));
    LIST_ADD(*list, value, entryPtr);
}

size_t intIntPairListSize(IntIntPairList* list) {
    return CONTAINER_SIZE(*list);
}

IntIntPairListCursor intIntPairListBegin(IntIntPairList* list) {
    return LIST_BEGIN(*list);
}

IntIntPairListCursor intIntPairListEnd(IntIntPairList* list) {
    return LIST_END(*list);
}

IntIntPairListCursor intIntPairListCursorNext(
        IntIntPairListCursor cursor) {
    IntIntPairListCursor newCursor;
    LIST_CURSOR_NEXT(cursor,newCursor);
    return newCursor;
}

IntIntPair intIntPairListCursorGet(
        IntIntPairListCursor cursor) {
    return LIST_CURSOR_GET(cursor);
}

