#ifndef __FUNC_COMM_H__
#define __FUNC_COMM_H__

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/* current support: 32, 64 */
#define SYSTEM_BIT  64
#define DEFAULT_CONFIG_PATH "config/default_config"

/* 32bit system: int 4byte; 64bit system: int 8byte*/
#define MAX_MINI_STRING     (SYSTEM_BIT / 8)
#define SYSTEM_NUMBER       (64 / SYSTEM_BIT)
#define MAX_STRING_16       (MAX_MINI_STRING * SYSTEM_NUMBER * (1 << 1))
#define MAX_STRING_32       (MAX_MINI_STRING * SYSTEM_NUMBER * (1 << 2))
#define MAX_STRING_64       (MAX_MINI_STRING * SYSTEM_NUMBER * (1 << 3))
#define MAX_STRING_128      (MAX_MINI_STRING * SYSTEM_NUMBER * (1 << 4))
#define MAX_STRING_256      (MAX_MINI_STRING * SYSTEM_NUMBER * (1 << 5))
#define MAX_STRING_512      (MAX_MINI_STRING * SYSTEM_NUMBER * (1 << 6))
#define MAX_STRING_1024     (MAX_MINI_STRING * SYSTEM_NUMBER * (1 << 7))
#define MAX_STRING_2048     (MAX_MINI_STRING * SYSTEM_NUMBER * (1 << 8))

#define SUCCESS 0
#define TRUE 0
#define FALSE -1

typedef struct 
{
    int nErrorNum;
    char chErrorStr[MAX_STRING_128];
}ST_ERROR_STRING;

typedef struct 
{
    int nLogMethod;
    int nLogLevel;
    char chLogFilePath[MAX_STRING_256];
    long nMaxLogFileSize;
}ST_DEFAULT_CONFIG;

typedef enum
{
    CONFIG_LOG_METHOD,
    CONFIG_LOG_LEVEL,
    CONFIG_LOG_FILE_PATH,
    CONFIG_MAX_LOG_SIZE,
}ENUM_DEFAULT_CONFIG;

typedef enum
{
    ERROR_NULL = 1,
    ERROR_OUT_OF_RANGE,
    ERROR_OPEN,
    ERROR_WRITE,
    ERROR_READ,
    ERROR_FAIL,
    ERROR_END,
}ENUM_ERROR_LEVEL;

static ST_ERROR_STRING stErrorString[] = {
    {ERROR_NULL, "input string is null point"},
    {ERROR_OUT_OF_RANGE, "input number out of range"},
    {ERROR_OPEN, "file open failed"},
    {ERROR_WRITE, "file write failed"},
    {ERROR_READ, "file read failed"},
    {ERROR_FAIL, "failed"}
};

extern void get_Error_String(int nErrorNum, char *chErrorStr);
extern int string_find(char *source, char *target, char *value);
extern void trim(char *strIn, char *strOut);

#endif