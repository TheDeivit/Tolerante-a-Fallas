#include <iostream>
#include <locale.h>
#include "listaestatica.h"
	
using namespace std;
	
int main() {
	setlocale(LC_ALL, "spanish");
	
	ListaEstatica<int> numeros;		//Se menciona el tipo de dato
	ListaEstatica<char> simbolos;
	
	numeros.insert(33);
	numeros.insert(44);
	
	numeros[1] = 55;
	
	ListaEstatica<int> enteros(numeros);
	
	cout<<"Numeros"<<endl
	<<"Vacia: "<<numeros.empty()<<endl	//Si no hay nada en la lista se regresa un 0
	<<"Llena: "<<numeros.full()<<endl	//Si esta llena regresa un 1, y si no, un 0
	<<"Tamaño: "<<numeros.size()<<endl;  //Regresa el numero de elemtnos dentro de la lista
	
	for(size_t i(0);i<numeros.size();++i)
			cout<<numeros[i]<<endl;
	
	simbolos.insert('a');
	cout<<"Simbolos"<<endl
	<<"Vacia: "<<simbolos.empty()<<endl
	<<"Llena: "<<simbolos.full()<<endl
	<<"Tamaño: "<<simbolos.size()<<endl;
	
	for(size_t i(0);i<simbolos.size();++i)
			cout<<simbolos[i]<<endl;
	return 0;
}
	
	
//size_t ->unsigned int, si no encuentro el elemento regreso size_t+1
