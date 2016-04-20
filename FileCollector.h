/*
FileCollector.h
Author: Jackson Marusarz
*/

#ifndef FILECOLLECTOR_H
#define FILECOLLECTOR_H

#include <vector>

//model of dataCollector concept
class FileCollector{
  public:
    typedef double featureType;
    typedef double outputType;
    typedef std::vector<featureType> example;
    typedef std::vector<featureType>::iterator featureIterator;
    typedef std::vector< std::vector<featureType> > exampleContainer;
    typedef exampleContainer::iterator exampleIterator;
    int getData( exampleContainer& ec);
    FileCollector(char *fileName);
  private:
    int examples, features;
    exampleContainer container;
};




#endif
