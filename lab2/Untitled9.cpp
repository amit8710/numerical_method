// Write a program to implement least square approximation
//  polynomial data.

// INPUT : 4 1 6 2 11 3 18 4 27

#include <iostream>
#include <cmath>

using namespace std;

float B[3][3], C[3];

float determinant(float mat[][3])
{

    // 0 1 2
    // 3 4 5
    // 6 7 8
    float val = mat[0][0] * (mat[1][1] * mat[2][2] - mat[2][1] * mat[1][2]) - mat[0][1] * (mat[1][0] * mat[2][2] - mat[2][0] * mat[1][2]) + mat[0][2] * (mat[1][0] * mat[2][1] - mat[2][0] * mat[1][1]);
    return val;
}

float swap_col(float mat[][3], float c[], int col)
{
    float n[3][3];

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            n[i][j] = mat[i][j];
        }
        // CHANGING THE COLUMN
        n[i][col] = c[i];
    }

    return determinant(n);
}

int main()
{
    // f
    // E y = a n + a2 E xi + a3  E x^2
    // E y xi = a E xi + a2 E xi^ 2 + a3 E xi ^ 3
    // E y xi^2  = a Exi ^ 2 + a2 E xi ^ 3 + a3 E x ^ 4

    // C = (Ey, E y*xi , E y*xi^2)
    // B = (b1, b2, b3)
    // b1 = (n, Exi, Exi^2)
    // b2 = (Exi, Exi^2, Exi^3);
    // b3 = (Exi^2, Exi^3, Exi^4);

    int n;
    cout << "Enter the number of data points: ";
    cin >> n;

    float x[n], y[n];

    // INPUT DATA POINTS X, Y
    for (int i = 0; i < n; i++)
    {
        cin >> x[i] >> y[i];
    }

    // LEAST SQUARE ;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < n; j++)
        {
            float val[] = {1, x[j], x[j] * x[j]};
            C[i] += y[j] * val[i];
            B[i][0] += val[i];
            B[i][1] += x[j] * val[i];
            B[i][2] += x[j] * x[j] * val[i];
        }
    }

    // using cramers rule
    float D, D1, D2, D3;

    D = determinant(B);
    D1 = swap_col(B, C, 0);
    D2 = swap_col(B, C, 1);
    D3 = swap_col(B, C, 2);

    cout << "A: " << D1 / D << "\t";
    cout << "B: " << D2 / D << "\t";
    cout << "C: " << D3 / D << "\n";

    cout << "Y = " << D1 / D << " + " << D2 / D << "x + " << D3 / D << "x^2";

    return 0;
}
