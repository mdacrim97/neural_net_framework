#include "neural_network.hpp"

NeuralNetwork::NeuralNetwork(int layers[], int layersCount, ActivationFunction layerActivations[]){
	
	int i;
	for(i=0; i<layersCount; i++)
		this->layerSizes.push_back(layers[i]);
		if(i < layersCount-1)
			this->layerActivations.push_back(layerActivations[i]);
	
}

void NeuralNetwork::debug(){
	
}


void NeuralNetwork::initializeWeight(){

}

void NeuralNetwork::activate(){

}

void NeuralNetwork::updateWeights(){

}

void NeuralNetwork::build(){
	//code go here
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

