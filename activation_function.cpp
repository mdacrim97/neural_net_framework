#include "activation_function.hpp"

ActivationFunction::ActivationFunction((*pActivation)(double), (*pActivationDerivative)(double));
ActivationFunction::ActivationFunction(string function)

double ActivationFunction::sigmoid(double input){

}
double ActivationFunction::sidmoidDerivative(double input){

}

double ActivationFunction::tanh(double input){

}
double ActivationFunction::tanhDerivative(double input){

}

double ActivationFunction::reLu(double input){

}
double ActivationFunction::reLuDerivative(double input){
}

double ActivationFunction::leakyReLu(double input){

}
double ActivationFunction::leakyReLuDerivative(double input){

}

double swish(double input){

}
double swishDerivative(double input){

}
