
/* Pøedmìt: Algoritmy (IAL) - FIT VUT v Brnì
 * Hlavièkový soubor pro c206.c (Dvousmìrnì vázaný lineární seznam)
 * Vytvoøil: Martin Tuèek, záøí 2005
 * Upravil: Bohuslav Køena, øíjen 2008
 *  
 *  Tento soubor, prosíme, neupravujte!  
 */

#include<stdio.h>
#include<stdlib.h>

#define FALSE 0
#define TRUE 1

extern int errflg;
extern int solved;
 
typedef struct tDLElem {                /* prvek dvouosmìrnì vázaného seznamu */ 
        int data;                                            /* u¾iteèná data */
        struct tDLElem *lptr;          /* ukazatel na pøedchozí prvek seznamu */
        struct tDLElem *rptr;        /* ukazatel na následující prvek seznamu */
} *tDLElemPtr;

typedef struct {                                  /* dvousmìrnì vázaný seznam */
    tDLElemPtr First;                      /* ukazatel na první prvek seznamu */
    tDLElemPtr Act;                     /* ukazatel na aktuální prvek seznamu */
    tDLElemPtr Last;                    /* ukazatel na posledni prvek seznamu */
} tDLList;

                                             /* prototypy jednotlivých funkcí */
void DLInitList (tDLList *);
void DLDisposeList (tDLList *);
void DLInsertFirst (tDLList *, int);
void DLInsertLast(tDLList *, int);
void DLFirst (tDLList *);
void DLLast (tDLList *);
void DLCopyFirst (tDLList *, int *);
void DLCopyLast (tDLList *, int *);
void DLDeleteFirst (tDLList *);
void DLDeleteLast (tDLList *);
void DLPostDelete (tDLList *);
void DLPreDelete (tDLList *);
void DLPostInsert (tDLList *, int);
void DLPreInsert (tDLList *, int);
void DLCopy (tDLList *, int *);
void DLActualize (tDLList *, int);
void DLSucc (tDLList *);
void DLPred (tDLList *);
int DLActive (tDLList *);

