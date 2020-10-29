////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//
//
//
//Data utworzenia: 10.02.2019
//
//Definicja klasy iloczyn. Mno¿y dwie liczby.
//
//
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#ifndef ILOCZYN_H
#define ILOCZYN_H

#include <iostream>
#include <sstream>

class iloczyn
{
    public:
        //definicja kostruktora
        iloczyn();
        //definicja konstruktora kopiujacego
        iloczyn(iloczyn &);
        //definicja destruktora
        ~iloczyn();
        //definicja przeci¹¿enia operatora =
        iloczyn& operator = (iloczyn const &);
        //definicja metody do zamiany znaku na liczbê
        int liczba( char );
        //definicja metody do zmiany liczby na znak
        char znak( int ) ;
        //definicja metody mno¿enia
        std::string iloczyn_silni(std::string, int);
        //definicja metody dodawania
        void dodawanie(std::string);


    private:

        int buf_iloczyn;
        int buf_dodawanie;
        std::string wynik_iloczynu;
        std::string zera;
        std::string wynik_koncowy;
        std::string pomocnicza;
        std::string m;
        std::ostringstream r;

        int *bufor;
        int *bufor_suma;

};

#endif // ILOCZYN_H
