	
/* c206.c **********************************************************}
{* Téma: Dvousmìrnì vázanı lineární seznam
**
**                   Návrh a referenèní implementace: Bohuslav Køena, øíjen 2001
**                            Pøepracované do jazyka C: Martin Tuèek, øíjen 2004
**                                             Úpravy: Bohuslav Køena, záøí 2012
**
** Implementujte abstraktní datovı typ dvousmìrnì vázanı lineární seznam.
** U¾iteènım obsahem prvku seznamu je hodnota typu int.
** Seznam bude jako datová abstrakce reprezentován promìnnou
** typu tDLList (DL znamená Double-Linked a slou¾í pro odli¹ení
** jmen konstant, typù a funkcí od jmen u jednosmìrnì vázaného lineárního
** seznamu). Definici konstant a typù naleznete v hlavièkovém souboru c206.h.
**
** Va¹ím úkolem je implementovat následující operace, které spolu
** s vı¹e uvedenou datovou èástí abstrakce tvoøí abstraktní datovı typ
** obousmìrnì vázanı lineární seznam:
**
**      DLInitList ...... inicializace seznamu pøed prvním pou¾itím,
**      DLDisposeList ... zru¹ení v¹ech prvkù seznamu,
**      DLInsertFirst ... vlo¾ení prvku na zaèátek seznamu,
**      DLInsertLast .... vlo¾ení prvku na konec seznamu, 
**      DLFirst ......... nastavení aktivity na první prvek,
**      DLLast .......... nastavení aktivity na poslední prvek, 
**      DLCopyFirst ..... vrací hodnotu prvního prvku,
**      DLCopyLast ...... vrací hodnotu posledního prvku, 
**      DLDeleteFirst ... zru¹í první prvek seznamu,
**      DLDeleteLast .... zru¹í poslední prvek seznamu, 
**      DLPostDelete .... ru¹í prvek za aktivním prvkem,
**      DLPreDelete ..... ru¹í prvek pøed aktivním prvkem, 
**      DLPostInsert .... vlo¾í novı prvek za aktivní prvek seznamu,
**      DLPreInsert ..... vlo¾í novı prvek pøed aktivní prvek seznamu,
**      DLCopy .......... vrací hodnotu aktivního prvku,
**      DLActualize ..... pøepí¹e obsah aktivního prvku novou hodnotou,
**      DLSucc .......... posune aktivitu na dal¹í prvek seznamu,
**      DLPred .......... posune aktivitu na pøedchozí prvek seznamu, 
**      DLActive ........ zji¹»uje aktivitu seznamu.
**
** Pøi implementaci jednotlivıch funkcí nevolejte ¾ádnou z funkcí
** implementovanıch v rámci tohoto pøíkladu, není-li u funkce
** explicitnì uvedeno nìco jiného.
**
** Nemusíte o¹etøovat situaci, kdy místo legálního ukazatele na seznam 
** pøedá nìkdo jako parametr hodnotu NULL.
**
** Svou implementaci vhodnì komentujte!
**
** Terminologická poznámka: Jazyk C nepou¾ívá pojem procedura.
** Proto zde pou¾íváme pojem funkce i pro operace, které by byly
** v algoritmickém jazyce Pascalovského typu implemenovány jako
** procedury (v jazyce C procedurám odpovídají funkce vracející typ void).
**/

#include "c206.h"

int solved;
int errflg;

void DLError() {
/*
** Vytiskne upozornìní na to, ¾e do¹lo k chybì.
** Tato funkce bude volána z nìkterıch dále implementovanıch operací.
**/	
    printf ("*ERROR* This program has performed an illegal operation.\n");
    errflg = TRUE;             /* globální promìnná -- pøíznak o¹etøení chyby */
    return;
}

