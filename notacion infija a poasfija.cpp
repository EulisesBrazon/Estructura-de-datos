/*
Integrantes
Eulises Brazon
Josue Baez
*/
#include<iostream>
#include <string>
#include "pila_con_nodos.cpp"
using namespace std;

int ideOperadores(char o) {

	if (o == '{' || o == '['  || o == '(' ) {
		return -5;
	}
	else if (o == '}' || o == ']'|| o == ')') {
		return -4;
	}
	else if (o == '^') {
		return 3;
	}
	else if (o == '*' || o == '/') {
		return 2;
	}
	else if (o == '+' || o == '-') {
		return 1;
	}
	else {
		return -1;
	}
}

string sinEspacio(string cadena){
	
	int tamanio =cadena.size();	
	string resultado;
	int i=0;
	bool bandera=true;
	
	//necesito cargar mi primer dato para inicializar el string
	while(bandera && i<tamanio){
		if(cadena[i]!=32){   //32 es el numero asignado al espacio en blanco
			resultado=cadena[i];
			bandera=false;
			i++;
		}
		else{
			i++;
		}
	}
	
	for( ; i<tamanio;i++){
		if(cadena[i]!=32){
			resultado=resultado+cadena[i];
		}
	}
	return resultado;
}

string infojo_Posfijo(string infijo){
	
	infijo=sinEspacio(infijo);
	int tamanio=infijo.size();
    string posfijo= " ";//es necesario inicializar
    Pila<char> operador;
	char presedencia;
	
	for(int i=0; i<tamanio; i++){
		
		if(ideOperadores(infijo[i])==-5){
			operador.push(infijo[i]);
		}
		else if(ideOperadores(infijo[i])==-4){
			char final;
			if(infijo[i]==41){
				final=40;
			}else{
				final=infijo[i]-2;
			}
			int bandera=0;
			char evaluar=operador.pop();
			
			while(evaluar!=final){
				posfijo=posfijo+evaluar;
				evaluar=operador.pop();
			}
		}
		else if(ideOperadores(infijo[i])==-1){
			posfijo=posfijo+infijo[i];
		}
		else{
			presedencia=operador.pop();
			while(!operador.pilaVacia() && ideOperadores(infijo[i])<=ideOperadores(presedencia)){	
				posfijo=posfijo+presedencia;
				presedencia=operador.pop();
			}
			operador.push(presedencia);//para que no se pierda el dato obteniendo.... el valor del tope sin eliminarlo
			operador.push(infijo[i]);		
		}
	}
	while(!operador.pilaVacia()){
		posfijo=posfijo+operador.pop();
	}
	
    return sinEspacio(posfijo);
}

	
	
	


int main(){

	string infija;
	cout<<"intregrese el refijo"<<endl;
	getline(cin, infija );
	cout<<"resultado :"<< infojo_Posfijo(infija)<<endl;	
	
	return 0;
}

