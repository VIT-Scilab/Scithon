function builder_c()
    src_c = get_absolute_file_path("builder_c.sce");
    cflags = ilib_include_flag(src_c);
    cflags = cflags + " " + ilib_include_flag(src_c + "../../python/include");
    ldflags = fullfile(src_c + "../../python", "libs", "python38.lib");
    names = ["PythonInstance"];
    files = ["PythonInstance.c"];

    tbx_build_src(names, files, "c", src_c, "", ldflags, cflags);
endfunction

builder_c();
clear builder_c;