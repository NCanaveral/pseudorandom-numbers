#include <iostream>
#include <iomanip>
#include <sstream> 
#include <string>
#include <fstream>
#include <vector>
#include <cmath>
#include <filesystem>
#include "../encabezados/Limpieza.h"

using namespace std;

void uniforme();
void uniformeProbabilidad();
void poisson();
void exponencial();
double randomNumber();
template <typename T>
void archivo(const vector<T>& numeros);

vector<double> randomsUsed;

void menuDistribuciones()
{
    int opcion;
	do
	{
		system(limpiarConsola.c_str());
		cout<<"GENERADOR DE NUMEROS POR DISTRIBUCION"<<endl;
		cout<<"1. Distribucion uniforme"<<endl;
		cout<<"2. Distribucion de probabilidad uniforme"<<endl;
		cout<<"3. Distribucion Poisson"<<endl;
		cout<<"4. Distribucion exponencial"<<endl;
        cout<<"0. salir"<<endl;
		cout<<"Seleccione una opcion: ";
		cin>>opcion;
		switch(opcion)
		{
			case 1:
				uniforme();
				break;
			case 2:
				uniformeProbabilidad();
				break;
			case 3:
				poisson();
				break;
            case 4:
				exponencial();
				break;
			case 0: 
				system(limpiarConsola.c_str());
				break;
			default: cout<<"Opcion Seleccionada es Incorrecta"<<endl;
		}
	}while(opcion != 0);
}

void uniforme()
{
    system(limpiarConsola.c_str());
    int n;
    double A, B, numero;
    vector<double> resultados;
    cout<<"Ingrese el limite inferior de la distribucion: ";
    cin>>A;
    do
    {
        cout<<"Ingrese el limite superior de la distribucion: ";
        cin>>B;
        if(B<A)
        {
            cout<<"El limite superior no puede ser inferior al limite inferior, intente de nuevo"<<endl;
        }
    }while(B<A);
    cout<<"Ingrese el numero de numeros a incluir en la distribucion: ";
    cin>>n;
    for(int i=0; i<n; i++)
    {
        randomsUsed.push_back(randomNumber());
        numero = A + (randomsUsed.at(i) * (B-A));
        resultados.push_back(numero);
    }
    archivo(resultados);
}

void uniformeProbabilidad()
{
    system(limpiarConsola.c_str());
    int i=0, n;
    vector<double> probabilidades;
    vector<int> resultados;
    double dato, datoAnterior=0;
    cout<<"Ingrese un set de probabilidad acumulada, tenga en cuenta que"<<endl;
    cout<<"Deben ser entre 0 y 1, ademas de introducirlos en orden ascendente"<<endl;
    cout<<"Es decir que el siguiente sea mayor al anterior"<<endl;
    cout<<"Para terminar de anadir probabilidades ingrese 0"<<endl;
    probabilidades.push_back(0.0);
    do
    {
        cout<<"Ingrese la probabilidad numero "<<i+1<<": ";
        cin>>dato;
        if(dato < 0 || dato > 1)
        {
            cout<<"Dato rechazado, no es un numero de probabilidad entre 0 y 1"<<endl;
        }else if(dato < datoAnterior)
        {
            cout<<"Dato rechazado, no es mayor a la anterior probabilidad digitada"<<endl;
        }
        else if(dato != 0){
            probabilidades.push_back(dato);
            i++;
        }
    }while(dato != 0);
    probabilidades.push_back(1.0);
    cout<<"Ingrese el numero de numeros a incluir en la distribucion: ";
    cin>>n;

    for (int k = 0; k < n; ++k) {
        double rand = randomNumber();
        randomsUsed.push_back(rand);
        for (size_t j = 0; j < probabilidades.size(); ++j) {
            if (rand <= probabilidades[j]) {
                resultados.push_back(j);
                break;
            }
        }
    }
    archivo(resultados);
}

void poisson()
{
    system(limpiarConsola.c_str());
    int n, x = 0;
    double lambda, cdf = 0.0;
    cout<<"Ingrese el parametro lambda (frecuencia del suceso): ";
    cin>>lambda;
    cout<<"Ingrese el numero de numeros a incluir en la distribucion: ";
    cin>>n;

    double pmf = exp(-lambda);
    vector<double> pmfValues;
    vector<double> cdfValues;

    pmfValues.push_back(pmf);
    cdf += pmf;
    cdfValues.push_back(cdf);

    while (cdf < 0.999) {
        x++;
        pmf *= lambda / x;
        cdf += pmf;
        pmfValues.push_back(pmf);
        cdfValues.push_back(cdf);
    }

    vector<int> numeros;
    for (int i=0; i<n; i++) {
        randomsUsed.push_back(randomNumber());
        auto it = lower_bound(cdfValues.begin(), cdfValues.end(), randomsUsed.at(i));
        int index = distance(cdfValues.begin(), it);
        numeros.push_back(max(0, index));
    }

    ofstream archivo("Distribucion.csv");
	if(archivo.fail())
	{
		cout<<"Error al abrir Distribucion.csv"<<endl;
		exit(0);
	}
    archivo<<"Indice;Numero Aleatorio;Numero Generado"<<endl;
	for(size_t i=0; i<numeros.size(); i++)
	{
		archivo<<i+1<<";";
        archivo<<randomsUsed.at(i)<<";";
		archivo<<numeros.at(i)<<";";
        archivo<<endl;
	}
    archivo<<endl<<"x;PMF;CDF"<<endl;
    for (size_t i = 0; i < pmfValues.size(); ++i) 
    {
        archivo<<i<<";"<<pmfValues.at(i)<<";"<<cdfValues.at(i)<<endl;
    }
	cout<<"Los numeros generados fueron guardados en Distribucion.csv"<<endl;
	archivo.close();
    randomsUsed.clear();
	system(pausarConsola.c_str());
}

void exponencial()
{
    system(limpiarConsola.c_str());
    int n;
    double media, numero;
    vector<double> resultados;
    cout<<"Ingrese la media de la distribucion: ";
    cin>>media;
    cout<<"Ingrese el numero de numeros a incluir en la distribucion: ";
    cin>>n;
    for(int i=0; i<n; i++)
    {
        randomsUsed.push_back(randomNumber());
        numero = -media * log(randomsUsed.at(i));
        resultados.push_back(numero);
    }
    archivo(resultados);
}

template <typename T>
void archivo(const vector<T>& numeros)
{
	ofstream archivo("Distribucion.csv");
	if(archivo.fail())
	{
		cout<<"Error al abrir Distribucion.csv"<<endl;
		exit(0);
	}
    archivo<<"Indice;X;Numero"<<endl;
	for(size_t i=0; i<numeros.size(); i++)
	{
		archivo<<i+1<<";";
        archivo<<randomsUsed.at(i)<<";";
		archivo<<numeros.at(i)<<";";
        archivo<<endl;
	}
	cout<<"Los numeros generados fueron guardados en Distribucion.csv"<<endl;
	archivo.close();
    randomsUsed.clear();
	system(pausarConsola.c_str());
}

double randomNumber() 
{
    return static_cast<double>(rand()) / RAND_MAX;
}