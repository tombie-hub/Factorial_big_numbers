#include <iostream>

#include <iloczyn.h>

int main()
{
    std::string silnia = "1";
    int y;

    std::cout << "Podaj liczbe: ";
    std::cin>>y;

    //obliczanie silni
    if( y == 0 || y == 1 ) std::cout << "1";
    else
    {
        for(int i = 2; i <= y; i++ )
            {
            iloczyn * x = new iloczyn;
            silnia = x->iloczyn_silni( silnia, i );
            delete x;
            }
    }

    //wypisanie wyniku
    std::cout << y <<"! = " <<silnia;

return 0;
}
