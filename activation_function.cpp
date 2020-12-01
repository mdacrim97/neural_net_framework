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

	if(function == "sigmoid"){
		this->function.oneArg = sigmoid;
		this->derivative.oneArg = sigmoidDerivative;
		this->paramCount = 1;
	}
	else if(function == "linear"){
		this->function.twoArg = linear;
		this->derivative.twoArg = linearDerivative;
		this->paramCount = 2;
		std::cout << "in linear if" << std::endl;
	}
	else if(function == "elu"){
		this->function.twoArg = elu;
		this->derivative.twoArg = eluDerivative;
		this->paramCount = 2;
	}
	else if(function == "reLu"){
		this->function.oneArg = reLu;
		this->derivative.oneArg = reLuDerivative;	
		this->paramCount = 1;	
	}
	else if(function == "leaky_relu"){
		this->function.twoArg = leakyReLu;
		this->derivative.twoArg = leakyReLuDerivative;	
		this->paramCount = 2;
	}
	else if(function == "tanh"){
		this->function.oneArg = tanh;
		this->derivative.oneArg = tanhDerivative;
		this->paramCount = 1;
	}
	else if(function == "swish"){
		this->function.oneArg = swish;
		this->derivative.oneArg = swishDerivative;
		this->paramCount = 1;	
	}
	else{
		  //need to throw custom exception here
		std::cout << "shit fucked" << std::endl;
	}

	this->name = function;
	this->alpha = alpha;

}

std::string ActivationFunction::getName(){
	return this->name;
}

int ActivationFunction::getParamCount(){
	return this->paramCount;
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
