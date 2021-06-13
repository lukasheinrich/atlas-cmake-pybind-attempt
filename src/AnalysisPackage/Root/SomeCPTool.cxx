#include "AnalysisPackage/SomeCPTool.h"
#include "PATInterfaces/CorrectionCode.h"
#include "xAODEgamma/Egamma.h"
#include <iostream>

CP::SomeCPTool::SomeCPTool(const std::string& name) : asg::AsgTool(name) {    
    declareProperty("MyIncrement", m_increment = 1.0);
}


StatusCode CP::SomeCPTool::initialize() {
    return StatusCode::SUCCESS;
}

CP::CorrectionCode CP::SomeCPTool::applyCorrection(xAOD::Egamma& e) {
    std::cout << "IINC" << m_increment << std::endl;
    e.setPt(e.pt() + m_increment);
    return CP::CorrectionCode::Ok;
}

CP::SystematicSet CP::SomeCPTool::affectingSystematics() const {
    return SystematicSet();
}

CP::SystematicSet CP::SomeCPTool::recommendedSystematics() const {
    return SystematicSet();
}

StatusCode CP::SomeCPTool::applySystematicVariation(const CP::SystematicSet&) {
    return StatusCode::SUCCESS;
}
