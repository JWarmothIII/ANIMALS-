{ pkgs }:let
   aspell = pkgs.aspellWithDicts (dicts : [dicts.en]);
in {
	deps = [
    pkgs.python38Full
		pkgs.clang_12
		pkgs.ccls
		pkgs.gdb
		pkgs.gnumake
	];
    env = {
    PYTHON_LD_LIBRARY_PATH = pkgs.lib.makeLibraryPath [
      pkgs.stdenv.cc.cc.lib
      pkgs.zlib
      pkgs.glib
      pkgs.xorg.libX11
      pkgs.enchant
    ];
    PYTHONBIN = "${pkgs.python38Full}/bin/python3.8";
    LANG = "en_US.UTF-8";
    ASPELL_CONF = "dict-dir ${aspell}/lib/aspell;data-dir ${aspell}/lib/aspell";
  };
}