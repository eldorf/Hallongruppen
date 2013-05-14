all:
	g++ -lwiringPi -lwiringPiDev switchWiringPi.c -o aoff

clean:
	rm aoff
