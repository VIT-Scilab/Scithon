function [] = _verifyPython(toolbox_path) 
    os = getos();
    if (os == "Windows") then
        [pythonVer, status, err] = unix_g("python -V");
    else
        [pythonVer, status, err] = unix_g("python3 -V");
    end
    _checkPython(pythonVer, toolbox_path, os);
endfunction
