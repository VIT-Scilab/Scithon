function build_cpp()
    origPath = pwd();
    cppPath = get_absolute_file_path("builder_cpp.sce");
    //cd(cppPath);

    CFLAGS = ilib_include_flag(cppPath);
    CFLAGS = CFLAGS + " " + ilib_include_flag(fullpath(cppPath + "../../python/include"));
    CFLAGS = CFLAGS + " " + ilib_include_flag(SCI + "/modules/ast/includes");
    CFLAGS = CFLAGS + " " + ilib_include_flag(fullpath(cppPath + "../c"));
    CFLAGS = CFLAGS + " -DSCITHON_EXPORTS";

    LDFLAGS = fullfile(cppPath + "../../python/libs/python38.lib");
    LDFLAGS = LDFLAGS + " " + fullpath(cppPath + "../c/libPythonInstance.lib");
    src_cpp = ["PyVar.cpp"];

    tbx_build_src("PyVar", src_cpp, "cpp", cppPath, ["../c/libPythonInstance"], LDFLAGS, CFLAGS);
    //cd(origPath);
endfunction

build_cpp();
clear build_cpp;

