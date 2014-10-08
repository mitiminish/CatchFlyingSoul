#ifdef GLOBAL_INSTANCE

#define GLOBAL 

#else

#define GLOBAL extern

#endif

#include "define.h"
#include"vector.h"
#include "key.h"
#include "struct.h"
#include "function.h"
#include "fps.h"
#include "Check_time.h"

GLOBAL ch_t ch;
GLOBAL Ckey key;
GLOBAL Cfps fps;
GLOBAL CCheck_time check_time;
GLOBAL bar_t bar[BAR_MAX];
GLOBAL soul_t soul[SOUL_MAX];
GLOBAL int game_cnt;
GLOBAL int auto_scroll;

GLOBAL int color[COLOR_MAX];