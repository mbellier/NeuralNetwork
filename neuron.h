#ifndef NEURON_H_
#define NEURON_H_

#include <string>
#include <vector>

class Output;

class Neuron{
 public:
  Neuron();
  void init(std::string name, float treshold);
  void setName(std::string name);
  void setTreshold(float treshold);
  void connect(Neuron &neuron, float weight);
  void excitate(float weighted_value);
  void excitate(float value, float weight);
  void process();
  void info();


  virtual void compute() = 0;

  // protected:
  void activate();

  std::string name;
  float treshold;
  float potential;
  float delta;
  std::vector < Output * > outputs;
};

struct Output{
 public:
  Output(Neuron &neuron, float weight);
  Neuron &neuron;
  float weight;
};

#endif
