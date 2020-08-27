//AREA TO TEST IMPLEMENTATIONS

#include <iostream>
//#include "neural_network.hpp"
#include "activation_function.hpp"

using namespace std;

double test1(double z){
	return 0.420;
}

double test2(double z)
{
	return 0.666;
}

int main (int argc, char** argv){


	ActivationFunction sigmoid = ActivationFunction("swish");

	return 0;
}
