function builder_gateway_cpp()
    gwPath = get_absolute_file_path("builder_gateway_cpp.sce");
    origPath = pwd();
    gw_table = [
//                 Functions
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
        "pyAdd", "sci_pyAdd", "cppsci";
        "pyDiff", "sci_pyDiff", "cppsci";
        "pyMul", "sci_pyMul", "cppsci";
        "pyDiv", "sci_pyDiv", "cppsci";
        "pyMod", "sci_pyMod", "cppsci";
        "pyPow", "sci_pyPow", "cppsci";
        "pyXor", "sci_pyXor", "cppsci";
        "pyEquals", "sci_pyEquals", "cppsci";
        "pyLesser", "sci_pyLesser", "cppsci";
        "pyGreater", "sci_pyGreater", "cppsci";
        "pyLEquals", "sci_pyGEquals", "cppsci";
        "pyGEquals", "sci_pyLEquals", "cppsci";
//                  Operators
//Addition
        "%py_a_s", "sci_pyAdd", "cppsci";
        "%py_a_b", "sci_pyAdd", "cppsci";
        "%py_a_c", "sci_pyAdd", "cppsci";
        "%py_a_py", "sci_pyAdd", "cppsci";
        "%s_a_py", "sci_pyAdd", "cppsci";
        "%b_a_py", "sci_pyAdd", "cppsci";
        "%c_a_py", "sci_pyAdd", "cppsci";
//Difference
        "%py_s_s", "sci_pyDiff", "cppsci";
        "%py_s_b", "sci_pyDiff", "cppsci";
        "%py_s_c", "sci_pyDiff", "cppsci";
        "%py_s_py", "sci_pyDiff", "cppsci";
        "%s_s_py", "sci_pyDiff", "cppsci";
        "%b_s_py", "sci_pyDiff", "cppsci";
        "%c_s_py", "sci_pyDiff", "cppsci";
//Multiplication
        "%py_m_s", "sci_pyMul", "cppsci";
        "%py_m_b", "sci_pyMul", "cppsci";
        "%py_m_c", "sci_pyMul", "cppsci";
        "%py_m_py", "sci_pyMul", "cppsci";
        "%s_m_py", "sci_pyMul", "cppsci";
        "%b_m_py", "sci_pyMul", "cppsci";
        "%c_m_py", "sci_pyMul", "cppsci";
//Division
        "%py_r_s", "sci_pyDiv", "cppsci";
        "%py_r_b", "sci_pyDiv", "cppsci";
        "%py_r_c", "sci_pyDiv", "cppsci";
        "%py_r_py", "sci_pyDiv", "cppsci";
        "%s_r_py", "sci_pyDiv", "cppsci";
        "%b_r_py", "sci_pyDiv", "cppsci";
        "%c_r_py", "sci_pyDiv", "cppsci";
//Power
        "%py_p_s", "sci_pyPow", "cppsci";
        "%py_p_b", "sci_pyPow", "cppsci";
        "%py_p_c", "sci_pyPow", "cppsci";
        "%py_p_py", "sci_pyPow", "cppsci";
        "%s_p_py", "sci_pyPow", "cppsci";
        "%b_p_py", "sci_pyPow", "cppsci";
        "%c_p_py", "sci_pyPow", "cppsci";
//Equals
        "%py_o_s", "sci_pyEquals", "cppsci";
        "%py_o_b", "sci_pyEquals", "cppsci";
        "%py_o_c", "sci_pyEquals", "cppsci";
        "%py_o_py", "sci_pyEquals", "cppsci";
        "%s_o_py", "sci_pyEquals", "cppsci";
        "%b_o_py", "sci_pyEquals", "cppsci";
        "%c_o_py", "sci_pyEquals", "cppsci";
//Not Equals
        "%py_n_s", "sci_pyNEquals", "cppsci";
        "%py_n_b", "sci_pyNEquals", "cppsci";
        "%py_n_c", "sci_pyNEquals", "cppsci";
        "%py_n_py", "sci_pyNEquals", "cppsci";
        "%s_n_py", "sci_pyNEquals", "cppsci";
        "%b_n_py", "sci_pyNEquals", "cppsci";
        "%c_n_py", "sci_pyNEquals", "cppsci";
//Lesser Than
        "%py_1_s", "sci_pyLesser", "cppsci";
        "%py_1_b", "sci_pyLesser", "cppsci";
        "%py_1_c", "sci_pyLesser", "cppsci";
        "%py_1_py", "sci_pyLesser", "cppsci";
        "%s_1_py", "sci_pyLesser", "cppsci";
        "%b_1_py", "sci_pyLesser", "cppsci";
        "%c_1_py", "sci_pyLesser", "cppsci";
//Greater Than
        "%py_2_s", "sci_pyGreater", "cppsci";
        "%py_2_b", "sci_pyGreater", "cppsci";
        "%py_2_c", "sci_pyGreater", "cppsci";
        "%py_2_py", "sci_pyGreater", "cppsci";
        "%s_2_py", "sci_pyGreater", "cppsci";
        "%b_2_py", "sci_pyGreater", "cppsci";
        "%c_2_py", "sci_pyGreater", "cppsci";
//Lesser Than or Equal To
        "%py_3_s", "sci_pyLEquals", "cppsci";
        "%py_3_b", "sci_pyLEquals", "cppsci";
        "%py_3_c", "sci_pyLEquals", "cppsci";
        "%py_3_py", "sci_pyLEquals", "cppsci";
        "%s_3_py", "sci_pyLEquals", "cppsci";
        "%b_3_py", "sci_pyLEquals", "cppsci";
        "%c_3_py", "sci_pyLEquals", "cppsci";
//Greater Than or Equal To
        "%py_4_s", "sci_pyGEquals", "cppsci";
        "%py_4_b", "sci_pyGEquals", "cppsci";
        "%py_4_c", "sci_pyGEquals", "cppsci";
        "%py_4_py", "sci_pyGEquals", "cppsci";
        "%s_4_py", "sci_pyGEquals", "cppsci";
        "%b_4_py", "sci_pyGEquals", "cppsci";
        "%c_4_py", "sci_pyGEquals", "cppsci";
//                  Miscellaneous
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
        "sci_pyAdd.cpp";
        "sci_pyDiff.cpp";
        "sci_pyMul.cpp";
        "sci_pyDiv.cpp";
        "sci_pyMod.cpp";
        "sci_pyPow.cpp";
        "sci_pyXor.cpp";
        "sci_pyEquals.cpp";
        "sci_pyNEquals.cpp";
        "sci_pyLesser.cpp";
        "sci_pyGreater.cpp";
        "sci_pyLEquals.cpp";
        "sci_pyGEquals.cpp";
        "sci_checkPython.cpp";
    ];

    tbx_build_gateway("scithon_cpp", gw_table, gw_src_cpp, gwPath, ["../../src/c/libPythonInstance"], LDFLAGS, CFLAGS);
endfunction

builder_gateway_cpp();
clear builder_gateway_cpp;