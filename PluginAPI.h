/* Do not edit this file. It was automatically generated. */

#ifndef HEADER_PluginAPI
#define HEADER_PluginAPI

#ifdef HAVE_LUA


#include <lua.h>
#include <lualib.h>
#include <lauxlib.h>

#define check_field(_name, _type, _err)    \
   do {                                    \
      int typ = lua_getfield(L, 1, _name); \
      if (typ != _type) {                  \
         lua_settop(L, 0);                 \
         lua_pushnil(L);                   \
         lua_pushliteral(L, _err);         \
         return 2;                         \
      }                                    \
      lua_pop(L, 1);                       \
   } while(0)

#define assign_string(_var, _idx, _field)  \
   do {                                    \
      lua_getfield(L, _idx, _field);       \
      _var = xStrdup(lua_tostring(L, -1)); \
      lua_pop(L, 1);                       \
   } while(0)


int PluginAPI_newColumn(lua_State* L);

int PluginAPI_new(lua_State* L);

#endif

#endif