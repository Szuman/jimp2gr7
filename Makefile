all:
		gcc -o game io.c main.c simulation.c io.h simulation.h   -std=c99 
		mkdir -p image

.PHONY: clean

clean: 
	-rm -rf image/*.pgm image/*.gif gif/ image/

gif:
	mkdir -p gif
	convert -delay 20 -loop 0 image/*.pgm gif/game.gif
