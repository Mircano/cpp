.SILENT:
C = g++

Test2:	Test2.o Couleur.o Forme.o Point.o
	echo Test2
	$(C) Test2.o Couleur.o Forme.o Point.o -o Test2

Test2.o:	Test2.cpp
		echo Test2.o
		$(C) -c Test2.cpp

Couleur.o:	Couleur.cpp Couleur.h
		echo Couleur.o
		$(C) -c Couleur.cpp

Forme.o:	Forme.cpp Forme.h
		echo Forme.o
		$(C) -c Forme.cpp
		
Point.o:	Point.cpp Point.h
		echo Point.o
		$(C) -c Point.cpp
