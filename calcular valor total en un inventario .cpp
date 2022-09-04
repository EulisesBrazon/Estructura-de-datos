/*
Integrantes
Eulises Brazon
Josue Baez
*/
#include<iostream>
#include<string>
#include<fstream>
#include<conio.h>
#include <cstring>

using namespace std;
string nombreArchivo = "inventario.txt";//para poder visualizar sin mayor complicacion

struct Libro {
	char titulo[30];
	char autor[20];
	unsigned long isbn;
	int precio;
	int cantidad;
	char editorial[30];
};
	
int agregar(string archivo,Libro &persona){
	
	ofstream archivoOut(archivo.c_str(), ios::out | ios::binary| ios::app);
	
	if(!archivoOut){
		cerr<<"error al intentar abrir "<<archivo<<endl;
		return 1;
	}
	
	archivoOut.write((char*)&persona, sizeof(Libro));
	
	archivoOut.close();
	return 0;
}

void limpiar(Libro &libro){
//en ocaciones llega a imprimir basura en los espacio que no se asigna ningun valor
	
	for(int i=0; i<30; i++){
		libro.titulo[i]= 32;//32 es el numero asignado al espacio en blanco en la tabla ascii
	}
	for(int i=0; i<20; i++){
		libro.autor[i]= 32;
	}
	for(int i=0; i<30; i++){
		libro.editorial[i]= 32;
	}
}

void pedirNuevoDato(string archivo){
	
	Libro libro;
	limpiar(libro);

	cout<<"titulo: "<<endl;
	cin>>libro.titulo;
	
	cout<<"autor: "<<endl;
	cin>>libro.autor;
	
	cout<<"isbn: "<<endl;
	cin>>libro.isbn;
	
	cout<<"precio: "<<endl;
	cin>>libro.precio;
	
	cout<<"cantidad: "<<endl;
	cin>>libro.cantidad;
	
	cout<<"editorial: "<<endl;
	cin>>libro.editorial;
	
	libro.editorial[29]='\n';//para poder terner un resultado visual aunque no sea necesario para la funcionalidad
	
	agregar(archivo.c_str(),libro);
}

int calcularTolal(string archivo){
	
	ifstream entrada(archivo.c_str(), ios::in | ios::binary);

	if(!entrada ){
		cerr<<"error al intentar acceder a "<<archivo<<endl;
		return 1;
	}

	Libro temporal;
	
	long total=0;
	
	while (entrada.read((char*)&temporal,sizeof(Libro))){	   
	    total=total+(temporal.precio*temporal.cantidad);
	}
	entrada.close();
	
	cout<<"El total en el inventario es: "<<total<<endl;
	
	return 0;
}

void instrucciones(){
	cout<<"seleciones la funcion a realizar"<<endl;
	cout<<"1 - agregar libro"<<endl;
	cout<<"2 - calcular valor total en el inventario"<<endl;
	cout<<"x - salir"<<endl;
}

int main() {
	char opc;
	string s;
	
	do{
		instrucciones();
		opc=getch();
		system("cls");
		
		if(opc=='1'){
			pedirNuevoDato(nombreArchivo);	
		}
		else if(opc=='2'){
			calcularTolal(nombreArchivo);
		}
		system("pause");
		
	}while(opc!='x' &&  opc!='X' );
	
	getch();
	return 0;
}
