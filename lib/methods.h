/**
file: methods.h
class: Methods
author: Caio Viktor, Cristiano Melo, Francisco Lucas, Geraldo Braz and Matheus Mayron
abstract: this class contains the follow methods: Bissection, Regula_Falsi, Fixed Point Iteration, 
Secant and Newton-Raphson; all these methods will be aplyed in a gived function.
*/


class Methods{

	float a, b; // Range

	float error; // Allowed error
	
	int maxIter; // Maximum amount iterations

public:	

	// Constructor
	Methods(float a, float b, float error, int maxIter);

	// Methods

	void Bisection();
	void Regula_Falsi();

	// Auxiliary function

	float Function( float x );
	void print_values();
	
	

};