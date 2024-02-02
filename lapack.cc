#include <iostream>
#include <lapacke.h>

using namespace std;

int main() {
    // Define the matrix A
    double A[3][2] = {
        {1.0, 2.0},
        {3.0, 4.0},
        {5.0, 6.0}
    };

    // Define the dimensions of the matrix A
    int m = 3; // number of rows
    int n = 2; // number of columns

    // Define variables for LAPACK functions
    double tau[2];



    // Perform QR factorization
    int info;
    info = LAPACKE_dgeqrf(LAPACK_ROW_MAJOR, m, n, *A, n, tau);
    if (info != 0) {
        cout << "QR factorization failed with error code " << info << endl;
        return 1;
    }






    // Print Output
    cout << endl << "Output " << endl;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cout << A[i][j] << "\t";
        }
        cout << endl;
    }

    cout << endl << tau[0] << " " << tau[1] << endl; 

    cout << endl << "R Matrix " << endl;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (i <= j) {
                // printf("%lf ", A[i][j]);
                cout << A[i][j] << "\t";
            } else {
                // printf("0.0 ");
                cout << 0.0 << "\t";
            }
        }
        cout << endl;
    }
    return 0;
}
