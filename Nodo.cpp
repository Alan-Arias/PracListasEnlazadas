//---------------------------------------------------------------------------

//#pragma hdrstop

#include "Nodo.h"
#include <stdio.h>
typedef int Tipo;
struct Nodo{
	Tipo Data;
	Nodo *Link;
};
typedef Nodo *Puntero;

const TIERRA = NULL;

void CrearNodo(Puntero &p)
{
// Pre: El almacenamiento no está lleno
// A p se le dá una caja de almacenamiento
	p = new Nodo;
}
bool AlmacLleno()
{// Retorna TRUE si y solo si el almacenamiento está lleno y FALSE en caso contrario
	Puntero aux;
	aux=new Nodo;
	if (aux == NULL) {
		return true;
	}else{
		delete aux;  //libera memoria pedida para aux
		return false;
    }
}
void Retornar(Puntero &p)
{ //devuelve la caja apuntada por p al almacenamiento
	delete p;
}
Tipo Data(Puntero p)
{ // Retorna el valor del campo data de la caja apuntada por p
	return (*p).Data;
}
Puntero Link(Puntero p)
{ // Retorna el valor (dirección) del puntero Link de la "caja" apuntada por p
	return (*p).Link;
}
void PonerData(Puntero &p, Tipo valor)
{ // Asigna valor al data del nodo apuntado por p
	(*p).Data=valor;
}
void PonerLink(Puntero &p, Puntero q)
{ // Asigna el puntero q al link del nodo apuntado por p
	(*p).Link=q;
}
//---------------------------------------------------------------------------
#pragma package(smart_init)
