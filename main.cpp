#include <iostream>
#include "ldl.h"

using namespace std;

int main()
{
    LDL<string> cadenas;
    cadenas.push_front("Hello");
    cadenas.push_front("Hola");
    cadenas.push_back("Mundo");
    cadenas.push_back("World");
    cadenas.pop_front();
    cadenas.pop_back();

    LDL<string> other(cadenas);
    other = cadenas;

    cout<<"Empty(): "<<cadenas.empty()<<endl
       <<"Size(): "<<cadenas.size()<<endl
      <<"Front(): "<<cadenas.front()<<endl
     <<"Back(): "<<cadenas.back()<<endl<<endl;

    cout<<"LISTA DE ELEMENTOS: "<<endl<<endl;

    for(size_t i(0); i < cadenas.size(); ++i)
        cout<<cadenas[i]<<endl;

    return 0;
}
