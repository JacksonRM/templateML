/*
Kernels.h
A file in the templateML library
Author: Jackson Marusarz
*/


#ifndef KERNELS_H
#define KERNELS_H

#include <math.h>

//Models of Kernel concept

class LinearKernel {
 typedef double featureType;
 public:
   featureType eval(const featureType *a, const featureType *b, unsigned n_features)
    {
    double dp = 0;
    for (unsigned i=0;i<n_features;i++)
    {
      dp += a[i] * b[i];
    }
    return dp;
    }
};


class PolynomialKernel {
 typedef double featureType;
 private:
   int power;
 public:
   PolynomialKernel() : power(1) {};
   PolynomialKernel(int a) : power(a) {};
   featureType eval(const featureType *a, const featureType *b, unsigned n_features)
    {
    double dp = 0;
    
    for (unsigned i=0;i<n_features;i++)
    {
      dp += a[i] * b[i];
    }
    for(int i=1; i<power;i++){
      dp=dp*dp;
    }

    return dp;
    }
};


class RBFKernel {
  typedef double featureType;
  double sigma;
  public:
    RBFKernel(double d) : sigma(d) {};
    featureType eval(const featureType *a, const featureType *b, unsigned n_features)
    {
      double dis = 0;
      for(unsigned i = 0; i<n_features; i++)
      {
        dis = dis + ((a[i]-b[i]) * (a[i]-b[i]));
      }
      return exp(sigma * dis);

    }

};

#endif


