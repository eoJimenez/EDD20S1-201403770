#include <iostream>
#include <string>
#include <cstring>
#include <bits/stdc++.h>

using namespace::std;

struct Nodo{
	char letra;
	Nodo* siguente;
	Nodo* anterior;
	//string palabra; 
	
}
*primero, *ultimo;

void InsertarNodo();
void MostrarLista();
void BuscarNodo();
void EliminarNodo();

int main(){

int opcion_menu=0;
	do
	{
		cout << "\n|----------------- |";
		cout << "\n| ° LISTA DOBLE °  |";
		cout << "\n|------------------|";
		cout << "\n| 1. Insertar      |";
		cout << "\n| 2. Buscar        |";
		cout << "\n| 3. Eliminar      |";
		cout << "\n| 4. Mostrar       |";
		cout << "\n| 5. Salir         |";
		cout << "\n|------------------|";
		cout << "\n\n Escoja una Opcion: ";
		cin >> opcion_menu;
		switch(opcion_menu){
		case 1:
			cout << "\n\n INSERTA NODO EN LA LISTA \n\n";
			InsertarNodo();
			break;
		case 2:
			cout << "\n\n BUSCAR UN NODO EN LA LISTA \n\n";
			BuscarNodo();
			break;
	 	case 3:
			cout << "\n\n ELIMINAR UN NODO DE LA LISTA \n\n";
			EliminarNodo();
			break;
		case 4:
			cout << "\n\n MOSTRAR LISTA\n\n";
			MostrarLista();
			break;
		case 5: 
			cout << "\n\n Programa finalizado...";
			break;
		default:
			cout << "\n\n Opcion No Valida \n\n";
		}
		
	} while (opcion_menu != 5);	
	return 0;
}

void InsertarNodo(){
	Nodo* nuevo = new Nodo();
	cout << " Ingrese el caracter: ";
	cin >> nuevo->letra;
	
	if(primero==NULL){
		primero = nuevo;
		primero->siguente = NULL;
		primero->anterior = NULL;
		ultimo = primero;
	}else{
		ultimo->siguente = nuevo;
		nuevo->siguente = NULL;
		nuevo->anterior = ultimo;
		ultimo = nuevo;
	}
	cout << "\n Nodo Ingresado\n\n";
}

void MostrarLista(){
	Nodo* actual = new Nodo();
	actual = primero;
	if(primero!=NULL){
		while(actual!=NULL){
			cout << "\n " << actual->letra;
			actual = actual->siguente;
		} 
	}else{
		cout << "\n La lista se encuentra vacia\n\n";
	}
}

void BuscarNodo(){
	Nodo* act = new Nodo();
	act = primero;
	bool encontrado = false;
	string NodoBuscado;
	cout << " Ingrese el texto a buscar: ";
	cin >> NodoBuscado;
	//cout << NodoBuscado;
	int n = NodoBuscado.length();
	char char_array[n+1];
	strcpy (char_array, NodoBuscado.c_str());
	if(primero!=NULL){
		while(act!=NULL && encontrado!=true){
			if(act->letra == char_array[0]){
				cout<< "\n Nodo con el dato ( " <<char_array[0] << " ) Encontrado\n\n";
				encontrado = true;
			}
			
			act = act->siguente;
		}
		if(!encontrado){
			cout<< "\n Nodo no Encontrado\n\n";
		}
	}else{
		cout << "\n La lista se encuentra vacía\n\n";
	}
	
}

void EliminarNodo(){
	Nodo* actual = new Nodo();
	actual = primero;
	Nodo* ant = new Nodo();
	ant = NULL;
	bool encontrado = false;
	if(primero != NULL){
		while(actual->siguente!=NULL){
			if(actual == primero){
				primero = primero->siguente; 
				primero->anterior = NULL;
			}else if(actual == ultimo){
				ant->siguente= NULL;
				ultimo = ant;
			}else{
				ant->siguente = actual->siguente;
				actual->siguente->anterior = ant;
			}
			ant = actual;
			actual = actual->siguente;
		}
	}else{
		cout<< "\n Nodo no encontrado\n\n";
	}
}


