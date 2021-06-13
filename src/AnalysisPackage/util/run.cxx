#include <iostream>
#include <memory>
#include "AnalysisPackage/TestClass.h"
#include "AnalysisPackage/ISomeCPTool.h"
#include "AnalysisPackage/SomeCPTool.h"
#include "xAODEgamma/ElectronContainer.h"
#include "xAODEgamma/Electron.h"
#include <xAODCore/AuxContainerBase.h>
#include <AsgTools/ToolHandle.h>
#include <AsgTools/AnaToolHandle.h>
#include "PATInterfaces/CorrectionCode.h"
#include "EgammaAnalysisInterfaces/IEgammaCalibrationAndSmearingTool.h"

int main(){
    std::cout << "hello" << std::endl;
    auto getc = TestClass().test_create_container();

    for(auto x : getc){
        std::cout << x << " ,";
    }
    std::cout << "\n";


    auto electrons = std::make_unique<xAOD::ElectronContainer>();
    auto ele_aux = std::make_unique<xAOD::AuxContainerBase>();
    electrons->setStore (ele_aux.get());
    electrons->push_back(new xAOD::Electron());
    electrons->at(0)->setPt(3.141);


    std::cout << "before: " << electrons->at(0)->pt() << std::endl;

    CP::SomeCPTool t("tool");
    t.applyCorrection(*(electrons->at(0)));

    std::cout << "after: " << electrons->at(0)->pt() << std::endl;

    std::cout << "bye" << std::endl;
    return 0;
}