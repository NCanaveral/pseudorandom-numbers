#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
#include <cmath>
#include <cstdint>
#include "../encabezados/Limpieza.h"
using namespace std;

void congruencial_aditivo();
void congruencial_multiplicativo();
void congruencial_mixto();
void tausworthe();
void parte_central();
void archivo(double numeros[], int iniciales, int n);
void cambiar_cifras();
int cifras_significativas = 3;

void menuGeneradores()
{
	int opcion;
	do
	{
		system(limpiarConsola.c_str());
		cout<<"GENERADOR DE NUMEROS PSEUDOALEATORIOS"<<endl;
		cout<<"1. Congruencial aditivo"<<endl;
		cout<<"2. Congruencial multiplicativo"<<endl;
		cout<<"3. Congruencial mixto"<<endl;
		cout<<"4. Metodo de tausworthe"<<endl;
		cout<<"5. Metodo de la parte central del cuadrado"<<endl;
		cout<<"6. Cambiar numero de cifras significativas (actual: "<<cifras_significativas<<")"<<endl;
		cout<<"0. Salir"<<endl;
		cout<<"Seleccione el metodo a realizar: ";
		cin>>opcion;
		system(limpiarConsola.c_str());
		switch(opcion)
		{
			case 1:
				congruencial_aditivo();
				break;
			case 2:
				congruencial_multiplicativo();
				break;
			case 3:
				congruencial_mixto();
				break;
			case 4:
				tausworthe();
				break;
			case 5:
				parte_central();
				break;
			case 6:
				cambiar_cifras();
				break;
			case 0: break;
			default: cout<<"Opcion Seleccionada es Incorrecta"<<endl;
		}
	}while(opcion != 0);	
}

void congruencial_aditivo()
{
	int k, n, modulo;
	double cifras = pow(10, cifras_significativas);
	cout<<"Ingrese la cantidad de numeros a generar: ";
    cin>>n;
    double listaAleatorios[n];
    int numeros[n + k];
	cout<<"Ingrese el modulo: ";
	cin>>modulo;
    cout<<"Ingrese el numero de numeros iniciales: ";
    cin>>k;
    
    for(int i=0; i<k; i++)
    {
		cout<<"Ingrese el numero #"<<(i+1)<<": ";
    	cin>>numeros[i];
	}
	
    for(int i=0; i<n; i++)
    {
    	numeros[k] = (numeros[i] + numeros[k-1]) % modulo;
    	listaAleatorios[i] = round(((double) numeros[k] / (modulo-1)) * cifras) / cifras;
		k++;
		cout<<"Numero #"<<i+1<<" generado: "<<listaAleatorios[i]<<endl;
	}
	archivo(listaAleatorios, 0, n);
}

void congruencial_multiplicativo()
{
	int multi, modulo, n, semilla;
	double cifras = pow(10, cifras_significativas);
	cout<<"Ingrese la cantidad de numeros a generar: ";
    cin>>n;
    double listaAleatorios[n];
    cout<<"Ingrese la constante multiplicativa: ";
    cin>>multi;
    cout<<"Ingrese la semilla: ";
    cin>>semilla;
    cout<<"Ingrese el modulo: ";
    cin>>modulo;
    
    for(int i=0; i<n; i++)
    {
    	semilla = (semilla * multi) % modulo;
    	listaAleatorios[i] = round(((double) semilla / (modulo-1)) * cifras) / cifras;
		cout<<"Numero #"<<i+1<<" generado: "<<listaAleatorios[i]<<endl;
	}
	archivo(listaAleatorios, 0, n);
}

void congruencial_mixto()
{
	int multi, aditi, modulo, n, semilla;
	double cifras = pow(10, cifras_significativas);
	cout<<"Ingrese la cantidad de numeros a generar: ";
    cin>>n;
    double listaAleatorios[n];
    cout<<"Ingrese la constante multiplicativa: ";
    cin>>multi;
    cout<<"Ingrese la constante aditiva: ";
    cin>>aditi;
    cout<<"Ingrese la semilla: ";
    cin>>semilla;
    cout<<"Ingrese el modulo: ";
    cin>>modulo;
    
    for(int i=0; i<n; i++)
    {
    	semilla = ((semilla * multi) + aditi) % modulo;
    	listaAleatorios[i] = round(((double) semilla / modulo) * cifras) / cifras;
		cout<<"Numero #"<<i+1<<" generado: "<<listaAleatorios[i]<<endl;
	}
	archivo(listaAleatorios, 0, n);
}

void tausworthe()
{
	int longitud, nbits, n, semilla;
	double cifras = pow(10, cifras_significativas);
	cout<<"Ingrese la cantidad de numeros a generar: ";
    cin>>n;
    double listaAleatorios[n];
    cout<<"Ingrese la longitud de la relacion de recurrencia: ";
    cin>>longitud;
    cout<<"Ingrese el numero de bits de la secuencia: ";
    cin>>nbits;
    cout<<"Ingrese la semilla: ";
    cin>>semilla;

	uint64_t bits = semilla & ((1ULL << nbits) - 1); 
    for (int i=0; i<n; i++) 
	{
        uint64_t nuevo_bit = ((bits >> (nbits - longitud)) ^ bits) & 1;
        bits = ((bits << 1) | nuevo_bit) & ((1ULL << nbits) - 1);
        listaAleatorios[i] = round((static_cast<double>(bits) / ((1ULL << nbits) - 1)) * cifras) / cifras;
		cout<<"Numero #"<<i+1<<" generado: "<<listaAleatorios[i]<<endl;
    }
	archivo(listaAleatorios, 0, n);
}

void parte_central()
{
	int n, semilla, counter = 1;
	double cifras = pow(10, cifras_significativas);
	cout<<"Ingrese la cantidad de numeros a generar: ";
    cin>>n;
    double listaAleatorios[n];
    cout<<"Ingrese la semilla: ";
    cin>>semilla;
    for(int i=0; i<n; i++)
    {
    	string numero = to_string(semilla*semilla);
    	while(numero.length() > cifras_significativas)
    	{
    		if(counter % 2 == 0)
			{
				numero = numero.substr(1);
			}
			else
			{
				numero = numero.substr(0, numero.length() - 1);
			}
			counter++;
		}
		counter = 1;
		listaAleatorios[i] = stod(numero) / cifras;
		cout<<"Numero #"<<i+1<<" generado: "<<listaAleatorios[i]<<endl;
		semilla = stod(numero);
	}
	archivo(listaAleatorios, 0, n);
}

void archivo(double numeros[], int iniciales, int n)
{
	int k=0;
	ofstream archivo("Numeros_Generados.csv");
	if(archivo.fail())
	{
		cout<<"Error al abrir Numeros_Generados.csv"<<endl;
		exit(0);
	}
	for(int i=iniciales; i<n; i++)
	{
		archivo<<numeros[i]<<";";
		k++;
		if(k % 10 == 0)
		{
			archivo<<endl;
		}
	}
	cout<<"Los numeros generados fueron guardados en Numeros_Generados.csv"<<endl;
	archivo.close();
	system(pausarConsola.c_str());
}

void cambiar_cifras()
{
	cout<<"El numero actual de cifras maxima que cuentan los generadores es de: "<<cifras_significativas<<endl;
	cout<<"Que numero de cifras desea para futuras generaciones?: ";
	cin>>cifras_significativas;
	cout<<"El cambio se realizo correctamente!"<<endl;
	system(pausarConsola.c_str());
}

