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
		void initializeWeights(Neuron *n);
		void activate(); // will activate each neuron in the network
		void updateWeights();
		int getNeuronPos(int layerPos, int neuronPos = -1); //if null gets the first neuron of the layer.

	public:
		
		//contructor and destructor
		NeuralNetwork(int layers[], int layersCount, ActivationFunction layerActivations[]);
		~NeuralNetwork(){};

		//main functions for using model. 
		void build(); //puts the network together
		void train(std::string path, int xDim, int yDim); //path to csv of training data. will be manuaally split bsaed on xDim and yDim
		void prune();

		//utility functions
		void debug();

		void insertLayer(int size, ActivationFunction activationFunction, int position= -1); //if null adds to end of network.
		void removeLayer(int position=-1); //if null removes last layer
		
		void insertNeuron(int layerPos, int neuronPos = -1); //if null adds to end
		void removeNeuron(int layerPos, int neuronPos = -1); //if null removes from the end

		void activateEdge(int layerPos, int neuronPos, int edgePos); //sets weight via initWeight()
		void disableEdge(int layerPos, int neuronPos, int edgePos); //sets edge weight to null

		int getOrder(); //returns total number of neurons
		int getSize(); //returns amount of edges
		int getLayerCount(); //returns number of layers including input and output layer

};

double randDouble();


#endif
