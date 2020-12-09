#include "neural_network.hpp"


NeuralNetwork::NeuralNetwork(int layers[], int layersCount, ActivationFunction layerActivations[]){
	for(int i=0; i < layersCount; i++){
		this->layerSizes.push_back(layers[i]);
		if(i < layersCount-1)
			this->layerActivations.push_back(layerActivations[i]);
	}
}


NeuralNetwork::~NeuralNetwork(){

	this->validateNetwork();

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
	std::cout << std::endl;
	 
	//print layer sizes vec
	std::cout << "layer Sizes: ";
	for(std::vector<int>::iterator it = layerSizes.begin(); it!= layerSizes.end(); it++){
		std:: cout << ' ' << *it;
	}
	std:: cout << std::endl;

	//print an neurons edges.
	std:: cout << "neuron 0 edge weights: ";
	for(std::vector<double*>::iterator it = neuralNetwork[0].edges.begin(); it != neuralNetwork[0].edges.end(); it++){
		std:: cout << ' ' << **it;
	}
	std:: cout << std::endl; 
}


int NeuralNetwork::getNeuronPosition(int layerPos, int neuronPos){

	int position = 0;
	for(std::vector<int>::iterator it = layerSizes.begin(); it != layerSizes.begin() + layerPos; it++)
		position += *it;
	position += neuronPos;
	
	return position;
}


