#include "function.hxx"
#include "string.hxx"
#include "PyVar.hxx"

extern "C" {
#include "Scierror.h"
#include "localization.h"
}

using namespace types;

types::Function::ReturnValue sci_pyImport(types::typed_list& in, int _iRetCount, types::typed_list& out) {
    if (!Py_IsInitialized()) {
        Scierror(999, "pyImport: No instance of python is currently running! Did you forget to call startPy?");
        return types::Function::Error;
    }

    if (in.size() != 1) {
        Scierror(999, "pyImport: Wrong number of input arguements, 1 expected");
        return types::Function::Error;
    }

    if (_iRetCount > 1) {
        Scierror(999, "pyImport: Wrong number of output arguements, 1 expected");
        return types::Function::Error;
    }

    wchar_t **winput = in[0] -> getAs<String>() -> get();
    char *input = new char[wcslen(*winput) + 1];
    sprintf(input, "%ws", *winput);

    PyObject *output = PyImport_ImportModule(input);
    if (output == NULL) {
        Py_DECREF(output);
        Scierror(999, "pyImport: Error while importing module '%s'", input);
        return types::Function::Error;
    }

    PyVar *pOut = new PyVar(output);
    out.push_back(pOut);
    return types::Function::OK;
}
