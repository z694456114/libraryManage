#include "func_log.h"

int g_log_show_method = 0;
int g_current_log_level = LOG_DEBUG;

int get_current_log_level()
{
    return g_current_log_level;
}

int set_current_log_level(int nLogLevel)
{
    if(nLogLevel < LOG_OFF || nLogLevel >= LOG_END)
        return ERROR_OUT_OF_RANGE;
    
    g_current_log_level = nLogLevel;
    return SUCCESS;
}

int get_Log_Current_Level(char *strLogLevel)
{
    int i;
    int nFindStatus = 0;
    char chStr[MAX_STRING_16];

    if(NULL == strLogLevel)
        return ERROR_NULL;

    memset(chStr, 0, MAX_STRING_16);
    for(i = LOG_OFF; i < LOG_END; i++)
    {
        if(stLogLevelString[i].unLogLevel == g_current_log_level)
        {
            nFindStatus = 1;
            memcpy(chStr, stLogLevelString[i].chLogStr, MAX_STRING_16);
            break;
        }
    }
    
    if(1 == nFindStatus)
        memcpy(strLogLevel, chStr, strlen(chStr) + 1);
    else
        memcpy(strLogLevel, chStr, strlen(chStr) + 1);

    return SUCCESS;
}

int get_log_method()
{
    return g_log_show_method;
}

int set_log_method(int nMethod)
{
    if(nMethod < 0 || nMethod > 1)
        return ERROR_OUT_OF_RANGE;

    g_log_show_method = nMethod;
    return SUCCESS;
}

int set_log_write_file(char *stFileName, char *buffer, int nLen)
{
    FILE *fp = NULL;
    int count = 0;

    if(NULL == stFileName || NULL == buffer)
        return ERROR_NULL;

    fp = file_fopen(stFileName, "tb+");
    if(NULL == fp)
        return ERROR_OPEN;

    count = file_fwrite(fp, buffer, nLen);
    if(count < 0)
        return ERROR_WRITE;

    file_fclose(fp);
    return SUCCESS;
}

void __logPrint(const char *func, const int line, int level, char *chMsg, ...)
{
    #if 1
    va_list args;
    char chFormat[MAX_STRING_32];
    char chLogFilePath[MAX_STRING_256];
    char chLogNewFilePath[MAX_STRING_256];
    char chCurTime[MAX_STRING_64];
    long nMaxLogFileSize = 0;
    int len = 0;
    int nLogLevel = 0;
    int nFileSize = 0;

    nLogLevel = get_current_log_level();
    if(nLogLevel < level)
        return;

    memset(chFormat, 0, MAX_STRING_32);
    sprintf(chFormat, "[%s %d] ", func, line);
    va_start(args, chMsg);
    len = strlen(chFormat);
    vsprintf(chFormat + len, chMsg, args);
    va_end(args);

    memset(chLogFilePath, 0, MAX_STRING_256);
    memset(chLogNewFilePath, 0, MAX_STRING_256);
    memset(chCurTime, 0, MAX_STRING_64);
    get_default_config(CONFIG_LOG_FILE_PATH, chLogFilePath);
    get_default_config(CONFIG_MAX_LOG_SIZE, &nMaxLogFileSize);
    get_Current_Time(chCurTime, TIME_CONNECT);
    sprintf(chLogNewFilePath, "%s-%s", chLogFilePath, chCurTime);

    if(0 == g_log_show_method)
        printf("%s", chFormat);
    else
    {
        nFileSize = get_file_size(chLogFilePath);
        if(nFileSize > nMaxLogFileSize)
        {
            file_rename(chLogFilePath, chLogNewFilePath);
        }

        set_log_write_file(chLogFilePath, chFormat, strlen(chFormat) + 1);
    }
    
    #endif
}