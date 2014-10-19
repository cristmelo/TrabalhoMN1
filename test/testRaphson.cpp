#include "../lib/imports.h"

int main(){
    cout<<setprecision(10);
    double erro1 = pow(10,-7);
    NewtonRaphson* zeroPeloNewton = new NewtonRaphson(3.0,0.0,erro1,erro1);
    zeroPeloNewton->loop();
    zeroPeloNewton->show();

    cout<<endl<<endl;
    zeroPeloNewton->loop();
    zeroPeloNewton->show();
    return 0;
}