void DLInitList (tDLList *L)	{
/*
** Provede inicializaci seznamu L pøed jeho prvním pou¾itím (tzn. ¾ádná
** z následujících funkcí nebude volána nad neinicializovanım seznamem).
** Tato inicializace se nikdy nebude provádìt nad ji¾ inicializovanım
** seznamem, a proto tuto mo¾nost neo¹etøujte. V¾dy pøedpokládejte,
** ¾e neinicializované promìnné mají nedefinovanou hodnotu.
**/

 	if(!L)
		return;
			
	L->First = NULL;
	L->Act = NULL;
	L->Last = NULL;   
}

void DLDisposeList (tDLList *L)	{
/*
** Zru¹í v¹echny prvky seznamu L a uvede seznam do stavu, v jakém
** se nacházel po inicializaci. Ru¹ené prvky seznamu budou korektnì
** uvolnìny voláním operace free. 
**/

	if(!L)
		return;
	
	tDLElemPtr iterator;
	
	while((iterator = L->First)){
		L->First = iterator->rptr;
		
		free(iterator);
	}
		
	L->First = NULL;
	L->Act = NULL;
	L->Last = NULL;
}

void DLInsertFirst (tDLList *L, int val)	{
/*
** Vlo¾í novı prvek na zaèátek seznamu L.
** V pøípadì, ¾e není dostatek pamìti pro novı prvek pøi operaci malloc,
** volá funkci DLError().
**/

    if(!L)
		return;
    
    tDLElemPtr item = malloc(sizeof(struct tDLElem));
    
    if(!item){
		DLError();
		return;
	}
	
	item->data = val;
	item->lptr = NULL;
	item->rptr = L->First;
	
	//If nonempty
	if(L->First)
		L->First->lptr = item;	
	else
		L->Last = item;
	
	L->First = item;	
}

void DLInsertLast(tDLList *L, int val)	{
/*
** Vlo¾í novı prvek na konec seznamu L (symetrická operace k DLInsertFirst).
** V pøípadì, ¾e není dostatek pamìti pro novı prvek pøi operaci malloc,
** volá funkci DLError().
**/ 	

    if(!L)
		return;
    
    tDLElemPtr item = malloc(sizeof(struct tDLElem));
    
    if(!item){
		DLError();
		return;
	}
	
	item->data = val;
	item->lptr = L->Last;
	item->rptr = NULL;
	
	//If empty
	if(!L->First)
		L->First = item;
	else
		L->Last->rptr = item;
	
	L->Last = item;	
}

void DLFirst (tDLList *L)	{
/*
** Nastaví aktivitu na první prvek seznamu L.
** Funkci implementujte jako jedinı pøíkaz (nepoèítáme-li return),
** ani¾ byste testovali, zda je seznam L prázdnı.
**/

	L->Act = L->First;
}

void DLLast (tDLList *L)	{
/*
** Nastaví aktivitu na poslední prvek seznamu L.
** Funkci implementujte jako jedinı pøíkaz (nepoèítáme-li return),
** ani¾ byste testovali, zda je seznam L prázdnı.
**/
	
	L->Act = L->Last;
}

void DLCopyFirst (tDLList *L, int *val)	{
/*
** Prostøednictvím parametru val vrátí hodnotu prvního prvku seznamu L.
** Pokud je seznam L prázdnı, volá funkci DLError().
**/

	if(!L)
		return;
	
	if(!L->First){
		DLError();
		return;
	}
	
	*val = L->First->data;	
}

void DLCopyLast (tDLList *L, int *val)	{
/*
** Prostøednictvím parametru val vrátí hodnotu posledního prvku seznamu L.
** Pokud je seznam L prázdnı, volá funkci DLError().
**/
	
	if(!L)
		return;
	
	if(!L->First){
		DLError();
		return;
	}
	
	*val = L->Last->data;	
}

void DLDeleteFirst (tDLList *L)	{
/*
** Zru¹í první prvek seznamu L. Pokud byl první prvek aktivní, aktivita 
** se ztrácí. Pokud byl seznam L prázdnı, nic se nedìje.
**/

	if(!L || !L->First)
		return;
	
	tDLElemPtr iterator = L->First->rptr;
	
	if(L->First == L->Act)
		L->Act = NULL;
	
	free(L->First);
	
	L->First = iterator;
	
	if(!iterator->rptr)
		L->Last = L->First;
}	

