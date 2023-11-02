#include <stdio.h>
#include <iostream>
#include <conio.h>
#include <stdlib.h>

using namespace std;

struct TNode{
    int data;
    TNode *next;
};

TNode *head, *tail;

void init (){
    head = NULL;
    tail = NULL;
}

int isEmpty(){
    if(tail==NULL)return 1;
    else return 0;
}

void insertDepan(int databaru)
{
    TNode *baru;
    baru = new TNode;
    baru->data = databaru;
    baru->next = NULL;
    if(isEmpty()==1)
    {
        head=tail=baru;
        tail->next=NULL;
    }else
    {
        baru->next = head;
        head=baru;
    }
    cout<<"Data masuk\n";
}

void tampil(){
    TNode *bantu;
    bantu=head;
    if(isEmpty()==0)
    {
        while(bantu!=NULL)
        {
            cout<<bantu->data<<" ";
            bantu=bantu->next;
        }
    }else cout <<"Masih kosong\n";
}

void search(int cari)
{
    TNode *bantu;
    bantu=head;
    bool ada = false;
    if(isEmpty()==0)
    {
        while(ada==false && bantu!=NULL)
        {
            if (bantu->data == cari)
            {
                cout << "data " << cari << " ada pada file";
                ada = true;
                return;
            }
            bantu=bantu->next;
        }
        cout << "Data tidak ada";
    }else cout <<"Data masih kosong";
}

void clear()
{
    TNode *bantu, *hapus;
    bantu =head;
    while(bantu!=NULL)
    {
        hapus=bantu;
        bantu=bantu->next;
        delete hapus;
    }
    head = NULL;
    printf("clear");
}

main()
{
    int pil, databaru, cari;
    do
    {
        cout<<endl;
        cout<<" ============================"<<endl;
        cout<<" =   PROGRAM LINKED LIST    ="<<endl;
        cout<<" ============================"<<endl;
        cout<<" = 1. Insert                ="<<endl;
        cout<<" = 2. View                  ="<<endl;
        cout<<" = 3. Search                ="<<endl;
        cout<<" = 4. Delete                ="<<endl;
        cout<<" = 5. Keluar                ="<<endl;
        cout<<" ============================"<<endl;
        cout<<" Masukan Pilihan : ";cin>>pil;
        switch (pil)
        {
            case 1: {
                cout<<"Masukan Data = ";cin>>databaru;
                insertDepan(databaru);
                break;
            }
            case 2: {
                tampil();
                break;
            }
            case 3: {
                cout<<"Data yang akan dicari = ";cin>>cari;
                search(cari);
                break;
            }
            case 4: {
                clear();
                break;
            }
            case 5: {
                return 0;
                break;
            }
            default : 
            {
                cout<<"\n Maaf, Pilihan yang anda pilih tidak tersedia!";
            }
        }
        getch();
    }
    while (pil!=7);
}