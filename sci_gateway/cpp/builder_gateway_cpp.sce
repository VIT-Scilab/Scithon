function builder_gateway_cpp()
    gwPath = get_absolute_file_path("builder_gateway_cpp.sce");
    origPath = pwd();
    //cd(gwPath);
    gw_table = [
        "startPy", "sci_startPy", "cppsci";
        "quitPy", "sci_quitPy", "cppsci";
        "py", "sci_py", "cppsci";
        "pyExec", "sci_pyExec", "cppsci";
        "pyGet", "sci_pyGet", "cppsci";
        "pyList", "sci_pyList", "cppsci";
        "pyTuple", "sci_pyTuple", "cppsci";
        "pyDict", "sci_pyDict", "cppsci";
        "pySet", "sci_pySet", "cppsci";
        "pyImport", "sci_pyImport", "cppsci";
        "pyEquals", "sci_pyEquals", "cppsci";
        "_checkPython", "sci_checkPython", "cppsci";
    ];

    CFLAGS = ilib_include_flag(gwPath);
    CFLAGS = ilib_include_flag(fullpath(gwPath + "../../src/c"));
    CFLAGS = CFLAGS + " " + ilib_include_flag(fullpath(gwPath + "../../src/cpp"));
    CFLAGS = CFLAGS + " " + ilib_include_flag(fullpath(gwPath + "../../python/include"));
    CFLAGS = CFLAGS + " " + ilib_include_flag(fullpath(SCI + "/modules/ast/includes"));

    LDFLAGS = fullpath(gwPath + "../../src/c/libPythonInstance.lib");
    LDFLAGS = LDFLAGS + " " + fullpath(gwPath + "../../src/cpp/libPyVar.lib");
    LDFLAGS = LDFLAGS + " " + fullpath(gwPath + "../../python/libs/python38.lib");

    gw_src_cpp = [
        "sci_startPy.cpp";
        "sci_quitPy.cpp";
        "sci_py.cpp";
        "sci_pyExec.cpp";
        "sci_pyGet.cpp";
        "sci_pyList.cpp";
        "sci_pyTuple.cpp";
        "sci_pyDict.cpp";
        "sci_pySet.cpp";
        "sci_pyImport.cpp";
        "sci_pyEquals.cpp";
        "sci_checkPython.cpp";
    ];

    //WITHOUT_AUTO_PUTLHSVAR = %t;
    //disp(CFLAGS);
    tbx_build_gateway("scithon_cpp", gw_table, gw_src_cpp, gwPath, ["../../src/c/libPythonInstance"], LDFLAGS, CFLAGS);
    //cd(origPath);
endfunction

builder_gateway_cpp();
clear builder_gateway_cpp;