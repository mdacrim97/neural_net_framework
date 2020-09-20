//AREA TO TEST IMPLEMENTATIONS

#include <iostream>
#include "neural_network.hpp"
#include "activation_function.hpp"

using namespace std;

int main (int argc, char** argv){


	ActivationFunction elu = ActivationFunction("elu");

	ActivationFunction layerFunctions[4] = {elu, elu, elu, elu};
	int layerSizes[5] = {2, 16, 8, 4, 1};
	NeuralNetwork testNetwork = NeuralNetwork(layerSizes, 5, layerFunctions);
	cout << "here" << endl;

	

	return 0;
}
