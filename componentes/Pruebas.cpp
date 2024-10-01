#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <fstream>
#include <cmath>
#include <math.h>
#include <map>
#include <algorithm>
#include "../encabezados/Limpieza.h"
using namespace std;

void prueba_promedios(vector<double> numeros, int n);
void prueba_frecuencias(vector<double> numeros, int n);
void prueba_distancias(vector<double> numeros, int n);
void prueba_corridas(vector<double> numeros, int n);
void kolgomorov_smirnov(vector<double> numeros, int n);

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
			case 1: prueba_promedios(numeros, n);
				break;
			case 2: prueba_frecuencias(numeros, n);
				break;
			case 3: prueba_distancias(numeros, n);
				break;
			case 4: prueba_corridas(numeros, n);
				break;
			case 5: kolgomorov_smirnov(numeros, n);
				break;
			case 0: break;
			default: cout<<"Opcion Seleccionada es Incorrecta"<<endl;
		}
	}while(opcion != 0);
}


void prueba_promedios(vector<double> numeros, int n)
{
    /*
	double p = 0;
	double Z = 0;

	for (int i = 0; i < n; i++)
	{
		p = p + numeros.at(i);
	}

	p = p / (n - 1);
	Z = ((p - 0.5) * (sqrt((n - 1)))) / (1 / 12);

	if (Z < 1.96)
	{
		cout << "El valor promedio obtenido" << Z << "es menor a 1.96" << endl;
		cout << "por tanto, no se puede rechazar la hipotesis de que los numeros pseudoaleatorios presentados" << endl;
		cout << "provienen de una distribucion uniforme" << endl;
	}
	else
	{
		cout << "El valor promedio obtenido" << Z << "es mayor a 1.96" << endl;
		cout << "por tanto, se puede rechazar la hipotesis de que los numeros pseudoaleatorios presentados" << endl;
		cout << "provienen de una distribucion uniforme" << endl;
	}
    */
    cout<<"Esta funcionalidad no esta implementada, espere otra iteracion"<<endl;
}

void prueba_frecuencias(vector<double> numeros, int n)
{
    /*
	int k;
    cout << "Ingrese el número de intervalos para dividir los datos: ";
    cin >> k;

    double frecuencias[k];
	for(int i=0;i<k;i++)
	{
		frecuencias[i] = 0;
	}

    for (int i = 0; i < n; ++i) 
	{
        int intervalo = min(static_cast<int>(numeros.at(i) * k), k - 1);
        frecuencias[intervalo]++;
    }
    double frecuencia_esperada = static_cast<double>(n) / k;
    double chi_cuadrado = 0.0;
    for (int i = 0; i < k; ++i) 
	{
        chi_cuadrado += pow(frecuencias[i] - frecuencia_esperada, 2) / frecuencia_esperada;
    }
    int grados_libertad = k - 1;
    double chi_cuadrado_critico = grados_libertad + sqrt(2 * grados_libertad);  
    if (chi_cuadrado > chi_cuadrado_critico) 
	{
        cout << "Se rechaza la hipótesis de que los números provienen de una distribución uniforme." <<endl;
    } 
	else 
	{
        cout << "No se puede rechazar la hipótesis de que los números provienen de una distribución uniforme." <<endl;
    }
    */
    cout<<"Esta funcionalidad no esta implementada, espere otra iteracion"<<endl;
}

