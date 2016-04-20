#include "templateML.h"
#include "RandomCollector.h"
#include "RandomCollectorClassifier.h"
#include "FileCollector.h"
#include "LanguageCollector.h"
#include <iostream>

int main(){
  
  //Test Random Collector
  std::cout<<std::endl;
  std::cout<<std::endl;
  std::cout<<"Testing RandomCollector..."<<std::endl;
  RandomCollector r(5,4); //5 examples with 4 features each
  RandomCollector::exampleContainer rC;
  int rCount = r.getData(rC); //build the data
  double aVec[4];
  
  std::cout << "Data created by RandomCollector: "<<std::endl;
  for(RandomCollector::exampleIterator I = rC.begin(); I != rC.end(); I++){
    std::cout<<"Feature Values: ";
    for(int i = 0; i < rCount; i++)
    {
      std::cout<<(*I)[i]<<" ";
      aVec[i] = (*I)[i];
    }
    std::cout<<" Output: "<<(*I)[rCount]<<std::endl;
  }
  //Basic kernel test
  LinearKernel k;
  std::cout<<"linear kernel on (last example)X(last example): "<<k.eval(aVec,aVec,4)<<std::endl;
  PolynomialKernel p(2);
  std::cout<<"quadratic kernel on (last example)X(last example): "<<p.eval(aVec,aVec,4)<<std::endl;
  
  Regression<RandomCollector> R;
  R.Train(rC, rCount);
  std::cout<<"Regression prediction: "<<R.Predict(*(rC.begin()))<<std::endl;
  std::cout<<std::endl;
  
  std::cout<<"Testing RandomCollectorClassifier..."<<std::endl;
  RandomCollectorClassifier classifier(5,3); //5 examples with 3 features each
  RandomCollectorClassifier::exampleContainer ClsCont;
  int count2 = classifier.getData(ClsCont);
  std::cout << "Data created by RandomCollectorClassifier: "<<std::endl;
  for(RandomCollectorClassifier::exampleIterator I = ClsCont.begin(); I != ClsCont.end(); I++){
    std::cout<<"Feature Values: ";
    for(int i = 0; i < count2; i++)
    {
      std::cout<<(*I)[i]<<" ";
    }
    std::cout<<" Output: "<<(*I)[count2]<<std::endl;
  }
  
  Classification<RandomCollectorClassifier> Cls;
  Cls.Train(ClsCont, count2);
  std::cout<<"Classification Prediction: "<<Cls.Predict(*(ClsCont.begin()))<<std::endl;
  std::cout<<std::endl; 
  
  //Classification<RandomCollectorClassifier> Cls;
  KNN<RandomCollectorClassifier> KCls(2);
  KCls.Train(ClsCont, count2);
  int i =0;
  for(RandomCollectorClassifier::exampleIterator I = ClsCont.begin(); I != ClsCont.end(); I++)
  {
    std::cout<<"Example "<<i<<" KNN K=2 Prediction: "<<KCls.Predict(*I)<<std::endl;
    i++;
  }

  //Tests for ridge regression, builds but not functional
  //RidgeRegression<RandomCollector> RRR;
  //RRR.Train(rC, rCount);
  //std::cout<<"Predict: "<<KCls.Predict(*(ClsCont.begin()))<<std::endl;

 //Test file collector DataCollector
  FileCollector F("testFile");
  FileCollector::exampleContainer C1;
  int count3 = F.getData(C1);
  
  
  std::cout<<std::endl;
  std::cout<<std::endl;
  std::cout << "Data created by FileCollector (from \"testFile\"): "<<std::endl;
  for(FileCollector::exampleIterator I = C1.begin(); I != C1.end(); I++){
    std::cout<<"Feature Values: ";
    for(int i = 0; i < count3; i++)
    {
      std::cout<<(*I)[i]<<" ";
    }
    std::cout<<" Output: "<<(*I)[count3]<<std::endl;
  }
  
  Regression<FileCollector> Reg1;
  Reg1.Train(C1, count3);
  std::cout<<"Regression prediction: "<<Reg1.Predict(*(C1.begin()))<<std::endl;
  std::cout<<std::endl;

  //Test LanguageCollector to determine stats of source code
  LanguageCollector L("./");//current directory
  LanguageCollector::exampleContainer LC;
  int LCcount = L.getData(LC);
  KNN<LanguageCollector> KLC(2);
  KLC.Train(LC, LCcount);
  std::cout<<std::endl;
  
  
  std::cout << "Data created by LanguageCollector (from current directory) and Predictions: "<<std::endl;
  int correct = 0;
  std::cout<<"Feature Values   ;  {  [  <  :  ("<<std::endl;
  for(FileCollector::exampleIterator I = LC.begin(); I != LC.end(); I++){
    std::cout<<"Feature Values: ";
    for(int i = 0; i < LCcount; i++)
    {
      std::cout<<(*I)[i]<<" ";
    }
    std::cout<<" Output: "<<(*I)[LCcount]<<"  Predicted: "<<KLC.Predict(*I)<<std::endl;
    if((*I)[LCcount]==KLC.Predict(*I))
      correct++;
  }
  std::cout<<std::endl;
  std::cout <<"Accuracy of KNN N=2 Predictions: "<<(double)correct/LC.size()<<std::endl;
  std::cout<<std::endl;
  std::cout<<std::endl;
  return 0;
}
