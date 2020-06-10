function [] = _verifyPython() 
    pythonVer = unix_g("python -V");
    _checkPython(pythonVer);
endfunction