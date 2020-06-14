#include "function.hxx"
#include "string.hxx"


extern "C" {
#include "localization.h"
#include "Scierror.h"    
#include "PythonInstance.h"
}

types::Function::ReturnValue sci_startPy(types::typed_list& in, int _iRetCount, types::typed_list& out) {
    if (in.size() != 0) {
        Scierror(999, "startPy: Wrong number of input arguements, none expected");
        return types::Function::Error;
    }

    if (_iRetCount > 1) {
        Scierror(999, "startPy: Wrong number of output arguements, one or lesser expected");
        return types::Function::Error;
    }
    
    if (Py_IsInitialized()) {
        Scierror(999, "startPy: An instance of python is already running! Did you forget to call quitPy?");
        return types::Function::Error;
    } else {      
        Initialize();
        return types::Function::OK;
    }
}