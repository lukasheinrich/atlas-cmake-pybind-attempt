#include "AnalysisPackage/ISomeCPTool.h"
#include "PATInterfaces/SystematicSet.h"
#include "AsgTools/AsgTool.h"

namespace CP {

    class SomeCPTool : virtual public CP::ISomeCPTool, public asg::AsgTool {
        ASG_TOOL_CLASS2( SomeCPTool, ISomeCPTool, asg::AsgTool) 

    public:

        SomeCPTool(const std::string& name);


        StatusCode initialize() override;
        virtual CP::CorrectionCode applyCorrection(xAOD::Egamma&) override;
        virtual SystematicSet affectingSystematics() const override;
        virtual SystematicSet recommendedSystematics() const override;
        bool isAffectedBySystematic( const SystematicVariation& systematic ) const override {return false;};
        virtual StatusCode applySystematicVariation(const CP::SystematicSet&) override;
    };      


}