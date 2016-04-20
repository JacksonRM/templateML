/*
RandomCollectorClassifier.cpp
Author: Jackson Marusarz

The RandomCollectorClassifier is a model of the DataCollector model in templateML.
It generates random data vectors of type double with binary class outputs of
1 or 0 to be used in machine learning classification algorithms.
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "RandomCollectorClassifier.h"
#include <iostream>

//getData function
int RandomCollectorClassifier::getData( exampleContainer& ec){
  srand ( time(NULL) );
  std::vector<featureType> aData;
  exampleContainer allData;
  for(int i = 0 ; i < examples; i++){
    aData.clear();
    for(int j = 0; j < features; j++){
      double num = ( (double)(rand()%100)/100 );
      aData.push_back( num );
    }
    double num = ( (double)(rand()%100)/100 );
    if(num>0.5)
      aData.push_back(1);
    else
      aData.push_back(0);

    allData.push_back(aData);
  }
  ec = allData;
  return features;
}

