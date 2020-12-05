#ifndef NEURAL_NETWORK
#define NEURAL_NETWORK

#include <vector>
#include <random>
#include <fstream>
#include <sstream>
#include <string>
#include <iostream>
#include "activation_function.hpp"

struct NetworkNotBuiltException : public std::exception
{
	const char * what () const throw ()
    {
    	return "NetworkNotBuiltException thrown.";
    }
};

struct InvalidLayerPositionException : public std::exception
{
	const char * what () const throw ()
    {
    	return "InvalidLayerPositionException thrown.";
    }
};

struct InvalidNeuronPositionException : public std::exception
{
	const char * what () const throw ()
    {
    	return "InvalidNeuronPositionException thrown.";
    }
};

struct InvalidEdgePositionException : public std::exception
{
	const char * what () const throw ()
    {
    	return "InvalidEdgePositionException thrown.";
    }
};

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
		
		void initializeWeights(Neuron *n, int edges);
		void updateWeights(std::vector<double> error);

		void validateNetwork(int layerPos=0, int neuronPos=0, int edgePos=0);//throws exception if something is not correct.
		int getNeuronPosition(int layerPos, int neuronPos);

	public:
		
		//contructor and destructor
		NeuralNetwork(int layers[], int layersCount, ActivationFunction layerActivations[]);
		~NeuralNetwork();

		//main functions for using model. 
		void build(); //puts the network together
		std::vector<double> evaluate(std::vector<double> input); //will activate each neuron in the network	
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
