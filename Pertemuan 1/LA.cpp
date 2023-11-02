#include <iostream>

using namespace std;

int main()
{
    string namaMhs[2];
    string NPMMhs[2];

    for (int i = 0; i < 2; i++)
    {
        cout << "Nama: ";
        cin >> namaMhs[i];
        cout << "NPM: ";
        cin >> NPMMhs[i];
    }
    
    cout << endl << "==== OUTPUT ====" << endl;
    for (int i = 0; i < 2; i++)
    {
        cout << "Nama: " << namaMhs[i] << endl;
        cout << "NPM: " << NPMMhs[i] << endl << endl;
    }
    return 0;
}