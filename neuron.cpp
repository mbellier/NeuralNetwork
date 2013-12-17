#include "neuron.h"
#include <iostream>

Output::Output(Neuron &neuron, float weight)
  : neuron(neuron), 
    weight(weight)
{
}

Neuron::Neuron(){
  this->name = "?";
  this->treshold = 0;
  this->delta=0;
  this->potential=0;
}

void Neuron::init(std::string name, float treshold){
  setName(name);
  setTreshold(treshold);
}

void Neuron::setName(std::string name){
  this->name = name;
}

void Neuron::setTreshold(float treshold){
  this->treshold = treshold;
}

void Neuron::connect(Neuron &neuron, float weight){
  Output *out = new Output(neuron, weight);
  outputs.push_back(out);
}

void Neuron::excitate(float weighted_value){
  this->delta += weighted_value;
}

void Neuron::excitate(float value, float weight){
  excitate(value * weight);
}

void Neuron::activate(){
  for(std::vector< Output* >::iterator out = outputs.begin();
      out != outputs.end();
      ++out) {
    (*out)->neuron.excitate(potential, (*out)->weight);
  }
   std::cout << " [" << name << "] Activation\n";
}

void Neuron::info(){
  std::cout << " [" << name <<"] Potential="<< potential <<", Delta="<< delta <<", Treshold="<< treshold <<"\n";
  
}

int main(){
  class BasicNeuron : public Neuron{
  public:
    void compute(){
      potential += delta;
      delta = 0;
      if (potential > treshold){
	activate();
	potential = 0;
      }	
    }
  };


  BasicNeuron a1, a2, b1, b2;

  a1.init("a1",0.8);
  a2.init("a2",0.7);
  b1.init("b1",0.1);
  b2.init("b2",0.1);

  a1.connect(b1, 1);
  b1.connect(a2, -1);
  a2.connect(b2, 1);
  b2.connect(a1, -1);

  

  for (int i = 0; i < 5; i++){

    a1.excitate(1, .8);
    a2.excitate(1, .2);

    
    a1.info();
    a2.info();
    b1.info();
    b2.info();

    std::cout << "\n";
    
    a1.compute();
    a2.compute();
    b1.compute();
    b2.compute();
  }

 a1.info();
 a2.info();

  
  return 0;
}
