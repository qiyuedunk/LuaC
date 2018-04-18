# LuaC
sublime text3 build system
{
    "cmd"         : ["gcc -o ${file_base_name} $file_name -I../../include/ -L../../lib/ -llua"],
    "shell"       : true,
    "working_dir" : "$file_path",
    "selector"    : "source.c",
    "encoding"    : "utf-8",
    "variants"    :
    [{
        "name"    : "Run",
        "cmd"     : "./${file_base_name}"
    }]
}
