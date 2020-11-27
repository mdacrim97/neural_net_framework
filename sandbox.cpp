//AREA TO TEST IMPLEMENTATIONS

#include <iostream>
#include "neural_network.hpp"
#include "activation_function.hpp"

using namespace std;

double foo(double x){
		return x;
}

double fooPrime(double x){
		return 1;
}

double bar(double x, double alpha=1){
	retunr alpha * x;
}

double barPrime(double x, double alpha=1){
	retunr alpha;
}

int main (int argc, char** argv){

	ActivationFunction foo = activationFunction(foo, fooPrime, "foo", )

	ActivationFunction swish = ActivationFunction("swish");
	ActivationFunction relu = ActivationFunction("leakyReLu", 1.3);

	int layerSizes[7] = {784, 2500, 2000, 1500, 1000, 500, 10};
	ActivationFunction layerFunctions[6] = {swish, swish, swish, swish, swish, relu};

	NeuralNetwork testNetwork = NeuralNetwork(layerSizes, 7, layerFunctions);

	testNetwork.build();
	//testNetwork.debug();
	testNetwork.train("myfile.csv", 3);
	testNetwork.evaluate()

	cout << testNetwork.getOrder() << endl;
	cout << testNetwork.getSize() << endl;
	cout << testNetwork.getLayerCount() << endl;

	return 0;
}
