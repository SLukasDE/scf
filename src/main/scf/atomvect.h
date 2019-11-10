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

#ifndef ATOMVECT_H_
#define ATOMVECT_H_

#include "scf/scfvect.h"
#include "scf/atomtype.h"
#include "scf/atomlist.h"

/* *******************************************************************/
/* Int-Vectorfunktionen                                                 */
/* *******************************************************************/

/**
 * @typedef IntVector
 * Vector mit int-Eintraegen
 */
TYPEDEF_VECTOR(IntVector, int);
/** Cursor/Iterator eines Vectors mit int-Eintraegen */
typedef VECTOR_CURSOR(IntVector) IntVectorCursor;

/** Initialisiere eine int-Vector */
void intVectorInit(IntVector* cont, size_t size);

/**
 * Hinzufuegen eines neuen Elementes in eine IntVector-Struktur
 * - IntVector: Container, dem ein neues Element hinzugefuegt wird
 * @param value Element, das hinzugefuegt wird
 * @return 0 gdw. Fehler trat auf.
 */
void intVectorAdd(IntVector* cont, int value);

/**
 * Groesse eines int-Vectors
 * @return Anzahl der Elemente in dem Vector.
 */
size_t intVectorSize(IntVector* cont);

/**
 * Zeiger auf das erste Element eines Containers.
 * @return Cursor, der aus das erste Element des Container zeigt.
 */
IntVectorCursor intVectorBegin(IntVector* cont);

/**
 * Zeiger auf das letzte Element eines Containers.
 * @return Cursor, der aus das letzte Element des Container zeigt.
 */
IntVectorCursor intVectorEnd(IntVector* cont);

/**
 * Iterierung eines IntVectorCursors
 * @return Zeiger auf aktuelles Element im IntVector
 */
IntVectorCursor intVectorCursorNext(IntVectorCursor cur);

IntVectorCursor intVectorFindIf(
        IntVectorCursor begin, IntVectorCursor end,
        int (*condition)(int value, void*), void* data);

/**
 * Holen des aktuellen Elementes eines int-Vectors
 * @return aktuelles Element der int-Liste
 */
int intVectorCursorGet(IntVectorCursor cursor);

void intVectorSort(IntVector* cont);

void copyIntListToIntVector(IntVector *dest, IntList *src);

void copyIntVectorToIntList(IntList *dest, IntVector *src);


/* *******************************************************************/
/* Double-Vectorfunktionen                                           */
/* *******************************************************************/

/**
 * @typedef DoubleVector
 * Vector mit double-Eintraegen
 */
TYPEDEF_VECTOR(DoubleVector, double);
/** Cursor/Iterator eines Vectors mit double-Eintraegen */
typedef VECTOR_CURSOR(DoubleVector) DoubleVectorCursor;

/** Initialisieren eine double-Vector */
void doubleVectorInit(DoubleVector* cont, size_t size);

/**
 * Hinzufuegen eines neuen Elementes in eine DoubleVector-Struktur
 * - DoubleVector: Container, dem ein neues Element hinzugefuegt wird
 * @param value Element, das hinzugefuegt wird
 * @return 0 gdw. Fehler trat auf.
 */
void doubleVectorAdd(DoubleVector* cont, double value);

/**
 * Groesse eines double-Vectors
 * @return Anzahl der Elemente in dem Vector.
 */
size_t doubleVectorSize(DoubleVector* cont);

size_t doubleVectorMaxSize(DoubleVector* cont);

/**
 * Zeiger auf das erste Element eines Containers.
 * @return Cursor, der aus das erste Element des Container zeigt.
 */
DoubleVectorCursor doubleVectorBegin(DoubleVector* cont);

/**
 * Zeiger auf das letzte Element eines Containers.
 * @return Cursor, der aus das letzte Element des Container zeigt.
 */
DoubleVectorCursor doubleVectorEnd(DoubleVector* cont);

/**
 * Iterierung eines DoubleVectorCursors
 * @return Zeiger auf aktuelles Element im DoubleVector
 */
DoubleVectorCursor doubleVectorCursorNext(
        DoubleVectorCursor cur);

