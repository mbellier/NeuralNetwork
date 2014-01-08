CC=g++
CFLAGS=

BIN=neural-network

all:	$(BIN)

$(BIN):	neuron.cpp neuron.h
	$(CC) $(CFLAGS) -o $(BIN) neuron.cpp

run:	$(BIN)
	./$(BIN)