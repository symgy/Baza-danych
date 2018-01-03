#include <iostream>
#include <fstream>
#include <stdlib.h>

using namespace std;

class Baza
{

    string imie, nazwisko,klient,linia,nr_klienta,telefon;
    int nr_linii,pozycja,znaleziona_linia,rok,miesiac,dzien,godzina,minuta,sekunda;
    fstream plik;


public:

    void aktualna_data();
    void inicjalizacja();
    void dodaj_klienta();
    void wczytaj_klienta();
    void kalkulator();
    string usuwanie_spacji(string &tekst);



};


