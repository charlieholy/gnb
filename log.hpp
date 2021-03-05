#include <iostream>
#include <sys/time.h>
using namespace std;

#define LOGO(COLOR, LEVEL, FMT, ...)                                                                      \
    do                                                                                                    \
    {                                                                                                     \
        struct timeval tv;                                                                                \
        gettimeofday(&tv, NULL);                                                                          \
        time_t now;                                                                                       \
        char szTime[32];                                                                                  \
        time(&now);                                                                                       \
        int lenDT = strftime(szTime, sizeof(szTime), "%Y-%m-%d %H:%M:%S", localtime(&now));               \
        snprintf(szTime + lenDT, sizeof(szTime) - lenDT, ".%06ld", tv.tv_usec);                           \
        fprintf(stdout, "%s%s [%s] %s:%d " FMT, COLOR, szTime, LEVEL, __FILE__, __LINE__, ##__VA_ARGS__); \
        fflush(stdout);                                                                                   \
    } while (0)

#define LOGD(fmt, ...) LOGO("\033[0;33;40m", "DEBUG", fmt, ##__VA_ARGS__)
#define LOGI(fmt, ...) LOGO("\033[0;32;40m", "INFO ", fmt, ##__VA_ARGS__)
#define LOGE(fmt, ...) LOGO("\033[0;31;40m", "ERROR", fmt, ##__VA_ARGS__)
