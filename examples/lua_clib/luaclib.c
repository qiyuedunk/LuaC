//compile cmd
//gcc $file_name -fPIC -shared -o ${file_base_name}.so  -../../Iinclude/ -L../../lib/ -llua"
#include <stdio.h>
#include "lua.h"
#include "lauxlib.h"
#include "lualib.h"


int average(lua_State *L)
{
  int n = lua_gettop(L);
  float sum = 0;
  for(int i=1; i<=n; i++)
  {
    sum += lua_tonumber(L, i);
  }
  lua_pushnumber(L, sum/n);
  lua_pushnumber(L, sum);
  return 2;
}

//可以将c中定义的函数以数组的形式进行分组，这样require到lua中，可以以不同的名称调用
const luaL_Reg mylib[] =
{
  {"average", average},
  {"NULL", NULL}
};

static const luaL_Reg s_lib_preload[] = {
  // { "socket.core", luaopen_socket_core },
  // { "pb",    luaopen_pb }, // any 3rd lualibs added here
  { NULL, NULL }
};

//lua 中require(#{filename})的时候，会调用名为luaopen_#{filename}的函数，所以该函数名很重要
int luaopen_luaclib(lua_State *L)
{
  luaopen_socket_core(L);
  luaL_register(L, "mylib", mylib);

  const luaL_Reg *lib;
  lua_getglobal(L,"package");
  lua_getfield(L,-1,"preload");
  for (lib = s_lib_preload; lib->func; lib++) {
    lua_pushcfunction(L, lib->func);
    lua_setfield(L, -2, lib->name);
  }
  return 1;
}
