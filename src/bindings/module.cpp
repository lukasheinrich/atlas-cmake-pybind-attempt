#include <pybind11/pybind11.h>
#include <pybind11/numpy.h>


#include "AnalysisPackage/TestClass.h"

namespace py = pybind11;

int add(int i, int j) {
    TestClass c;
    return c.runit(i,j);
}

py::array_t<double> column_maker(){

    TestClass c;
    auto cont = c.test_create_container();
    
    auto result = py::array_t<double>(cont.size());
    py::buffer_info buf3 = result.request();
    double* ptr3 = (double*)buf3.ptr;

    for (unsigned int i = 0; i < buf3.shape[0]; i++)
    {
        ptr3[i] = cont[i];
    }

    return result;
}


PYBIND11_MODULE(_AnalysisPackage, m) {
    m.doc() = "pybind11 example plugin"; // optional module docstring

    m.def("add", &add, "A function which adds two numbers");
    m.def("column_maker", &column_maker, "A function that produces a column from xAOD");
}
