#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
#include <cmath>
using namespace std;

void menuPruebas()
{
	int opcion;
	do
	{
		system("cls");
		cout<<"MENU PARA PRUEBAS ESTADISTICAS SOBRE CONJUNTOS DE NUMEROS PSEUDOALEATORIOS"<<endl;
		cout<<"1. Metodo 1"<<endl;
		cout<<"2. Metodo 2"<<endl;
		cout<<"3. Metodo 3"<<endl;
		cout<<"4. Metodo 4"<<endl;
		cout<<"5. Metodo 5"<<endl;
		cout<<"0. Salir"<<endl;
		cout<<"Seleccione el metodo a realizar: ";
		cin>>opcion;
		switch(opcion)
		{
			case 1:
				break;
			case 2:
				break;
			case 3:
				break;
			case 4:
				break;
			case 5:
				break;
			case 0: break;
			default: cout<<"Opcion Seleccionada es Incorrecta"<<endl;
		}
	}while(opcion != 0);	
}