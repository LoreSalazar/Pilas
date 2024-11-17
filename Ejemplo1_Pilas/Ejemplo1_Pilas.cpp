/* Utilizando pilas, hacer un programa que tenga un menú con:
*
* 1) Insertar un caracter a la pila
* 2) Mostrar todos los elementos de la pila
* 3) Salir

*/

#include <iostream>
#include <stdlib.h>

using namespace std;

struct nodo {
	char letra;
	nodo* siguiente;
};

void agregarPila(nodo*&, char);
void sacarPila(nodo*&, char&);

int main() {

	char caracter;
	nodo* pila = NULL;
	int opcion = 0;

	cout << "BIENVENIDO ";

	do {
		cout << "\nPor favor elige una opcion para continuar: " << endl;
		cout << "\n\t1) Insertar un caracter a la pila \n\t2) Mostrar todos los elementos de la pila \n\t3) Salir" << endl;
		cin >> opcion;

		switch (opcion)
		{
		case 1:
			cout << "Introduce tu caracter: ";
			cin >> caracter;
			agregarPila(pila, caracter);
			break;
		case 2:
			cout << "\n\n";
			while (pila != NULL) {
				sacarPila(pila, caracter);
				cout << caracter;
			}
		default:
			break;
		}
	} while (opcion != 3);

	return 0;
}

void agregarPila(nodo*& pila, char nombre) {
	nodo* nuevoNodo = new nodo();
	nuevoNodo->letra = nombre;
	nuevoNodo->siguiente = pila;
	pila = nuevoNodo;
}

void sacarPila(nodo*& pila, char& nombre) {
	nodo* aux = pila;
	nombre = aux->letra;
	pila = aux->siguiente;
	delete aux;
}