DoubleVectorCursor doubleVectorFindIf(
        DoubleVectorCursor begin, DoubleVectorCursor end,
        int (*condition)(double value, void*), void* data);

/**
 * Holen des aktuellen Elementes eines double-Vectors
 * @return aktuelles Element der double-Liste
 */
double doubleVectorCursorGet(DoubleVectorCursor cursor);

double* doubleVectorAt(DoubleVector* cont, int index);

void doubleVectorSort(DoubleVector* cont);

/* *******************************************************************/

/* *******************************************************************/
/* Int-Object-Pair-Vectorfunktionen                                  */
/* *******************************************************************/

/**
 * @typedef IntObjectPairVector
 * Vector mit Eintraegen aus einem int-key gepaart
 * mit einem void pointer
 */
TYPEDEF_VECTOR(IntObjectPairVector, IntObjectPair);
/** Cursor/Iterator eines Vectors mit IntObjectPair-Eintraegen */
typedef VECTOR_CURSOR(IntObjectPairVector) IntObjectPairVectorCursor;

/** Initialisieren eine IntObjectPair-Vector */
void intObjectPairVectorInit(IntObjectPairVector* cont, size_t size);

/**
 * Hinzufuegen eines Elementes in eine IntObjectPairVector-Struktur
 * - IntObjectPairVector: Container, dem ein Element hinzugefuegt wird
 * @param value Element, das hinzugefuegt wird
 * @return 0 gdw. Fehler trat auf.
 */
void intObjectPairVectorAdd(IntObjectPairVector* cont, IntObjectPair value);

/**
 * Groesse eines IntObjectPair-Vectors
 * @return Anzahl der Elemente in dem Vector.
 */
size_t intObjectPairVectorSize(IntObjectPairVector* cont);

/**
 * Zeiger auf das erste Element eines Containers.
 * @return Cursor, der aus das erste Element des Container zeigt.
 */
IntObjectPairVectorCursor intObjectPairVectorBegin(IntObjectPairVector* cont);

/**
 * Zeiger auf das letzte Element eines Containers.
 * @return Cursor, der aus das letzte Element des Container zeigt.
 */
IntObjectPairVectorCursor intObjectPairVectorEnd(IntObjectPairVector* cont);

/**
 * Iterierung eines IntObjectPairVectorCursors
 * @return Zeiger auf aktuelles Element im IntObjectPairVector
 */
IntObjectPairVectorCursor intObjectPairVectorCursorNext(IntObjectPairVectorCursor cur);

IntObjectPairVectorCursor intObjectPairVectorFindIf(IntObjectPairVectorCursor begin, IntObjectPairVectorCursor end,
        int (*condition)(IntObjectPair value, void*), void* data);

/**
 * Holen des aktuellen Elementes eines int-Vectors
 * @return aktuelles Element der IntObjectPair-Liste
 */
IntObjectPair intObjectPairVectorCursorGet(IntObjectPairVectorCursor cursor);

void intObjectPairVectorSort(IntObjectPairVector* cont);

/* *******************************************************************/
/* Object-Vectorfunktionen                                           */
/* *******************************************************************/

/**
 * @typedef ObjectVector
 * Vector mit void*-Eintraegen
 */
TYPEDEF_VECTOR(ObjectVector, void*);
typedef VECTOR_CURSOR(ObjectVector) ObjectVectorCursor;

void objectVectorInit(ObjectVector* cont, size_t size);

void objectVectorAdd(ObjectVector* cont, void* value);

size_t objectVectorSize(ObjectVector* cont);

ObjectVectorCursor objectVectorBegin(ObjectVector* cont);

ObjectVectorCursor objectVectorEnd(ObjectVector* cont);

ObjectVectorCursor objectVectorCursorNext(
        ObjectVectorCursor cur);

ObjectVectorCursor objectVectorFindIf(
        ObjectVectorCursor begin, ObjectVectorCursor end,
        int (*condition)(void*, void*), void* data);

void* objectVectorCursorGet(ObjectVectorCursor cursor);

void objectVectorSort(ObjectVector* cont, int (*objectVectorComp)(const void* first, const void* second));

/* *******************************************************************/

#endif /* ATOMVECT_H_ */
