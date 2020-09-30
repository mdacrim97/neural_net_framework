#include "neural_network.hpp"


NeuralNetwork::NeuralNetwork(int layers[], int layersCount, ActivationFunction layerActivations[]){
	for(int i=0; i < layersCount; i++){
		this->layerSizes.push_back(layers[i]);
		if(i < layersCount-1)
			this->layerActivations.push_back(layerActivations[i]);
	}
}

NeuralNetwork::~NeuralNetwork(){

	//for each neuron delete each edge.
	for(std::vector<Neuron>::iterator neuron = neuralNetwork.begin(); neuron!=neuralNetwork.end(); neuron++)
		for(std::vector<double*>::iterator edge = neuron->edges.begin(); edge != neuron->edges.end(); edge++)
			delete *edge;
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
	
	built = true;
}


void NeuralNetwork::enableEdge(int layerPos, int neuronPos, int edgePos){

	if(layerPos >= layerSizes.size() - 1){
		//throw invalid layer exception since there will be no edges to enable in the output layer
	}

	int position = 0;
	for(std::vector<int>::iterator it = layerSizes.begin(); it != layerSizes.begin() + layerPos; it++)
		position += *it;
	position += neuronPos;

	*((neuralNetwork.at(position)).edges.at(edgePos)) = randDouble();

}


void NeuralNetwork::disableEdge(int layerPos, int neuronPos, int edgePos){

	if(layerPos >= layerSizes.size() - 1){
		//throw invalid layer exception since there will be no edges to enable in the output layer
	}

	int position = 0;
	for(std::vector<int>::iterator it = layerSizes.begin(); it != layerSizes.begin() + layerPos; it++)
		position += *it;
	position += neuronPos;

	(neuralNetwork.at(position)).edges.at(edgePos) = nullptr;

}


void NeuralNetwork::activate(std::vector<double> input){

	//sets each input neuron's value
	for(int i = 0; i < *layerSizes.begin(); i++)
		neuralNetwork.at(i).value = input.at(i);

	//now activates network.s
	
}


void NeuralNetwork::updateWeights(){

}


void NeuralNetwork::train(std::string path, int xDim, int yDim){
	
}


void NeuralNetwork::prune(){
	
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

