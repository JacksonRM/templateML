/*

LanguageCollector.cpp
Author: Jackson Marusarz

REQUIRES python

The LanguageCollector is a model of the DataCollector model in templateML.
It generates features based on character counts of  ;  {  [  <  :  ( found in files.
It examines all files in the directory passed to the constructor 
and classifies them as C++ if they are of extension .cpp or .h   
All oteher files are classified as not C++
*/



#include "LanguageCollector.h"
#include "FileCollector.h"
#include <fstream>
#include <string>
#include <iostream>

//Constuctor 
LanguageCollector::LanguageCollector(char *dirName)
{
  //Call python script on directory
  std::string s = "./languageAnalyzer.py -d ";
  s.append(dirName);
  s.append(" > .tmpX");
  system(s.c_str());
  FileCollector F(".tmpX");
  features = F.getData(container);
  examples = container.size();
  system("rm .tmpX");
}

int LanguageCollector::getData( exampleContainer& ec)
{
  ec = container;
  return features;
}

