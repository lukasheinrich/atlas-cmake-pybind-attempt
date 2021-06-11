# include(GNUInstallDirs)

pybind11_add_module(_AnalysisPackage module.cpp)
target_link_libraries(
    _AnalysisPackage 
    PRIVATE
    AnalysisPackageLib
    Python::Python
)
