#ifndef ACTIVATION_FUNCTION
#define ACTIVATION_FUNCTION

#define _USE_MATH_DEFINES

#include <cmath>
#include <string>


using namespace std;


class ActivationFunction{

	private:
		double (*pFunction)(double),
			   (*pDerivative)(double);	
		
		string name;


		//provided activation functions
		double sigmoid(double z);
		double sigmoidDerivative(double z);

		double linear(double z);
		double linearDerivative(double z);

		double ActivationFunction::elu(double z, double alpha=1){
		double ActivationFunction::eluDerivative(double z, double alpha=1){

		double tanh(double input);
		double tanhDerivative(double z);

		double reLu(double input);
		double reLuDerivative(double z);

		double leakyReLu(double input, double alpha=1);
		double leakyReLuDerivative(double z, double alpha=1);

		double swish(double input);
		double swishDerivative(double z);
		

	public:

		ActivationFunction((*pActivation)(double), (*pActivationDerivative)(double));
		ActivationFunction(string functionName)
}

#endif
