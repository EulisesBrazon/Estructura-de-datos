/*
Integrantes
Eulises Brazon
Kao Lo  
Karoli Quijada           
*/
#include <iostream>
#include <conio.h>
using namespace std;

template<class T>
class Nodo {
	
	protected: 
		T clave;
		Nodo<T> *previo;
		Nodo<T> *proximo;
		
	public:
		Nodo() {
			previo = proximo = NULL;
		}
		
		void fijarClave(T c) {
			clave = c;
		}
		
		T obtenerClave() {
			return clave;
		}
		
		void fijarPrevio(Nodo <T>*x) {
			previo = x;
		}
		
		Nodo<T> *obtenerPrevio() {
			return previo;
		}
		
		void  fijarProximo(Nodo <T>*x) {
			proximo = x;
		}
		
		Nodo<T> *obtenerProximo() {
			return proximo;
		}
};

template <class T>
class ListaDobleCircular{
	
	protected:
		Nodo<T> *S;
	
	public:
		ListaDobleCircular() {
			S = new Nodo <T>;
			S-> fijarProximo(S);
			S->fijarPrevio(S);
		}
		
	Nodo<T> *ObtenerS() {
		return S;
	}
	
	void vaciarLista(){
		Nodo<T> *x = S->obtenerProximo();
		while (x != S) {
			eliminar(x);
			x = x->obtenerProximo();
		}
	}		
			
	void mostrarNodos() {
		Nodo<T> *x = S->obtenerProximo();
		while (x != S) {
			cout<<"Informacion encontrada: "<< x->obtenerClave()<<endl;
			x = x->obtenerProximo();
		}
	}
		
	//Destructor de la lista para liberar el espacio de memoria	
	~ListaDobleCircular() {
		Nodo<T> *x = S->obtenerProximo();
		while (x != S) {
			Nodo<T> *y = x->obtenerProximo();
			delete x;
			x = y;
		}
		delete(S);
	}
	
	//Metodos de la clase Lista Doble Circular
	void insertar(Nodo<T> *x) {
		x-> fijarProximo(S->obtenerProximo());
		S->obtenerProximo()->fijarPrevio(x);
		S-> fijarProximo(x);
		x->fijarPrevio(S);
	}
		
	Nodo<T> *buscar(T K) {
		Nodo<T> *x = S->obtenerProximo();
		while (x!=S && x->obtenerClave()!=K)
			x = x->obtenerProximo();
		return x;
	}
	
	void eliminar(Nodo<T>*x) {
		x->obtenerPrevio()-> fijarProximo(x->obtenerProximo());
		x->obtenerProximo()->fijarPrevio(x->obtenerPrevio());
	}
		
};

void menu() {
	ListaDobleCircular <int> ldc;
	Nodo <int> *x;
	int opcion = 0;
	
	do {
		cout<<"==================================="<<endl;
		cout<<"            BIEVENIDA              "<<endl;
		cout<<"==================================="<<endl;
		cout<<"\nSeleccione una opcion:\n"<<endl;
		cout<<"1. insertar en la lista "<<endl;
		cout<<"2. Eliminar valor de la lista"<<endl;
		cout<<"3. Mostrar la lista"<<endl;
		cout<<"4. Vaciar lista"<<endl;
 		cout<<"5. Salir\n"<<endl;
		cin>>opcion;
		system("cls");
		
		switch(opcion) {
			case 1: {
				int valor = 0, cant=0, i=0;
				cout<<"Ingrese la cantidad de valores que desea agregar: ";
				cin>>cant;
				while(i<cant){
					cout<<"Ingrese el valor nro "<<i+1<<": ";
					cin>> valor; cin.ignore();
					x = new Nodo <int>;
					x->fijarClave(valor);
					ldc.insertar(x);
					i++;
				}
				break;
			}		
			case 2: {
				int valorEliminar;
				cout<<"ingrese el valor que desea eliminar de la lista: ";
				cin>>valorEliminar;
				x = new Nodo <int>;
				x =ldc.buscar(valorEliminar);
				ldc.eliminar(x);		
				break;
			}
			case 3: {
				ldc.mostrarNodos();					
				break;
			}
			case 4: {
				ldc.vaciarLista();
				cout<<"La lista esta vacia";		
				break;
			}
			case 5: {
				cout<<"El programa ha finalizado"<<endl;							
				break;
			}
			
			default: 
				cout<<"Opcion incorrecta, presione ENTER para continuar"<<endl;
				getch();					
				break;			
		}
		
	} while (opcion!=5);
	
	system("pause");
}

/*-------MAIN--------*/
int main(){
	system("title Implementacion de una pila simulada con nodos");
    system("color 03");
    menu();
    return 0;	
}