void DLDeleteLast (tDLList *L)	{
/*
** Zru¹í poslední prvek seznamu L. Pokud byl poslední prvek aktivní,
** aktivita seznamu se ztrácí. Pokud byl seznam L prázdnı, nic se nedìje.
**/ 
	
	
 solved = FALSE;                   /* V pøípadì øe¹ení, sma¾te tento øádek! */
}

void DLPostDelete (tDLList *L)	{
/*
** Zru¹í prvek seznamu L za aktivním prvkem.
** Pokud je seznam L neaktivní nebo pokud je aktivní prvek
** posledním prvkem seznamu, nic se nedìje.
**/
	
		
 solved = FALSE;                   /* V pøípadì øe¹ení, sma¾te tento øádek! */
}

void DLPreDelete (tDLList *L)	{
/*
** Zru¹í prvek pøed aktivním prvkem seznamu L .
** Pokud je seznam L neaktivní nebo pokud je aktivní prvek
** prvním prvkem seznamu, nic se nedìje.
**/
	
			
 solved = FALSE;                   /* V pøípadì øe¹ení, sma¾te tento øádek! */
}

void DLPostInsert (tDLList *L, int val) {
/*
** Vlo¾í prvek za aktivní prvek seznamu L.
** Pokud nebyl seznam L aktivní, nic se nedìje.
** V pøípadì, ¾e není dostatek pamìti pro novı prvek pøi operaci malloc,
** volá funkci DLError().
**/
	
	
 solved = FALSE;                   /* V pøípadì øe¹ení, sma¾te tento øádek! */
}

void DLPreInsert (tDLList *L, int val)		{
/*
** Vlo¾í prvek pøed aktivní prvek seznamu L.
** Pokud nebyl seznam L aktivní, nic se nedìje.
** V pøípadì, ¾e není dostatek pamìti pro novı prvek pøi operaci malloc,
** volá funkci DLError().
**/
	
	
 solved = FALSE;                   /* V pøípadì øe¹ení, sma¾te tento øádek! */
}

void DLCopy (tDLList *L, int *val)	{
/*
** Prostøednictvím parametru val vrátí hodnotu aktivního prvku seznamu L.
** Pokud seznam L není aktivní, volá funkci DLError ().
**/
		
	
	
 solved = FALSE;                   /* V pøípadì øe¹ení, sma¾te tento øádek! */
}

void DLActualize (tDLList *L, int val) {
/*
** Pøepí¹e obsah aktivního prvku seznamu L.
** Pokud seznam L není aktivní, nedìlá nic.
**/
	
	if(!L || !L->Act)
		return;
		
	L->Act->data = val;
}

void DLSucc (tDLList *L)	{
/*
** Posune aktivitu na následující prvek seznamu L.
** Není-li seznam aktivní, nedìlá nic.
** V¹imnìte si, ¾e pøi aktivitì na posledním prvku se seznam stane neaktivním.
**/

	if(!L || !L->Act)
		return;
		
	L->Act = L->Act->rptr;
}


void DLPred (tDLList *L)	{
/*
** Posune aktivitu na pøedchozí prvek seznamu L.
** Není-li seznam aktivní, nedìlá nic.
** V¹imnìte si, ¾e pøi aktivitì na prvním prvku se seznam stane neaktivním.
**/
	
	if(!L || !L->Act)
		return;
		
	L->Act = L->Act->lptr;
}

int DLActive (tDLList *L) {		
/*
** Je-li seznam aktivní, vrací true. V opaèném pøípadì vrací false.
** Funkci implementujte jako jedinı pøíkaz.
**/
	
	
 solved = FALSE;                   /* V pøípadì øe¹ení, sma¾te tento øádek! */
}

/* Konec c206.c*/
