#ifndef ACTIVATION_FUNCTION
#define ACTIVATION_FUNCTION

#define _USE_MATH_DEFINES

#include <cmath>
#include <string>
#include <iostream>

class ActivationFunction{

	private:

		int paramCount;
		std::string name;
		double alpha;

		//unions used for whether function being used is 1 or 2 parameters
		union{
			double (*oneArg)(double);
			double (*twoArg)(double, double);
		
		} function;

		union {
			double (*oneArg)(double);
			double (*twoArg)(double, double);

		} derivative;		

		//provided activation functions
		static double sigmoid(double z);
		static double sigmoidDerivative(double z);

		static double linear(double z, double alpha=1);
		static double linearDerivative(double z, double alpha=1);

		static double elu(double z, double alpha=1);
		static double eluDerivative(double z, double alpha=1);

		static double tanh(double z);
		static double tanhDerivative(double z);

		static double reLu(double z);
		static double reLuDerivative(double z);

		static double leakyReLu(double z, double alpha=1);
		static double leakyReLuDerivative(double z, double alpha=1);

		static double swish(double z);
		static double swishDerivative(double z);		

	public:

		ActivationFunction(double (*pActivation)(double), double (*pActivationDerivative)(double), std::string name="Custom");
		ActivationFunction(double (*pActivation)(double, double), double (*pActivationDerivative)(double, double), std::string name="Custom", double alpha=1);
		ActivationFunction(std::string functionName, double alpha=1);
		
		std::string getName();
		double callFunction(double x);
		double callDerivative(double x);

};

#endif
