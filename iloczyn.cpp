#include "iloczyn.h"

iloczyn::iloczyn():
    buf_iloczyn(0),
    buf_dodawanie(0),
    wynik_iloczynu(),
    zera(""),
    wynik_koncowy(""),
    pomocnicza(""),
    m(""),
    r("")
{
    bufor = & buf_iloczyn;
    bufor_suma = & buf_dodawanie;
}

iloczyn::~iloczyn()
{

}
//konstruktor kopiujacy
iloczyn::iloczyn( iloczyn &kop )
{
    buf_dodawanie = kop.buf_dodawanie;
    buf_iloczyn = kop.buf_iloczyn;
    wynik_iloczynu = kop.wynik_iloczynu;
    zera = kop.zera;
    wynik_koncowy = kop.wynik_koncowy;
    pomocnicza = kop.pomocnicza;
    m = kop.m;
}

iloczyn& iloczyn::operator = ( iloczyn const &a )
{
        //sprawdzenie czy to nie ten sam obiekt
        if( &a != this )
    {
        buf_iloczyn = a.buf_iloczyn;
        buf_iloczyn = a.buf_iloczyn;
        wynik_iloczynu = a.wynik_iloczynu;
        zera = a.zera;
        wynik_koncowy = a.wynik_koncowy;
        pomocnicza = a.pomocnicza;
        m = a.m;
    }
        return * this;
}

 // Funckcja zamieniająca znak na liczbe
inline
int iloczyn::liczba( char znak )
{
    return int(znak-48);
}

// Funkcja zamieniająca liczbe na znak
inline
char iloczyn::znak( int liczba )
{
    return char(liczba+48);
}

std::string iloczyn::iloczyn_silni(std::string n, int i)
{
    //zamiana int na string
    r << i;
    m = r.str();

    //pętle do mnożenia znak po znaku (tak jak mnoży się pisemnie)
    for(int i = n.length()-1 ; i >= 0 ; i--)
        {
            for(int j = m.length()-1 ; j >= 0 ; j--)
            {
                if( liczba(n[i]) * liczba(m[j]) + *bufor > 9 )
                {
                    wynik_iloczynu = znak((liczba(n[i])*liczba(m[j]) + *bufor)%10) + wynik_iloczynu;
                    *bufor = (liczba(n[i])*liczba(m[j]) + *bufor)/10;
                }
                else
                {
                    wynik_iloczynu = znak(liczba(n[i])*liczba(m[j]) + *bufor) + wynik_iloczynu;
                    *bufor=0;
                }

            }

            if( *bufor != 0 ) wynik_iloczynu = znak( *bufor ) + wynik_iloczynu;
            *bufor = 0;
            dodawanie( wynik_iloczynu + zera );
            zera += '0';
            wynik_iloczynu="";
        }

    return wynik_koncowy;
}


void iloczyn::dodawanie( std::string wynik_z_iloczynu)
{
        //wyrównanie stringów przed dodawaniem
        while(wynik_koncowy.length() != wynik_z_iloczynu.length())
            {
                if(wynik_koncowy.length() > wynik_z_iloczynu.length())
                {
                    wynik_z_iloczynu = '0' + wynik_z_iloczynu;
                }
                else
                {
                    wynik_koncowy = '0' + wynik_koncowy;
                }
            }

        //dodawanie stringów znak po znaku (tak jak pisemnie)
        for(int i = wynik_z_iloczynu.length()-1; i >= 0 ; i--)
        {

            if((liczba(wynik_koncowy[i]) + liczba(wynik_z_iloczynu[i]) + *bufor_suma) > 9)
            {
                pomocnicza = wynik_koncowy;
                wynik_koncowy[i] = znak((liczba(wynik_koncowy[i]) + liczba(wynik_z_iloczynu[i]) + *bufor_suma)%10);
                *bufor_suma = (liczba(pomocnicza[i]) + liczba(wynik_z_iloczynu[i]) + *bufor_suma)/10;
            }
            else
            {
                wynik_koncowy[i] = znak(liczba(wynik_koncowy[i]) + liczba(wynik_z_iloczynu[i]) + *bufor_suma);
                *bufor_suma = 0;
            }
        }

            if( *bufor_suma != 0 ) wynik_koncowy = znak( *bufor_suma ) + wynik_koncowy;
}

