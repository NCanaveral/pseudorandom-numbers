#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
#include <cmath>
#include <numeric>
#include <cstdint>
#include <set>
#include "../encabezados/Limpieza.h"
using namespace std;

void congruencial_aditivo();
void congruencial_multiplicativo();
void congruencial_mixto();
void tausworthe();
void parte_central();
void archivo(double numeros[], int iniciales, int n);
void cambiar_cifras();

void warningsCongruencial_aditivo(int k, int modulo, int numeros[]);
void warningsCongruencial_multiplicativo(int multi, int modulo, int semilla);
void warningsCongruencial_mixto(int multi, int aditi, int modulo, int semilla);
bool pareceCompleto(int n, int modulo, int repetido);

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
	int k, n, modulo, primerRepetidoEn = -1;
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
		if(listaAleatorios[0] == listaAleatorios[i] && i > 0 && primerRepetidoEn == -1)
		{
			primerRepetidoEn = i;
		}
	}
	if(pareceCompleto(n, modulo, primerRepetidoEn))
	{
		warningsCongruencial_aditivo(k, modulo, numeros);
	}
	archivo(listaAleatorios, 0, n);
}

void congruencial_multiplicativo()
{
	int multi, modulo, n, semilla, primerRepetidoEn = -1;
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
		if(listaAleatorios[0] == listaAleatorios[i] && i > 0 && primerRepetidoEn == -1)
		{
			primerRepetidoEn = i;
		}
	}
	if(pareceCompleto(n, modulo, primerRepetidoEn))
	{
		warningsCongruencial_multiplicativo(multi, modulo, semilla);
	}
	archivo(listaAleatorios, 0, n);
}

