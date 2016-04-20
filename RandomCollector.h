/*
RandomCollector.h
Author: Jackson Marusarz
*/


#ifndef RANDOMCOLLECTOR_H
#define RANDOMCOLLECTOR_H

#include <vector>

//model of dataCollector concept
class RandomCollector{
  public:
    typedef double featureType;
    typedef double outputType;
    typedef std::vector<featureType> example;
    typedef std::vector<featureType>::iterator featureIterator;
    typedef std::vector< std::vector<featureType> > exampleContainer;
    typedef exampleContainer::iterator exampleIterator;
    int getData( exampleContainer& ec);
    RandomCollector(int e, int f) : examples(e), features(f){};
  private:
    int examples, features;
};




#endif
