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

	NeuralNetwork testNetwork = NeuralNetwork(layerSizes, 4, layerFunctions, "binary_and");
	testNetwork.build();

	vector<double> vec;
	vec.push_back(1);
	vec.push_back(1);

	double result = testNetwork.evaluate(vec);
	cout << "Pre Train Result: " << result << endl;

	
	testNetwork.train("myfile.csv", 50);
	result = testNetwork.evaluate(vec);
	cout << "Post Train Result: " << result << endl;
	
	testNetwork.prune(0.03);
	result = testNetwork.evaluate(vec);
	cout << "Post Prune Result: " << result << endl;
	

	return 0;
}
