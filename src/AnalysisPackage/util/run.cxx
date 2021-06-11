#include <iostream>
#include "AnalysisPackage/TestClass.h"


int main(){
    std::cout << "hello" << std::endl;
    auto getc = TestClass().test_create_container();

    for(auto x : getc){
        std::cout << x << " ,";
    }
    std::cout << "\n";

    std::cout << "bye" << std::endl;
    return 0;
}