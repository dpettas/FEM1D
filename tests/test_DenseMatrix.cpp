#include <iostream>
#include <iomanip>
#include "LinearAlgebra/DenseMatrix.h"
#include "LinearAlgebra/Matrices.h"



// LAPACK test code

#include <iostream>
#include <vector>


extern "C" void dgetrs_(char *TRANS, int *N, int *NRHS, double *A, int *LDA, int *IPIV, double *B, int *LDB, int *INFO );
extern "C" int dgetrf_(int *m, int *n, double *a, int *lda, int *ipiv, int *info);

using namespace std;

int main()
{
    char trans = 'N';
    int dim = 2;    
    int nrhs = 1;
    int LDA = dim;
    int LDB = dim;
    int info;

    vector<double> a, b;

    a.push_back(1);
    a.push_back(1);
    a.push_back(1);
    a.push_back(-1);

    b.push_back(2);
    b.push_back(0);

    int ipiv[3];

    dgetrf_(&dim, &dim, &*a.begin(), &LDA, ipiv, &info);
    dgetrs_(&trans, &dim, &nrhs, & *a.begin(), &LDA, ipiv, & *b.begin(), &LDB, &info);


    std::cout << "solution is:";    
    std::cout << "[" << b[0] << ", " << b[1] << ", " << "]" << std::endl;
    std::cout << "Info = " << info << std::endl; 

    return(0);
}

