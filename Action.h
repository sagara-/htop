/* Do not edit this file. It was automatically generated. */

#ifndef HEADER_Action
#define HEADER_Action
/*
htop - Action.h
(C) 2014 Hisham H. Muhammad
Released under the GNU GPL, see the COPYING file
in the source distribution for its full text.
*/


#include "IncSet.h"
#include "Settings.h"
#include "UsersTable.h"

typedef enum {
   HTOP_OK = 0x00,
   HTOP_REFRESH = 0x01,
   HTOP_RECALCULATE = 0x03, // implies HTOP_REFRESH
   HTOP_SAVE_SETTINGS = 0x04,
   HTOP_KEEP_FOLLOWING = 0x08,
   HTOP_QUIT = 0x10,
   HTOP_REDRAW_BAR = 0x20,
   HTOP_UPDATE_PANELHDR = 0x41, // implies HTOP_REFRESH
} Htop_Reaction;

typedef Htop_Reaction (*Htop_Action)();

typedef struct State_ {
   IncSet* inc;
   Settings* settings;
   UsersTable* ut;
} State;

typedef bool(*Action_ForeachProcessFn)(Process*, size_t);


bool Action_foreachProcess(Panel* panel, Action_ForeachProcessFn fn, int arg, bool* wasAnyTagged);


#endif