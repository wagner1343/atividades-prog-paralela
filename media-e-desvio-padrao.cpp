#include "omp.h"
#include <cmath>
#include <iostream>
#include "math.h"

using namespace std;

double average(double *vet, int n) {
  double sum = 0;
#pragma pragma omp parallel for reduction(+ : sum)
  {
    for (int x = 0; x < n; x++) {
      sum += vet[x];
    }
  }

  return sum / n;
}

double variance(double * vet, int n){
  double avg = average(vet, n);
  double totalVariance = 0;

#pragma pragma omp parallel for reduction(+: totalVariance)
     {
         for(int x = 0; x < n; x++){
           totalVariance += pow(vet[x] - avg, 2);
         }
     }

     return totalVariance/n;
}

double deviation(double * vet, int n){
    double var = variance(vet, n);
    return sqrt(var);
}

int main() {
    int n;
    double * vet;
    cin >> n;
    vet = (double*) malloc(sizeof(double) * n);
    for(int x = 0; x < n ;x++){
        cin >> vet[x];
    }

    printf("Média: %f\n", average(vet, n));
    printf("variancia: %f\n", variance(vet, n));
    printf("Desvio padrão: %f\n", deviation(vet, n));
}