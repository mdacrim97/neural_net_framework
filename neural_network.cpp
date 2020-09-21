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
}

//for initializing weights
double randDouble(){
	double random = ((double) rand())/(double)RAND_MAX;
	double range = 1 - (-1); //max - min 
	return random*range + (-1);
}

void NeuralNetwork::initializeWeights(Neuron *n){

	//takes pointer to neuron
	//iterator through each edge and set it to a weight.
}

void NeuralNetwork::activate(){

}

void NeuralNetwork::updateWeights(){

}

void NeuralNetwork::build(){
	/*
	sum neurons count
	add them all to adjaceny list
	for each neuron add all edges to the next layer. 
	initializeWeights on each node.
	
*/
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

