CC = g++
CFLAGS = -Wall -lz
LIBHARU = ./libharu

spiralPDF: spiralPDF.o HaruPDF.o Spiral.o
	$(CC) $(CFLAGS) -o spiralPDF spiralPDF.o Spiral.o HaruPDF.o

spiralPDF.o: spiralPDF.cpp $