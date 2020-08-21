#include "neural_network.hpp"

NeuralNetwork::NeuralNetwork(int layers[], int layersCount, tuple<(*pActivation)(double),(*pDerivative)(double)> actsAndDers[]){
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

void NeuralNetwork::insertLayer(int size, tuple<(*pActivation)(double),(*pDerivative)(double), int position=NULL){
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


//Activation functions and their derivatives.
double sigmoid(double input){

}
double sidmoidDerivative(double input){

}

double tanh(double input){

}
double tanhDerivative(double input){

}

double reLu(double input){

}
double reLuDerivative(double input){
}

double leakyReLu(double input){

}
double leakyReLuDerivative(double input){

}

double swish(double input){

}
double swishDerivative(double input){

}



