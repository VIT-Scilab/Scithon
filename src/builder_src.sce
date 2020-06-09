function builder_src()
    langage_src = ["c", "cpp"];
    path_src = get_absolute_file_path("builder_src.sce");
    tbx_builder_src_lang(langage_src, path_src);
  endfunction
  
  builder_src();
  clear builder_src;