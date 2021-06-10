#ifndef AnalysisPackage_UserAlgorithm_H
#define AnalysisPackage_UserAlgorithm_H

#include <AnaAlgorithm/AnaAlgorithm.h>
#include "TH1.h"

class UserAlgorithm : public EL::AnaAlgorithm
{
public:
  // this is a standard algorithm constructor
  UserAlgorithm (const std::string& name, ISvcLocator* pSvcLocator);

  // these are the functions inherited from Algorithm
  virtual StatusCode initialize () override;
  virtual StatusCode execute () override;
  virtual StatusCode finalize () override;

private:
  // Configuration, and any other types of variables go here.
};

#endif
