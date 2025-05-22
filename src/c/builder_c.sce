function builder_c()
    src_c = get_absolute_file_path("builder_c.sce");
    CFLAGS = ilib_include_flag(src_c);
    if (getos() == "Windows") then
        CFLAGS = CFLAGS + " " + ilib_include_flag(src_c + "../../thirdparty/Windows/include");
        LDFLAGS = fullfile(src_c + "../../thirdparty/Windows", "libs", "python313.lib");
    else
        CFLAGS = CFLAGS + " " + ilib_include_flag(src_c + "../../thirdparty/Linux/include");
        LDFLAGS = "-L" + fullfile(src_c + "../../thirdparty/Linux", "lib", "config-3.13-x86_64-linux-gnu") + " -lpython3";
    end
    names = ["PythonInstance"];
    files = ["PythonInstance.c"];

    tbx_build_src(names, files, "c", src_c, "", LDFLAGS, CFLAGS);
endfunction

builder_c();
clear builder_c;
