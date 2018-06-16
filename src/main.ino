#include "luafunc.h"

void setup(){
  Serial.begin(115200);
  // Luaのコンテキストの作成
  lua_State *L = luaL_newstate();
  // Luaの標準関数群の登録
  luaL_openlibs(L);

  // ===== Lua文字列の評価 ====
  if(luaL_dostring(L, "\
    function mul(a, b)\
      return a * b\
    end\n")){
    printf("run error %s\n", lua_tostring(L, -1));
  }

  // ===== C言語関数の登録 ====

  // l_add関数をaddという名前で登録
  lua_register(L, "add", l_add);

  // l_print関数をprintという名前で登録
  lua_register(L, "print", l_print);

  // ===== Lua文字列の評価 + C言語関数の呼び出し ====
  if(luaL_dostring(L, "\
    print(\"Hello Lua!\")\
    ")){
    printf("run error %s\n", lua_tostring(L, -1));
  }

  // ===== C言語からLua関数の呼び出し ====

  // mul関数を呼び出し
  lua_getglobal(L, "mul");
  lua_pushnumber(L, 4); //引数1
  lua_pushnumber(L, 5); //引数2
  if (lua_pcall(L, 2, 1, 0)) {
    fprintf(stderr, "cannot exec add. %s\n", lua_tostring(L, -1));
    return;
  }
  // 戻り値の確認
  if (lua_isnumber(L, -1)) {
    int ret = lua_tointeger(L, -1);
    printf("ret=%d\n", ret);
  }
  lua_pop(L, 1); // 戻り値を捨てる

  lua_close(L);
}

void loop(){
}
