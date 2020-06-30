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
    if (in.size() !=3) {
        Scierror(999, "checkPython: Wrong number of input arguements, three expected");
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
    std::wstring ver = L"3.8.";
    if (input.find(ver) != std::wstring::npos) {
        sciprint("User installation of Python 3.8 found.\n");
    } else {
        char* buffer;
        char* token;
        wchar_t **toolbox_path = in[1] -> getAs<String>() -> get();
        wchar_t **os = in[2] -> getAs<String>() -> get();
        std::wstring final_home(*toolbox_path);
        if (*os == L"Windows") {
            final_home += L"thirdparty/Windows";
        } else {
            final_home += L"thirdparty/Linux";
        }        
        const wchar_t *final_path = final_home.c_str();
        char *path = new char[final_home.length() + 1];
        wcstombs(path, final_path, wcslen(final_path) + 1);
        size_t len = final_home.length();
        Py_SetPythonHome(Py_DecodeLocale(path, &len));
        sciprint("No user installation of Python 3.8 found, consider installing and setting it as the default python in order to use non standard modules.\n");
    }
    return Function::OK;
}