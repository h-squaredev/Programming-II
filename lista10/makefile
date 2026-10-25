CC = g++
CFLAGS = -Wall -O2

#Target  principal
PhysicsEngine: Vetor2D.o main.o
	$(CC) $(CFLAGS) Vetor2D.o main.o -o PhysicsEngine

# Regra para o Vetor2D.o
Vetor2D.o: Vetor2D.cpp Vetor2D.h
	$(CC) $(CFLAGS) -c Vetor2D.cpp

# Regra para o main.o
main.o: main.cpp Vetor2D.h
	$(CC) $(CFLAGS) -c main.cpp

#limpeza
clean:
	rm -f *.o PhysicsEngine