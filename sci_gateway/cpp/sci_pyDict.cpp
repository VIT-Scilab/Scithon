#include "function.hxx"
#include "alltypes.hxx"
#include "PyVar.hxx"


extern "C" {
#include "Scierror.h"
#include "localization.h"
#include "PythonInstance.h"
}

using namespace types;

types::Function::ReturnValue sci_pyDict(types::typed_list& in, int _iRetCount, types::typed_list& out) {
    if (!Py_IsInitialized()) {
        Scierror(999, "pyDict: No instance of python is currently running! Did you forget to call startPy?");
        return types::Function::Error;
    }

    if (in.size() % 2) {
        Scierror(999, "pyDict: Wrong arguement format, expected pyDict(key1, value1, key2, value2,...)");
        return types::Function::Error;
    }

    if (_iRetCount > 1) {
        Scierror(999, "pyDict: Wrong number of output arguements, 1 expected");
        return types::Function::Error;
    }

    PyObject *newDict = PyDict_New();
    for (size_t i = 0; i < in.size(); i+=2) {
        PyVar key = PyVar(in[i]);
        PyVar value = PyVar(in[i + 1]);
        
        if (PyDict_SetItem(newDict, key.get(), value.get()) == -1) {
            Py_DECREF(newDict);
            Scierror(999, "pyDict: Incompaitble type for arguement %zu, key must be hashable", i + 1);
            return types::Function::Error;
        }
    }

    PyVar *pOut = new PyVar(newDict);
    out.push_back(pOut);
    return types::Function::OK;
}