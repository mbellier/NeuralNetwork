CC=g++
CFLAGS=

BIN=neural-network

all:	$(BIN)

neuralnetwork.o: neuralnetwork.cpp neuralnetwork.h neuron.h
	$(CC) $(CFLAGS) -o $@ -c $<

neuron.o:	neuron.cpp neuron.h
	$(CC) $(CFLAGS) -o $@ -c neuron.cpp

$(BIN):	main.cpp neuron.o neuralnetwork.o
	$(CC) $(CFLAGS) -o $(BIN) $^

run:	$(BIN)
	./$(BIN)

clean:
	@rm -rf $(BIN) *.o
	@echo "Cleaned."