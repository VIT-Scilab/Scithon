#include "function.hxx"
#include "string.hxx"
#include "double.hxx"



extern "C" {
#include "Scierror.h"
#include "localization.h"
#include "PythonInstance.h"
#include "sciprint.h"
}

types::Function::ReturnValue sci_pyExec(types::typed_list& in, int _iRetCount,
                                    types::typed_list& out) {

	
    if (in.size() != 1) {
        Scierror(999, "pyExec: Wrong number of input arguements, 1 expected");
        return types::Function::Error;
    }

    if (_iRetCount > 0) {
        Scierror(999, "pyExec: Wrong number of output arguements, none expected");
        return types::Function::Error;
    }

    if (in[0]->isString() == false) {
        Scierror(999,
                 "pyExec: Wrong type of arguement. string of filepath expected");
        return types::Function::Error;
    }

    if (!Py_IsInitialized()) {
        Scierror(999, "pyExec: No instance of python is currently running! Did you forget to call startPy?");
        return types::Function::Error;
    }

    types::String *pIn = in[0]->getAs<types::String>();
    wchar_t **winput = pIn -> get();
    char *input = new char[wcslen(*winput) + 1];
    //sprintf(input, "%ws", *winput);
    wcstombs(input, *winput, wcslen(*winput) + 1);
    FILE *fp = fopen(input, "rb");
    if (fp == NULL) {
        delete input;
        Scierror(999, "pyExec: Error while opening the file");
        return types::Function::Error;
    }
    
    PyRun_SimpleFileEx(fp, input, true);

    int errSize = GetStdErrSize();
    if (errSize) {
        char *err = new char[errSize + 1];
        GetStdErr(err);
        std::string errMsg = "Encountered an error while running the code:\n";
        errMsg.append(err);
        errMsg.append("\n\nOutput:");
        sciprint(errMsg.c_str());
    } 

    char *output = new char[GetStdOutSize() + 1];
    GetStdOut(output);
    sciprint(output);
    // types::String *pOut = new types::String(output);
    // out.push_back(pOut);
    delete input;
    delete output;
    return types::Function::OK;
}
