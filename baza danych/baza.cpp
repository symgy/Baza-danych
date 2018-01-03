#include <iostream>
#include "baza.h"
#include <fstream>
#include <stdlib.h>
#include <windows.h>
#include <string>
using namespace std;
int i=0;
int war_poczatkowa;
int aktualna_linia=1 ;

string szukaj="Klient nr: ", szukaj2;

string Baza::usuwanie_spacji(string &napis)
{
    while(napis.find(" ") != string::npos)
    {
        napis.erase(napis.find(" "), 1);
        //cin.clear();
        //cin.sync();

    }

    return napis;
}

void Baza::aktualna_data()
{
    SYSTEMTIME dzisiaj;
    GetLocalTime(&dzisiaj);
    rok = dzisiaj.wYear;
    miesiac = dzisiaj.wMonth;
    dzien = dzisiaj.wDay;
    godzina = dzisiaj.wHour;
    minuta = dzisiaj.wMinute;
    sekunda = dzisiaj.wSecond;

    cout<<"Data: "<<dzien<<"."<<miesiac<<"."<<rok<<endl;
}


void Baza::inicjalizacja()
{
    war_poczatkowa=0;
    plik.open("baza.txt",ios::in);
    if(plik.good()==false)

        cout<<"Utworzono nowy plik bazy danych o nazwie baza.txt \n";
    while(getline(plik,linia))
    {
        war_poczatkowa++;

    }
    plik.close();
    if (war_poczatkowa%4!=0)
    {
        cout<<"Sprawdz poprawnosc bazy danych!!!"<<endl;
        Sleep(2000);
        exit(0);
    }

    i=war_poczatkowa/4;

    cout<<"Obecnie w bazie jest: "<<i<<" klientow"<<endl;
}

void Baza::dodaj_klienta()
{
    ++i;
    plik.open("baza.txt",ios::out | ios::app);
    if(plik.good()==false) cout<<"Nie mozna otworzyc pliku!";
    cout<<endl;
    plik<<"Klient nr: "<<i<<" "<<"(dodano: "<<dzien<<"."<<miesiac<<"."<<rok<<" "<<godzina<<":"<<minuta<<")"<<endl;
    cout<<"Imie: ";
    cin>>imie;
    plik<<imie<<endl;
    cin.clear();
    cin.sync();

    cout<<"Nazwisko: ";
    cin>>nazwisko;
    plik<<nazwisko<<endl;
    cin.clear();
    cin.sync();

    cout<<"Telefon: ";
    getline(cin,telefon);
    usuwanie_spacji(telefon);
    while (telefon.length()!=9)
    {
        cout<<endl;
        cout<<"Numer telefonu powinien miec 9 cyfr, bez spacji."<<endl;
        cout<<"Sprobuj wpisac jeszcze raz."<<endl;
        getline(cin,telefon);
        usuwanie_spacji(telefon);
    }
    plik<<telefon<<endl;
    plik.close();
    cout<<endl;
    cout<<"Klient dodany poprawnie !"<<endl;

    Sleep(2000);
    system("cls");
}
void Baza::wczytaj_klienta()
{
    cout<<"Podaj numer klienta ktorego chcesz znalezc: ";
    cin>>nr_klienta;
    cout<<endl;
    int nr_klienta_int = atoi(nr_klienta.c_str());

    while(nr_klienta_int>i)
    {
    cout << "Nie ma takiego klienta! W bazie jest aktualnie: "<<i<<" klientow." <<endl;
    cout<<endl<<"Podaj numer klienta ktorego chcesz znalezc: "<<endl;
    cin >>nr_klienta;
    nr_klienta_int = atoi(nr_klienta.c_str());
    }

    plik.open("baza.txt",ios::in);
    while(!plik.eof())
    {
        getline(plik, linia);
        if(!(string::npos == linia.find(szukaj+nr_klienta))) znaleziona_linia=aktualna_linia;

        if (znaleziona_linia==aktualna_linia) szukaj2=linia;
        else if (znaleziona_linia+1==aktualna_linia) imie=linia;
        else if (znaleziona_linia+2==aktualna_linia) nazwisko=linia;
        else if (znaleziona_linia+3==aktualna_linia) telefon=linia;

        aktualna_linia++;
    }
    plik.close();
    cout<<"----------------------------------"<<endl;
    cout<<szukaj2<<endl;
    cout<<"Imie: "<<imie<<endl;
    cout<<"Nazwisko: "<<nazwisko<<endl;
    cout<<"Telefon: "<<telefon<<endl;
    cout<<"----------------------------------"<<endl<<endl;
    cout<<"Wcisnij ENTER, aby wrocic do menu glownego."<<endl;
    getchar();
    getchar();
    Sleep(1000);
    system("cls");

}
void Baza::kalkulator()
{

}
