#include <iostream>
#include "encabezados/Generadores.h"
#include "encabezados/Pruebas.h"
using namespace std;

void creditos();

int main()
{
    int opcion;
	do
	{
		system("cls");
		cout<<"GENERADORES DE NUMEROS PSEUDOALEATORIOS Y PRUEBAS ESTADISTICAS"<<endl;
		cout<<"1. Generar numeros pseudoaleatorios"<<endl;
		cout<<"2. Realizar pruebas sobre un conjunto de numeros"<<endl;
		cout<<"3. Creditos"<<endl;
		cout<<"0. Salir"<<endl;
		cout<<"Seleccione una opcion: ";
		cin>>opcion;
		system("cls");
		switch(opcion)
		{
			case 1:
				menuGeneradores();
				break;
			case 2:
				menuPruebas();
				break;
			case 3:
				creditos();
				break;
			case 0: break;
			default: cout<<"Opcion Seleccionada es Incorrecta"<<endl;
		}
	}while(opcion != 0);
}

void creditos()
{
	system("cls");
    cout<<"ESTE CODIGO FUE REALIZADO POR LOS ESTUDIANTES DE INGENIERIA DE SISTEMAS"<<endl;
    cout<<"NESTOR CAÑAVERAL - LOPEZ FONTALVO"<<endl;
    cout<<"DE LA UNIVERSIDAD DE CARTAGENA PARA EL CURSO DE SIMULACION DIGITAL"<<endl;
    system("pause");
}