//AREA TO TEST IMPLEMENTATIONS

#include <iostream>
#include "neural_network.hpp"
#include "activation_function.hpp"

using namespace std;


int main (int argc, char** argv){

	ActivationFunction swish = ActivationFunction("swish");
	ActivationFunction elu = ActivationFunction("elu", 1.3);
	ActivationFunction leaky = ActivationFunction("leaky_relu", 1.2);





	//test neural network
	int layerSizes[4] = {2, 4, 2, 1};
	ActivationFunction layerFunctions[3] = {swish, leaky, elu};

	NeuralNetwork testNetwork = NeuralNetwork(layerSizes, 4, layerFunctions);
	testNetwork.build();

	testNetwork.train("myfile.csv", 3);

	vector<double> vec;
	vec.assign(2,1);
	
	vector<double> results = testNetwork.evaluate(vec);
	cout << "results: " << results.at(0) << endl;
	cout << testNetwork.getSize() << endl;

	testNetwork.prune(0.03);

	results = testNetwork.evaluate(vec);
	cout << "results: " << results.at(0) << endl;
	cout << testNetwork.getSize() << endl;

	return 0;
}
