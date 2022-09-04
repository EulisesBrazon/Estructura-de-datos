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
string nombreArchivo = "datosIniciales.txt";//para poder visualizar sin mayor complicacion

struct Persona {
	char nombre[20];
	char altura[4];
	char tamanioZapato[4];
	char edad[3];
	char edoCivil[10];
};

int agregar(string archivo,Persona &persona){
	
	ofstream archivoOut(archivo.c_str(), ios::out | ios::binary| ios::app);
	
	if(!archivoOut){
		cerr<<"error al intentar abrir "<<archivo<<endl;
		return 1;
	}
	
	archivoOut.write((char*)&persona, sizeof(Persona));
	
	archivoOut.close();
	return 0;
}

void limpiar(Persona &persona){

	for(int i=0; i<20; i++){
		persona.nombre[i]= 32;//32 es el numero asignado al espacio en blanco en la tabla ascii
	}
	for(int i=0; i<4; i++){
		persona.altura[i]=32;
	}
	for(int i=0; i<4; i++){
		persona.tamanioZapato[i]=32;
	}
	for(int i=0; i<3; i++){
		persona.edad[i]=32;
	}
	for(int i=0; i<10; i++){
		persona.edoCivil[i]=32;
	}
}

void pedirNuevoDato(string archivo){
	
	Persona persona;
	limpiar(persona);

	cout<<"nombre: "<<endl;
	cin>>persona.nombre;
	
	cout<<"altura: "<<endl;
	cin>>persona.altura;
	
	cout<<"tamaño zapato: "<<endl;
	cin>>persona.tamanioZapato;
	
	cout<<"edad: "<<endl;
	cin>>persona.edad;
	
	cout<<"estado civil: "<<endl;
	cin>>persona.edoCivil;
	persona.edoCivil[9]='\n';
	
	agregar(archivo.c_str(),persona);
}

int preguntar(Persona persona){
	
	char opc;
	
	do{
		system("cls");	
		cout<<"imgrese h si es hombres y m si es mujer"<<endl;
		cout<<persona.nombre<<endl;
		opc=getch();
		if(opc=='h' || opc=='H'){
			return 1;
		}
		if(opc=='m' || opc=='M'){
			return -1;
		}
		
		
	}while (opc!='h' &&  opc!='H' &&  opc!='m' &&  opc!='M');
	return 0;
}

int ordenar(string archivo){
	
	ifstream entrada(archivo.c_str(), ios::in | ios::binary);
	ofstream hombre("hombres.txt", ios::out | ios::binary | ios::app);
	ofstream mujer("mujeres.txt", ios::out | ios::binary | ios::app);
	
	
	if(!entrada ){
		cerr<<"error al intentar acceder a "<<archivo<<endl;
		return 1;
	}
	if(!hombre){
		cerr<<"error al intentar acceder a hombres.txt"<<endl;
		return 1;
	}
	if(!mujer){
		cerr<<"error al intentar acceder a mujeres.txt"<<endl;
		return 1;
	}

	
	Persona temporal;
	
	int i;
	while (entrada.read((char*)&temporal,sizeof(Persona))){	
		i=preguntar(temporal);
		
		if(i==1){//para el hombre
			hombre.write((char*)&temporal, sizeof(Persona));
		}
		else if(i==-1){// para la mujer
			mujer.write((char*)&temporal, sizeof(Persona));
		}
		
	}
	mujer.close();
	hombre.close();
	entrada.close();
	
	cout<<"elementros reasignados correctamente"<<endl;
	
	return 0;
}

void instrucciones(){
	cout<<"seleciones la funcion a realizar"<<endl;
	cout<<"1 - agregar persona"<<endl;
	cout<<"2 - reordenar hombres y mujeres"<<endl;
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
			ordenar(nombreArchivo);
		}
		system("pause");
		
	}while(opc!='x' &&  opc!='X' );
	
	getch();
	return 0;
}
