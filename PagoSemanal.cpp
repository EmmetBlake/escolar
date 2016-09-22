#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <string>
#include <string.h>

using namespace std;

int main(){
	float premioPuntualidad,sueldo,pagoSemana;
	int numeroFaltas,numeroRetardos,numeroSemana, otraOperacion,decision;
	string nombreEmpleado,estatus;
	cout<< "Programa para calcular el sueldo semanala de los trabajadores";
	cout<< "\n Por favor ingresa el numero de la semana de la que se va a hacer el calculo: ";
	cin>> numeroSemana;
	int ver1=0;
	while(ver1==0){
		if(numeroSemana<1||numeroSemana>52){
			cout<<"\n Numero de semana invalido introduce un numero valido:  ";
			cin>>numeroSemana;
		}else{
			ver1=1;
		}
	}
	ofstream archivo;
	archivo.open("NominaSemanal.txt");
	otraOperacion=0;
	ifstream leer;
	leer.open("kardex.txt");
	char prueba[40];
	archivo<< "Nomina de los empleados correspondiente a la semana "<<numeroSemana;
	while(otraOperacion<16){
		for(int i=0;i<4;i++){
			leer.getline(prueba,40,'\n');                    
   
			if(i==0){
				nombreEmpleado=prueba;
			}else if(i==1){
				sueldo = atof(prueba);
			}else if(i==2){
				numeroRetardos = atoi(prueba);
			}else if(i==3){
				numeroFaltas = atoi(prueba);
			}
		
            			
		}
                        
	
		if(numeroRetardos>0){
			premioPuntualidad=0;
		}else{
			premioPuntualidad=sueldo*.10;
		}
		if (numeroRetardos<6&&numeroRetardos>=3){
			numeroFaltas=numeroFaltas+1;
		}else if(numeroRetardos>=6){
			numeroFaltas=numeroFaltas+2;
		}
		if(numeroFaltas>3){
			estatus= "Inactivo";
			
		}else{
			estatus= "Activo";
		}
		if(numeroFaltas>0){
              premioPuntualidad=0;}
		pagoSemana=sueldo+premioPuntualidad-((sueldo/7)*numeroFaltas);
		if(numeroFaltas>3){
			pagoSemana=0;
		}
		archivo<< "\n"<< "\n Nombre Empleado: "<<nombreEmpleado;
		archivo<< "\n sueldo Semanal: "<<sueldo;
		archivo<< "\n Numero de retardos: "<<numeroRetardos;
		archivo<< "\n Numero Faltas: "<<numeroFaltas;
		archivo<< "\n Estatus del Trabajador:  "<<estatus;
		archivo<< "\n Pago Semanal: "<<pagoSemana<<"\n"<<"\n";
		otraOperacion++;

	}
		cout<< "\n El archivo NominaSemanal.txt correspondiente a la semana "<<numeroSemana<<" a sido creado y se encuentra en la carpeta raiz del programa"<<"\n"<<"Gracias buen dia"<<"\n";
		system("pause");
}