void congruencial_mixto()
{
	int multi, aditi, modulo, n, semilla, primerRepetidoEn = -1;
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
		if(listaAleatorios[0] == listaAleatorios[i] && i > 0 && primerRepetidoEn == -1)
		{
			primerRepetidoEn = i;
		}
	}
	if(pareceCompleto(n, modulo, primerRepetidoEn))
	{
		warningsCongruencial_mixto(multi, aditi, modulo, semilla);
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

bool pareceCompleto(int n, int modulo, int repetido)
{
	if(repetido == -1 && n > modulo)
	{
		cout<<"Los numeros generados parecen poseer periodo completo!"<<endl;
		return false;
	}else if(repetido == -1 && n < modulo)
	{
		cout<<"No se puede confirmar ni descartar que la muestra posea periodo completo"<<endl;
		return false;
	}
	else
	{
		if (modulo - 3 <= repetido && modulo + 3 >= repetido) 
		{
			cout<<"Los numeros generados parecen poseer periodo completo!"<<endl;
			return false;
		} 
		else 
		{
			cout<<"Los numeros generados parece que no cumplen periodo completo"<<endl;
			cout<<"Tenemos algunas recomendaciones: "<<endl;
			return true;
		}
	}
}

void warningsCongruencial_mixto(int multi, int aditi, int modulo, int semilla)
{
	/*
	cout << "Revisando los parámetros para el método congruencial mixto:" << endl;
    if (modulo <= 0) {
        cout << "- El valor del módulo (m) debe ser mayor que 0. Considera cambiar el módulo." << endl;
    } else {
        cout << "- El módulo (m) es válido: " << modulo << endl;
    }
    if (gcd(aditi, modulo) != 1) {
        cout << "- La constante aditiva (c) y el módulo (m) no son coprimos. Para garantizar un periodo completo, cambia c a un valor que sea coprimo con " << modulo << "." << endl;
    } else {
        cout << "- La constante aditiva (c) es válida para garantizar un periodo completo." << endl;
    }
    if (modulo % 4 == 0 && (multi - 1) % 4 != 0) {
        cout << "- Como el módulo (m) es divisible por 4, la constante multiplicativa (a) debe cumplir a - 1 divisible por 4. Considera cambiar a a un valor que cumpla esta condición." << endl;
    } else {
        cout << "- La constante multiplicativa (a) es válida para garantizar un periodo completo bajo la condición de divisibilidad." << endl;
    }
    int powerOfTwo = 1;
    while (powerOfTwo < modulo) {
        powerOfTwo *= 2;
    }
    if (powerOfTwo == modulo) {
        if ((multi & (multi - 1)) != 0) {
            cout << "- Como el módulo (m) es potencia de 2, la constante multiplicativa (a) debería ser potencia de 2. Considera cambiar a a una potencia de 2." << endl;
        } else {
            cout << "- La constante multiplicativa (a) es válida como potencia de 2." << endl;
        }
    }
    if (semilla < 0 || semilla >= modulo) {
        cout << "- La semilla (X0) debe estar en el rango [0, m). Considera cambiar la semilla para que esté en este rango." << endl;
    } else {
        cout << "- La semilla (X0) está en un rango válido." << endl;
    }
    cout << "Si sigues estas recomendaciones, puedes mejorar la calidad de los números pseudoaleatorios generados." << endl;
	*/
	cout<<"intentare arreglar esto despues"<<endl;
}

void warningsCongruencial_multiplicativo(int multi, int modulo, int semilla)
{
	/*
	cout << "Revisando los parámetros para el método congruencial multiplicativo:" << endl;
    if (modulo <= 0) {
        cout << "- El valor del módulo (m) debe ser mayor que 0. Considera cambiar el módulo." << endl;
    } else {
        cout << "- El módulo (m) es válido: " << modulo << endl;
    }
    if ((modulo & (modulo - 1)) == 0) {
        if ((multi - 3) % 8 != 0) {
            cout << "- Como el módulo (m) es potencia de 2, la constante multiplicativa (a) debería ser de la forma 3 + 8k. Considera cambiar a a un valor que cumpla esta condición." << endl;
        } else {
            cout << "- La constante multiplicativa (a) es válida para el módulo como potencia de 2." << endl;
        }
    }

    bool isPrime = true;
    if (modulo <= 1) {
        isPrime = false;
    } else {
        for (int i = 2; i * i <= modulo; i++) {
            if (modulo % i == 0) {
                isPrime = false;
                break;
            }
        }
    }
    
    if (isPrime) {
        cout << "- El módulo (m) es primo, considera seleccionar un 'a' que sea un generador primitivo para garantizar un periodo completo." << endl;
    } else {
        cout << "- El módulo (m) no es primo, por lo tanto, no se aplica la recomendación de generador primitivo." << endl;
    }
    if (semilla <= 0 || semilla >= modulo) {
        cout << "- La semilla (X0) debe estar en el rango (0, m). Considera cambiar la semilla para que esté en este rango." << endl;
    } else {
        cout << "- La semilla (X0) está en un rango válido." << endl;
    }
    cout << "Si sigues estas recomendaciones, puedes mejorar la calidad de los números pseudoaleatorios generados." << endl;
	*/
	cout<<"intentare arreglar esto despues"<<endl;
}

void warningsCongruencial_aditivo(int k, int modulo, int numeros[])
{
	/*
	cout << "Revisando los parámetros para el método congruencial aditivo:" << endl;
    if (modulo <= 0) {
        cout << "- El valor del módulo (m) debe ser mayor que 0. Considera cambiar el módulo." << endl;
    } else {
        cout << "- El módulo (m) es válido: " << modulo << endl;
    }
    if (k <= 0) {
        cout << "- El valor de k (número de valores iniciales) debe ser mayor que 0. Considera cambiar k." << endl;
    } else if (k > modulo) {
        cout << "- El valor de k no debe ser mayor que el módulo (m). Considera reducir k." << endl;
    } else {
        cout << "- El valor de k es válido: " << k << endl;
    }
    bool allValid = true;
    for (int i = 0; i < k; i++) {
        if (numeros[i] < 0 || numeros[i] >= modulo) {
            cout << "- El número inicial en la posición " << i << " (" << numeros[i] << ") no está en el rango [0, m). Considera cambiar este valor." << endl;
            allValid = false;
        }
    }
    if (allValid) {
        cout << "- Todos los números iniciales están en un rango válido." << endl;
    }
    set<int> unique_numbers(numeros, numeros + k);
    if (unique_numbers.size() != k) {
        cout << "- Los números iniciales no deben ser iguales entre sí. Considera elegir valores diferentes para evitar ciclos cortos." << endl;
    } else {
        cout << "- Los números iniciales son únicos, lo cual es bueno para evitar ciclos cortos." << endl;
    }

    bool coprime = true;
    for (int i = 0; i < k; i++) {
        if (gcd(numeros[i], modulo) != 1) {
            cout << "- El número inicial en la posición " << i << " (" << numeros[i] << ") no es coprimo con el módulo (m). Esto puede reducir el periodo. Considera cambiar este valor." << endl;
            coprime = false;
        }
    }
    if (coprime) {
        cout << "- Los números iniciales son coprimos con el módulo, lo cual es ideal para garantizar un buen periodo." << endl;
    }
    cout << "Si sigues estas recomendaciones, puedes mejorar la calidad de los números pseudoaleatorios generados." << endl;
	*/
	cout<<"intentare arreglar esto despues"<<endl;
}