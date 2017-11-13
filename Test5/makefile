.SILENT:
C = g++

Test5:	Test5.o BaseException.o Couleur.o Forme.o InvalidColorException.o Ligne.o Pixel.o Point.o Rectangle.o
	echo Test5
	$(C) Test5.o BaseException.o Couleur.o Forme.o InvalidColorException.o Ligne.o Pixel.o Point.o Rectangle.o -o Test5

Test5.o:	Test5.cpp
		echo Test5.o
		$(C) -c Test5.cpp

BaseException.o:	BaseException.cpp BaseException.h
			echo BaseException.o
			$(C) -c BaseException.cpp

Couleur.o:	Couleur.cpp Couleur.h
		echo Couleur.o
		$(C) -c Couleur.cpp

Forme.o:	Forme.cpp Forme.h
		echo Forme.o
		$(C) -c Forme.cpp

InvalidColorException.o:	InvalidColorException.cpp InvalidColorException.h
				echo InvalidColorException.o
				$(C) -c InvalidColorException.cpp

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
