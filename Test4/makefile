.SILENT:
C = g++

Test4:	Test4.o Couleur.o Forme.o Ligne.o Pixel.o Point.o Rectangle.o
	echo Test4
	$(C) Test4.o Couleur.o Forme.o Ligne.o Pixel.o Point.o Rectangle.o -o Test4

Test4.o:	Test4.cpp
		echo Test4.o
		$(C) -c Test4.cpp

Couleur.o:	Couleur.cpp Couleur.h
		echo Couleur.o
		$(C) -c Couleur.cpp

Forme.o:	Forme.cpp Forme.h
		echo Forme.o
		$(C) -c Forme.cpp

Ligne.o:	Ligne.cpp Ligne.h
		echo Ligne.o
		$(C) -c Ligne.cpp

Pixel.o:	Pixel.cpp Pixel.h
		echo Pixel.o
		$(C) -c Pixel.cpp

Point.o:	Point.cpp Point.h
		echo Point.o
		$(C) -c Point.cpp

Rectangle.o:	Rectangle.cpp Rectangle.h
		echo Rectangle.o
		$(C) -c Rectangle.cpp
