#include "omp.h"
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
using namespace std;

int* sumParallel(int* a, int* b, int n){
    int* result = (int *) malloc(n * sizeof(int));
    #pragma omp parallel
    {
        #pragma omp for
        for(int x = 0; x < n; x++){
            result[x] = a[x] + b[x];
        }
    }

    return result;
}
/* 
   Entrada de exemplo:
    3       -> tamanho do vetor
    1 2 3   -> elementos dos vetores
    1 2 3   -> *********************

   Resultado: 2, 4, 6, 
*/
int main() {

    int * a;
    int * b;
    int n;

    cin >> n;

    a = (int*) malloc(n * sizeof(int));
    for(int x = 0; x < n; x++){
        cin >> a[x];
    }

    b = (int*) malloc(n * sizeof(int));
    for(int x = 0; x < n; x++){
        cin >> b[x];
    }

    int * r = sumParallel(a, b, 3);
    for(int x = 0; x< n; x++){
        printf("%d, ", r[x]);
    }
}
