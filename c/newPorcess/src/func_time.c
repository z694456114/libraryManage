#include "func_time.h"

void get_Current_Time(char *chTimeStr, int format)
{
    time_t unRawTime;
    struct tm *stTimeInfo = NULL;

    time(&unRawTime);
    stTimeInfo = localtime(&unRawTime);
    switch(format)
    {
        case TIME_APART:
            sprintf(chTimeStr, "%04d-%02d-%02d %02d:%02d:%02d",
                    (stTimeInfo->tm_year + 1900), stTimeInfo->tm_mon, stTimeInfo->tm_mday,
                    stTimeInfo->tm_hour, stTimeInfo->tm_min, stTimeInfo->tm_sec);
            break;
        case TIME_CONNECT:
            sprintf(chTimeStr, "%04d%02d%02d%02d%02d%02d",
                    (stTimeInfo->tm_year + 1900), stTimeInfo->tm_mon, stTimeInfo->tm_mday,
                    stTimeInfo->tm_hour, stTimeInfo->tm_min, stTimeInfo->tm_sec);
            break;
        default:
            sprintf(chTimeStr, "Not Found");
            break;
    }
}