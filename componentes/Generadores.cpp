#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
#include <cmath>
using namespace std;

void congruencial_aditivo();
void congruencial_multiplicativo();
void congruencial_mixto();
void lehmer();
void parte_central();
void archivo(double numeros[], int iniciales, int n);
void cambiar_cifras();
int cifras_significativas = 3;

void menuGeneradores()
{
	int opcion;
	do
	{
		system("cls");
		cout<<"GENERADOR DE NUMEROS PSEUDOALEATORIOS"<<endl;
		cout<<"1. Congruencial aditivo"<<endl;
		cout<<"2. Congruencial multiplicativo"<<endl;
		cout<<"3. Congruencial mixto"<<endl;
		cout<<"4. Metodo de lehmer"<<endl;
		cout<<"5. Metodo de la parte central del cuadrado"<<endl;
		cout<<"6. Cambiar numero de cifras significativas (actual: "<<cifras_significativas<<")"<<endl;
		cout<<"0. Salir"<<endl;
		cout<<"Seleccione el metodo a realizar: ";
		cin>>opcion;
		system("cls");
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
				lehmer();
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
    cout<<"Ingrese el numero de numeros iniciales: ";
    cin>>k;
    cout<<"Ingrese la cantidad de numeros a generar: ";
    cin>>n;
    double listaAleatorios[n];
    int numeros[n + k];
    
    for(int i=0; i<k; i++)
    {
		cout<<"Ingrese el numero #"<<(i+1)<<": ";
    	cin>>numeros[i];
	}
	
	cout<<"Ingrese el modulo: ";
	cin>>modulo;
    
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
	int multi, modulo, n;
	double cifras = pow(10, cifras_significativas);
	cout<<"Ingrese la cantidad de numeros a generar: ";
    cin>>n;
    double listaAleatorios[n];
    int numeros[n+1];
    cout<<"Ingrese la constante multiplicativa: ";
    cin>>multi;
    cout<<"Ingrese la semilla: ";
    cin>>numeros[0];
    cout<<"Ingrese el modulo: ";
    cin>>modulo;
    
    for(int i=0; i<n; i++)
    {
    	numeros[i+1] = (numeros[i] * multi) % modulo;
    	listaAleatorios[i] = round(((double) numeros[i+1] / (modulo-1)) * cifras) / cifras;
		cout<<"Numero #"<<i+1<<" generado: "<<listaAleatorios[i]<<endl;
	}
}

void congruencial_mixto()
{
	int multi, aditi, modulo, n;
	double cifras = pow(10, cifras_significativas);
	cout<<"Ingrese la cantidad de numeros a generar: ";
    cin>>n;
    double listaAleatorios[n];
    int numeros[n+1];
    cout<<"Ingrese la constante multiplicativa: ";
    cin>>multi;
    cout<<"Ingrese la constante aditiva: ";
    cin>>aditi;
    cout<<"Ingrese la semilla: ";
    cin>>numeros[0];
    cout<<"Ingrese el modulo: ";
    cin>>modulo;
    
    for(int i=0; i<n; i++)
    {
    	numeros[i+1] = ((numeros[i] * multi) + aditi) % modulo;
    	listaAleatorios[i] = round(((double) numeros[i+1] / modulo) * cifras) / cifras;
		cout<<"Numero #"<<i+1<<" generado: "<<listaAleatorios[i]<<endl;
	}
}

void lehmer()
{
	
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
				numero = numero.substr(1, numero.length() - 1);
			}
			else
			{
				numero = numero.substr(0, numero.length() - 2);
			}
			counter++;
		}
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
	if (archivo.fail())
	{
		cout<<"Error al abrir Numeros_Generados.csv"<<endl;
		exit(0);
	}
	archivo<<"Numeros generados: "<<n<<endl;
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
	system("pause");
}

void cambiar_cifras()
{
	cout<<"El numero actual de cifras maxima que cuentan los generadores es de: "<<cifras_significativas<<endl;
	cout<<"Que numero de cifras desea para futuras generaciones?: ";
	cin>>cifras_significativas;
	cout<<"El cambio se realizo correctamente!";
	system("pause");
}

