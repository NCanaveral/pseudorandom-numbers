#include <iostream>
#include <iomanip>
#include <sstream> 
#include <string>
#include <fstream>
#include <vector>
#include <cmath>
#include <filesystem>
#include "../encabezados/Limpieza.h"
#include "../encabezados/Pruebas.h"
using namespace std;

void leer(int n);

void obtenerDatos()
{
    int opcion;
    int pase = 1;
    ifstream existe("Numeros_Generados.csv");
    system(limpiarConsola.c_str());
    cout<<"---NOTA---"<<endl;
    cout<<"Para realizar pruebas estadisticas se necesita un conjunto de datos"<<endl;
    cout<<"ahora, puede utilizar los numeros que genera cualquier generador disponible"<<endl;
    cout<<"en el programa los cuales se guardan en un archivo llamado Numeros_Generados.csv"<<endl;
    cout<<"en la carpeta del proyecto, o importar datos de su computadora"<<endl;
    cout<<"si hay problemas leyendo el archivo, lea REAMME.md para mas informacion"<<endl;
    if(existe.good())
    {
        existe.close();
        do
        {
            cout<<"Se encontro un archivo generado en el proyecto"<<endl;
            cout<<"Desea usar estos datos? (0. No - 1. Si): ";
            cin>>opcion;
            switch(opcion)
            {
                case 1:
                    leer(0);
                    pase=0;
                    break;
                case 0:
                    pase=1;
                    break;
                default: cout<<"Opcion Seleccionada es Incorrecta"<<endl;
            }
        }while(opcion != 0 && opcion != 1);
    }
    else
    {
        cout<<"No se encontro un archivo generado en el proyecto"<<endl;
	}
    if(pase == 1)
    {
        do
        {
            cout<<"Puede volver al menu anterior para acceder a los generadores"<<endl;
            cout<<"y crear datos para hacer pruebas, o importar datos de su computadora"<<endl;
            cout<<"1. Importar datos de mi pc"<<endl;
            cout<<"0. Volver al anterior menu"<<endl;
            cout<<"Seleccione una opcion: ";
            cin>>opcion;
            switch(opcion)
            {
                case 1:
                    leer(1);
                    break;
                case 0: break;
                default: cout<<"Opcion Seleccionada es Incorrecta"<<endl;
            }
        }while(opcion != 0 && opcion != 1);
    }
}

void leer(int n)
{
    ifstream archivo;
    int salir = 0;
    system(limpiarConsola.c_str());
    fflush(stdin);
    if(n == 1)
    {
        string ruta;
        do
        {
            cout << "Por favor, introduzca la ruta del archivo CSV (ejemplo: C:/documents/info.csv): ";
            getline(cin, ruta);
            fflush(stdin);
            archivo.open(ruta);
            if(ruta == "0")
            {
                salir = 1;
                break;
            }
            if (!archivo.is_open()) 
            {
                cout<<"No se pudo abrir el archivo en la ruta proporcionada: "<<ruta<<endl;
                cout<<"Intente nuevamente"<<endl;
                cout<<"Si desea salir del programa ingrese 0 en la opcion"<<endl;
            }
        }while(!archivo.is_open());
    }
    else
    {
        archivo.open("Numeros_Generados.csv");
    }
    int counter=0;
    vector<double> numeros;
    string linea;
    while(getline(archivo, linea))
    {
        fflush(stdin);
        stringstream datos(linea);
        string numero;
        while(getline(datos, numero, ';')) 
        {
            fflush(stdin);
            if(!numero.empty()) 
            {
                counter++;
                cout<<"Numero #"<<counter<<" extraido: "<<numero<<endl;
                numeros.push_back(stod(numero));
            }
        }
    }
    archivo.close();
    if(salir != 1)
    {
        cout<<"Extraccion de datos terminada"<<endl;
        system(pausarConsola.c_str());
        menuPruebas(numeros, counter);
    }
}