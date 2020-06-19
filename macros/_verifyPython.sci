function [] = _verifyPython(toolbox_path) 
    os = getos();
    if (os == "Windows") then
        pythonVer = unix_g("python -V");
    else
        pythonVer = unix_g("python3.8 -V");
    end
    _checkPython(pythonVer, toolbox_path, os);
endfunction