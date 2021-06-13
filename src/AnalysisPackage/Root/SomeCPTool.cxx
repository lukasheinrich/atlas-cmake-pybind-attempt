#include "AnalysisPackage/SomeCPTool.h"
#include "PATInterfaces/CorrectionCode.h"
#include "xAODEgamma/Egamma.h"

CP::SomeCPTool::SomeCPTool(const std::string& name) : asg::AsgTool(name) {    
}


StatusCode CP::SomeCPTool::initialize() {
    return StatusCode::SUCCESS;
}

CP::CorrectionCode CP::SomeCPTool::applyCorrection(xAOD::Egamma& e) {
    e.setPt(e.pt() + 1.0);
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
