#include "../encabezados/Limpieza.h"
#include <string>
using namespace std;

string limpiarConsola;
string pausarConsola;

void verificarSO() 
{
    #if defined(_WIN32) || defined(_WIN64)
        limpiarConsola = "cls";
        pausarConsola = "pause";
    #elif defined(__linux__) || defined(__APPLE__)
        limpiarConsola = "clear";
        pausarConsola = "read -p 'Presione cualquier tecla para continuar...' var";
    #endif
}