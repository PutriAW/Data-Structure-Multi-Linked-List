#include "parent.h"

void createList_celeb(List_celeb &L)
{
    first(L) = NULL;
    last(L) = NULL;
}

address_celeb alokasi_c(string username)
{
    address_celeb P = new elm_celeb;
    info(P) = username;
    next(P) = NULL;
    prev(P) = NULL;
    createList_relation(followers(P));

    return P;
}

void insertFirst_c(List_celeb &L, address_celeb P)
{
    if (first(L) == NULL)
    {
        first(L) = P;
        last(L) = P;
    }
    else
    {
        next(P) = first(L);
        prev(first(L)) = P;
        first(L) = P;
    }
}

void insertLast_c(List_celeb &L, address_celeb P)
{
    if (first(L) == NULL)
    {
        first(L) = P;
        last(L) = P;
    }
    else
    {
        prev(P) = last(L);
        next(last(L)) = P;
        last(L)=P;
    }
}

void insertAfter_c(List_celeb &L, address_celeb Prec, address_celeb P)
{
    if (Prec != NULL)
    {
        if (Prec == last(L))
        {
            insertLast_c(L,P);
        }
        else
        {
            next(P) = next(Prec);
            prev(P) = Prec;
            prev(next(Prec)) = P;
            next(Prec) = P;
        }
    }
}

void deleteFirst_c(List_celeb &L, address_celeb &P)
{
    if (first(L) == NULL)
        cout<<"EMPTY"<<endl;

    else if (first(L) == last(L))
    {
        P = first(L);

        first(L) = NULL;
        last(L) = NULL;
    }
    else
    {
        P = first(L);
        first(L) = next(P);
        prev(first(L)) = NULL;
        next(P) = NULL;
    }
}

void deleteLast_c(List_celeb &L, address_celeb &P)
{
    if (first(L) == NULL)
        cout<<"EMPTY"<<endl;
    else if (first(L) == last(L))
    {
        address_celeb P = first(L);
        first(L) = NULL;
        last(L) = NULL;

        delete P;
    }
    else
    {
        address_celeb P = last(L);
        last(L) = prev(P);
        next(last(L)) = NULL;
        prev(P) = NULL;
    }
}

void deleteAfter_c(List_celeb &L,address_celeb Prec, address_celeb &P)
{
    if (first(L)!= NULL)
    {
        if (Prec != NULL)
        {
            if (next(Prec)== last(L))
            {
                deleteLast_c(L,P);
            }
            else if (Prec == first(L))
            {
                deleteFirst_c(L,P);
            }
            else
            {
                P = next(Prec);
                next(Prec)=next(P);
                prev(next(P)) = Prec;
                next(P) = NULL;
                prev(P) = NULL;
            }
        }
    }
}

void dealokasi_c(address_celeb &P)
{
    delete P;
    P = NULL;
}

address_celeb findElm_c(List_celeb L, infotype_celeb x)
{
    address_celeb P = first(L);
    while(P != NULL && info(P)!= x)
    {
        P = next(P);
    }
    if(P == NULL)
        return NULL;
    else
        return P;
}

void delete_c(List_celeb &L,address_celeb Prec ,address_celeb &P)
{
    if (first(L)!= NULL)
    {
        if (Prec != NULL)
        {
            if (Prec == first(L))
            {
                deleteFirst_c(L,P);
            }
            else if (Prec == last(L))
            {
                deleteLast_c(L,P);
            }
            else
            {
                P = Prec;
                address_celeb Q = prev(P);
                next(Q) = next(P);
                prev(next(P)) = Q;
                next(P) = NULL;
                prev(P) = NULL;

            }
        }
    }
}

void printInfo_c(List_celeb L)
{
    if (L.first == NULL )
        cout<<"EMPTY"<<endl;
    else
    {
        address_celeb P = first(L);
        while(P!=NULL)
        {
            cout<<"Celebrity : "<< info(P)<<endl;
            printInfo(followers(P));
            P = next(P);
        }
    }
}

void printInfo_C_WF(List_celeb L)
{
    if (L.first == NULL )
        cout<<"EMPTY"<<endl;
    else
    {
        address_celeb P = first(L);
        while(P!=NULL)
        {
            cout<<"Celebrity : "<< info(P)<<endl;
            P = next(P);
        }
    }
}


void celebManyFolllower(List_celeb L,List_relasi R)
{
    int n;
    int A[20];
    address_celeb P;
    if (first(L) == NULL)
    {
        cout<<"EMPTY";
    }
    else
    {
        P = first(L);
        n = 0;
        int i;
        i = 0;
        //address_relasi S;
        while (P != NULL)
        {
            address_relasi Q = first(followers(P));
            while (Q != NULL)
            {
                //cout<<info(info(Q))<<endl;
                n = n+1;
                Q = next(Q);
            }
            A[i] = n;
            i++;
            n=0;
            P = next(P);
        }
        int j;
        j = 0;
        int counter = 0;
        n = A[j];
        while (j< i)
        {
            //cout<<A[j]<<endl;
            if (A[j]>=n)
            {
                n = A[j];;
                counter = j;
            }
            j++;
        }
        //cout<<n<<endl;
        P = first(L);
        //j = 0;
        //while (j<counter)
        for (j = 0; j < counter; j++)
        {
            P = next(P);
            j++;
        }
        cout <<"Celebrity Yang Mempunyai Banyak Followers Adalah  "<<info(P)<<endl;
        printInfo(followers(P));
    }
}

void follower3celebrity(List_followers F, List_celeb L, List_relasi LR)
{
    address_followers P;
    address_celeb Q;
    address_relasi car;
    int A[20];
    int i = 0, n = 0;
    P = first(F);
    while (P != NULL)
    {
        Q = first(L);
        while (Q != NULL)
        {
            car = first(followers(Q));
            while (car != NULL)
            {
                if ( info(info(car)) == info(P))
                {
                    n++;
                }
                car = next(car);
            }
            Q = next(Q);
        }
        A[i] = n;
        i++;
        n = 0;
        P = next(P);
    }
    int j = 0;
    P = first(F);
    while (j < i)
    {
        //cout<<A[j]<<endl;
        if (A[j] > 3)
        {
            cout<<"Jadi follower yang mengikuti lebih dari 3 celebrity adalah "<<info(P)<<endl;
        }
        j++;
        P = next(P);
    }

}

void sorting_c(List_celeb &L)
{
    address_celeb P,coun,Q;
    P = first(L);
    while( next(P) != NULL)
    {
        for(coun = next(P); coun != NULL; coun = next(coun))
        {
            if(info(P) > info(coun))
            {
                infotype_celeb temp = info(P);
                info(P)= info(coun);
                info(coun)= temp;
            }
        }
        P = next(P);
    }
    Q = first(L);
    printInfo_C_WF(L);
}
