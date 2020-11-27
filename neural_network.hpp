#ifndef NEURAL_NETWORK
#define NEURAL_NETWORK

#include <vector>
#include <random>
#include <fstream>
#include <sstream>
#include <string>
#include <iostream>
#include "activation_function.hpp"

struct Neuron{
	double value,
		   derivativeValue; 
	std::vector<double*> edges; // if edges[i] == nullptr it is not connected.
};


class NeuralNetwork{
	
	private:
		
		std::vector<int> layerSizes; 
		std::vector<ActivationFunction> layerActivations;
		std::vector<Neuron> neuralNetwork; //adjacency list of all neurons.
		bool built = false; //true if built
		
		//functions
		void initializeWeights(Neuron *n, int edges);

		//needs implemented
		void updateWeights(std::vector<double> error);

	public:
		
		//contructor and destructor
		NeuralNetwork(int layers[], int layersCount, ActivationFunction layerActivations[]);
		~NeuralNetwork();

		//main functions for using model. 
		void build(); //puts the network together

		//needs tested.
		std::vector<double> evaluate(std::vector<double> input); // will activate each neuron in the network		
		void train(std::string path, int iterations); //path to csv of training data. will be automagically split into xDim and yDim based on inp and out layer sizes.
		void prune(double variance);

		

		//utility functions
		void debug();

		void enableEdge(int layerPos, int neuronPos, int edgePos);
		void disableEdge(int layerPos, int neuronPos, int edgePos); //sets edge weight to null

		int getOrder(); //returns total number of neurons
		int getSize(); //returns amount of edges
		int getLayerCount(); //returns number of layers including input and output layer

};

double randDouble();


#endif
