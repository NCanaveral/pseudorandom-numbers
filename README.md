This is a work in progress, language used is spanish

this software needs a c++ compiler that supports versions +11
for vscode users i included a settings.json because the IDE doesnt allow to create arrays without a specific constant value
the setting.json avoids that problem

to run the program open a terminal and write "make" then "./pseudorandom_numbers"
you dont need to have installed the extension "Makefile tools" developed by microsoft but its useful to edit the makefile file

the default compiler used by the makefile is g++, if you have it the make command i mentioned should run as normal
if you use another compiler you can overwritte the variable used by the makefile, example if you use clang++ you can writte "make CXX=clang++"

the executable and output file will be generated on the root directory of the project 
