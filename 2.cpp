#include <iostream>
#include <iomanip>


using namespace std;

int itr = 1;

float fx(float x) {
	return (x*x*x - x - 3);
}

float f_fx(float x) {
	return (3*x*x-1);
}

float getNextX(float xn){
	return ( xn - ( fx(xn) / f_fx(xn) ) );
}

float* getPosError(float *error) {
	if(*error < 0) {
	*error = (-1 * (*error) );
	}
	return error;
}

float calculate(float *xn, float *fxn, float *f_fxn, float *x_next, float *error) {
	
	cout << setw(5) << left << itr++;
	cout << setw(10) << left << fixed << setprecision(4) << *xn;
	cout << setw(10) << left << fixed << setprecision(4) << *fxn;
	cout << setw(10) << left << fixed << setprecision(4) << *f_fxn;
	cout << setw(10) << left << fixed << setprecision(4) << *x_next;
	cout << setw(10) << left << fixed << setprecision(4) << *error << "\n";
	
	
	if(*error >= 0.005f) {
		*xn = *x_next;
		*fxn = fx(*xn);
		*f_fxn = f_fx(*xn);
		*x_next = getNextX(*xn);
		*error = (*x_next - *xn) / *x_next;
		
		return calculate(xn, fxn, f_fxn, x_next, getPosError(error) );
	} else {
		return *xn;
	}
	
}

int main(){
	
	float xn, fxn, f_fxn, x_next, error;
	
	cout << "Enter the initial guess: ";
	cin >> xn;
	
	fxn = fx(xn);
	f_fxn = f_fx(xn);
	x_next = getNextX(xn);
	error = (x_next - xn) / x_next;
	
	cout << "Itr" << setw(5) << right << "xn" << setw(10) << right << "fxn" << setw(10) << right;
	cout << "f_fxn" << setw(10) << right << "x_next" << setw(10) << "error\n";
	
	float root = calculate(&xn, &fxn, &f_fxn, &x_next, getPosError(&error));
	
	cout << "\nThe root is: " << fixed << setprecision(2) << root;
	
	return 0;
	
}
