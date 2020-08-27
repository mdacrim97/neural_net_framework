#include "activation_function.hpp"

ActivationFunction::ActivationFunction(double (*pActivation)(double), double (*pActivationDerivative)(double), std::string name ){

	this->pFunction = pActivation;
	this->pDerivative = pActivationDerivative;
	this->name = name;	
}

ActivationFunction::ActivationFunction(std::string function){

	if(function.compare("sigmoid") == 0){
		pFunction = sigmoid;
		pDerivative = sigmoidDerivative;
	}
	else if(function.compare("linear") == 0){
		//pFunction = linear;
		//pDerivative = linearDerivative;
	}
	else if(function.compare("elu") == 0){
		//pFunction = elu;
		//pDerivative = eluDerivative;
	}
	else if(function.compare("reLu") == 0){
		pFunction = reLu;
		pDerivative = reLuDerivative;		
	}
	else if(function.compare("leaky_reLu") == 0){
		//pFunction = leakyRelu;
		//pDerivative = leakyReluDerivative;	
	}
	else if(function.compare("tanh") == 0){
		pFunction = tanh;
		pDerivative = tanhDerivative;
	}
	else if(function.compare("swish") == 0){
		pFunction = swish;
		pDerivative = swishDerivative;	
	}
	else{
		  //need to throw custom exception here
	}

	this->name = function;

}

std::string ActivationFunction::getName(){
	return this->name;
}
double ActivationFunction::callFunction(double x){
	return this->pFunction(x);
}
double ActivationFunction::callDerivative(double x){
	return this->pDerivative(x);
}


double ActivationFunction::sigmoid(double z){
	return 1/(1 + std::pow(M_E, -z));

}
double ActivationFunction::sigmoidDerivative(double z){
	return sigmoid(z) * (1- sigmoid(z));
}

double ActivationFunction::linear(double z, double alpha){
	return alpha * z;
}

double ActivationFunction::linearDerivative(double z, double alpha){
	return alpha;
}

double ActivationFunction::elu(double z, double alpha){
	
	if(z>0)
		return z;
	else
		return alpha * (std::pow(M_E, z) - 1);
}

double ActivationFunction::eluDerivative(double z, double alpha){
	
	if(z >0)
		return 1;
	else 
		return alpha * std::pow(M_E, z);
}

double ActivationFunction::tanh(double z){
	
	double posPow = std::pow(M_E, z);
	double negPow = std::pow(M_E, -z);

	return (posPow - negPow)/(posPow + negPow);
}

double ActivationFunction::tanhDerivative(double z){

	return 1 - std::pow(tanh(z), 2);
}

double ActivationFunction::reLu(double z){

	if( z > 0)
		return z;
	else
		return 0;
}

double ActivationFunction::reLuDerivative(double z){

	if (z > 0)
		return 1;
	else
		return 0;
}

double ActivationFunction::leakyReLu(double z, double alpha){

	if( z > 0)
		return z;
	else
		return alpha*z;
}

double ActivationFunction::leakyReLuDerivative(double z, double alpha){

	if( z > 0)
		return 1;
	else
		return alpha;
}


double ActivationFunction::swish(double z){
	return z * sigmoid(z);
}

double ActivationFunction::swishDerivative(double z){
	double result = swish(z);
	return result + sigmoid(z)*(1-result);
}
