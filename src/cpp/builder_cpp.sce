function build_cpp()
    origPath = pwd();
    cppPath = get_absolute_file_path("builder_cpp.sce");

    CFLAGS = ilib_include_flag(cppPath);
    CFLAGS = CFLAGS + " " + ilib_include_flag(fullpath(cppPath + "../c"));
	
    if (getos() == "Windows") then
        CFLAGS = CFLAGS + " " + ilib_include_flag(fullpath(cppPath + "../../thirdparty/Windows/include"));
        CFLAGS = CFLAGS + " " + ilib_include_flag(SCI + "/modules/ast/includes");
        CFLAGS = CFLAGS + " -DSCITHON_EXPORTS";
        
        LDFLAGS = fullpath(cppPath + "../../thirdparty/Windows/libs/python313.lib");
        LDFLAGS = LDFLAGS + " " + fullpath(cppPath + "../c/libPythonInstance.lib");
    else
        CFLAGS = CFLAGS + " " + ilib_include_flag(fullpath(cppPath + "../../thirdparty/Linux/include"));
        CFLAGS = CFLAGS + " " + ilib_include_flag(SCI + "/../../include/scilab");
        LDFLAGS = ""
    end

    
    src_cpp = ["PyVar.cpp"];

    tbx_build_src("PyVar", src_cpp, "cpp", cppPath, ["../c/libPythonInstance"], LDFLAGS, CFLAGS);
endfunction

build_cpp();
clear build_cpp;