void prueba_distancias(vector<double> numeros, int n)
{
    /*
	int k, h = 0, cont1 = 0, num_intervals;
    double alpha, beta, H = 0, total = 0;

    cout << "Se necesita primero tener un intervalo para comparar los numeros." <<endl;
	cout << "Por favor, digite los limites de los intervalos a usar." <<endl;
    cout << "Valor de alpha (limite inferior): ";
    cin >> alpha;
    cout << "Valor de beta (limite superior): ";
    cin >> beta;
	cout << "Digite el número de intervalos: ";
    cin >> num_intervals;
    vector<int> cont(num_intervals, 0);
    vector<double> vector1(n, 0);
    vector<double> e(num_intervals, 0); 
    vector<double> EO(num_intervals, 0);

    for (int i = 0; i < n; i++) {
        if (alpha < numeros.at(i) && numeros.at(i) < beta) {
            vector1[i] = 1;
        } else {
            vector1[i] = 0;
        }
    }

    for (int j = 0; j < n; j++) {
        if (vector1[j] == 0) {
            k = j;
            while (k < n && vector1[k] != 1) {
                cont[h]++;
                cont1++;
                k++;
            }
            h++;
        }
    }

    for (int f = 0; f < num_intervals; f++) {
        e[f] = (cont1) * (beta - alpha) * pow((1 - (beta - alpha)), f);
        H += e[f];
        if (e[f] > 0) {
            EO[f] = pow((cont[f] - e[f]), 2) / e[f];
            total += EO[f];
        }
    }

    double chi_cuadrado_critico = 3.841 + 2 * (num_intervals - 1);
    if (total < chi_cuadrado_critico) {
    	cout << "El valor total de las distancias " << total << " es menor a " << chi_cuadrado_critico << "." << endl;
        cout << "Por tanto, no se puede rechazar la hipotesis de que los numeros pseudoaleatorios presentados" << endl;
        cout << "provienen de una distribucion uniforme." << endl;
    } else {
        cout << "El valor total de las distancias " << total << " es mayor a " << chi_cuadrado_critico << "." <<endl;
        cout << "Por tanto, se puede rechazar la hipotesis de que los numeros pseudoaleatorios presentados" <<endl;
        cout << "provienen de una distribucion uniforme." << endl;
    }
    */
    cout<<"Esta funcionalidad no esta implementada, espere otra iteracion"<<endl;
}

void prueba_corridas(vector<double> numeros, int n)
{
    /*
	int totalc = 1;
    double medioaco, varco, Zo;
    int vect1[n];
    for (int i = 0; i < n - 1; i++)
    {
        if (numeros.at(i) <= numeros.at(i))
        {
            vect1[i] = 0;
        }
        else
        {
            vect1[i] = 1;
        }
    }

    for (int j = 1; j < n - 1; j++) 
    {
        if (vect1[j] != vect1[j - 1])
        {
            totalc++;
        }
    }

    medioaco = (2.0 * n - 1) / 3.0;
    varco = (16.0 * n - 29.0) / 90.0;
    Zo = abs((totalc - medioaco) / sqrt(varco));

    cout << "El valor total de las corridas es " << Zo << endl;
    if (Zo < 1.96)
    {
        cout << "El valor es menor a 1.96." << endl;
        cout << "Por tanto, no se puede rechazar la hipótesis de que los números pseudoaleatorios provienen de una distribución uniforme." << endl;
    }
    else
    {
        cout << "El valor es mayor a 1.96." << endl;
        cout << "Por tanto, se puede rechazar la hipótesis de que los números pseudoaleatorios provienen de una distribución uniforme." << endl;
    }
    */
    cout<<"Esta funcionalidad no esta implementada, espere otra iteracion"<<endl;
}

void kolgomorov_smirnov(vector<double> numeros, int n)
{
    /*
    sort(numeros.begin(), numeros.end());
    double Dn = 0.0;
    double fn[n];
    double maxDifferences[n];

    for (int j = 0; j < n; j++)
    {
        fn[j] = (j + 1) / double(n);
    }

    for (int k = 0; k < n; k++)
    {
        double difference = abs(fn[k] - numeros[k]);
        maxDifferences[k] = difference;
        Dn = max(Dn, difference);
    }
    double D_critico = 1.36 / sqrt(n);
    cout << "El valor máximo obtenido Dn es " << Dn << endl;
    if (Dn < D_critico)
    {
        cout << "El valor Dn es menor al valor crítico " << D_critico << endl;
        cout << "Por tanto, no se puede rechazar la hipótesis de que los números pseudoaleatorios provienen de una distribución uniforme." << endl;
    }
    else
    {
        cout << "El valor Dn es mayor al valor crítico " << D_critico << endl;
        cout << "Por tanto, se puede rechazar la hipótesis de que los números pseudoaleatorios provienen de una distribución uniforme." << endl;
    }
    */
   cout<<"Esta funcionalidad no esta implementada, espere otra iteracion"<<endl;
}
