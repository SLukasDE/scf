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

#ifndef ATOMLIST_H_
#define ATOMLIST_H_
#include "scf/scflist.h"
#include "scf/atomtype.h"
#include <stdlib.h>

/* *******************************************************************/
/* Pointer-Listenfunktionen                                          */
/* *******************************************************************/

/**
 * @typedef PtrList
 * Liste mit void*-Eintraegen
 */
TYPEDEF_LIST(PtrList, void*);
/** Cursor/Iterator eine Liste mit void*-Eintraegen */
typedef LIST_CURSOR(PtrList) PtrListCursor;

/** Initialisieren eine void*-Liste */
void ptrListInit(PtrList*);

/**
 * Hinzufuegen eines neuen Elementes in eine PtrList-Struktur
 * - PtrList: Container, der ein neues Element hinzugefuegt wird
 * @param value Element, das hinzugefuegt wird
 * @return 0 gdw. Fehler trat auf.
 */
void ptrListAdd(PtrList*, void* value);

/**
 * Loescht aktuelles Element und erhoeht den Cursor
 * @param list AusgangsListe
 * @param cursor Cursorpos, deren Element geloescht wird
 * @return Cursor des naechsten Elementes in der Liste
 */
PtrListCursor ptrListCursorRemove(PtrList* list, PtrListCursor cursor);

/**
 * Groesse einer void*-Liste
 * @return Anzahl der Elemente in der Liste.
 */
unsigned long ptrListSize(const PtrList *);

/**
 * Zeiger auf das erste Element eines Containers.
 * @return Cursor, der aus das erste Element des Container zeigt.
 */
PtrListCursor ptrListBegin(const PtrList *);

/**
 * Zeiger auf das letzte Element eines Containers.
 * @return Cursor, der aus das letzte Element des Container zeigt.
 */
PtrListCursor ptrListEnd(const PtrList *);

/**
 * Iterierung eines PtrListCursors
 * @return Zeiger auf aktuelles Element in PtrList
 */
PtrListCursor ptrListCursorNext(PtrListCursor);

/**
 * Holen des aktuellen Elementes einer void*-Liste
 * @return aktuelles Element der void*-Liste
 */
void* ptrListCursorGet(PtrListCursor);

/* *******************************************************************/
/* Int-Listenfunktionen                                              */
/* *******************************************************************/

/**
 * @typedef IntList
 * Liste mit int-Eintraegen
 */
TYPEDEF_LIST(IntList, int);

/** Cursor/Iterator eine Liste mit int-Eintraegen */
typedef LIST_CURSOR(IntList) IntListCursor;

/** Initialisieren eine int-Liste */
void intListInit(IntList*);

/**
 * Hinzufuegen eines neuen Elementes in eine IntList-Struktur
 * - IntList: Container, dem ein neues Element hinzugefuegt wird
 * @param value Element, das hinzugefuegt wird
 * @return 0 gdw. Fehler trat auf.
 */
void intListAdd(IntList*, int value);

/**
 * Groesse einer int-Liste
 * @return Anzahl der Elemente in der Liste.
 */
size_t intListSize(IntList *);

/**
 * Zeiger auf das erste Element eines Containers.
 * @return Cursor, der aus das erste Element des Container zeigt.
 */
IntListCursor intListBegin(IntList *);

/**
 * Zeiger auf das letzte Element eines Containers.
 * @return Cursor, der aus das letzte Element des Container zeigt.
 */
IntListCursor intListEnd(IntList *);

/**
 * Iterierung eines IntListCursors
 * @return Zeiger auf aktuelles Element im IntList
 */
IntListCursor intListCursorNext(IntListCursor);

/**
 * Holen des aktuellen Elementes einer int-Liste
 * @return aktuelles Element der int-Liste
 */
int intListCursorGet(IntListCursor);

/**
 * Loescht aktuelles Element und erhoeht den Cursor
 * @param list AusgangsListe
 * @param cursor Cursorpos, deren Element geloescht wird
 * @return Cursor des naechsten Elementes in der Liste
 */
