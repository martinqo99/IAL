
/* Hlavièkový soubor pro c402.c - nerekurzívní implementace operací nad BVS
obsahuje jednak nutné knihovny a externí promìnné, ale rovnì¾ definici datových
typù, se kterými se pracuje v pøíslu¹ných úlohách. Nemodifikovat! */

/* ********************** SOUBOR S HLAVIÈKOU ********************** */
/* ********************** ------------------ ********************** */

/*  Pøedmìt: Algoritmy (IAL) - FIT (Fakulta Informaèních Technologií)
    Hlavièka pro soubor: c402.c
    Vytvoøil: Martin Tuèek, záøí 2005
    Upravil: Bohuslav Køena, listopad 2009                           
    Upravil: Karel Masarik, rijen 2012                               */
/* ***************************************************************** */

#include<stdio.h>
#include<stdlib.h>
#include<stdarg.h>
#include<stdbool.h>

#define FALSE 0
#define TRUE 1
#define MAXSTACK 30                      /* maximální poèet prvkù v zásobníku */

extern int solved; 			                  /* indikace, zda byla funkce øe¹ena */

typedef struct tBTNode	{                                      /* uzel stromu */
    int Cont;                                         /* u¾iteèný obsah uzlu  */
    struct tBTNode * LPtr;                                  /* levý podstrom  */
    struct tBTNode * RPtr; 	  	                            /* pravý podstrom */
} *tBTNodePtr;                                     /* ukazatel na uzel stromu */

/* pomocné zásobníky */
typedef struct	{                          /* zásobník hodnot typu tBTNodePtr */
    tBTNodePtr a[MAXSTACK];
    int top;
} tStackP;

typedef struct {                                 /* zásobník hodnot typu bool */
    bool a[MAXSTACK];
    int top;
} tStackB;

/***prototypes***/
void BTInit (tBTNodePtr * );
void BTInsert (tBTNodePtr *, int );

void Leftmost_Preorder(tBTNodePtr, tStackP *);
void BTPreorder(tBTNodePtr );

void Leftmost_Inorder(tBTNodePtr, tStackP *);
void BTInorder(tBTNodePtr );

void Leftmost_Postorder(tBTNodePtr, tStackP *, tStackB *);
void BTPostorder(tBTNodePtr );

void BTDisposeTree(tBTNodePtr *);
/********end of prototypes******/

/* konec c402.h */
