#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

struct node
{
    struct node *prev;
    int data;
    struct node *next;
};

typedef struct node node;

node *pHead = NULL;

node *alokasiNodeBaru(){
    node *pNew = NULL;
    pNew = (node *) malloc(sizeof(node));
    return (pNew);
}

void tambahAwal(node *pNew){
    printf("masukkan bilangan: "); scanf("%d", pNew->data);

    if(pHead == NULL){
        pNew->prev = pHead;
        pNew->next = pHead;
        pHead = pNew;
    }
    else{
        pNew->prev = pHead;
        pNew->next = pHead;
        pHead->prev = pNew;
        pHead = pNew;
    }
}

void cetak(){
    node *pWalker = pHead; int i = 1;
    while (pWalker!=NULL)
    {
        printf("Node ke-%d = %d\n",i,pWalker->data);
        i++;
        pWalker=pWalker->next;
    }
    printf("NULL\n");
}

void tambahAkhir(node *pNew){
    node *pEnd;
    pEnd = pHead;
    printf("masukkan nilai yang ingin ditambahkan: "); scanf("%d", &pNew->data);

    while (pEnd->next != NULL)
    {
        pEnd = pEnd->next;
    }
    
    pEnd->next = pNew;
    pNew->next = pEnd;
    pNew->next = NULL;
}

void hapusAwal(){
    node *pHapus;
    pHapus = pHead;
    pHapus = pHead->next;
    pHead->prev =NULL;
    free(pHapus);
}

int main(){
    node *pNew; int pilih, bil;
    do
    {
        system("cls");
        printf("-----MENU-----");
        printf("\n1. Tambah awal");
        printf("\n2. Tambah akhir");
        printf("\n3. Hapus awal");
        printf("\n4. Cetak");
        printf("\n5. Exit");
        printf("\nPilihan: ");scanf("%d",&pilih);
        if (pilih == 1) 
        {
            pNew = alokasiNodeBaru();
            tambahAwal(pNew);
        }
        else if(pilih == 2){
            pNew = alokasiNodeBaru();
            tambahAkhir(pNew);
        }
        else if(pilih == 3){
            hapusAwal();
        }
        else if(pilih == 4){
            cetak();
            getch();
        }
    } while (pilih!=5);
    printf("\n");
    system("PAUSE");
    return 0;
}