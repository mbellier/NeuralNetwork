#ifndef NEURALNETWORK_H_
#define NEURALNETWORK_H_

#include "neuron.h"
#include <string>
#include <vector>

class NeuralNetwork{
 public:
  ~NeuralNetwork();
  void add(Neuron *neuron);
  Neuron *get(std::string name);
  void simulate(bool showInfo = false);
  void info();
  Neuron *operator[] (std::string name);
 private:
  std::vector< Neuron *> brain;
};

#endif
