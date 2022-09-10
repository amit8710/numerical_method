#include <iostream>
#include <iomanip>

using namespace std;

int itr = 1;

float gx(float x) {
	return (x*x*x-3);
}

float* getPosError(float *error) {
	if(*error < 0) {
	*error = (-1 * (*error) );
	}
	return error;
}

float calculate(float *xn, float *x_next, float *error) {
	
	cout << setw(5) << left << itr++;
	cout << setw(10) << left << fixed << setprecision(4) << *xn;
	cout << setw(10) << left << fixed << setprecision(4) << *x_next;
	cout << setw(10) << left << fixed << setprecision(4) << *error << "\n";
	
	
	if(*error >= 0.005f) {
		*xn = *x_next;
		*x_next = gx(*xn);
		*error = (*x_next - *xn) / *x_next;
		
		return calculate(xn, x_next, getPosError(error) );
	} else {
		return *x_next;
	}
	
}

int main() {
	
	float xn, x_next, error;
	
	cout << "Enter the initial guess: ";
	cin >> xn;
	
	x_next = gx(xn);
	error = (x_next - xn) / x_next;

	cout << "Itr" << setw(5) << right << "xn" << setw(10) << right;
	cout << "x_next" << setw(10) << right << "error\n";
	
	float root = calculate(&xn, &x_next, getPosError(&error));
	
	cout << "\nThe root is: " << fixed << setprecision(2) << root; root;
	
	
	return 0;
}
