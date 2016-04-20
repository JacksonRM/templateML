/*
LanguageCollector.h
Author: Jackson Marusarz
*/


#ifndef LANGUAGECOLLECTOR_H
#define LANGUAGECOLLECTOR_H

#include <vector>

//model of dataCollector concept
class LanguageCollector{
  public:
    typedef double featureType;
    typedef int outputType;
    typedef std::vector<featureType> example;
    typedef std::vector<featureType>::iterator featureIterator;
    typedef std::vector< std::vector<featureType> > exampleContainer;
    typedef exampleContainer::iterator exampleIterator;
    int getData( exampleContainer& ec);
    LanguageCollector(char *dirName);
  private:
    int examples, features;
    exampleContainer container;
};




#endif
