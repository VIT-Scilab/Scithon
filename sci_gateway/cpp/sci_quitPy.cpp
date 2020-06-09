#include "function.hxx"
#include "string.hxx"


extern "C" {
#include "Scierror.h"
#include "localization.h"
#include "PythonInstance.h"
}

types::Function::ReturnValue sci_quitPy(types::typed_list& in, int _iRetCount, types::typed_list& out) {
    if (in.size() != 0) {
        Scierror(999, "quitPy: Wrong number of input arguements, none expected");
        return types::Function::Error;
    }

    if (_iRetCount > 1) {
        Scierror(999, "quitPy: Wrong number of output arguements, one or lesser expected");
        return types::Function::Error;
    }
 
    if (!Py_IsInitialized()) {
        Scierror(999, "quitPy: No instance of python is currently running! Did you forget to call startPy?");
        return types::Function::Error;
    } else {
        Finalize();
        return types::Function::OK;
    }
}