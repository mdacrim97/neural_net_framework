#include "neural_network.hpp"


NeuralNetwork::NeuralNetwork(int layers[], int layersCount, ActivationFunction layerActivations[]){
	for(int i=0; i < layersCount; i++){
		this->layerSizes.push_back(layers[i]);
		if(i < layersCount-1)
			this->layerActivations.push_back(layerActivations[i]);
	}
}


void NeuralNetwork::debug(){

	//print activation functions 
	std::cout << "ActivationLayers: ";
	for(std::vector<ActivationFunction>::iterator it = layerActivations.begin(); it != layerActivations.end(); it++){
		std::cout << ' '<< it->getName(); 
	}
	std::cout << endl;
	 
	//print layer sizes vec
	std::cout << "layer Sizes: ";
	for(std::vector<int>::iterator it= layerSizes.begin(); it!= layerSizes.end(); it++){
		std:: cout << ' ' << *it;
	}
	std:: cout << endl;

	//print an neurons edges.
	std:: cout << "neuron 0 edge weights: ";
	for(std::vector<double*>::iterator it = neuralNetwork[0].edges.begin(); it != neuralNetwork[0].edges.end(); it++){
		std:: cout << ' ' << **it;
	}
	std:: cout << endl; 
}


//for initializing weights
double randDouble(){

	double random = ((double) rand())/(double)RAND_MAX;
	double range = 1 - (-1); //max - min 
	return random*range + (-1);
}

void NeuralNetwork::initializeWeights(Neuron *n, int edges){
	
	for(int i = 0; i< edges; i++){	
		double *weight = new double;
		*weight = randDouble();
		n->edges.push_back(weight);
	}
}

void NeuralNetwork::build(){

	//each layer
	for(std::vector<int>::iterator it = layerSizes.begin(); it!= layerSizes.end(); it++){

		//calc how many neurons in the next layer for amount of edges needed.
		int neuronEdges = *(next(it));

		//each neuron that layer needs.
		for(int i=0; i < *it; i++){
				
			struct Neuron n;

			//if the layer we are adding neurons to is the output layer dont add edges to them.
			if(next(it) != layerSizes.end())
				initializeWeights(&n, neuronEdges);
			
			neuralNetwork.push_back(n);
		}
	}
}


void NeuralNetwork::activate(){

}


void NeuralNetwork::updateWeights(){

}


void NeuralNetwork::train(std::string path, int xDim, int yDim){
	//code go here
}


void NeuralNetwork::prune(){
	//code go here
}


void NeuralNetwork::insertLayer(int size, ActivationFunction activationFunction, int position){
   	//if null adds to end of network.
} 


void NeuralNetwork::removeLayer(int position){
 	//if null removes last layer
}


void NeuralNetwork::insertNeuron(int layerPos, int neuronPos){
	//if null adds to end
}


void NeuralNetwork::removeNeuron(int layerPos, int neuronPos){

}

void NeuralNetwork::activateEdge(int layerPos, int neuronPos, int edgePos){

}


void NeuralNetwork::disableEdge(int layerPos, int neuronPos, int edgePos){

}


int NeuralNetwork::getOrder(){
	return neuralNetwork.size();
}


int NeuralNetwork::getSize(){

	int size = 0;
	for(std::vector<Neuron>::iterator it = neuralNetwork.begin(); it != neuralNetwork.end(); it++ )
		size += it->edges.size();

	return size;
}


int NeuralNetwork::getLayerCount(){ //returns number of layers including input and output layer
	return layerSizes.size();
}

