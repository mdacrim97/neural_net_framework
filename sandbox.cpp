//AREA TO TEST IMPLEMENTATIONS

#include <iostream>
#include "neural_network.hpp"
#include "activation_function.hpp"

using namespace std;

int main (int argc, char** argv){

	ActivationFunction elu = ActivationFunction("elu", 4);
	ActivationFunction sigmoid = ActivationFunction("sigmoid");

	int layerSizes[5] = {2, 16, 8, 4, 1};
	ActivationFunction layerFunctions[4] = {elu, sigmoid, elu, sigmoid};

	NeuralNetwork testNetwork = NeuralNetwork(layerSizes, 5, layerFunctions);

	testNetwork.build();
	//testNetwork.debug();
	testNetwork.train("myfile.csv", 3);

	cout << testNetwork.getOrder() << endl;
	cout << testNetwork.getSize() << endl;
	cout << testNetwork.getLayerCount() << endl;

	return 0;
}
