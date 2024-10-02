#include <iostream>
#include "encabezados/Generadores.h"
#include "encabezados/Archivo.h"
#include "encabezados/Limpieza.h"
#include "encabezados/Distribuciones.h"
using namespace std;

void creditos();

int main()
{
	verificarSO();
    int opcion;
	do
	{
		system(limpiarConsola.c_str());
		cout<<"GENERADORES DE NUMEROS PSEUDOALEATORIOS Y PRUEBAS ESTADISTICAS"<<endl;
		cout<<"1. Generar numeros pseudoaleatorios"<<endl;
		cout<<"2. Realizar pruebas sobre un conjunto de numeros"<<endl;
		cout<<"3. Generar numeros siguiendo una distribucion"<<endl;
		cout<<"4. Creditos"<<endl;
		cout<<"0. Salir"<<endl;
		cout<<"Seleccione una opcion: ";
		cin>>opcion;
		switch(opcion)
		{
			case 1:
				menuGeneradores();
				break;
			case 2:
				obtenerDatos();
				break;
			case 3:
				menuDistribuciones();
				break;
			case 4:
				creditos();
				break;
			case 0: 
				system(limpiarConsola.c_str());
				break;
			default: cout<<"Opcion Seleccionada es Incorrecta"<<endl;
		}
	}while(opcion != 0);
}

void creditos()
{
	system(limpiarConsola.c_str());
    cout<<"ESTE CODIGO FUE REALIZADO POR EL ESTUDIANTE DE INGENIERIA DE SISTEMAS"<<endl;
    cout<<"NESTOR FABIAN CANAVERAL VELASQUEZ"<<endl;
    cout<<"DE LA UNIVERSIDAD DE CARTAGENA PARA EL CURSO DE SIMULACION DIGITAL"<<endl;
    system(pausarConsola.c_str());
}