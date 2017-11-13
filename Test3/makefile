.SILENT:
C = g++

Test3:	Test3.o Couleur.o Forme.o Point.o
	echo Test3
	$(C) Test3.o Couleur.o Forme.o Point.o -o Test3

Test3.o:	Test3.cpp
		echo Test3.o
		$(C) -c Test3.cpp

Couleur.o:	Couleur.cpp Couleur.h
		echo Couleur.o
		$(C) -c Couleur.cpp

Forme.o:	Forme.cpp Forme.h
		echo Forme.o
		$(C) -c Forme.cpp
		
Point.o:	Point.cpp Point.h
		echo Point.o
		$(C) -c Point.cpp
