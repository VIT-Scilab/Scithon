#include "function.hxx"
#include "alltypes.hxx"
#include "PyVar.hxx"


extern "C" {
#include "Scierror.h"
#include "localization.h"
#include "PythonInstance.h"
}

using namespace types;

types::Function::ReturnValue sci_pySet(types::typed_list& in, int _iRetCount, types::typed_list& out) {
    if (!Py_IsInitialized()) {
        Scierror(999, "pySet: No instance of python is currently running! Did you forget to call startPy?");
        return types::Function::Error;
    }

    if (_iRetCount > 1) {
        Scierror(999, "pySet: Wrong number of output arguements, 1 expected");
        return types::Function::Error;
    }

    PyObject *newSet;
    if (in.size() == 1 && in[0] -> getTypeStr() == L"Python Variable" && PySequence_Check(in[0] -> getAs<PyVar>() -> get())) {
        newSet = PySet_New(in[0] -> getAs<PyVar>() -> get());
        if (newSet == NULL) {
            Py_DECREF(newSet);
            Scierror(999, "pySet: Error while creating set from iterable");
            return types::Function::Error;
        }
    } else {
        newSet = PySet_New(NULL);
        for (size_t i = 0; i < in.size(); i++) {
            PyVar item = PyVar(in[i]);
            if (PySet_Add(newSet, item.get()) == -1) {
                Py_DECREF(newSet);
                Scierror(999, "pySet: Incompaitble type for arguement %zu, variable must be hashable", i + 1);
                return types::Function::Error;
            }
        }   
    }    

    PyVar *pOut = new PyVar(newSet);
    out.push_back(pOut);
    return types::Function::OK;
}