#include "scf/atomhash.h"

static unsigned int intHashmapHashFunction(int value) {
    return value;
}

static int intHashmapEqualFunction(int v1, int v2) {
    return (v1 == v2);
}

void intHashmapInit(IntHashmap* cont) {
    HASHMAP_INIT(IntHashmap, *cont,
            intHashmapHashFunction, intHashmapEqualFunction);
}

size_t intHashmapSize(IntHashmap* cont) {
    return HASHMAP_SIZE(*cont);
}

void intHashmapAdd(IntHashmap* cont, int value) {
    HASHMAP_ENTRY(IntHashmap)* entryPtr;

    entryPtr = (HASHMAP_ENTRY(IntHashmap)*) malloc(sizeof (HASHMAP_ENTRY(IntHashmap)));
    HASHMAP_ADD(*cont, value, entryPtr);
}

IntHashmapCursor intHashmapCursorRemove(IntHashmapCursor cursor) {
    IntHashmapCursor nextCursor;

    nextCursor = intHashmapCursorNext(cursor);
    HASHMAP_REMOVE(cursor);
    return nextCursor;
}

IntHashmapCursor intHashmapBegin(IntHashmap* cont) {
    return HASHMAP_BEGIN(*cont);
}

IntHashmapCursor intHashmapEnd(IntHashmap* cont) {
    return HASHMAP_END(*cont);
}

IntHashmapCursor intHashmapCursorNext(IntHashmapCursor cursor) {
    IntHashmapCursor newCursor;

    HASHMAP_CURSOR_NEXT(cursor, newCursor);
    return newCursor;
}

IntHashmapCursor intHashmapFind(IntHashmap* cont, int value) {
    IntHashmapCursor cursor;

    HASHMAP_FIND(*cont, value, cursor);
    return cursor;
}

IntHashmapCursor intHashmapFindNext(IntHashmapCursor cursor,
        int value) {
    IntHashmapCursor nextCursor;

    HASHMAP_CURSOR_FIND_NEXT(nextCursor, cursor, value);
    return nextCursor;
}

int intHashmapCursorGet(IntHashmapCursor cursor) {
    return HASHMAP_CURSOR_GET(cursor);
}


/*********************************************************************/

static unsigned int intObjectPairHashmapHashFunction(
        IntObjectPair* pair) {
    return pair->key;
}

static int intObjectPairHashmapEqualFunction(IntObjectPair* p1,
        IntObjectPair* p2) {
    return (p1->key == p2->key);
}

void intObjectPairHashmapInit(IntObjectPairHashmap* cont) {
    HASHMAP_INIT(IntObjectPairHashmap, *cont,
            intObjectPairHashmapHashFunction,
            intObjectPairHashmapEqualFunction);
}

size_t intObjectPairHashmapSize(IntObjectPairHashmap* cont) {
    return HASHMAP_SIZE(*cont);
}

void intObjectPairHashmapAdd(IntObjectPairHashmap* cont, IntObjectPair* value) {
    HASHMAP_ENTRY(IntObjectPairHashmap)* entryPtr;

    entryPtr = (HASHMAP_ENTRY(IntObjectPairHashmap)*) malloc(sizeof (HASHMAP_ENTRY(IntObjectPairHashmap)));
    HASHMAP_ADD(*cont, value, entryPtr);
}

IntObjectPairHashmapCursor intObjectPairHashmapCursorRemove(IntObjectPairHashmapCursor cursor) {
    IntObjectPairHashmapCursor nextCursor;

    nextCursor = intObjectPairHashmapCursorNext(cursor);
    HASHMAP_REMOVE(cursor);
    return nextCursor;
}

IntObjectPairHashmapCursor intObjectPairHashmapBegin(IntObjectPairHashmap* cont) {
    return HASHMAP_BEGIN(*cont);
}

IntObjectPairHashmapCursor intObjectPairHashmapEnd(IntObjectPairHashmap* cont) {
    return HASHMAP_END(*cont);
}

IntObjectPairHashmapCursor intObjectPairHashmapCursorNext(IntObjectPairHashmapCursor cursor) {
    IntObjectPairHashmapCursor newCursor;

    HASHMAP_CURSOR_NEXT(cursor, newCursor);
    return newCursor;
}

IntObjectPairHashmapCursor intObjectPairHashmapFind(IntObjectPairHashmap* cont, int value) {
    IntObjectPairHashmapCursor cursor;
    IntObjectPair pair;
    pair.key = value;

    HASHMAP_FIND(*cont, &pair, cursor);
    return cursor;
}

IntObjectPairHashmapCursor intObjectPairHashmapFindNext(IntObjectPairHashmapCursor cursor, int value) {
    IntObjectPairHashmapCursor nextCursor;
    IntObjectPair pair;
    pair.key = value;

    HASHMAP_CURSOR_FIND_NEXT(nextCursor, cursor, &pair);
    return nextCursor;
}

IntObjectPair* intObjectPairHashmapCursorGet(IntObjectPairHashmapCursor cursor) {
    return HASHMAP_CURSOR_GET(cursor);
}
