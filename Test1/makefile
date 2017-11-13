.SILENT:
C = g++

Test1:	Test1.o Couleur.o
	echo Test1
	$(C) Test1.o Couleur.o -o Test1

Test1.o:	Test1.cpp
		echo Test1.o
		$(C) -c Test1.cpp

Couleur.o:	Couleur.cpp Couleur.h
		echo Couleur.o
		$(C) -c Couleur.cpp
