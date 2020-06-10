#include "function.hxx"
#include "string.hxx"


extern "C" {
#include "Scierror.h"
#include "localization.h"
#include "PythonInstance.h"
#include "sciprint.h"
}

using namespace types;

types::Function::ReturnValue sci_checkPython(types::typed_list& in, int _iRetCount, types::typed_list& out) {
    if (in.size() != 1) {
        Scierror(999, "checkPython: Wrong number of input arguements, one expected");
        return types::Function::Error;
    }

    if (_iRetCount > 1) {
        Scierror(999, "checkPython: Wrong number of output arguements, one or lesser expected");
        return types::Function::Error;
    }
 
    if (!in[0] -> isString()) {
        Scierror(999, "checkPython: Incompatible arguement type, string expected");
        return types::Function::Error;
    }

    wchar_t **winput = in[0] -> getAs<String>() -> get();
    std::wstring input(*winput);
    std::wstring ver = L"3.8";
    if (input.find(ver) != std::wstring::npos) {
        sciprint("User installation of Python 3.8 found.\n");
    } else {
        char* buffer;
        char* token;
        std::string final_home;
        // const char s[2] = "\\";
        buffer = _getcwd(NULL, 0);
        token = strtok(buffer, "\\");
        while (token != NULL && strcmp(token, "sci_gateway") != 0) {
            std::string temp(token);
            final_home = final_home + temp + '\\';
            token = strtok(NULL, "\\");
        }
        final_home += "python";
        char *path = new char[final_home.length() + 1];
        strcpy(path, final_home.c_str());
        size_t len = final_home.length();
        //Py_SetPath(Py_DecodeLocale(final_home.c_str(), &len));
        Py_SetPythonHome(Py_DecodeLocale(path, &len));
        sciprint("No user installation of Python 3.8 found, consider installing it in order to use non standard modules.\n");
    }
    return Function::OK;
}