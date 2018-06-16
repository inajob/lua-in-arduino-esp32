extern "C" {
#include "lua.h"

#include "lualib.h"
#include "lauxlib.h"

int gprint(char* s){
  printf(s);
  return 0;
}
int system(const char* c){
  //none
  return 0;
}

int l_print(lua_State* L){
  const char* s = lua_tostring(L, 1);
  Serial.println(s);
  return 0; // 戻り値なし
}

int l_add(lua_State* L){
  int a = lua_tointeger(L, 1);
  int b = lua_tointeger(L, 2);
  lua_pushinteger(L, a + b);
  return 1; // 戻り値が1つ
}
}

