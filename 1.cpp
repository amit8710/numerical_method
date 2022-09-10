#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

int itr = 1;

float calc(float value) {
    return ( pow(value, 3) - value - 3);
}

void display(float *xl, float *fxl, float *xu, float *fxu, float *xm, float *fxm, float *err){
    
    cout << itr++ << "\t";
    cout << fixed << setprecision(4) << *xl << "\t" << fixed << setprecision(4) << *fxl << "\t";
    cout << fixed << setprecision(4) << *xu << "\t" << fixed << setprecision(4) << *fxu << "\t";
    cout << fixed << setprecision(4) << *xm << "\t" << fixed << setprecision(4) << *fxm << "\t";
    cout << fixed << setprecision(4) << *err << "\n";
}

float halfInterval(float *xl, float *fxl, float *xu, float *fxu, float *xm, float *fxm, float *err) {
    
    display(xl, fxl, xu, fxu, xm, fxm, err);
    
    if(*fxm < 0){
        *xl = *xm;
        *fxl = *fxm;
    } else {
        *xu = *xm;
        *fxu = *fxm;
    }
    
    float oldxm = *xm;
    
    *xm = (*xu + *xl)/2;
    *fxm = calc(*xm);
    *err = abs( (*xm - oldxm) / *xm );
    
    if(*err > 0.005f){
        return halfInterval(xl, fxl, xu, fxu, xm, fxm, err);
    } else {
        display(xl, fxl, xu, fxu, xm, fxm, err);
        return *xm;
    }
    
}

int main() {
    float xl, fxl, xu, fxu, xm, fxm, err;
    
    cout << "Enter the lower initial guess: ";
    cin >> xl;
    
    cout << "Enter the upper initial guess: ";
    cin >> xu;

    fxl = calc(xl);
    fxu = calc(xu);

    if(fxl > 0 || fxu < 0) {
        cout << "Invalid guesses";
        exit(0);
    }

    xm = (xl+xu)/2;
    fxm = calc(xm);
    err = (xu - xl)/xu;
    
    cout << "Itr" << "\t";
    cout << "xl" << "\t" << "fxl" << "\t";
    cout << "xu" << "\t" << "fxu" << "\t";
    cout << "xm" << "\t" << "fxm" << "\t";
    cout << "err" << "\n";

    float root = halfInterval(&xl, &fxl, &xu, &fxu, &xm, &fxm, &err);

    cout << "\nRoot is:" << fixed << setprecision(2) << root;

    return 0;
}
