#include <stdio.h>
#include <iostream>
#include <vector>
#include <Python.h>


int main() {

    Py_Initialize();


    // PyObject * sys = PyImport_ImportModule("sys");
    // PyObject * path = PyObject_GetAttrString(sys, "path");
    // PyList_Append(path, ModuleString);
    PySys_SetArgv(0, NULL); // does not work with Python 3.11 and above (deprecated)
    PyObject* myModuleString = PyUnicode_FromString((char*)"mytest");
     
    PyObject* Module = PyImport_Import(myModuleString);
    // PyObject * Dict = PyModule_GetDict(Module);
    // PyObject * Func = PyDict_GetItemString(Dict, "simpleFunction");
    // PyObject * Result = PyObject_CallObject(Func, NULL);


    // Method CHATGPT
    // PyObject* pModule = PyImport_ImportModule("ml");
    PyObject* pFunc = PyObject_GetAttrString(Module, "simpleFunction");

    // Create a vector of integers to pass to the Python function
    std::vector<double> myArray = {1, 2, 3, 4, 5};


    // Convert the vector of integers to a Python tuple
    PyObject* pArgs = PyList_New(myArray.size());
    for (size_t i = 0; i < myArray.size(); i++) {
        PyList_SetItem(pArgs, i, PyFloat_FromDouble(myArray[i]));
    }

    PyObject* pResult = PyObject_CallObject(pFunc, pArgs);
    double result = PyFloat_AsDouble(pResult);
    std::cout << "Result: " << result << std::endl;
    
    Py_XDECREF(myModuleString);
    Py_XDECREF(pResult);
    Py_XDECREF(pArgs);
    Py_XDECREF(pFunc);
    Py_XDECREF(Module);
    Py_Finalize();
    
    return 0;
}

