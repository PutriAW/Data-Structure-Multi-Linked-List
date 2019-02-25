#ifndef PARENT_H_INCLUDED
#define PARENT_H_INCLUDED

using namespace std;

#include "relation.h"
#include "child.h"
#define Nil NULL
#define next(P) P->next
#define prev(P) P->prev
#define first(L) L.first
#define last(L) L.last
#define info(P) P->info
#define followers(P) P->followers

typedef string infotype_celeb ;

typedef struct elm_celeb *address_celeb;

struct elm_celeb {
    infotype_celeb info;
    address_celeb next;
    address_celeb prev;
    List_relasi followers;

};

struct List_celeb{
    address_celeb first;
    address_celeb last;
};

void createList_celeb(List_celeb &L);
void insertFirst_c(List_celeb &L, address_celeb P);
void insertLast_c(List_celeb &L, address_celeb P);
void insertAfter_c(List_celeb &L,address_celeb Prec,address_celeb P);
void deleteFirst_c(List_celeb &L, address_celeb &P);
void deleteLast_c(List_celeb &L, address_celeb &P);
void deleteAfter_c(List_celeb &L,address_celeb Prec, address_celeb &P);
address_celeb alokasi_c(string username);
void dealokasi_c(address_celeb &P);
address_celeb findElm_c (List_celeb L, infotype_celeb x);
void delete_c(List_celeb &L, address_celeb Prec ,address_celeb &P);
void printInfo_c(List_celeb L);
void printInfo_C_WF(List_celeb L);
void celebManyFolllower(List_celeb L,List_relasi R);
void follower3celebrity(List_followers F, List_celeb C,List_relasi LR);
void sorting_c(List_celeb &L);



#endif // PARENT_H_INCLUDED
