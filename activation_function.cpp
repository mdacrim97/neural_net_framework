#include "activation_function.hpp"

ActivationFunction::ActivationFunction((*pActivation)(double), (*pActivationDerivative)(double)){

}
ActivationFunction::ActivationFunction(string function){

	if(function = "sigmoid"){
		pFunction = sigmoid;
		pDerivative = sigmoidDerivative;
	}
	else if(function = "linear"){
		pFunction = linear;
		pDerivative = linearDerivative;
	}
	else if(function = "elu"){
		pFunction = elu;
		pDerivative = eluDerivative;
	}
	else if(function = "reLu"){
		pFunction = reLu;
		pDerivative = reLuDerivative;		
	}
	else if(function = "leaky_reLu"){
		pFunction = leakyRelu;
		pDerivative = leakyReluDerivative;	
	}
	else if(function = "tanh"){
		pFunction = tanh;
		pDerivative = tanhDerivative;
	}
	else if(function = "swish"){
		pFunction = swish;
		pDerivative = swishDerivative;	
	}
	else{
		  
	}

	this->name = function;

}

double ActivationFunction::sigmoid(double z){
	return 1/(1 + math.pow(M_E, -z))

}
double ActivationFunction::sigmoidDerivative(double z){
	return sigmoid(z) * 1 (1- sigmoid(z))
}

double ActivationFunction::linear(double z, double alpha=1){
	return alpha * z;
}

double ActivationFunction::linearDerivative(double z, double alpha=1){
	return alpha;
}

double ActivationFunction::elu(double z, double alpha=1){
	
	if(z>0)
		return z;
	else
		return alpha *(math.pow(M_E, z) - 1);
}

double ActivationFunction::eluDerivative(){
	
	if(z >0)
		return 1;
	else 
		return alpha * math.pow(M_E, z);
}

double ActivationFunction::tanh(double z){
	
	double posPow = math.pow(M_E, z),
		   negPow = math.pow(M_E, -z);

	return (posPow - negPow)/(posPow + negPow;/)
}

double ActivationFunction::tanhDerivative(double z){

	return 1 - math.pow(tanh(z), 2)
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

double ActivationFunction::leakyReLu(double z, double alpha=1){

	if( z > 0)
		return z;
	else
		return alpha*z;
}

double ActivationFunction::leakyReLuDerivative(double z, double alpha=1){

	if( z > 0)
		return 1;
	else
		return alpha;
}

double swish(double z){
	return z * sigmoid(z);
}

double swishDerivative(double z){
	result = swish(z)
	return result + sigmoid(z)*(1-result)
}
