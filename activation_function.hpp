#ifndef ACTIVATION_FUNCTION
#define ACTIVATION_FUNCTINO

#define _USE_MATH_DEFINES

#include <cmath>
#include <string>


using namespace std;


class ActivationFunction{

	private:
		double (*pFunction)(double),
			   (*pDerivative)(double);	


		//provided activation functions
		double sigmoid(double input);
		double sidmoidDerivative(double input);

		double tanh(double input);
		double tanhDerivative(double input);

		double reLu(double input);
		double reLuDerivative(double input);

		double leakyReLu(double input);
		double leakyReLuDerivative(double input);

		double swish(double input);
		double swishDerivative(double input);
		

	public:

		ActivationFunction((*pActivation)(double), (*pActivationDerivative)(double));
		ActivationFunction(string functionName)
}

#endif
