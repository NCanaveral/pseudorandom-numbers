Esto es un proyecto en progreso.

Este software necesita un compilador de c++ que soporte versiones +11, para usuarios de vscode, incluí un settings.json porque el IDE no permite crear arreglos sin un valor constante específico, el settings.json evita ese problema visual.

Para ejecutar el programa abra una terminal cualquiera y escribe "make" luego "./pseudorandom_numbers", no necesitas tener instalada la extensión "Makefile tools" desarrollada por microsoft pero es útil para editar el archivo makefile.

El compilador predeterminado usado por el makefile es g++, si lo tienes el comando make que mencioné debería correr bien, si usas otro compilador puedes sobreescribir la variable usada por el makefile, ejemplo si usas clang++ puedes escribir "make CXX=clang++".

El ejecutable, los objetos compilados y el archivo de salida .csv serán generados en el directorio raíz del proyecto.

Para eliminar todos los archivos generados por el compilador necesarios para crear el programa escribe el comando "make clean", se puede abrir en cualquier terminal
como powershell o cmd.exe deberia funcionar de la misma forma tanto para compilar y eliminar, este comando elimina todos los objetos, la carpeta en la que estos se guardan
y el ejecutable 

#INFORMACION SOBRE LOS ARCHIVOS

Todos los archivos que se quieran utilizar en el codigo deben cumplir las siguientes condiciones
1. Deben ser formato .csv 

2. No deben existir espacios en blanco entre datos en las filas del archivo, esto afectaria que datos toma el programa
un ejemplo es: 2.2;4.3;1.1;;6; en este caso el programa no importaria el 6

3. No deben existir lineas vacias entre lineas con datos, el programa para cuando no lee datos en una fila 

4. Todos los numeros en caso de ser decimales deben tener un . en lugar de , como lo prefieren los archivos de ese tipo

El archivo Numeros_Generados.csv guarda en cada fila 10 datos, esto no afecta en nada el funcionamiento del algoritmo
ya que no deja espacios en blanco por ni entre filas, esto se hace en aras de facilitar la lectura
si tiene 100 datos en la misma fila dentro del .csv y en la siguiente fila solamente 2 el programa leera todo satisfactoriamente 
independientemente del valor de datos por fila, tambien el nombre del archivo no importa
mientras la ruta absoluta al archivo este escrita correctamente, copeala desde el administrador de archivos
