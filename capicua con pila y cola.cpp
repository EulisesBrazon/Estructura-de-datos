/*
Integrantes
Eulises Brazon
Josue Baez
*/
#include<iostream>

using namespace std;
const int MAX = 30;
template<class T>
class Pila {
	T s[MAX];
	int tope;
public:
	Pila() { tope = -1; }
	bool PilaVacia() {
		return tope == -1;
	}
	void Push(T dato) {
		tope = tope + 1;
		s[tope] = dato;
	}
	T Pop() {
		if (!PilaVacia()) {
			tope = tope - 1;
			return s[tope + 1];
		}
		else
			return -1;
	}
	T Tope(){
		return s[tope];
	}
};

template<class T2>
class Cola {
	int cola[MAX];
	int frente;
	int fin;
	int contador;
public:
	Cola() {
		frente = -1;
		fin = -1;
		contador = -1;
	}
	insertar(T2 nuevo) {
		if (colaVacia()) {
			fin = 0;
			frente = 0;
			cola[fin] = nuevo;//agreglo el elemento en la posicion que le corresponde
			contador++;

		}
		else if (!colaLena()) {
			fin = (fin + 1) % MAX;//incremento la psociciocour
			cola[fin] = nuevo;// y guardo
			contador++;
		}
	}
	int retirar() {
		if (colaVacia()) {
			return -1;
		}
		else {
			int aux = cola[frente];
			frente = (frente + 1) % MAX; 
				contador = contador - 1;
			return aux;
		}
	}
	bool colaVacia() {
		if (contador == -1)
			return true;
		return false;
	}
	bool colaLena() {
		if (contador == MAX)
			return true;
		return false;
	}
	int getTamanio() {
		return contador;
	}
	/*mostrar (){  //para realizar pruebas
		cout<<"[ ";
		for(int i=frente; cola[i] < cola[fin] ; i++){
			cout<<cola[i]<<" , ";
		}
		cout << cola[fin] << "]" << endl;
	}*/
};

	
bool capicua( long int unsigned numero){
	
	long int unsigned aux = numero;
	int i;
	
	Cola<char> cola;
	Pila<char> pila;
	
	for( i=0; aux%10>0; i++){
		char c=aux%10;
		cola.insertar(c);
		pila.Push(c);
		aux=aux/10;
	}//cargo los elementos en posiciones separadas por caracteres
	
	int tamanio=cola.getTamanio();
	
	i=0;
	while(cola.retirar()==pila.Pop() && i<tamanio){
		i++;
	}
	
	if(i==tamanio){
		return true;
	}
	return false;
};

void cargarDato(long int unsigned &numero){
	
	cout<<"ingrese el numero a evaluar"<<endl;
	cin>>numero;

}

void mostrarResultado(long int unsigned &numero, bool resultado){
	
	if(resultado){
		cout<<"El numero "<<numero<<" es capicua"<<endl;
	}
	else
	{
		cout<<"El numero "<<numero<<" no es capicua"<<endl;
	}
}

int main() {
	
	long int unsigned numero;
	cargarDato(numero);
	mostrarResultado(numero,capicua(numero));

	system("pause");
	return 0;
}
