/*
RidgeRegression.h
A file in the templateML library
Author: Jackson Marusarz
*/

/*NOT FUNCTIONAL YET*/

#ifndef RIDGE_REGRESSION_H
#define RIDGE_REGRESSION_H

#include <vector>
#include <iostream>

/*
RidgeRegression is a model to perform ridge regression

Model of TModel concept
TDataCollector is dataCollector concept
*/
template<typename TDataCollector>
class RidgeRegression
{
  public:
    typedef typename TDataCollector::featureType featureType;
    typedef typename TDataCollector::outputType outputType;
    
    RidgeRegression() : prediction(0) {};
    void Train( typename TDataCollector::exampleContainer& Container, unsigned num_features);
    featureType Predict(typename TDataCollector::example e);

  private:
    //TKernel kernel;
    outputType prediction;
    unsigned my_num_features;
    unsigned my_num_examples;

};

template <typename TDataCollector>
void RidgeRegression<TDataCollector>::Train( typename TDataCollector::exampleContainer& Container, unsigned num_features)
{
  std::vector<std::vector<featureType> > XMatrix;
  std::vector<std::vector<featureType> > XMatrixTrans;
  std::vector<std::vector<featureType> > XMatrixMult;
  std::vector<std::vector<featureType> > IMatrix;
  std::vector<outputType> YMatrix;
  my_num_features = num_features;
  my_num_examples = Container.size();
  double my_lamda = 0.2;
  //Create Matrix
  for(typename TDataCollector::exampleIterator I = Container.begin(); I != Container.end(); I++)
  {
    std::vector<featureType> example;
    for(unsigned i = 0; i<my_num_features; i++)
    {
      std::cout << (*I)[i] << " ";
      example.push_back((*I)[i]);
    }
    std::cout<<std::endl;
    YMatrix.push_back((*I)[my_num_features]);
    XMatrix.push_back(example);
  }
  
  //Create I matrix
  for(unsigned i = 0; i < my_num_features; i++)
  {
    std::vector<featureType> temp;
    for(unsigned j = 0; j < my_num_features; j++)
    {
      if(i==j){
        std::cout<< my_lamda<<" ";
        temp.push_back(my_lamda); 
      }
      else
      {
        std::cout<<"0 ";
        temp.push_back(0); 
      }
    }
    std::cout<<std::endl;
    IMatrix.push_back(temp);
  }
  
  //Create Transpose Matrix
  for(unsigned i = 0; i < my_num_features; i++)
  {
    std::vector<featureType> temp;
    for(unsigned j = 0; j < my_num_examples; j++)
    {
      std::cout<<XMatrix[j][i]<<" ";
      temp.push_back(XMatrix[j][i]); 
    }
    std::cout<<std::endl;
    XMatrixTrans.push_back(temp);
  }
  //Create (Xt * X + lamdaI)
  for(unsigned i = 0; i < XMatrixTrans.size(); i++) 
  { 
    std::vector<featureType> temp;
    for(unsigned j = 0; j < my_num_features; j++) 
    { 
      double temp_sum = 0;
      for(unsigned k = 0; k < XMatrix.size(); k++)
      {
        temp_sum += XMatrixTrans[i][k] * XMatrix[k][j]; 
      }
      if(i==j){
        temp_sum+=my_lamda;
      }
      std::cout<<temp_sum<<" ";
      temp.push_back(temp_sum);
    }
    std::cout<<std::endl;
    XMatrixMult.push_back(temp);
  }
  /*TODO
    Calculate inv(XMatrixTrans*XMatrix+IMatrix)*XMatrixTrans*YMatrix
  */

}

template <typename TDataCollector>
typename TDataCollector::featureType RidgeRegression<TDataCollector>::Predict(typename TDataCollector::example e)
{
  return prediction;
}


#endif
