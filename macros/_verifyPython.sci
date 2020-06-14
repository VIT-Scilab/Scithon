function [] = _verifyPython(toolbox_path) 
    pythonVer = unix_g("python -V");
    _checkPython(pythonVer, toolbox_path);
endfunction