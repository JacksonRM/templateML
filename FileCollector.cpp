/*
FileCollector.cpp
Author: Jackson Marusarz

The FileCollector is a model of the DataCollector model in templateML.
It generates data vectors of type double from an input file specified to 
the constructor.  The data is to be used in machine learning algorithms.

Input File Format
Doubles separated by spaces with NO NEWLINE at end of file
Each row is an example, the last column is the output
To use for classification the last column must be a 1 or 0

3.0 23 .06
0.0 0.3 1.2
1.1 0.3 0.06

*/


#include "FileCollector.h"
#include <fstream>
#include <string>
#include <iostream>

//Constructor requiring a file name
FileCollector::FileCollector(char *fileName)
{
  std::ifstream file;
  file.open(fileName);
  if (!file){
    std::cout << "Error in openening file";
  }
  std::string lineread;
  unsigned cut;
  bool first = true;  //delimiter to only update feature number on 1st example
  int featureCount = 0;
  int exampleCount = 0;
  while(std::getline(file, lineread)) // Read line by line and save in container
  {
    example ex;
    while( (cut = lineread.find_first_of(' ')) != lineread.npos )
    {
      if(cut > 0)
      {
        featureCount++;
        ex.push_back(atof(lineread.substr(0,cut).c_str()));
      }
      lineread = lineread.substr(cut+1);
    }
    if(lineread.length() > 0)
    {
      featureCount++;
      ex.push_back(atof(lineread.c_str()));
    }
    container.push_back(ex);
    exampleCount++;
    if(first)
    {
      first = false;
      features = featureCount-1;
    }
  }
  examples=exampleCount;
}

int FileCollector::getData( exampleContainer& ec)
{
  ec = container;
  return features;
}

