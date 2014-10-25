

#include "../lib/imports.h"


// Constructor method
Methods::Methods( double a, double b, double value_a, double error, int maxIter ){

    this->a = a;
    this->b = b;
    this->value_a = value_a;
    this->error = error;
    this->maxIter = maxIter;
    iterationsNumber = 0;
    allResults = new ListResults();

}


//Function
double Methods::Function( double x ){

    x = cos(x) + (1 - (this->value_a) );

    return x ;

}



//////////////////////////////////////////////////////////////////////

//METHODS: The following methods guarantee convergence

//BISECTION

void Methods::Bisection(){

    cout << "\n **BISECTION METHOD: **\n" << endl;

    double a, b; // It will store the values of bound
    double Fa, Fb, Fx; // Values applyed on f(x)
    double x; // Root
    double range; // range where the root is
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

           //saveIntoList( a, b, Fa, Fb, x, Fx, range );
           // show();

        }while( range > error && k <= maxIter );

    }else{

        cout << "There is no root in this range" << endl;

    }


    /*cout << "The value of the root is " << x << "\n" << endl;
    cout << "Ideal iterations " << ideal_k << "\n" << endl;
    cout << "Total of iterations: " << k << "\n" << endl ;
    cout << "Range value is " << range << endl; */

}


//REGULA_FALSI

void Methods::Regula_Falsi(){

    cout << "\n **REGULA FALSI: **\n" << endl;

    double a, b; // It will store the values of bound
    double Fa, Fb, Fx; // Values applyed on f(x)
    double x; // Root
    double range; //range where the root is
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

            saveIntoList( a, b, Fa, Fb, x, Fx, range );
            //show();

        }while( fabs( Fx ) > error && k <= maxIter );

    }else{

        cout << "There is no root in this range" << endl;

    }


    /*cout << "The value of the root is " << x << "\n" << endl;
    cout << "Total of iterations: " << k << "\n" << endl ;
    cout << "Range value is " << range << endl; */

}



//////////////////////////////////////////////////////////////////////

void Methods::saveIntoList( double a, double b, double Fa, double Fb, double x, double Fx, double range ){

    iterationResults = new double[7];
    iterationResults[0] = x;
    iterationResults[1] = Fx;
    iterationResults[2] = a;
    iterationResults[3] = Fa;
    iterationResults[4] = b;
    iterationResults[5] = Fb;
    iterationResults[6] = range;
    iterationsNumber++;
    allResults->push( iterationResults );

}


// AUXILIARY FUNCTIONS

// Method to print the values of parameters
void Methods::print_values(){

    cout << "a = " << this->a << endl;
    cout << "b = " << this->b << endl;
    cout << "error = " << this->error << endl;
    cout << "maxIter = " << this->maxIter << endl;

}


ListResults Methods::getAllResults(){
    return *this->allResults;
}
