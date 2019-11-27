CC = g++
CFLAGS = -g
OBJECTS = main.o myMosquitto.o

app : $(OBJECTS)
	$(CC) $(OBJECTS) -o app -lmosquittopp
main.o : main.cpp
	$(CC) $(CFLAGS) -c main.cpp
myMosquitto.o : myMosquitto.cpp
	$(CC) $(CFLAGS) -c myMosquitto.cpp
clean :
	rm -rf *.o app
