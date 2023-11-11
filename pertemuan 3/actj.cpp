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

void tambahAkhir(Node *pNew)
{
    printf("Masukkan nilai yang ingin ditambahkan: ");
    scanf("%d", &pNew->data);

    if (pHead == NULL)
    {
        pHead = pNew;
    }
    else
    {
        Node *pEnd = pHead;
        while (pEnd->next != NULL)
        {
            pEnd = pEnd->next;
        }

        pEnd->next = pNew;
        pNew->prev = pEnd;
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

int main()
{
    int pilih;
    Node *pNew;

    do
    {
        system("cls");

        printf("-- MENU --\n");
        printf("1. Tambah Awal\n");
        printf("2. Tambah Akhir\n");
        printf("3. Hapus Awal\n");
        printf("4. Cetak\n");
        printf("5. Exit\n");
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
            hapusAwal();
        }
        else if (pilih == 4)
        {
            cetak();
            getch();
        }

        printf("\n");
    } while (pilih != 5);

    return 0;
}