#include "neural_network.hpp"

NeuralNetwork::NeuralNetwork(int layers[], int layersCount, ActivationFunction layerActivations[]){
	//code go here
}

void NeuralNetwork::initializeWeight(){

}

void NeuralNetwork::activate(){

}

void NeuralNetwork::updateWeights(){

}

void NeuralNetwork::Build(){
	//code go here
}

void NeuralNetwork::train(double data[][], int xDim, int yDim){
	//code go here
}

void NeuralNetwork::prune(){
	//code go here
}

void NeuralNetwork::insertLayer(int size, ActivationFunction activationFunction, int position=NULL){
   	//if null adds to end of network.
} 
void NeuralNetwork::removeLayer(int position=NULL){
 	//if null removes last layer
}

void NeuralNetwork::insertNeuron(int layerPos, int neuronPos = NULL){
	//if null adds to end
}

void NeuralNetwork::removeNeuron(int layerPos, int neuronPos = NULL){

}

void NeuralNetwork::activateEdge(int layerPos, int neuronPos, int edgePos){

}

void NeuralNetwork::disableEdge(int layerPos, int neuronPos, int edgePos){

}

