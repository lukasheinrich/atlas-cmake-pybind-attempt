#ifndef ISOMECPTOOL_H
#define ISOMECPTOOL_H

#include "AsgTools/IAsgTool.h"
#include "PATInterfaces/ISystematicsTool.h"
#include "xAODEgamma/EgammaFwd.h"

namespace CP {

  class ISomeCPTool : public CP::ISystematicsTool {
    /// Declare the interface that the class provides
    ASG_TOOL_INTERFACE( ISomeCPTool )
    public:
    
    virtual ~ISomeCPTool() {};
    
    virtual StatusCode initialize() = 0;
    
    //Apply the correction on a modifyable egamma object (xAOD::Electron or xAOD::Photon)
    virtual CP::CorrectionCode applyCorrection(xAOD::Egamma &) = 0;
    
  };
  
}
#endif
