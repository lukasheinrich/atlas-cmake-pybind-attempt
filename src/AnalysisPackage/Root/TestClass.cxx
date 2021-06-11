#include "AnalysisPackage/TestClass.h"
#include "xAODEgamma/ElectronContainer.h"
#include "xAODEgamma/Electron.h"
#include <xAODCore/AuxContainerBase.h>
#include <iostream>

TestClass::TestClass(){
    
}

int TestClass::runit(int a, int b){
    return a+b;
}


std::vector<double> TestClass::test_create_container(){
   auto electrons = std::make_unique<xAOD::ElectronContainer>();
   auto ele_aux = std::make_unique<xAOD::AuxContainerBase>();
   electrons->setStore (ele_aux.get());

   std::cout << "ok created container" << std::endl;

   for (int i = 0; i < 10; ++i) {
    std::cout << "ok create ele" << std::endl;
      auto ele = new xAOD::Electron();
      electrons->push_back(ele);
      ele->setPt(i);
      std::cout << "added electron with " << electrons->at(i)->pt() << std::endl;
   }
   std::cout << "preparer output column" << std::endl;
   std::vector<double> r;
   for(auto ele : *electrons){
       r.push_back(ele->pt());
   }
   return r;
}