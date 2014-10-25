/**
file: methods.h
class: Methods
author: Caio Viktor, Cristiano Melo, Francisco Lucas, Geraldo Braz and Matheus Mayron
abstract: this class contains the follow methods: Bissection, Regula_Falsi, Fixed Point Iteration, 
Secant and Newton-Raphson; all these methods will be aplyed in a gived function.
*/

class Methods{

    double a, b; // Range
    double Fa, Fb, Fx;
    double value_a; // Values of a from list
    double error; // Allowed error
    int maxIter; // Maximum amount iterations
    int iterationsNumber;
    double *iterationResults;
    ListResults *allResults;

public:

    // Constructor
    Methods(double a, double b, double value_a, double error, int maxIter);

    // Methods

    void Bisection();
    void Regula_Falsi();

    void saveIntoList( double a, double b, double Fa, double Fb, double x, double Fx, double range );

    // Auxiliary function

    double Function( double x );
    void print_values();
    ListResults getAllResults();



};
