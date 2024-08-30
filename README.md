Esto es un proyecto en progreso.

Este software necesita un compilador de c++ que soporte versiones +11, para usuarios de vscode, incluí un settings.json porque el IDE no permite crear arreglos sin un valor constante específico, el settings.json evita ese problema visual.

Para ejecutar el programa abra una terminal y escribe "make" luego "./pseudorandom_numbers", no necesitas tener instalada la extensión "Makefile tools" desarrollada por microsoft pero es útil para editar el archivo makefile.

El compilador predeterminado usado por el makefile es g++, si lo tienes el comando make que mencioné debería correr bien, si usas otro compilador puedes sobreescribir la variable usada por el makefile, ejemplo si usas clang++ puedes escribir "make CXX=clang++".

El ejecutable y el archivo de salida .csv serán generados en el directorio raíz del proyecto.
