
/* Hlavièkový soubor pro c016.h - Tabulka s Rozptýlenými Polo¾kami,
**  obsahuje jednak nutné includes a externované promìnné,
**  ale rovne¾ definici datových typù. Tento soubor neupravujte!
**  Téma:  Tabulka s explicitnì zøetìzenými synonymy
**                      První implementace: Petr Pøikryl, prosinec 1994
**                      Do jazyka C prepsal a upravil: Vaclav Topinka, 2005
**                      Úpravy: Karel Masaøík, øíjen 2012
**
***/


#ifndef _HASHTABLE_H_
#define _HASHTABLE_H_

#include <stdlib.h>
#include <string.h>

extern int solved;			/* externi promenna pouzivana v testeru */

/* Maximální velikost pole pro implementaci
   vyhledávací tabulky. Øe¹ené procedury v¹ak
   vyu¾ívají pouze HTSIZE prvkù pole (viz deklarace této promìnné).
*/
#define MAX_HTSIZE 101

/* typ klíèe (napøíklad identifikace zbo¾í) */
typedef char* tKey;

/* typ obsahu (napøíklad cena zbo¾í) */
typedef float tData;

/*Datová polo¾ka TRP s explicitnì øetìzenými synonymy*/
 typedef struct tHTItem{
	tKey key;				/* klíè  */
	tData data;				/* obsah */
	struct tHTItem* ptrnext;	/* ukazatel na dal¹í synonymum */
} tHTItem;

/* TRP s explicitnì zøetìzenými synonymy. */
typedef tHTItem* tHTable[MAX_HTSIZE];

/* Pro úèely testování je vhodné mít mo¾nost volby velikosti pole,
   kterým je vyhledávací tabulka implementována. Fyzicky je deklarováno
   pole o rozmìru MAX_HTSIZE, ale pøi implementaci va¹ich procedur uva¾ujte
   velikost HTSIZE.  Ve skriptu se pøed voláním øe¹ených procedur musí
   objevit pøíkaz HTSIZE N, kde N je velikost po¾adovaného prostoru.
   
   POZOR! Pro správnou funkci TRP musí být hodnota této promìnné prvoèíslem.
*/
extern int HTSIZE;

/* Hlavièky øe¹ených procedur a funkcí. */

int hashCode ( tKey key );

void htInit ( tHTable* ptrht );

tHTItem* htSearch ( tHTable* ptrht, tKey key );

void htInsert ( tHTable* ptrht, tKey key, tData data );

tData* htRead ( tHTable* ptrht, tKey key );

void htDelete ( tHTable* ptrht, tKey key );

void htClearAll ( tHTable* ptrht );

#endif
