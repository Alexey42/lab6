#include <iostream>
#include "Header.h"

using namespace std;



void main()
{
    MyList ml;

    ml.push_back_current_level("Glava1");
    ml.push_back_next_level("Podzagolovok1");
    ml.push_back_current_level("Podzagolovok2");
    ml.push_back_next_level("Tekst1");
    ml.push_back_current_level("Tekst2");

    ml.print();

    cout << endl << ml.begin() << endl;
    cout << ml.end() << endl;

    system("pause");
}
