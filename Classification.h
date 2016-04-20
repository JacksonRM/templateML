/*
Classification.h
A file in the templateML library
Author: Jackson Marusarz
*/

#ifndef CLASSIFICATION_H
#define CLASSIFICATION_H

/*
Classification class is a model of the Model concept. 
It represents a simple naive binary classifier that 
presicts the most common class
*/

template<typename TDataCollector> //TDataCollector is a model of the DataCollector Concept
class Classification
{
  private:
    typedef typename TDataCollector::featureType featureType;
    featureType prediction;
  public:
    void Train( typename TDataCollector::exampleContainer& Container, unsigned num_features);
    featureType Predict(typename TDataCollector::example e);
};

//Save the most common class
template <typename TDataCollector>
void Classification<TDataCollector>::Train( typename TDataCollector::exampleContainer& Container, unsigned num_features)
{
  typename TDataCollector::featureType sum = 0;
  unsigned num_examples = 0;
  for(typename TDataCollector::exampleIterator I = Container.begin(); I != Container.end(); I++)
  {
    num_examples++;
    sum += (*I)[num_features];
  }
  prediction = 0;
  if(sum/num_examples >= 0.5)
    prediction = 1;

}

//Predict the most common class
template <typename TDataCollector>
typename TDataCollector::featureType Classification<TDataCollector>::Predict(typename TDataCollector::example e)
{
  return prediction;
}


#endif