IntListCursor intListCursorRemove(IntList *list, IntListCursor cursor);

IntListCursor intListFind(IntList *list, IntListCursor first, IntListCursor last, int value);

/* *******************************************************************/

/* *******************************************************************/
/* Double-Listenfunktionen                                           */
/* *******************************************************************/

/**
 * @typedef DoubleList
 * Liste mit double-Eintraegen
 */
TYPEDEF_LIST(DoubleList, double);
/** Cursor/Iterator eine Liste mit double-Eintraegen */
typedef LIST_CURSOR(DoubleList) DoubleListCursor;

/** Initialisieren eine double-Liste */
void doubleListInit(DoubleList*);

/**
 * Hinzufuegen eines neuen Elementes in eine DoubleList-Struktur
 * - DoubleList: Container, der ein neues Element hinzugefuegt wird
 * @param value Element, das hinzugefuegt wird
 * @return 0 gdw. Fehler trat auf.
 */
void doubleListAdd(DoubleList*, double value);

/**
 * Groesse einer double-Liste
 *  * @return Anzahl der Elemente in der Liste.
 */
size_t doubleListSize(DoubleList *);

/**
 * Zeiger auf das erste Element eines Containers.
 * @return Cursor, der aus das erste Element des Container zeigt.
 */
DoubleListCursor doubleListBegin(DoubleList *);

/**
 * Zeiger auf das letzte Element eines Containers.
 * @return Cursor, der aus das letzte Element des Container zeigt.
 */
DoubleListCursor doubleListEnd(DoubleList *);

/**
 * Iterierung eines DoubleListCursors
 * @return Zeiger auf aktuelles Element im DoubleList
 */
DoubleListCursor doubleListCursorNext(DoubleListCursor);

/**
 * Holen des aktuellen Elementes einer double-Liste
 * @return aktuelles Element der double-Liste
 */
double doubleListCursorGet(DoubleListCursor);

/* *******************************************************************/
/* Int-Object-Pair-Listenfunktionen                                  */
/* *******************************************************************/

/**
 * @typedef Int-Object-Pair-List
 * Liste mit Int-Object-Pair-Eintraegen
 */
TYPEDEF_LIST(IntObjectPairList, IntObjectPair);
/** Cursor/Iterator eine Liste mit IntObjectPair-Eintraegen            */
typedef LIST_CURSOR(IntObjectPairList) IntObjectPairListCursor;

void intObjectPairListInit(IntObjectPairList*);
void intObjectPairListAdd(IntObjectPairList*, IntObjectPair value);
size_t intObjectPairListSize(IntObjectPairList *);
IntObjectPairListCursor intObjectPairListBegin(IntObjectPairList *);
IntObjectPairListCursor intObjectPairListEnd(IntObjectPairList *);
IntObjectPairListCursor intObjectPairListCursorNext(IntObjectPairListCursor);
IntObjectPair intObjectPairListCursorGet(IntObjectPairListCursor);

/* *******************************************************************/

/* *******************************************************************/
/* Int-Int-Pair-Listenfunktionen                                     */
/* *******************************************************************/

/**
 * @typedef Int-Int-Pair-List
 * Liste mit double-Eintraegen
 */
TYPEDEF_LIST(IntIntPairList, IntIntPair);
/** Cursor/Iterator eine Liste mit IntIntPair-Eintraegen            */
typedef LIST_CURSOR(IntIntPairList) IntIntPairListCursor;

void intIntPairListInit(IntIntPairList*);
void intIntPairListAdd(IntIntPairList*, IntIntPair value);
size_t intIntPairListSize(IntIntPairList *);
IntIntPairListCursor intIntPairListBegin(IntIntPairList *);
IntIntPairListCursor intIntPairListEnd(IntIntPairList *);
IntIntPairListCursor intIntPairListCursorNext(IntIntPairListCursor);
IntIntPair intIntPairListCursorGet(IntIntPairListCursor);

/* *******************************************************************/

#endif /* ATOMLIST_H_ */
