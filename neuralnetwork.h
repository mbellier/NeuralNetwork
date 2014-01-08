#ifndef NEURALNETWORK_H_
#define NEURALNETWORK_H_

#include "neuron.h"
#include <string>
#include <vector>

class NeuralNetwork{
 public:
  ~NeuralNetwork();
  void addNeuron(Neuron *neuron);
  Neuron *get(std::string name);
  void simulate(bool showInfo = false);

 private:
  std::vector< Neuron *> brain;
};

#endif
