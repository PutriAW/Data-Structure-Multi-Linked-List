#include <stdlib.h>
#include <conio.h>
#include <string>
#include <stdio.h>
#include "parent.h"
#include "child.h"
#include "relation.h"
#include "procmain.h"


int main()
{
    cout<<"================================================================="<<endl;
    cout<<"=                    CELEBRITY AND FOLLOWERS                    ="<<endl;
    cout<<"================================================================="<<endl;
    cout<<"= Created BY                                                    ="<<endl;
    cout<<"= Mar Ayu Fotina (1301174013)                                   ="<<endl;
    cout<<"= Putri Apriyanti Windya (1301174169)                           ="<<endl;
    cout<<"= Kelas : IF-41-05                                              ="<<endl;
    cout<<"================================================================="<<endl<<endl<<endl;
    system("PAUSE");
    system("CLS");
    List_celeb C;
    List_followers F;
    List_relasi LR;
    createList_celeb(C);
    createList_followers(F);
    infotype_celeb carceb,celeb;
    infotype_followers carfo,follower;;
    address_celeb P,Prec;
    address_followers Q;
    address_relasi R;
    int pilih;
    menu(pilih);
    while (pilih != 11)
    {
        switch (pilih)
        {
        case 1:
            cout << "Masukkan Celebrity Baru : ";
            cin>>celeb;
            P = findElm_c(C,celeb);
            if (P == NULL)
            {
                insertLast_c(C,alokasi_c(celeb));
            }
            else
            {
                cout<<endl<<"Celebrity Sudah Ada, Silahkan Masukkan Celebrity Lain "<<endl<<endl;
            }
            cout<<endl;
            printInfo_C_WF(C);
            break;
        case 2:
            cout << "Masukkan followers Baru : ";
            cin>>follower;
            Q = findElm_f(F,follower);
            if (Q == NULL)
            {
                insertLast_f(F,alokasi_f(follower));
            }
            else
            {
                cout<<endl<<"Followers Sudah Terdaftar, Silahkan Masukkan Followers Lain "<<endl<<endl;
            }
            cout<<endl;
            printInfo_f(F);
            break;
        case 3:
            cout<<"Masukkan nama Celebrity yang ingin direlasikan : ";
            cin>>carceb;
            cout<<"Masukkan nama Follower yang ingin direlasikan  : ";
            cin>>carfo;
            P = findElm_c(C,carceb);
            Q = findElm_f(F,carfo);
            if (P != NULL && Q != NULL)
            {
                R = alokasi(Q);
                insertLast(followers(P), R);
            }
            cout<<endl;
            printInfo_c(C);
            break;
        case 4:
            cout<<"Masukkan Nama Celebrity Yang akan Dihapus : ";
            cin >>carceb;
            Prec = findElm_c(C,carceb);
            if (Prec != NULL)
            {
                cout<<endl<<"Celebrity Ditemukan!!!"<<endl<<endl;
                cout<<"Celebrity Sukses Dihapus "<<endl<<endl;
                delete_c(C,Prec,P);
                printInfo_C_WF(C);

            }
            else
            {
                cout<<"Celebrity Tidak Ditemukan !!!"<<endl;
            }

            break;
        case 5:
            printInfo_c(C);
            //printInfo_f(F);
            break;
        case 6:
            system("CLS");
            cout<<"======================================================="<<endl;
            cout<<"=            SHOW A FOLLOWERS OF A CELEBRITY          ="<<endl;
            cout<<"======================================================="<<endl<<endl;
            cout<<"Masukkan nama Celebrity : ";
            cin>>carceb;
            P = findElm_c(C,carceb);
            if (P != NULL)
            {
                printInfo(followers(P));
            }
            else
            {
                cout<<"EMPTY";
            }
            break;
        case 7:
            celebManyFolllower(C,LR);
            cout<<endl;
            break;
        case 8:
            follower3celebrity(F,C,LR);
            break;
        case 9:
            system("CLS");
            edit(C,F);
            break;
        case 10:
            system("CLS");
            sorting(C,F);
            break;
        default:
            cout<<endl<<"Pilihan Yang Anda Masukkan Salah "<<endl;
            break;

        }
        cout<<endl;
        system("PAUSE");
        system("CLS");
        menu(pilih);
    }

    cout<<endl<<"Terima Kasih Telah Menggunakan Aplikasi ini :)"<<endl;
    return 0;
}
