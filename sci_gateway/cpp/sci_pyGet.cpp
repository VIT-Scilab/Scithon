#include "function.hxx"
#include "string.hxx"
#include "double.hxx"
#include "PyVar.hxx"



extern "C" {
#include "Scierror.h"
#include "localization.h"
#include "PythonInstance.h"
}

types::Function::ReturnValue sci_pyGet(types::typed_list& in, int _iRetCount,
                                    types::typed_list& out) {

	
    if (in.size() != 1) {
        Scierror(999, "pyGet: Wrong number of input arguements, 1 expected");
        return types::Function::Error;
    }

    if (_iRetCount > 1) {
        Scierror(999, "pyGet: Wrong number of output arguements, 1 expected");
        return types::Function::Error;
    }

    if (in[0]->isString() == false) {
        Scierror(999,
                 "pyGet: Wrong type of arguement. string of variable name expected");
        return types::Function::Error;
    }

    if (!Py_IsInitialized()) {
        Scierror(999, "pyGet: No instance of python is currently running! Did you forget to call startPy?");
        return types::Function::Error;
    }

    types::String *pIn = in[0]->getAs<types::String>();
    wchar_t **winput = pIn -> get();
    char *input = new char[wcslen(*winput) + 1];
    sprintf(input, "%ws", *winput);
    
    PyObject *var = GetPyObject(input);
    if (var == NULL) {
        delete input;
        Scierror(999, "pyGet: No variable with the name '%s' found", input);
        return types::Function::Error;
    }
 
    types::PyVar *pOut = new types::PyVar(var);
    out.push_back(pOut);
    delete input;
    return types::Function::OK;
}
