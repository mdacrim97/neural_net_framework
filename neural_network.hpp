#ifndef NEURAL_NET_FRAMEWORK
#define NEURAL_NET_FRAMEWORK

#include <vector>
#include <tuple>
#include <cmath>

#define _USE_MATH_DEFINES

using namespace std;

struct Neuron{
	double value;
	double derivValue; 
	vector<double*> pWeights; // if pWeights == nullptr it is not connected.
};

class NeuralNetwork{
	
	private:
	
		//variables 
		vector<int> layerSizeVec; 
		vector<tuple<double (*pActivation)(double), double (*pDerivative)(double)>> 	layerActAndDerVec; //pairs of activation functions and its deritvitve respectively.
		std::vector<Neuron> neuralNetwork; //adjacency list of all neurons.
		
		int size; //number of layers in the network
		bool built; //true if built false otherwise
		
		//functions
		void initializeWeight();
		void activate(); // willl activate each neuron in the 
		void updateWeights();
		
		//utils
		int getNeuronPos(int layerPos, int neuronPos);


	public:
		
		//contructor and destructor
		NeuralNetwork(int layers[], int layersCount, tuple<(*pActivation)(double),(*pDerivative)(double)> actsAndDers[]);
		~NeuralNetwork();

		//main functions for using model. 
		void build(); //puts the network together
		void train(double data[][], int xDim, int yDim);
		void prune();

		//utility functions
		void insertLayer(int size, tuple<(*pActivation)(double),(*pDerivative)(double), int position=NULL); //if null adds to end of network.
		void removeLayer(int position=NULL); //if null removes last layer
		
		void insertNeuron(int layerPos, int neuronPos = NULL); //if null adds to end
		void removeNeuron(int layerPos, int neuronPos = NULL); //if null removes from the end

		void activateEdge(int layerPos, int neuronPos, int edgePos); //sets weight via initWeight()
		void disableEdge(int layerPos, int neuronPos, int edgePos); //sets edge weight to null

}

//Activation functions and their derivatives.
double sigmoid(double input);
double sidmoidDerivative(double input);

double tanh(double input);
double tanhDerivative(double input);

double reLu(double input);
double reLuDerivative(double input);

double leakyReLu(double input);
double leakyReLuDerivative(double input);

double swish(double input);
double swishDerivative(double input);


#endif
