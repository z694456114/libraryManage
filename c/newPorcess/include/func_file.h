#ifndef __FUNC_FILE_H__
#define __FUNC_FILE_H__

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include "func_comm.h"
#include "func_log.h"

extern ST_DEFAULT_CONFIG g_default_config;

extern long get_file_size(const char *chFileName);
extern void file_delete(const char *chFileName);
extern void file_rename(const char *chOldFileName, const char *chNewFileName);
extern FILE *file_fopen(const char *chFileName, const char *mode);
extern void file_fclose(FILE *fp);
extern size_t file_fread(FILE *fp, char *buffer, int nLen);
extern size_t file_fwrite(FILE *fp, char *buffer, int nLen);
extern int set_default_config(ENUM_DEFAULT_CONFIG item, void *pValue);
extern int get_default_config(ENUM_DEFAULT_CONFIG item, void *pValue);
extern int get_default_config_file();
#endif