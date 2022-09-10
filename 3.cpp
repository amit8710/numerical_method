#include <iostream>
#include <iomanip>

using namespace std;

int itr = 1;

float fx(float val) {
    return (val*val*val - val - 3);
}

float* getPosError(float *error) {
	if(*error < 0) {
	*error = (-1 * (*error) );
	}
	return error;
}

float calculate(float *x_prev, float *fxp, float *xn, float *fxn, float *x_next, float *fx_next, float *error) {
	
	cout << setw(5) << left << itr++ << "\t";
	cout << setw(10) << left << fixed << setprecision(4) << *x_prev;
	cout << setw(10) << left << fixed << setprecision(4) << *fxp;
	cout << setw(10) << left << fixed << setprecision(4) << *xn;
	cout << setw(10) << left << fixed << setprecision(4) << *fxn;
	cout << setw(10) << left << fixed << setprecision(4) << *x_next;
	cout << setw(10) << left << fixed << setprecision(4) << *fx_next;
	cout << setw(10) << left << fixed << setprecision(4) << *error << "\n";
	
	
	if(*error >= 0.005f) {
		*x_prev = *xn;
        *fxp = *fxn;

		*xn = *x_next;
        *fxn = *fx_next;
		
        *x_next = *xn - ((*xn-*x_prev)/(*fxn-*fxp) * *fxn );
        *fx_next = fx(*x_next);

		*error = (*x_next - *xn) / *x_next;
		
		return  calculate(x_prev, fxp, xn, fxn, x_next, fx_next, getPosError(error));
	} else {
		return *x_next;
	}
	
}

int main(){

	float x_prev, fxp, xn, fxn, x_next, fx_next, error;

    cout << "Enter the initial guess for xn-1: ";
	cin >> x_prev;
    
    cout << "Enter the initial guess for xn: ";
	cin >> xn;

    fxp = fx(x_prev);
    fxn = fx(xn);
    x_next = xn - ((xn-x_prev)/(fxn-fxp) * fxn );
    fx_next = fx(x_next);
	error = (x_next - xn) / x_next;

	cout << "Itr" << setw(10) << right << "xn-1" << setw(10) << right << "fxn-1" << setw(10) << right;
    cout << "xn" << setw(10) << right << "fxn" << setw(10) << right << "xn+1" << setw(10) << right;
    cout << "fxn+1" << setw(10) << right << "Error\n";


    float root = calculate(&x_prev, &fxp, &xn, &fxn, &x_next, &fx_next, getPosError(&error));

    cout << "\nThe root is: " << fixed << setprecision(2) << root;

    return 0;
}
