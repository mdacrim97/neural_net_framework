#ifndef NEURAL_NETWORK
#define NEURAL_NETWORK

#include <vector>
#include "activation_function.hpp"


using namespace std;


struct Neuron{
	double value,
		   derivativeValue; 
	vector<double*> pWeights; // if pWeights == nullptr it is not connected.
};


class NeuralNetwork{
	
	private:
		
		vector<int> layerSizeVec; 
		vector<ActivationFunction> layerActivation;
		std::vector<Neuron> neuralNetwork; //adjacency list of all neurons.
		
		int size; //number of layers in the network
		bool built = false; //true if built
		
		//functions
		void initializeWeight();
		void activate(); // will activate each neuron in the network
		void updateWeights();
		int getNeuronPos(int layerPos, int neuronPos = NULL); //if null gets the first neuron of the layer.

	public:
		
		//contructor and destructor
		NeuralNetwork(int layers[], int layersCount, ActivationFunction layerActivations[]);
		~NeuralNetwork();

		//main functions for using model. 
		void build(); //puts the network together
		void train(double data[][], int xDim, int yDim);
		void prune();

		//utility functions
		void insertLayer(int size, ActivationFunction activationFunction, int position=NULL); //if null adds to end of network.
		void removeLayer(int position=NULL); //if null removes last layer
		
		void insertNeuron(int layerPos, int neuronPos = NULL); //if null adds to end
		void removeNeuron(int layerPos, int neuronPos = NULL); //if null removes from the end

		void activateEdge(int layerPos, int neuronPos, int edgePos); //sets weight via initWeight()
		void disableEdge(int layerPos, int neuronPos, int edgePos); //sets edge weight to null

}


#endif
