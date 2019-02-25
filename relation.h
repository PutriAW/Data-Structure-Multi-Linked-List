#ifndef RELATION_H_INCLUDED
#define RELATION_H_INCLUDED

#include <iostream>
using namespace std;

#include "child.h"
#define next(P) P->next
#define first(L) L.first
#define info(P) P->info

typedef struct elm_relasi *address_relasi;

struct elm_relasi{
    address_relasi next;
    address_followers info;
};

struct List_relasi {
    address_relasi first;
};

void createList_relation(List_relasi &L);
void insertFirst(List_relasi &L, address_relasi P);
void insertLast(List_relasi &L, address_relasi P);
void insertAfter(address_relasi Prec, address_relasi P);
void deleteFirst(List_relasi &L, address_relasi &P);
void deleteLast(List_relasi &L, address_relasi &P);
void deleteAfter(address_relasi Prec, address_relasi &P);
address_relasi alokasi(address_followers F);
void dealokasi(address_relasi &P);
address_relasi findElm(List_relasi L, address_followers F);
void printInfo(List_relasi L);



#endif // RELATION_H_INCLUDED
