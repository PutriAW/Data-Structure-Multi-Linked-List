#ifndef CHILD_H_INCLUDED
#define CHILD_H_INCLUDED


#include <iostream>
#include <string>
using namespace std;

#define next(P) P->next
#define first(L) L.first
#define info(P) P->info

typedef string infotype_followers;
typedef struct elm_followers *address_followers;

struct elm_followers{
    infotype_followers info;
    address_followers next;
};

struct List_followers{
    address_followers first;
};

void createList_followers(List_followers &L);
address_followers alokasi_f(infotype_followers x);
void dealokasi_f(address_followers &P);
void insertFirst_f(List_followers &L, address_followers P);
void insertLast_f(List_followers &L, address_followers P);
void insertAfter_f(List_followers &L,address_followers Prec, address_followers P);
void deleteFirst_f(List_followers &L, address_followers &P);
void deleteLast_f(List_followers &L, address_followers &P);
void deleteAfter_f(List_followers &L,address_followers Prec, address_followers &P);
address_followers findElm_f(List_followers L, infotype_followers x);
void printInfo_f(List_followers L);
void sorting_f(List_followers &L);



#endif // CHILD_H_INCLUDED
