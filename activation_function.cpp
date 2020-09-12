#include "activation_function.hpp"

ActivationFunction::ActivationFunction(double (*pActivation)(double), double (*pActivationDerivative)(double), std::string name ){

		
	this->function.oneArg = pActivation;
	this->derivative.oneArg = pActivationDerivative;
	this->paramCount = 1;
	this->name = name;
}

ActivationFunction::ActivationFunction(double (*pActivation)(double, double), double (*pActivationDerivative)(double, double), std::string name, double alpha){
	this->function.twoArg = pActivation;
	this->derivative.twoArg = pActivationDerivative;
	this->alpha = alpha;
	this->paramCount = 2;
	this->name = name;
}

ActivationFunction::ActivationFunction(std::string function, double alpha){

	if(function.compare("sigmoid") == 0){
		this->function.oneArg = sigmoid;
		this->derivative.oneArg = sigmoidDerivative;
		paramCount = 1;
	}
	else if(function.compare("linear") == 0){
		this->function.twoArg = linear;
		this->function.twoArg = linearDerivative;
		paramCount = 2;
	}
	else if(function.compare("elu") == 0){
		this->function.twoArg = elu;
		this->derivative.twoArg = eluDerivative;
		paramCount = 2;
	}
	else if(function.compare("reLu") == 0){
		this->function.oneArg = reLu;
		this->function.oneArg = reLuDerivative;	
		paramCount = 1;	
	}
	else if(function.compare("leaky_reLu") == 0){
		this->function.twoArg = leakyReLu;
		this->derivative.twoArg = leakyReLuDerivative;	
		paramCount = 2;
	}
	else if(function.compare("tanh") == 0){
		this->function.oneArg = tanh;
		this->derivative.oneArg = tanhDerivative;
		paramCount = 1;
	}
	else if(function.compare("swish") == 0){
		this->function.oneArg = swish;
		this->derivative.oneArg = swishDerivative;
		paramCount = 1;	
	}
	else{
		  //need to throw custom exception here
	}

	this->name = function;
	this->alpha = alpha;

}

std::string ActivationFunction::getName(){
	return this->name;
}

double ActivationFunction::callFunction(double x){
	if(this->paramCount == 1)
		return this->function.oneArg(x);
	return this->function.twoArg(x, this->alpha);
}

double ActivationFunction::callDerivative(double x){
	if(this->paramCount == 1)
		return this->derivative.oneArg(x);
	return this->derivative.twoArg(x, this->alpha);
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
