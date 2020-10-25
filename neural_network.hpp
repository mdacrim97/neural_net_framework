#ifndef NEURAL_NETWORK
#define NEURAL_NETWORK

#include <vector>
#include <random>
#include "activation_function.hpp"


using namespace std;


struct Neuron{
	double value,
		   derivativeValue; 
	vector<double*> edges; // if edges[i] == nullptr it is not connected.
};


class NeuralNetwork{
	
	private:
		
		vector<int> layerSizes; 
		vector<ActivationFunction> layerActivations;
		std::vector<Neuron> neuralNetwork; //adjacency list of all neurons.
		bool built = false; //true if built
		
		//functions
		void initializeWeights(Neuron *n, int edges);

		//needs implemented 
		void activate(std::vector<double> input); // will activate each neuron in the network

		void updateWeights();

		//needs implemented
		int getPosition(int layerPos, int neuronPos = -1, int edgePos = -1); //if null gets the first neuron of the layer.

	public:
		
		//contructor and destructor
		NeuralNetwork(int layers[], int layersCount, ActivationFunction layerActivations[]);
		~NeuralNetwork();

		//main functions for using model. 
		void build(); //puts the network together

		//need implemented train and prune
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
