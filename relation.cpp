#include "relation.h"

void createList_relation(List_relasi &L)
{
    first(L) = NULL;
}
address_relasi alokasi(address_followers F)
{
    address_relasi P = new elm_relasi;
    info(P) = F;
    next(P) = NULL;
    return P;
}

void insertFirst(List_relasi &L, address_relasi P)
{
    if(first(L) == NULL)
    {
        first(L) = P;
    }
    else
    {
        next(P) = first(L);
        first(L) = P;
    }
}

void insertLast(List_relasi &L, address_relasi P)
{
    if (first(L) != NULL)
    {
        address_relasi Q = first(L);
        while (next(Q) != NULL)
        {
            Q = next(Q);
        }
        next(Q) = P;
    }
    else
    {
        insertFirst(L,P);
    }
}

void insertAfter(List_relasi &L, address_relasi Prec, address_relasi P)
{
    if (Prec != NULL)
    {
        if (first(L)== NULL)
        {
            insertFirst(L,P);
        }
        else if (next(Prec)== NULL)
        {
            insertLast(L,P);
        }
        else
        {
            next(P) = next(Prec);
            next(Prec) = P;
        }
    }
}

void deleteFirst(List_relasi &L, address_relasi &P)
{
    if(first(L) != NULL)
    {
        address_relasi P = first(L);
        first(L) = next(P);
        next(P) = NULL;
        dealokasi(P);
    }
    else
    {
        cout<<"List sudah kosong"<<endl;
    }
}

void deleteLast(List_relasi &L, address_relasi &P)
{
    address_relasi Q = first(L);

    if(first(L)!= NULL)
    {
        if(next(first(L)) == NULL)
            deleteFirst(L,P);
        else
        {
            while(next(next(Q)) != NULL)
            {
                Q = next(Q);
            }
            P = next(Q);
            next(Q) = NULL;
        }
    }
}

void deleteAfter(List_relasi &L, address_relasi Prec, address_relasi &P)
{
     if (first(L)== NULL)
    {
        cout<<"Kosong";
    }
    else
    {
        if (Prec != NULL)
        {
            address_relasi Q = first(L);
            if(next(first(L))== NULL )
            {
                P = first(L);
                first(L) = NULL;
            }
            else if (next(next(Prec)) == NULL)
            {
                deleteLast(L,P);
            }
            else
            {
                P = next(Prec);
                next(Prec) = next(P);
                next(P) = NULL;
            }
        }
    }
}

void dealokasi(address_relasi &P)
{
    delete P;
}

address_relasi findElm(List_relasi L, address_followers F)
{
    address_relasi P = first(L);
    while(P !=NULL)
    {
        if(P != NULL && info(P) == F)
        {
            return P;
        }
        else
        {
            return P;
        }
        P = next(P);
    }
}

void printInfo(List_relasi L)
{
    if (L.first == NULL )
        cout<<"EMPTY"<<endl;
    else
    {
        address_relasi P = first(L);
        while(P != NULL)
        {
            cout<<"==> "<<info(info(P))<<endl;
            P = next(P);
        }
    }
}
