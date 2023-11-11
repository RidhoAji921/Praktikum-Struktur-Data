#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

struct Node
{
    int data;
    struct Node *prev;
    struct Node *next;
};

typedef struct Node Node;

Node *pHead = NULL;

Node *alokasiNodeBaru()
{
    Node *pNew = (Node *)malloc(sizeof(Node));
    pNew->prev = NULL;
    pNew->next = NULL;
    return pNew;
}

void tambahAwal(Node *pNew)
{
    printf("Masukkan bilangan: ");
    scanf("%d", &pNew->data);
    if (pHead == NULL)
    {
        pHead = pNew;
    }
    else
    {
        pNew->next = pHead;
        pHead->prev = pNew;
        pHead = pNew;
    }
}

void cetak()
{
    Node *pWalker = pHead;
    int i = 1;

    while (pWalker != NULL)
    {
        printf("Node %d: %d\n", i, pWalker->data);
        pWalker = pWalker->next;
        i++;
    }
}

void hapusAwal()
{
    if (pHead == NULL)
    {
        printf("Linked list is empty.\n");
    }
    else
    {
        Node *pHapus = pHead;
        pHead = pHead->next;
        if (pHead != NULL)
        {
            pHead->prev = NULL;
        }
        free(pHapus);
    }
}

void tambahTengah(Node *pNew){
    Node *pWalker;
    pWalker=pHead;
    int nilai, sisip;
    printf("masukkan nilai yang ingin ditambahkan : ");
    scanf("%d",&pNew->data);
    cetak();
    printf("Data disisipkan setelah nilai : "); 
    scanf("%d",&sisip);
    while(pWalker!=NULL && pWalker->data!=sisip){
        pWalker=pWalker->next;
    }
    
    if (pWalker==NULL) {
    printf("\nada tidak disisipkan"); 
    getch();
	} else {
    pNew->next=pWalker->next;
    pWalker->next->prev=pNew;
    pWalker->next=pNew;
    pNew->prev=pWalker;
	}

}


void tambahAkhir(Node *pNew){
    Node *pEnd;
    pEnd=pHead;
    printf("masukkan nilai yang ingin ditambahkan: ");
    scanf("%d",&pNew->data);
    
    
    while (pEnd->next != NULL) {
    pEnd = pEnd->next; 
	}
	pEnd->next = pNew;
	pNew->prev = pEnd;
	pNew->next = NULL;
}

void hapusTengah(){
    Node *pCari;
    int hapus;
    pCari=pHead;
    cetak();
    printf("Masukkan bilangan yang ingin dihapus: ");
    scanf("%d",&hapus);
    while(pCari!=NULL && pCari->data!=hapus){
        pCari=pCari->next;
    }
    
    pCari->prev->next=pCari->next;
	pCari->next->prev=pCari->prev;
	free(pCari);
}

void hapusAkhir(){
    Node *pEnd;
    pEnd=pHead;
    while(pEnd->next!=NULL){
        pEnd=pEnd->next;
    }
    pEnd->prev->next=NULL;
    free(pEnd);
}

int main()
{
    int pilih;
    Node *pNew;

    do
    {
        system("clear");

        printf("-- MENU --\n");
        printf("1. Tambah Awal\n");
        printf("2. Tambah Akhir\n");
        printf("3.Tambah Tengah\n");
        printf("4. Hapus awal\n");
        printf("5. Hapus tengah\n");
        printf("6. Hapus akhir\n");
        printf("7. exit\n");
        printf("Pilihan: ");
        scanf("%d", &pilih);

        if (pilih == 1)
        {
            pNew = alokasiNodeBaru();
            tambahAwal(pNew);
        }
        else if (pilih == 2)
        {
            pNew = alokasiNodeBaru();
            tambahAkhir(pNew);
        }
        else if (pilih == 3)
        {
            pNew = alokasiNodeBaru();
            tambahTengah(pNew);
        }
        else if (pilih == 4)
        {
            hapusAwal();
        }
        else if (pilih == 5)
        {
            hapusTengah();
        }
        else if (pilih == 6)
        {
            hapusAkhir();
        }

        printf("\n");
    } while (pilih !=7);

    return 0;
}