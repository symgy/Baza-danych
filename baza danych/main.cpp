#include <iostream>
#include "baza.h"
#include <fstream>
#include <windows.h>
#include <stdlib.h>
#include <conio.h>
#include <string>
using namespace std;
int wybor;
int main()
{
Baza klient;
cout<<"----------------------------------"<<endl;
klient.inicjalizacja();
klient.aktualna_data();
char wybor;
//while(true)
    {
        cout<<"----------------------------------"<<endl;
        cout<<"BAZA DANYCH"<<endl;
        cout<<"---------------MENU---------------"<<endl;
        cout<<"1. Dodaj klienta"<<endl;
        cout<<"2. Wczytaj klienta"<<endl;
        cout<<"3. Kalkulator"<<endl;
        cout<<"4. Zakoncz program"<<endl;

        wybor=getch();

        switch (wybor)
        {
        case '1':
            klient.dodaj_klienta();
            break;
        case '2':
            klient.wczytaj_klienta();
            break;
        case '3':

            break;
        case '4':
            cout<<endl;
            cout<<"Zapraszam ponownie";
            Sleep(3000);
            exit(0);
            break;
        }

    }


main();
    return 0;
}
