#include "neuron.h"
#include <iostream>

Output::Output(Neuron &neuron, float weight)
  : neuron(neuron), 
    weight(weight)
{
}

Neuron::Neuron(std::string name, float treshold){
  this->delta=0;
  this->potential=0;
  setName(name);
  setTreshold(treshold);
}

void Neuron::setName(std::string name){
  this->name_ = name;
}

void Neuron::setTreshold(float treshold){
  this->treshold = treshold;
}

void Neuron::connect(Neuron *neuron, float weight){
  Output *out = new Output(*neuron, weight);
  outputs.push_back(out);
}

void Neuron::excitate(float weighted_value){
  this->delta += weighted_value;
}

void Neuron::excitate(float value, float weight){
  excitate(value * weight);
}

void Neuron::computePotential(){
  potential += delta;
  delta = 0;
}

void Neuron::activate(){
  for(std::vector< Output* >::iterator out = outputs.begin();
      out != outputs.end();
      ++out) {
    (*out)->neuron.excitate(potential, (*out)->weight);
  }
   std::cout << " [" << name_ << "] Activation\n";
}

void Neuron::info(){
  std::cout << " [" << name_ <<"] Potential="<< potential <<", Delta="<< delta <<", Treshold="<< treshold <<"\n";
  
}

void Neuron::checkActivation(){
  if (potential > treshold){
    activate();
    potential = 0;
  }	
}
std::string Neuron::getName(){
  return name_;
}

