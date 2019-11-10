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

#ifndef SCF_CONTAINER_H_
#define SCF_CONTAINER_H_

/*
 * Implementiert ein typedef mit dem Namen CONTAINER_TYPE, der einen
 * Container realisiert, der Werte vom Typ VALUE_TYPE speichert.
 * Abhaengig vom verwendeten Container folgen noch weitere Parameter.
 *
 * #define TYPEDEF_CONTAINER(CONTAINER_TYPE,VALUE_TYPE,...)
 */

/*
 * Liefert den Typ der einen internen Eintrag im angegebenen Container
 * repraesentiert.
 *
 * Dieses Makro existiert nicht fuer alle Container-Typen, sondern nur
 * fuer die Container-Typen, die beim Makro CONTAINER_ADD einen
 * Pointer auf den Entry-Typ benoetigt.
 *
 * #define CONTAINER_ENTRY(CONTAINER_TYPE)
 */

/**
 * Liefert den Cursortyp zum angegebenen Containertyps CONTAINER_TYPE
 */
#define CONTAINER_CURSOR(CONTAINER_TYPE) \
        CONTAINER_TYPE##_cursor*

/**
 * Initialisiert die allgemeinen Stellen eines jeden Container. Fuer
 * jeden konkreten Container exisitert eine spezialisierte Version zum
 * Initialisieren des Containers. Dies version wird nie direkt
 * verwendet, sondern wird vom der Container spezifischen Initiali-
 * sierungsmakro aufgerufen.
 */
#define CONTAINER_INIT(CONTAINER_TYPE,container) \
        (container).size = 0;

/**
 * Liefert die Anzahl an gespeicherten Elementen eines jeden
 * Containers.
 */
#define CONTAINER_SIZE(container) \
        ((container).size)

/*
 * Fuegt in dem angegebenen Container ein neues Element hinzu, welches
 * ebenfalls angegeben wurde. Anbhaengig vom konkreten Container-Typ
 * koennen noch weitere Arkgumente erforderlich sein.
 *
 * I.d.R. ist zuvor noch eine Instanz des Entry-Typs zu erzeugen,
 * dessen Pointer als 3. Argument uebergeben wird. Dieses Vorgehen
 * ermoeglicht es Einfluss auf die Speicherveraltung zu nehmen, wenn
 * z.B. statt malloc eine andere Variante verwendet werden soll.
 * Der Entry-Typ laesst sich bei den Container-Typen, die das beim
 * Makro CONTAINER_ADD das Argument benoetigen mit dem Makro
 * CONTAINER_ENTRY(CONTAINER_TYPE) erfragen.
 *
 * #define CONTAINER_ADD(container,value,...)
 */

/*
 * Liefert den Cursor auf das erste Element des Containers, sofern
 * der Container nicht leer ist. Ansonsten wird CONTAINER_END
 * zurueck gegeben.
 *
 * Hierfuer existiert lediglich eine spezialisierte Version fuer
 * jeden Container-Typ.
 *
 * #define CONTAINER_BEGIN(container)
 */

/*
 * Liefert den Cursor auf das Element, dass dem letzten
 * Element des Container folgt (EOF).
 *
 * Hierfuer existiert lediglich eine spezialisierte Version fuer
 * jeden Container-Typ.
 *
 * #define CONTAINER_END(container)
 */

/*
 * Weist 'next_cursor' den Cursor zu, der dem uebergebenen Cursor
 * 'current_cursor' folgt.
 *
 * #define CONTAINER_CURSOR_NEXT(current_cursor,next_cursor)
 */

/*
 * Liefert das gespeicherte Element im Container auf den der ueber-
 * gebene Cursor zeigt.
 *
 * #define CONTAINER_CURSOR_GET(cursor)
 */

#endif /* SCF_CONTAINER_H_ */
