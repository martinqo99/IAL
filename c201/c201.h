
/* Pøedmìt: Algoritmy (IAL) - FIT VUT v Brnì
 * Hlavièkový soubor pro c201.c (Jednosmìrnì vázaný lineární seznam)
 * Vytvoøil: Martin Tuèek, záøí 2005
 * Upravil: Bohuslav Køena, øíjen 2009
 * 
 *
 * Tento soubor, prosíme, neupravujte! 
 * Plese, do not change this file! 
 */
 
#include<stdio.h>
#include<stdlib.h>
#include<stdarg.h>

#define TRUE 1
#define FALSE 0
                                           /* Indikace, zda byl pøíklad øe¹en */
                                   /* Detects whether the task is implemented */
extern int solved;                         
                                                            /* Indikace chyby */
                                                                /* Error flag */
extern int errflg;
                                                             /* Prvek seznamu */
                                                /* Definition of list element */
typedef struct tElem {
    struct tElem *ptr;
    int data;
} *tElemPtr;	               
                                                            /* Vlastní seznam */
                                                        /* Definition of list */
typedef struct { 
    tElemPtr Act;
    tElemPtr First;
} tList;
                                                   /* Funkce pro implementaci */
                                             /* Funkctionst to be implemented */
void InitList (tList *);
void DisposeList (tList *);
void InsertFirst (tList *, int);
void First (tList *);
void CopyFirst (tList *, int *);
void DeleteFirst (tList *);
void PostDelete (tList *);
void PostInsert (tList *, int);
void Succ (tList *);
void Copy (tList *, int *);	
void Actualize (tList *, int );
int  Active (tList *);

