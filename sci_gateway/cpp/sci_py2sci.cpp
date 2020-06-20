#include "function.hxx"
#include "alltypes.hxx"
#include "PyVar.hxx"


extern "C" {
#include "Scierror.h"
#include "localization.h"
#include "PythonInstance.h"
}

using namespace types;

types::Function::ReturnValue sci_py2sci(types::typed_list& in, int _iRetCount, types::typed_list& out) {
    if (!Py_IsInitialized()) {
        Scierror(999, "py2sci: No instance of python is currently running! Did you forget to call startPy?");
        return types::Function::Error;
    }

    if (_iRetCount > 1) {
        Scierror(999, "py2sci: Wrong number of output arguements, 1 expected");
        return types::Function::Error;
    }

    if (in.size() != 1) {
        Scierror(999, "py2sci: Wrong number of input arguements, 1 expected");
        return types::Function::Error;
    }

    if (in[0] -> getTypeStr() != L"Python Variable") {
        Scierror(999, "py2sci: Incompatible type, python variable expected");
    }

    PyVar *input = in[0] -> getAs<PyVar>();
    InternalType *output = input -> sciParse();
    
    out.push_back(output);
    return types::Function::OK;
}