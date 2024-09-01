#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <fstream>
#include <cmath>
#include "../encabezados/Limpieza.h"
using namespace std;

void menuPruebas(vector<double> numeros, int n)
{
	int opcion;
	do
	{
		system(limpiarConsola.c_str());
		cout<<"MENU PARA PRUEBAS ESTADISTICAS SOBRE CONJUNTOS DE NUMEROS PSEUDOALEATORIOS"<<endl;
		cout<<"1. Prueba de los promedios"<<endl;
		cout<<"2. Prueba de frecuencias"<<endl;
		cout<<"3. Prueba de la distancia"<<endl;
		cout<<"4. Prueba de series"<<endl;
		cout<<"5. Prueba de kolgomorov-smirnov"<<endl;
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