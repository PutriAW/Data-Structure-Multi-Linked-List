#include "procmain.h"

void menu(int &pil)
{
    cout<<"================================================================="<<endl;
    cout<<"=                             MENU                              ="<<endl;
    cout<<"================================================================="<<endl;
    cout<<"= 1. ADD NEW CELEBRITY                                          ="<<endl;
    cout<<"= 2. ADD NEW FOLLOWER                                           ="<<endl;
    cout<<"= 3. ADD RELATION                                               ="<<endl;
    cout<<"= 4. DELETE A CELEBRITY                                         ="<<endl;
    cout<<"= 5. SHOW ALL CELEBRITIES AND THEIR FOLLOWERS                   ="<<endl;
    cout<<"= 6. SHOW A FOLLOWERS OF A CELEBRITY                            ="<<endl;
    cout<<"= 7. SHOW A CELEBRITY THAT HAS MANY FOLLOWER AND ITS FOLLOWERS  ="<<endl;
    cout<<"= 8. SHOW SOME FOLLOWERS THAT LOVE MORE THAN 3 CELEBRITIES      ="<<endl;
    cout<<"= 9. EDIT                                                       ="<<endl;
    cout<<"= 10.SORTING                                                    ="<<endl;
    cout<<"= 11.KELUAR                                                     ="<<endl;
    cout<<"================================================================="<<endl<<endl<<endl;
    cout<<"Masukkan Pilihan (1 - 11) : ";
    cin>>pil;

}

void edit(List_celeb &C,List_followers &F)
{
    int pil;
    infotype_celeb cel,newcel;
    infotype_followers fol,newfol;
    address_celeb P;
    address_followers Q;
    cout<<"================================================================="<<endl;
    cout<<"=                             EDIT                              ="<<endl;
    cout<<"================================================================="<<endl;
    cout<<"= 1. CELEBRITY'S NAME                                           ="<<endl;
    cout<<"= 2. FOLLOWER'S NAME                                            ="<<endl;
    cout<<"= 3. BACK                                                       ="<<endl;
    cout<<"================================================================="<<endl<<endl<<endl;
    cout<<"Masukkan Pilihan (1 - 3) : ";
    cin>>pil;
    if (pil == 1)
    {
        cout<<"Masukkan Nama Celebrity Yang Akan Diedit : ";
        cin>>cel;
        P = findElm_c(C,cel);
        if (P != NULL)
        {
            cout<<"Masukkan Nama Baru : ";
            cin>>newcel;
            info(P) = newcel;
        }
        else
        {
            cout<<"NOT FOUND";
        }
    }
    else if (pil == 2)
    {
        cout<<"Masukkan Nama followers Yang Akan Diedit : ";
        cin>>fol;
        Q = findElm_f(F,fol);
        if (Q != NULL)
        {
            cout<<"Masukkan Nama Baru : ";
            cin>>newcel;
            info(Q) = newcel;
        }
        else
        {
            cout<<"NOT FOUND";
        }
    }
    else
    {
        system("CLS");
    }
}

void sorting(List_celeb &C, List_followers &F)
{
    int pil;
    address_celeb P;
    address_followers Q;
    cout<<"================================================================="<<endl;
    cout<<"=                          SORTING                              ="<<endl;
    cout<<"================================================================="<<endl;
    cout<<"= 1. CELEBRITY'S NAME (A-Z)                                     ="<<endl;
    cout<<"= 2. FOLLOWER'S NAME  (A-Z)                                     ="<<endl;
    cout<<"= 3. BACK                                                       ="<<endl;
    cout<<"================================================================="<<endl<<endl<<endl;
    cout<<"Masukkan Pilihan (1 - 3) : ";
    cin>>pil;
    if (pil == 1)
    {
        sorting_c(C);
    }
    else if (pil == 2)
    {
        sorting_f(F);
    }
    else
    {
        system("CLS");
    }
}

