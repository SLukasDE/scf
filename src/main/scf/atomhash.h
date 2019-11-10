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

#ifndef ATOMHASH_H_
#define ATOMHASH_H_

#include "scf/scfhash.h"
#include "scf/atomtype.h"
#include <stdlib.h>

/* *******************************************************************/
/* Int-Hashmapfunktionen                                                 */
/* *******************************************************************/

/**
 * @typedef IntHashmap
 * Hashmap mit int-Eintraegen
 */
#define INT_HASHMAP_SIZE 10000

TYPEDEF_HASHMAP(IntHashmap, int, INT_HASHMAP_SIZE);
typedef HASHMAP_CURSOR(IntHashmap) IntHashmapCursor;

/** Initialisieren eine IntHashmap */
void intHashmapInit(IntHashmap* cont);

/**
 * Groesse der IntHashmap
 * @return Anzahl der Elemente in der Hashmap.
 */
size_t intHashmapSize(IntHashmap* cont);

/**
 * Hinzufuegen eines neuen Elementes in eine IntHashmap-Struktur
 * - IntHashmap: Container, dem ein neues Element hinzugefuegt wird
 * @param value Element, das hinzugefuegt wird
 * @return 0 gdw. Fehler trat auf.
 */
void intHashmapAdd(IntHashmap* cont, int value);

/**
 * Loescht aktuelles Element und erhoeht den Cursor
 * @param cont Ausgangs-Hashmap
 * @param cursor Cursorpos, deren Element geloescht wird
 * @return Cursor des naechsten Elementes in der Liste
 */
IntHashmapCursor intHashmapCursorRemove(IntHashmapCursor cursor);

/**
 * Cursor auf das erste Element eines Containers.
 * @return Cursor, der aus das erste Element des Container zeigt.
 */
IntHashmapCursor intHashmapBegin(IntHashmap* cont);

/**
 * Cursor auf das letzte Element eines Containers.
 * @return Cursor, der aus das letzte Element des Container zeigt.
 */
IntHashmapCursor intHashmapEnd(IntHashmap* cont);

/**
 * Iterierung eines IntHashmapCursors
 * @return Cursor auf aktuelles Element in IntHashmap
 */
IntHashmapCursor intHashmapCursorNext(IntHashmapCursor);

/**
 * Find in Hashmap
 * @return Cursor auf erstes gefundene Element
 */
IntHashmapCursor intHashmapFind(IntHashmap* cont, int value);

/**
 * Find in Hashmap
 * @return Cursor auf naechstes gefundene Element
 */
IntHashmapCursor intHashmapFindNext(IntHashmapCursor cursor, int value);

/**
 * Holen des aktuellen Elementes einer IntHashmap
 * @return aktuelles Element der IntHashmap
 */
int intHashmapCursorGet(IntHashmapCursor cursor);

/* *******************************************************************/

TYPEDEF_HASHMAP(IntObjectPairHashmap, IntObjectPair*, INT_HASHMAP_SIZE);
typedef HASHMAP_CURSOR(IntObjectPairHashmap) IntObjectPairHashmapCursor;

void intObjectPairHashmapInit(IntObjectPairHashmap* cont);
size_t intObjectPairHashmapSize(IntObjectPairHashmap* cont);
void intObjectPairHashmapAdd(IntObjectPairHashmap* cont, IntObjectPair* value);
IntObjectPairHashmapCursor intObjectPairHashmapCursorRemove(IntObjectPairHashmapCursor cursor);
IntObjectPairHashmapCursor intObjectPairHashmapBegin(IntObjectPairHashmap* cont);
IntObjectPairHashmapCursor intObjectPairHashmapEnd(IntObjectPairHashmap* cont);
IntObjectPairHashmapCursor intObjectPairHashmapCursorNext(IntObjectPairHashmapCursor);
IntObjectPairHashmapCursor intObjectPairHashmapFind(IntObjectPairHashmap* cont, int value);
IntObjectPairHashmapCursor intObjectPairHashmapFindNext(IntObjectPairHashmapCursor cursor, int value);
IntObjectPair* intObjectPairHashmapCursorGet(IntObjectPairHashmapCursor cursor);

#endif /* ATOMHASH_H_ */
