#include "func_main.h"

void init_default_config()
{
    memset(&g_default_config, 0, sizeof(ST_DEFAULT_CONFIG));
    get_default_config_file();
}

void init_log()
{
    int nLogMethod = 0;
    int nLogLevel = 0;

    get_default_config(CONFIG_LOG_METHOD, &nLogMethod);
    get_default_config(CONFIG_LOG_LEVEL, &nLogLevel);
    set_log_method(nLogMethod);
    set_current_log_level(nLogLevel);
}

int main(int argc, char **argv)
{
    char chCurTime[2] = {0};

    /* 读取配置文件 default_config信息，更新全局变量配置 */
    init_default_config();

    /* 通过配置文件修改log配置信息 */
    init_log();

    get_Current_Time(chCurTime, TIME_APART);
    logPrint(LOG_DEBUG, "%s\n", chCurTime);
	return 0;
}
