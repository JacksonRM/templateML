/*
KNN.h
A file in the templateML library
Author: Jackson Marusarz
*/


#ifndef KNN_H
#define KNN_H

#include <map>
#include <math.h>

/*
KNN class is a model of Model concept
It represents a K-Nearest Neighbor classifier
*/
template<typename TDataCollector> //TDataCollector is a DataCollector concept
class KNN
{
  private:
    typedef typename TDataCollector::featureType featureType;
    typename TDataCollector::exampleContainer myContainer;
    int K; //num neighbors
    int my_num_features; //number of features
  public:
    KNN() : K(1) {};
    KNN(int k) : K(k) {}; //Constructor with K as argument
    void Train( typename TDataCollector::exampleContainer& Container, unsigned num_features);
    featureType Predict(typename TDataCollector::example e);
};

template <typename TDataCollector>
void KNN<TDataCollector>::Train( typename TDataCollector::exampleContainer& Container, unsigned num_features)
{
  myContainer = Container;
  my_num_features = num_features;
}

//Calculate the K Nearest Neighbors and take most common class
template <typename TDataCollector>
typename TDataCollector::featureType KNN<TDataCollector>::Predict(typename TDataCollector::example e)
{
  std::map<double, int> neighbors;
  std::map<double, int>::iterator it;
  double dist;
  for(typename TDataCollector::exampleIterator I = myContainer.begin(); I != myContainer.end(); I++)
  {
    dist = 0;
    for(int i = 0; i<my_num_features; i++)
    {
      dist += ((e[i]-(*I)[i]) * (e[i]-(*I)[i]));
    
    }
    dist = sqrt(dist);
    neighbors[dist] = (*I)[my_num_features];
  }
  int prediction = 0;
  int i = 0;
  for(it = neighbors.begin(); i < K; ++it)
  {
    prediction += it->second;  
    i++;
  }

  
  if((prediction/K)>0.5)
    return 1;
  
  return 0;
}


#endif
