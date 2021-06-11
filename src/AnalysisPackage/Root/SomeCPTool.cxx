#include "SomeCPTool.h"
#include "PATInterfaces/CorrectionCode.h"

StatusCode CP::SomeCPTool::initialize() {
    return StatusCode::SUCCESS;
}

CP::CorrectionCode CP::SomeCPTool::applyCorrection(xAOD::Egamma&) {
    return CP::CorrectionCode::Ok;
}