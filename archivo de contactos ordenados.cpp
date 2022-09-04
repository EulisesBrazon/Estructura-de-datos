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


struct Contacto {
	string numero;
	string nombre;

};

int listar(string nombre) {

	ifstream archivoIn(nombre.c_str(),ios::in);
	
	if (!archivoIn) {
		
		cerr << "incapaz de abrir el archivo de entrada precaucion de salida\n";
		return -1;
	}

	Contacto contacto;
	cout << "info del archivo" << endl;
	cout << "Telefono " << "\t" << "nombre\n";
			
	while(archivoIn>>contacto.numero>>contacto.nombre){// && getline(archivoIn, contacto.nombre)) {
		cout << contacto.numero <<"\t\t"<< contacto.nombre << endl;
	}

	archivoIn.close();
	return 0;
}

long tamanio(string nombreArchivo){
	
	ifstream archivoIn(nombreArchivo.c_str(),ios::in);
	
	if(!archivoIn){
		cerr<<"error al intentar abrir "<<nombreArchivo<<endl;
		return 1;
	}
	long contador=0;
	Contacto registro;
	while(archivoIn>>registro.numero>>registro.nombre){ 
		contador++;
	}
	archivoIn.close();
	return contador;
}

int agregarOrdenado(string nombre){
	
	long total=tamanio(nombre);
	
	ifstream archivoIn(nombre.c_str(),ios::in);
		
	//si no hay archivo lo creo
	if (!archivoIn){
		archivoIn.close();
		ofstream archivoOut(nombre.c_str(), ios::out);// si no lo oncuentra lo crea
		archivoOut.close();
		
		ifstream archivoIn(nombre.c_str(),ios::in);//intento de nuevo
		if(!archivoIn)//si aun asi sigue dando error, ya es por otra causa
		{
			cerr << "erro al intentar abirir "<< nombre <<endl;
			return -1;
		}	
	}
	
	ofstream archivoOutTemp("temp.txt", ios::out);
	
	if (!archivoOutTemp ){
		cerr << "erro al intentar abirir un archivo temporal" <<endl;
		return -1;
	}
	
	
	Contacto nuevo;
	Contacto registro;
	bool cambio=false;
		
	cout << "ingrese Numero : ";
	cin>>nuevo.numero;
	
	cout << "ingrese Nombre : ";
	cin>> nuevo.nombre;
	
	if(total==0){//si por alguna razon esta vacio, no es necesario buscar nada, simplemente es agregar
		archivoOutTemp<< nuevo.numero << " "<< nuevo.nombre << endl;
	}
	else{
		while(archivoIn>>registro.numero>>registro.nombre){ 
		//&& getline(archivoIn, registro.nombre)) dio errores al momento de hacer  
		//getline(cin, registro.nombre) para cargar el nombre ya que al segundo contacto continuo
		//que se intentaba agregar, no retornaba ningun valor y cargaba directamento en blanco
			if(strcmp(registro.nombre.c_str(),nuevo.nombre.c_str())==1 && !cambio){
			//el getline de funcionar no modificaria en nada la logica de comparacion 	
				archivoOutTemp<< nuevo.numero << " "<< nuevo.nombre << endl;
				archivoOutTemp<< registro.numero <<" "<< registro.nombre << endl;
				cambio=true;
			}
			else{
					archivoOutTemp<< registro.numero <<" "<< registro.nombre << endl;	
			}
		}
		if(!cambio){//si no hubo ningun cambio significa que es el ultimo
			archivoOutTemp<< nuevo.numero <<" "<< nuevo.nombre << endl;	
		}
		
	}
	archivoIn.close();
	archivoOutTemp.close();
	cin.clear();
	remove(nombre.c_str());
	rename("temp.txt",nombre.c_str());
	
	return 0;
}
	
void instrucciones(){
	cout<<"seleciones la funcion a realizar"<<endl;
	cout<<"1 - agregar persona"<<endl;
	cout<<"2 - listar"<<endl;
	cout<<"x - salir"<<endl;
}

int main() {
	char opc;

	do{
		instrucciones();
		opc=getch();
		system("cls");
		if(opc=='1'){
			agregarOrdenado("telefono.txt");	
		}
		else if(opc=='2'){
			listar("telefono.txt");
		}
		system("pause");
		
	}while(opc!='x' &&  opc!='X' );
	
	getch();
	return 0;
}
