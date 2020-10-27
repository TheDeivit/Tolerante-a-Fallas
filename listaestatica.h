#ifndef LISTA_ESTATICA_H
#define LISTA_ESTATICA_H
#include <iostream>
#include <stdexcept> //Permite lanzar expresiones

using namespace std;

template<typename T>
class ListaEstatica
{
	private:
		static const size_t CAPACITY = 1000;
		T elements[CAPACITY];
		size_t index;
		
	public:
		ListaEstatica() : index(0) {}	//Constructor
		ListaEstatica(const ListaEstatica &other) : index(0)//index=0
		{
			for(size_t i(0);i<other.size();++i)
			insert(other.at(i));
		}
		bool empty() const;			//LISTA VACIA
		bool full() const;			//LISTA LLENA
		size_t size() const;		//NUMERO DE ELEMENTOS EN LA LISTA
		void insert(const T &elem);
		size_t find(const T &elem);
		void remove(size_t idx);
		T& operator[](size_t idx);	//Arreglo para mostrar los elementos de la lista
		T at(size_t idx) const;
};

template <typename T>
bool ListaEstatica<T>::empty() const
{
	return index == 0;
}

template <typename T>
bool ListaEstatica<T>::full() const		//Si la lista esta llena retorna la capcidad de la misma
{
	return index == CAPACITY;
}

template <typename T>
size_t ListaEstatica<T>::size() const
{
	return index;
}

template <typename T>
void ListaEstatica<T>::insert(const T &elem)
{
	if(full())
		throw invalid_argument("Insert() on full list");		//Si la lista esta llena lanza un argumento invalido
		
		 elements[index++] = elem;
}

template <typename T>
size_t ListaEstatica<T>::find(const T &elem)
{
	if(empty())
	throw invalid_argument("No contiene nada")<<endl;
	
	for(int i(0); i<idx;i++){
	if(elem==elements[idx])
	}
	return i;
}

template <typename T>
void ListaEstatica<T>::remove(size_t idx)	
{
	if(empty())
		throw invalid_argument("No hay datos")<<endl;
	if(elem==elements[idx])
	{
		for(int i=borrar+1;i<cont;i++)
		elements[i-1]= elements[i];
		cont--;
	}
	
	elements[index--];
	return idx;
		
}	

		
template <typename T>
T& ListaEstatica<T>::operator [](size_t idx)
{
	if(empty())
	throw invalid_argument("[] on empty list");
	if(idx >= index)
	throw invalid_argument("[] on non valid position");
	
	return elements[idx];//Regresa los elementos
}
 
 template <typename T>
 T ListaEstatica<T>::at(size_t idx) const
 {
 	if(empty())
	throw invalid_argument("[] on empty list");
	if(idx >= index)
	throw invalid_argument("[] on non valid position");
	
	return elements[idx];//Regresa los elementos
 }
#endif
