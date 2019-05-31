#include "func_file.h"

ST_DEFAULT_CONFIG g_default_config;

/* get file size */
long get_file_size(const char *chFileName)
{
    FILE *fp = NULL;
    long length = 0;

    fp = fopen(chFileName, "rb");
    if(NULL == fp)
        return length;

    fseek(fp, 0, SEEK_END);
    length = ftell(fp);
    
    fclose(fp);
    return length;
}

void file_delete(const char *chFileName)
{
    if(NULL == chFileName)
        return;

    remove(chFileName);
}

void file_rename(const char *chOldFileName, const char *chNewFileName)
{
    if(NULL == chOldFileName || NULL == chNewFileName)
        return;

    rename(chOldFileName, chNewFileName);
}

FILE *file_fopen(const char *chFileName, const char *mode)
{
    FILE *fp = NULL;
    if(NULL == chFileName || NULL == mode)
        return NULL;

    fp = fopen(chFileName, mode);
    if(NULL == fp)
        return NULL;

    return fp;
}

void file_fclose(FILE *fp)
{
    if(NULL == fp)
        return;

    fclose(fp);
}

size_t file_fread(FILE *fp, char *buffer, int nLen)
{
    size_t conut = 0;
    conut = fread(buffer, 1, nLen, fp);
    return conut;
}

size_t file_fwrite(FILE *fp, char *buffer, int nLen)
{
    size_t count = 0;
    count = fwrite(buffer, 1, nLen, fp);
    return count;
}

int set_default_config(ENUM_DEFAULT_CONFIG item, void *pValue)
{
    switch(item)
    {
        case CONFIG_LOG_METHOD:
            g_default_config.nLogMethod = *(int *)pValue;
            break;
        case CONFIG_LOG_LEVEL:
            g_default_config.nLogLevel = *(int *)pValue;
            break;
        case CONFIG_LOG_FILE_PATH:
            strcpy(g_default_config.chLogFilePath, pValue);
            break;
        case CONFIG_MAX_LOG_SIZE:
            g_default_config.nMaxLogFileSize = *(long *)pValue;
            break;
    }

    return SUCCESS;
}

int get_default_config(ENUM_DEFAULT_CONFIG item, void *pValue)
{
    switch(item)
    {
        case CONFIG_LOG_METHOD:
            *(int *)pValue = g_default_config.nLogMethod;
            break;
        case CONFIG_LOG_LEVEL:
            *(int *)pValue = g_default_config.nLogLevel;
            break;
        case CONFIG_LOG_FILE_PATH:
            strcpy(pValue, g_default_config.chLogFilePath);
            break;
        case CONFIG_MAX_LOG_SIZE:
            *(long *)pValue = g_default_config.nMaxLogFileSize;
            break;
    }

    return SUCCESS;
}

int get_default_config_file()
{
    FILE *fp = NULL;
    int count = 0;
    char buffer[MAX_STRING_1024];
    char value[MAX_STRING_256];
    char changeValue[MAX_STRING_256];
    int nData;
    long nLongData;

    fp = file_fopen(DEFAULT_CONFIG_PATH, "r");
    if(NULL == fp)
        return ERROR_OPEN;

    while(!feof(fp))
    {
        memset(buffer, 0, MAX_STRING_1024);
        memset(value, 0, MAX_STRING_256);
        memset(changeValue, 0, MAX_STRING_256);
        fgets(buffer, 1024, fp);
        if(buffer[0] == '\0' || buffer[0] == '#')
            continue;

        //printf("%s\n", buffer);
        if(0 == string_find(buffer, "LOG_METHOD=", value))
        {
            trim(value, changeValue);
            nData = atoi(changeValue);
            set_default_config(CONFIG_LOG_METHOD, &nData);
        }
        else if(0 == string_find(buffer, "lOG_LEVEL=", value))
        {
            trim(value, changeValue);
            nData = atoi(changeValue);
            set_default_config(CONFIG_LOG_LEVEL, &nData);
        }
        else if(0 == string_find(buffer, "LOG_FILE_PATH=", value))
        {
            trim(value, changeValue);
            set_default_config(CONFIG_LOG_FILE_PATH, changeValue);
        }
        else if(0 == string_find(buffer, "MAX_FILE_SIZE=", value))
        {
            trim(value, changeValue);
            nLongData = atol(changeValue);
            set_default_config(CONFIG_MAX_LOG_SIZE, &nLongData);
        }
    }

    file_fclose(fp);
    return SUCCESS;
}