runNetwork: neural_network.o sandbox.o

sandbox.o: sandbox.cpp
	cc -c sandbox.cpp

neural_network.o: neural_network.cpp neural_network.hpp
	cc -c neural_network.cpp

