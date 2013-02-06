
/* Hlavièkový soubor pro c401.c - rekurzívní implementace operaci nad BVS,
obsahuje jednak nutné knihovny a externí promìnné, ale rovnì¾ 
definici datových typù, se kterými se pracuje v jdenotlivých
funkcích. Nemodifikovat! */

/* ********************** SOUBOR S HLAVIÈKOU ********************** */
/* ********************** ------------------ ********************** */

/*  vytvoèil: Martin Tuèek
    pøedmìt: Algoritmy (IAL) - FIT (Fakulta Informacnich Technologií)
    hlavicka pro soubor: c401.c
    datum: záøí 2005
    upravil: Bohuslav Køena, listopad 2009
    upravil: Karel Masarik, rijen 2012                               */
/* ***************************************************************** */

#include<stdio.h>
#include<stdlib.h>
#include<stdarg.h>

#define TRUE 1
#define FALSE 0

extern int solved;                        /* indikace, zda byla funkce øe¹ena */

/* uzel stromu */
                                                                                                            
typedef struct tBSTNode {
	char Key;			                                                      /* klíè */
	int BSTNodeCont;                                            /* u¾iteèný obsah uzlu */
	struct tBSTNode * LPtr;                                    /* levý podstrom */
	struct tBSTNode * RPtr;                                   /* pravý podstrom */
} *tBSTNodePtr;	

/* prototypy funkcí */

void BSTInit   (tBSTNodePtr *);
int BSTSearch  (tBSTNodePtr, char, int *);
void BSTInsert (tBSTNodePtr *, char, int);
void BSTDelete (tBSTNodePtr *, char);
void BSTDispose(tBSTNodePtr *);

/* konec c401.h */
