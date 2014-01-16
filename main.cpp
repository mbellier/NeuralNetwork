#include "neuralnetwork.h"

#include <iostream>



int graph1(void){
// 4 neurones dont 2 inhibiteurs

    NeuralNetwork n;

    n.add(new Neuron("a1",0.8));
    n.add(new Neuron("a2",0.6));

    n.add(new Neuron("inhib1",0.1));
    n.add(new Neuron("inhib2",0.1));

    n["a1"]->connect(n["inhib1"],  1);
    n["a2"]->connect(n["inhib2"],  1);
    n["inhib2"]->connect(n["a1"], -.2);
    n["inhib1"]->connect(n["a2"], -.25);

    /*
    n.add(new Neuron("inhib", .1));
    n["a1"]->connect(n["inhib"],  1);
    n["a2"]->connect(n["inhib"],  1);
    n["inhib"]->connect(n["a1"], -.3);
    n["inhib"]->connect(n["a2"], -.2);
*/

    std::cout << "\033[01;34m * * * Initial Position * * *\033[01;00m\n";
    n.info();

    for (int i = 0; i < 20; i++){

        /*
        n["a1"]->excitate(1);
        n["a2"]->excitate(1);
*/

        if ((i / 10) % 2 == 0 ){
            n["a1"]->excitate(1, .8);
            n["a2"]->excitate(1, .2);
        }else{
            n["a1"]->excitate(1, .14);
            n["a2"]->excitate(1, .86);
        }

        std::cout << "\n\033[01;34m * * * Iteration #" << i << " * * *\033[01;0m\n";
        n.simulate(false);
    }

    return 0;
}


int graph2(void){
// 3 neurones dont 1 inhibiteur

    NeuralNetwork n;

    n.add(new Neuron("a1",0.8));
    n.add(new Neuron("a2",0.6));

    n.add(new Neuron("inhib", .1));
    n["a1"]->connect(n["inhib"],  1);
    n["a2"]->connect(n["inhib"],  1);
    n["inhib"]->connect(n["a1"], -.3);
    n["inhib"]->connect(n["a2"], -.2);

    std::cout << "\033[01;34m * * * Initial Position * * *\033[01;00m\n";
    n.info();

    for (int i = 0; i < 20; i++){

        /*
        n["a1"]->excitate(1);
        n["a2"]->excitate(1);
*/

        if ((i / 10) % 2 == 0 ){
            n["a1"]->excitate(1, .8);
            n["a2"]->excitate(1, .2);
        }else{
            n["a1"]->excitate(1, .14);
            n["a2"]->excitate(1, .86);
        }

        std::cout << "\n\033[01;34m * * * Iteration #" << i << " * * *\033[01;0m\n";
        n.simulate(false);
    }

    return 0;
}

int main(void){
    return graph1();
}
