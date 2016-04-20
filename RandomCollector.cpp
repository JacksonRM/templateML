/*
RandomCollector.cpp
Author: Jackson Marusarz

The RandomCollector is a model of the DataCollector model in templateML.
It generates random data vectors of type double with output type double 
to be used in machine learning regression algorithms.
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "RandomCollector.h"
#include <iostream>

int RandomCollector::getData( exampleContainer& ec){
  srand ( time(NULL) );
  std::vector<featureType> aData;
  exampleContainer allData;
  for(int i = 0 ; i < examples; i++){
    aData.clear();
    for(int j = 0; j < (features+1); j++){
      double num = ( (double)(rand()%100)/100 );
      aData.push_back( num );
    }
    allData.push_back(aData);
  }
  ec = allData;
  
  return features;
}

