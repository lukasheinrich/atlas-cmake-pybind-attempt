#include "AnalysisPackage/ISomeCPTool.h"
namespace CP {

    class SomeCPTool : virtual public CP::ISomeCPTool {
        ASG_TOOL_CLASS2( SomeCPTool, ISomeCPTool, CP::ISystematicsTool) 

    public:

        StatusCode initialize() override;
        virtual CP::CorrectionCode applyCorrection(xAOD::Egamma&) override;

    };      


}