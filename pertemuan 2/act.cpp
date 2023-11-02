#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

int main()
{
    int *data;
    int i, banyakdata;
    printf("Banyak data yang akan diinputkan : ");
    scanf("%d", &banyakdata);
    data = (int *)malloc(sizeof(int) * banyakdata);
    for (i = 0; i < banyakdata; i++)
    {
        printf("Memasukan data ke-%d : ", i + 1);
        scanf("%d", &data[i]);
    }
    printf("Data yang telah diinputkan adalah : \n");
    for (i = 0; i < banyakdata; i++)
    {
        printf("Data ke-%d : %d\n", i + 1, data[i]);
    }
    getch();
    return 0;
}