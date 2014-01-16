#include "neuralnetwork.h"

#include <iostream>

int main(void){

    NeuralNetwork n;

    n.add(new Neuron("a1",0.8));
    n.add(new Neuron("a2",0.7));
    n.add(new Neuron("Inhib1",0.1));
    n.add(new Neuron("Inhib2",0.1));

    n["a1"]->connect(n["Inhib1"],  1);
    n["Inhib1"]->connect(n["a2"], -1);
    n["a2"]->connect(n["Inhib2"],  1);
    n["Inhib2"]->connect(n["a1"], -1);

    n.info();

    for (int i = 0; i < 5; i++){

        n["a1"]->excitate(1, .8);
        n["a2"]->excitate(1, .2);

        std::cout << "\n * * * Iteration #" << i << " * * *\n";
        n.simulate(true);
    }

    return 0;
}
