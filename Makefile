runNetwork: neural_network.o sandbox.o activation_function.o

sandbox.o: sandbox.cpp
	cc -c sandbox.cpp

activation_function.o: activation_function.cpp activation_function.hpp
	cc -c activation_function.cpp

neural_network.o: neural_network.cpp neural_network.hpp
	cc -c neural_network.cpp

