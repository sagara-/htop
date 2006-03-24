/* Do not edit this file. It was automatically genarated. */

#ifndef HEADER_Header
#define HEADER_Header
/*
htop
(C) 2004-2006 Hisham H. Muhammad
Released under the GNU GPL, see the COPYING file
in the source distribution for its full text.
*/

#include "CPUMeter.h"
#include "MemoryMeter.h"
#include "SwapMeter.h"
#include "LoadMeter.h"
#include "LoadAverageMeter.h"
#include "UptimeMeter.h"
#include "ClockMeter.h"
#include "TasksMeter.h"

#include "debug.h"
#include <assert.h>


typedef enum HeaderSide_ {
   LEFT_HEADER,
   RIGHT_HEADER
} HeaderSide;

typedef struct Header_ {
   TypedVector* leftMeters;
   TypedVector* rightMeters;
   ProcessList* pl;
   bool margin;
   int height;
   int pad;
} Header;


Header* Header_new(ProcessList* pl);

void Header_delete(Header* this);

void Header_createMeter(Header* this, char* name, HeaderSide side);

void Header_setMode(Header* this, int i, MeterMode mode, HeaderSide side);

Meter* Header_getMeter(Header* this, int i, HeaderSide side);

int Header_size(Header* this, HeaderSide side);

char* Header_readMeterName(Header* this, int i, HeaderSide side);

MeterMode Header_readMeterMode(Header* this, int i, HeaderSide side);

void Header_defaultMeters(Header* this);

void Header_draw(Header* this);

int Header_calculateHeight(Header* this);

#endif