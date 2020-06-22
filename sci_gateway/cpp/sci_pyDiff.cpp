#include "function.hxx"
#include "alltypes.hxx"
#include "PyVar.hxx"


extern "C" {
#include "Scierror.h"
#include "localization.h"
#include "PythonInstance.h"
}

using namespace types;

types::Function::ReturnValue sci_pyDiff(types::typed_list& in, int _iRetCount, types::typed_list& out) {
    if (!Py_IsInitialized()) {
        Scierror(999, "pyDiff: No instance of python is currently running! Did you forget to call startPy?");
        return types::Function::Error;
    }

    if (_iRetCount > 1) {
        Scierror(999, "pyDiff: Wrong number of output arguements, 1 expected");
        return types::Function::Error;
    }

    if (in.size() != 2) {
        Scierror(999, "pyDiff: Wrong number of input arguements, 2 expected");
        return types::Function::Error;
    }

    PyVar pIn1 = PyVar(in[0]);
    PyVar pIn2 = PyVar(in[1]);

    PyObject *result = PyObject_CallMethod(pIn1.get(), "__sub__", "(O)", pIn2.get());
    if (result == Py_NotImplemented) {
        result = PyObject_CallMethod(pIn2.get(), "__rsub__", "(O)", pIn1.get());
    }
    if (result == Py_NotImplemented) {
        Scierror(999, "pyDiff: Incompatible types for operation");
        return Function::Error;
    } else if (PyErr_Occurred() != NULL) {
        PyErr_Print();
        char *err = new char[GetStdErrSize() + 1];
        GetStdErr(err);
        Scierror(999, "An error occured while performing the operation\n%s", err);
        PyErr_Clear();
        delete err;
        return Function::Error;
    } else {
        PyVar *output = new PyVar(result);
        out.push_back(output);
    }

    return types::Function::OK;
}