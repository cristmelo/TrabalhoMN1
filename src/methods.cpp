

#include "../lib/imports.h"


// Constructor method
Methods::Methods( float a, float b, float error, int maxIter ){
	
	this->a = a;
	this->b = b;
	this->error = error;
	this->maxIter = maxIter;

}


//Function
float Methods::Function( float x ){
	
	x = pow(x,2) + 2 * x - 1;

	return x;

}


//////////////////////////////////////////////////////////////////////

//METHODS: The following methods guarantee convergence

//BISECTION

void Methods::Bisection(){

	cout << "\n **BISECTION METHOD: **\n" << endl;

	float a, b; // It will store the values of bound
	float Fa, Fb, Fx; // Values applyed on f(x)
	float x; // Root
	float range; // range where the root is
	int k; // counter
	int ideal_k; // Computes the number of ideal iterations

	a = this->a;
	b = this->b;
	Fa = this->Function(this->a); // Computing f(a)
	Fb = this->Function(this->b); // Computing f(b)

	if( Fa * Fb < 0 ){

		range = fabs( (this->b) - (this->a) ); // Computing range
		k = 0;

		ideal_k = ceil( (log( (this->b) - (this->a) ) - log( error ) ) / log(2) ); //Computing the number of ideal iterations;

		do{

			x = ( a + b )/2;
			Fx = this->Function(x);
			if( Fa * Fx > 0 ){
				a = x;
				Fa = Fx;
			}else{
				b = x;
				Fb = Fx;
			}
			range = range/2;
			k++;

		}while( range > error && k <= maxIter );

	}else{

		cout << "There is no root in this range" << endl;

	}

	
	cout << "The value of the root is " << x << "\n" << endl;
	cout << "Ideal iterations " << ideal_k << "\n" << endl;
	cout << "Total of iterations: " << k << "\n" << endl ;
	cout << "Range value is " << range << endl;

}


//REGULA_FALSI

void Methods::Regula_Falsi(){

	cout << "\n **REGULA FALSI: **\n" << endl;

	float a, b; // It will store the values of bound
	float Fa, Fb, Fx; // Values applyed on f(x)
	float x; // Root
	float range; // range where the root is
	int k; // counter

	a = this->a;
	b = this->b;
	Fa = this->Function(this->a); // Computing f(a)
	Fb = this->Function(this->b); // Computing f(b)

	if( Fa * Fb < 0 ){

		range = fabs( b - a ); // Computing range
		k = 0;

		do{

			x = b - Fb*(b - a)/(Fb - Fa);
			Fx = this->Function(x);
			if( Fa * Fx > 0 ){
				a = x;
				Fa = Fx;
			}else{
				b = x;
				Fb = Fx;
			}
			range = fabs( b - a );
			k++;

		}while( fabs( Fx ) > error && k <= maxIter );

	}else{

		cout << "There is no root in this range" << endl;

	}

	
	cout << "The value of the root is " << x << "\n" << endl;
	cout << "Total of iterations: " << k << "\n" << endl ;
	cout << "Range value is " << range << endl;

}


//////////////////////////////////////////////////////////////////////

// AUXILIARY FUNCTIONS

// Method to print the values of parameters
void Methods::print_values(){
	
	cout << "a = " << this->a << endl;
	cout << "b = " << this->b << endl;
	cout << "error = " << this->error << endl;
	cout << "maxIter = " << this->maxIter << endl;

}
