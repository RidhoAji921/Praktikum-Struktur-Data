#include <iostream>

using namespace std;

int main()
{
    int menu;
    int banyakData;
    int *data;
    bool aktif = true;
    while (aktif)
    {
        cout << "=====================" << endl;
        cout << "| PROGRAM LINK LIST |" << endl;
        cout << "=====================" << endl;
        cout << "| 1. Insert         |" << endl;
        cout << "| 2. View           |" << endl;
        cout << "| 3. Search         |" << endl;
        cout << "| 4. Delete         |" << endl;
        cout << "| 5. Keluar         |" << endl;
        cout << "=====================" << endl;
        cout << "PILIH: ";
        cin >> menu;

        switch (menu)
        {
            case 1:
                int insert;
                cout << "Data masuk: ";
                cin >> insert;
                banyakData += 1;
                data = (int *)malloc(sizeof(int)*banyakData);
                data[banyakData] = insert;
                break;
            case 2:
                for (int i = 0; i < banyakData; i++)
                {
                    cout << data[i] << " ";
                }
                break;
            case 5:
                aktif = false;
            default:
                break;
        }
    }
    
    return 0;
}