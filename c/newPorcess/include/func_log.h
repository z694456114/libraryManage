#ifndef __FUNC_LOG_H__
#define __FUNC_LOG_H__

#include <stdio.h>
#include <string.h>
#include <stdarg.h>
#include "func_comm.h"
#include "func_file.h"
#include "func_time.h"

typedef struct 
{
    int unLogLevel;
    char chLogStr[MAX_STRING_16];
}ST_LOG_LEVEL_STRING;

typedef enum 
{
    LOG_OFF,
    LOG_FATAL,
    LOG_ERROR,
    LOG_WARN,
    LOG_INFO,
    LOG_DEBUG,
    LOG_TRACE,
    LOG_ALL,
    LOG_END
}ENUM_LOG_LEVEL;

static ST_LOG_LEVEL_STRING stLogLevelString[] = {
	{LOG_OFF, "OFF"},
    {LOG_FATAL, "FATAL"},
    {LOG_ERROR, "ERROR"},
    {LOG_WARN, "WARN"},
    {LOG_INFO, "INFO"},
    {LOG_DEBUG, "DEBUG"},
    {LOG_TRACE, "TRACE"},
    {LOG_ALL, "ALL"},
};

extern int g_log_show_method;
extern int g_current_log_level;

#define logPrint(level, chMsg, ...) __logPrint(__FUNCTION__, __LINE__, level, chMsg, ##__VA_ARGS__)
extern void __logPrint(const char *func, const int line, int level, char *chMsg, ...);
extern int get_current_log_level();
extern int set_current_log_level(int nLogLevel);
extern int get_Log_Current_Level(char *strLogLevel);
extern int get_log_method();
extern int set_log_method(int nMethod);
extern int set_log_write_file(char *stFileName, char *buffer, int nLen);
#endif
