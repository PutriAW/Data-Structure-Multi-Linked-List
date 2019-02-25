#include "child.h"

void createList_followers(List_followers &L)
{
    first(L) = NULL;
}

address_followers alokasi_f(infotype_followers x)
{
    address_followers P = new elm_followers;
    info(P) = x;
    next(P) = NULL;
    return P;
}
void dealokasi_f(address_followers &P)
{
    delete(P);
    P = NULL;
};

void insertFirst_f(List_followers &L, address_followers P)
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

void insertLast_f(List_followers &L, address_followers P)
{
    if (first(L)== NULL)
    {
        insertFirst_f(L,P);
    }
    else
    {
        address_followers Q = first(L);
        while (next(Q)!= NULL)
        {
            Q = next(Q);
        }
        next(Q) = P;
    }
}

void insertAfter_f(List_followers &L, address_followers Prec, address_followers P)
{
    if (Prec != NULL)
    {
        if (first(L)== NULL)
        {
            insertFirst_f(L,P);
        }
        else if (next(Prec)== NULL)
        {
            insertLast_f(L,P);
        }
        else
        {
            next(P) = next(Prec);
            next(Prec) = P;
        }
    }
}
void deleteFirst_f(List_followers &L, address_followers &P)
{
    if (first(L)== NULL)
    {
        cout<<"Kosong";
    }
    else
    {
        P = first(L);
        if(first(L)== P)
        {
            first(L) = NULL;
            delete P;
        }
        else
        {
            first(L) = next(P);
            next(P) = NULL;
            delete P;
        }
    }
}

void deleteLast_f(List_followers &L, address_followers &P)
{
    address_followers Q = first(L);
    if (first(L)== NULL)
    {
        cout<<"Kosong";
    }
    else
    {
        if(next(first(L))== NULL)
        {
            P = first(L);
            first(L) = NULL;
        }
        else
        {
            while (next(next(Q)) != NULL)
            {
                Q = next(Q);
            }
            P = next(Q);
            next(Q) = NULL;
        }
    }
}


void deleteAfter_f(List_followers &L, address_followers Prec, address_followers &P)
{

    if (first(L)== NULL)
    {
        cout<<"Kosong";
    }
    else
    {
        if (Prec != NULL)
        {
            if(next(first(L))== NULL)
            {
                P = first(L);
                first(L) = NULL;
            }
            else if (next(next(Prec)) == NULL)
            {
                deleteLast_f(L,P);
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

void printInfo_f(List_followers L)
{
    if (L.first == NULL )
        cout<<"EMPTY"<<endl;
    else
    {
        address_followers P = first(L);
        while(P!=NULL)
        {
            cout<<"Followers: "<< info(P)<<endl;
            P = next(P);
        }
    }
}

address_followers findElm_f(List_followers L, infotype_followers x)
{
    address_followers P = first(L);
    while(P != NULL && info(P)!= x)
    {
        P = next(P);
    }
    if(P == NULL)
        return NULL;
    else
        return P;
}

void sorting_f(List_followers &L)
{
    address_followers P,coun,Q;
    P = first(L);
	while( next(P) != NULL)
	{
		for(coun = next(P); coun != NULL; coun = next(coun))
		{
			if(info(P) > info(coun))
			{
				infotype_followers temp = info(P);
				info(P)= info(coun);
				info(coun)= temp;
			}
		}
        P = next(P);
	}
	Q = first(L);
	printInfo_f(L);
}
