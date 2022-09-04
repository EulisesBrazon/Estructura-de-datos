/*
Integrantes
Eulises Brazon
Josue Baez
*/
#include<iostream>
using namespace std;


template<class T>
class Nodo {
	T clave;
	Nodo<T> *proximo;
public:
	Nodo() { proximo = NULL; }
	Nodo<T> *obtenerProximo() { return proximo; }
	T obtenerClave() { return clave; }
	void fijarProximo(Nodo<T> *x) { proximo = x; }
	void fijarClave(T x) { clave = x; }
};
template<class T>
class Pila{
	Nodo<T> *cima;
public:
	Pila() { cima = NULL; }

	void push(T dato) {
		Nodo<T> *aux = new Nodo<T>;
		aux->fijarClave(dato);
		aux->fijarProximo(cima);
		cima = aux;
	}
	bool pilaVacia() {
		if (cima == NULL) 
			return true;
		else
			return false;
	}
	T pop() {
		if (!pilaVacia()) {
			Nodo<T> *aux = cima;
			//aux->fijarClave(cima->obtenerClave());
			cima = cima->obtenerProximo();			
			return aux->obtenerClave();
		}
		else 
	    	return -1; //El t�rmino subflujo aritm�tico es una condici�n en un programa de computadora donde el resultado de un c�lculo es un n�mero menor que el ordenador puede almacenar realmente en memoria. 
		
		
	}
	T cimaPila() {
		if (!pilaVacia()) {
			return cima->obtenerClave();
		}else
			return -1;
	}
	void limpiarPila() {
		while (!pilaVacia()) {
			Nodo<T> *aux = cima;
			cima = cima->obtenerProximo();
			delete aux;
		}
	}

};

