#ifndef __FUNC_TIME_H__
#define __FUNC_TIME_H__

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

typedef enum
{
    TIME_APART,
    TIME_CONNECT,
    TIME_END
}ENUM_TIME_FORMAT;

extern void get_Current_Time(char *chTimeStr, int format);

#endif