void NeuralNetwork::validateNetwork(int layerPos, int neuronPos, int edgePos){

	if(built == false)
		throw NetworkNotBuiltException();

	else if(layerPos > layerSizes.size()-1 || layerPos < 0)
		throw InvalidLayerPositionException();

	else if(neuronPos > layerSizes.at(layerPos)-1 || neuronPos < 0)
		throw InvalidNeuronPositionException();

	int position = this->getNeuronPosition(layerPos, neuronPos);
	if(edgePos > neuralNetwork.at(position).edges.size()-1 || edgePos < 0)
		throw InvalidEdgePositionException();
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

		//how many neurons in the next layer for amount of edges needed.
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


std::vector<double> NeuralNetwork::evaluate(std::vector<double> input){

	this->validateNetwork();

	int curLayer = 0, //which layer we are getting net weights from
		curNeuron = 0, //which neuron we are on in current layer.
		neuronsInLayer = layerSizes.at(0); //how many neurons in the current layer

	

	//place to store net weights for the layer being activated. 
	std::vector<double> finishedNets = input,
						computingNets,
						output;
	computingNets.assign(layerSizes.at(1), 0); 
	
	for(std::vector<Neuron>::iterator neuron = neuralNetwork.begin(); neuron != neuralNetwork.end(); neuron++){
		
		//if setting a input neuron's value dont call any activation function.
		if(curLayer == 0)
			(*neuron).value = finishedNets.at(curNeuron);
		else{

			(*neuron).value = layerActivations.at(curLayer-1).callFunction(finishedNets.at(curNeuron));
			(*neuron).derivativeValue = layerActivations.at(curLayer-1).callDerivative(finishedNets.at(curNeuron));

			if(curLayer == layerSizes.size() - 1 ){
				output.push_back((*neuron).value);
				if(curNeuron == neuronsInLayer-1)
					return output;
			}
		}

		if(curLayer < layerSizes.size() - 1){ //collects net weights up until the next to last layer. because no point doing it for the output layer.
			//for loop for each edge of the current neuron we are on.
			int edgeCount = (*neuron).edges.size();
			for(int i=0; i < edgeCount; i++){
				if((*neuron).edges.at(i) == nullptr) //dont add into net weights if edge is not connected
					continue; 
				else
					computingNets[i] += (*neuron).value *  *(*neuron).edges.at(i);
			}
		}
		
		if(curNeuron  == neuronsInLayer - 1 ){//reached the end of this layer
			curLayer++; //moving on to the next layer
			curNeuron = 0; //reset to the first neuron of that layer
			neuronsInLayer = layerSizes.at(curLayer); //get how many neurons are in this layer
			
			finishedNets = computingNets; //moved the now completely calcualted net weights to its vector and resize the vector for the computing netweights.
			if(curLayer < layerSizes.size() - 1)
				computingNets.assign(layerSizes.at(curLayer+1), 0);
		}
		else
			curNeuron++;
	}
}

void NeuralNetwork::parseData(std::string path, std::vector<std::vector<double>> &xDim, std::vector<std::vector<double>> &yDim){

	std::ifstream file(path);
	while(file){

		std::string line;
	  	if(!getline(file,line)) 
			break;
	
	  	std::istringstream ss(line);
	  	std::vector<double> xVals;
		std::vector<double> yVals;

		int i = 1;
		int xSize = layerSizes.at(0); //get how many values based on how many input neurons.

	  	while(ss){
	    	std::string s;
	    	if(!getline(ss, s, ',')) 
				break;
		
			//put data into either xDim or yDim based on which element of the line working on.
			if(i<= xSize)
	    		xVals.push_back(stod(s));
			else
				yVals.push_back(stod(s));
			i++;
	  	}
		
  		xDim.push_back(xVals);
		yDim.push_back(yVals);
	}

}

void NeuralNetwork::train(std::string path, int iterations){

	this->validateNetwork();		

	//Read in csv into xDim and yDim vectors to hold the training data.
	std::vector<std::vector<double>> xDim;
	std::vector<std::vector<double>> yDim;	

	this->parseData(path, xDim, yDim);
	
	for(int i=0; i< iterations; i++){

		int example = 0;
		std::cout << "Iteration " << i+1 << "/" << iterations << std::endl;
		for(std::vector<std::vector<double>>::iterator input = xDim.begin(); input != xDim.end(); input++){
			
			std::vector<double> output = this->evaluate(*input),
								error;
	
			for(int j=0; j < yDim.at(example).size(); j++)
				error.push_back(yDim.at(example).at(j)- output.at(j));

			this->backProp(error);
			this->updateWeights();
			error.clear();
			example++;
			
		}		
	}
}


void NeuralNetwork::backProp(std::vector<double> error){

	int curLayer = layerSizes.size() - 1, //start on output layer
		curNeuron = layerSizes.at(curLayer)-1, //start at last neuron of output layer
		curEdge,
		deltaPos;
	
	double  delta,
			summation;	

	std::vector<Neuron>::reverse_iterator neuron = neuralNetwork.rbegin();
	for(neuron; neuron != neuralNetwork.rend(); neuron++){
		
		summation = 0;
		
		if(curLayer == layerSizes.size() - 1){
 			(*neuron).delta = (*neuron).derivativeValue * error.at(curNeuron);
		}
		else{
			curEdge = 0; //also is which neuron to go to.
			std::vector<double*>::iterator edge = (*neuron).edges.begin();
			for(edge; edge != (*neuron).edges.end(); edge++){
				
				if(*edge != nullptr){
					deltaPos = getNeuronPosition(curLayer + 1 , curEdge);
					summation += **edge * neuralNetwork.at(deltaPos).delta;
				}
				curEdge++;
			}
			
			(*neuron).delta = (*neuron).derivativeValue * summation;
		}

		if(curNeuron == 0){
			curLayer--;
			curNeuron = layerSizes.at(curLayer) - 1;

			if(curLayer == 0) //done once input layer is hit.
				return;
		}
		else
			curNeuron--;
	}

}


void NeuralNetwork::updateWeights(){

	const double stepSize = 0.01;

	int curLayer = 0, //start at first layer.
		curNeuron = 0,
		neuronsInLayer = layerSizes.at(curLayer),
		curEdge,
		deltaPos;
	
	//for loops for updating every edge's weight
	std::vector<Neuron>::iterator neuron = neuralNetwork.begin();
	for(neuron; neuron != neuralNetwork.end(); neuron++){

		curEdge = 0;
		std::vector<double*>::iterator edge = (*neuron).edges.begin();
		for(edge; edge != (*neuron).edges.end(); edge++){
			if(*edge != nullptr){
				deltaPos = getNeuronPosition(curLayer+1, curEdge);
				double updatedWeight = **edge + (stepSize * (*neuron).value * neuralNetwork.at(deltaPos).delta);
	
				//keeps weight within [-1,1]
				if(updatedWeight > 1)
					**edge = 1;
				else if(updatedWeight < -1)
					**edge = -1;
				else
					**edge = updatedWeight;
			}
			curEdge++;
		}

		if(curNeuron == neuronsInLayer - 1){
			curLayer++;
			curNeuron = 0;
			neuronsInLayer = layerSizes.at(curLayer);

			if(curLayer == layerSizes.size() - 1) //If in the output layer stop.
				return;
		}
		else
			curNeuron++;
	}	
}


void NeuralNetwork::prune(double variance){

	this->validateNetwork();

	if(built == false)
		throw NetworkNotBuiltException();

	for(std::vector<Neuron>::iterator neuron = neuralNetwork.begin(); neuron != neuralNetwork.end(); neuron++)
		for(std::vector<double*>::iterator edge = (*neuron).edges.begin(); edge != (*neuron).edges.end(); edge++)
			if(0.0 - variance < **edge && **edge < 0.0 + variance)
				*edge = nullptr; 
}


void NeuralNetwork::enableEdge(int layerPos, int neuronPos, int edgePos){

	this->validateNetwork(layerPos, neuronPos, edgePos);
	int position = this->getNeuronPosition(layerPos, neuronPos);
	*((neuralNetwork.at(position)).edges.at(edgePos)) = randDouble();
}


void NeuralNetwork::disableEdge(int layerPos, int neuronPos, int edgePos){

	this->validateNetwork(layerPos, neuronPos, edgePos);	
	int position = this->getNeuronPosition(layerPos, neuronPos);
	(neuralNetwork.at(position)).edges.at(edgePos) = nullptr;
}


int NeuralNetwork::getOrder(){

	this->validateNetwork();
	return neuralNetwork.size();
}


int NeuralNetwork::getSize(){

	this->validateNetwork();

	int size = 0;
	for(std::vector<Neuron>::iterator neuron = neuralNetwork.begin(); neuron != neuralNetwork.end(); neuron++ )
		for(std::vector<double*>::iterator edge = (*neuron).edges.begin();edge != (*neuron).edges.end() ; edge++){		
			if(*edge != nullptr)
				size++;
		}
	return size;
}


int NeuralNetwork::getLayerCount(){ //returns number of layers including input and output layer
	
	return layerSizes.size();
}


