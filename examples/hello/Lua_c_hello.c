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

void LuaCallC()
{
  lua_State *L = lua_open();
  luaL_openlibs(L);

  lua_register(L, "average", average);

  luaL_dofile(L, "hello.lua");
  lua_close(L);
}

int main()
{
  LuaCallC();
  return 0;
}