#include <iostream>

using namespace std;

/**
 * The equation 3x^3 + 5x^2 - 8x + 2 is to be divided by (x-3). So, the format is: 
 * 3 | 3 5 -8 2 |
 *   |   x  x x |
 *  
 */


int calculation(int *coeffs, int degree, int x, int *quotient) {
    
    int remainder, temp = 0;
    for(int i = 0; i <= degree; i++) {
        
        if(degree == i) {
            remainder = *(coeffs+i) + temp;
        } else {
            *(quotient+i) = *(coeffs+i) + temp;
            temp = x * *(quotient+i);
        }
        
    }

    return remainder;
}

int main() {

    int *coeffs, *quotient, x, deg;

    cout << "Enter the degree of equation: ";
    cin >> deg;

    coeffs = new int[deg+1];
    quotient = new int[deg];

    cout << "Enter the coefficients: ";
    for(int i = 0; i <= deg; i++) {
        cin >> *(coeffs+i);
    }

    cout << "Enter the value of x: ";
    cin >> x;

    
    int remainder = calculation(coeffs, deg, x, quotient);

    cout << "\nQuotients: ";
    for(int i = 0; i < deg; i++) {
        cout << *(quotient+i) << "\t";
    }

    cout << "\nRemainder: " << remainder;

    return 0;
}
