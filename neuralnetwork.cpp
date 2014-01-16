#include "neuralnetwork.h"

NeuralNetwork::~NeuralNetwork(){
  if (brain.empty()){
    for(std::vector< Neuron* >::iterator neuron = brain.begin();
	neuron != brain.end(); ++neuron) {
      delete *neuron;
    }
  }
}

void NeuralNetwork::add(Neuron *neuron){
  brain.push_back(neuron);
}

Neuron *NeuralNetwork::get(std::string name){
  for(std::vector< Neuron* >::iterator neuron = brain.begin();
      neuron != brain.end(); ++neuron) {
    if ((*neuron)->getName().compare(name) != 0){
      return *neuron;
    }
  }
  return NULL;
}

void NeuralNetwork::simulate(bool showInfo){
  std::vector< Neuron* >::iterator neuron;
  for(neuron = brain.begin(); neuron != brain.end(); ++neuron) {
    (*neuron)->computePotential();
  }

  for(neuron = brain.begin(); neuron != brain.end(); ++neuron) {
      (*neuron)->checkActivation();
      if (showInfo)
          (*neuron)->info();
  }
}

Neuron *NeuralNetwork::operator [](std::string name){
    return get(name);
}
