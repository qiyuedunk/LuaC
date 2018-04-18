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

const luaL_Reg mylib[] =
{
  {"average", average},
  {"NULL", NULL}
};

int luaopen_luaclib(lua_State *L)
{
  luaL_register(L, "mylib", mylib);
  return 1;
}
