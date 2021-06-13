# The name of the package:
atlas_subdir (AnalysisPackage)


atlas_add_library( AnalysisPackageLib
   AnalysisPackage/*.h Root/*.cxx
   PUBLIC_HEADERS AnalysisPackage
   LINK_LIBRARIES
   AnaAlgorithmLib
   xAODEgamma
   xAODCore
   PATInterfaces
   AsgTools
   EgammaAnalysisInterfacesLib
)

atlas_add_executable( AnalysisPackageRunner
   util/run.cxx
   LINK_LIBRARIES
   AnalysisPackageLib
)




atlas_add_dictionary( AnalysisPackageDict
   AnalysisPackage/AnalysisPackageDict.h
   AnalysisPackage/selection.xml
   LINK_LIBRARIES
   AnalysisPackageLib
)


