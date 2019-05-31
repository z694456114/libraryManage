#include "func_comm.h"



void vGet_Error_String(int nErrorNum, char *chErrorStr)
{
    int i;
    int nFindStatus = 0;
    char chStr[MAX_STRING_128];

    if(NULL == chErrorStr)
    {
        printf("input string is null point\n");
        return;
    }

    if(nErrorNum < ERROR_NULL || nErrorNum >= ERROR_END)
    {
        printf("input number out of range\n");
        return;
    }

    memset(chStr, 0, MAX_STRING_128);
    for(i = ERROR_NULL; i < ERROR_END; i++)
    {
        if(stErrorString[i].nErrorNum == nErrorNum)
        {
            nFindStatus = 1;
            memcpy(chStr, stErrorString[i].chErrorStr, MAX_STRING_128);
            break;
        }
    }

    if(1 == nFindStatus)
        memcpy(chErrorStr, chStr, strlen(chStr) + 1);
    else
        memcpy(chErrorStr, "Not Found Error List", strlen("Not Found Error List") + 1);

    return;
}

/* KMP算法实现字符串查找 */ 
int string_find(char *source, char *target, char *value)
{ 
    int i = 0, j = 0; 
    int nFindStatus = 0;
    
    if(NULL == source || NULL == target)
        return FALSE;

    while(i <= strlen(source))
    { 
        if((source[i] == target[j]) && (j < strlen(target)))
        { 
            i++; 
            j++; 
        }
        else if(j >= strlen(target))
        { 
            nFindStatus = 1;
            break;
        }
        else if(source[i] != target[j])
        { 
            j = 0;
            i++;
        } 
    } 

    if(1 == nFindStatus)
    {
        memcpy(value, source + i, strlen(source) - i);
        return TRUE;
    }
    
    return FALSE; 
}

/* 去字符串首尾空格 */
void trim(char *strIn, char *strOut)
{
    int i, j;

    i = 0;
    j = strlen(strIn) - 1;

    while((strIn[i] == ' ') || strIn[i] == '\n')
        ++i;

    while((strIn[j] == ' ') || strIn[j] == '\n')
        --j;

    strncpy(strOut, strIn + i , j - i + 1);
    strOut[j - i + 1] = '\0';
}