/*
RandomCollectorClassifier.h
Author: Jackson Marusarz
*/


#ifndef RANDOMCOLLECTORCLASSIFIER_H
#define RANDOMCOLLECTORCLASSIFIER_H

#include <vector>

//model of dataCollector concept
class RandomCollectorClassifier{
  public:
    typedef double featureType;
    typedef std::vector<featureType> example;
    typedef std::vector<featureType>::iterator featureIterator;
    typedef std::vector< std::vector<featureType> > exampleContainer;
    typedef exampleContainer::iterator exampleIterator;
    //int getData( exampleIterator& ei, exampleContainer& ec);
    int getData( exampleContainer& ec);
    RandomCollectorClassifier(int e, int f) : examples(e), features(f){};
  private:
    int examples, features;
};




#endif
