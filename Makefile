CC=g++
CFLAGS=

BIN=neural-network

all:	$(BIN)

neuralnetwork.o: neuralnetwork.cpp neuralnetwork.h neuron.h
	$(CC) $(CFLAGS) -o $@ -c $<

$(BIN):	neuralnetwork.o neuron.cpp neuron.h
	$(CC) $(CFLAGS) -o $(BIN) neuron.cpp

run:	$(BIN)
	./$(BIN)

clean:
	@rm -rf $(BIN) *.o
	@echo "Cleaned."