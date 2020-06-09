#include "function.hxx"
#include "alltypes.hxx"
#include "PyVar.hxx"


extern "C" {
#include "Scierror.h"
#include "localization.h"
#include "PythonInstance.h"
}

using namespace types;

types::Function::ReturnValue sci_pyTuple(types::typed_list& in, int _iRetCount, types::typed_list& out) {
    if (!Py_IsInitialized()) {
        Scierror(999, "pyTuple: No instance of python is currently running! Did you forget to call startPy?");
        return types::Function::Error;
    }

    if (_iRetCount > 1) {
        Scierror(999, "pyTuple: Wrong number of output arguements, 1 expected");
        return types::Function::Error;
    }

    PyObject *newTuple = PyTuple_New(in.size());
    for (size_t i = 0; i < in.size(); i++) {
        PyVar *item = new PyVar(in[i]);
        PyTuple_SetItem(newTuple, i, item -> get());
    }

    PyVar *pOut = new PyVar(newTuple);
    out.push_back(pOut);
    return types::Function::OK;
}
    