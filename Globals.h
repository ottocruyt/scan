#ifndef GLOBALS_H
#define GLOBALS_H

extern int ms;
extern int max_ms;
extern int defaultAveragingFrames;

static inline const char * const BoolToString(bool b)
{
  return b ? "true" : "false";
}

enum DETAIL {
	NONE,
	LOW,
	HIGH,
	FULL
};




#endif