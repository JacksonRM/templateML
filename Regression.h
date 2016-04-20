/*
Regression.h
A file in the templateML library
Author: Jackson Marusarz
*/


#ifndef REGRESSION_H
#define REGRESSION_H

/*
Regression is a model of Model concept
It predicts the average of all outputs 
*/
template<typename TDataCollector>
class Regression
{
  public:
    typedef typename TDataCollector::featureType featureType;
    
    Regression() : prediction(0) {};
    void Train( typename TDataCollector::exampleContainer& Container, unsigned num_features);
    featureType Predict(typename TDataCollector::example e);
  private:
    featureType prediction;
};

template <typename TDataCollector>
void Regression<TDataCollector>::Train( typename TDataCollector::exampleContainer& Container, unsigned num_features)
{
  typename TDataCollector::featureType sum = 0;
  unsigned num_examples = 0;
  for(typename TDataCollector::exampleIterator I = Container.begin(); I != Container.end(); I++)
  {
    num_examples++;
    sum += (*I)[num_features]; 
  }
  prediction = sum/num_examples;

}

template <typename TDataCollector>
typename TDataCollector::featureType Regression<TDataCollector>::Predict(typename TDataCollector::example e)
{
  return prediction;
}


#endif
