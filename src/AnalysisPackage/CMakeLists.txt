# The name of the package:
atlas_subdir (AnalysisPackage)


atlas_add_library( AnalysisPackageLib
   AnalysisPackage/*.h Root/*.cxx
   PUBLIC_HEADERS AnalysisPackage
   LINK_LIBRARIES AnaAlgorithmLib )

atlas_add_dictionary( AnalysisPackageDict
   AnalysisPackage/AnalysisPackageDict.h
   AnalysisPackage/selection.xml
   LINK_LIBRARIES AnalysisPackageLib )


