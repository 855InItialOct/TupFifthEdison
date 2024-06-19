#define _CRT_SECURE_NO_WARNINGS

#define __STDC_LIB_EXT1__ 1

#include <stdio.h>
#include <locale.h>
#include <conio.h>
#include <time.h>
#include <windows.h>

// #define WIN64
// #ifdef WIN64
// #else
// #include <sys/time.h>
// #endif
// #ifdef WIN64
// #endif

int gettimeofday(struct timeval *tv, void *tz)
{
    time_t clock;
    struct tm tm_;
    SYSTEMTIME wtm;
    GetLocalTime(&wtm);
    tm_.tm_year = wtm.wYear - 1900;
    tm_.tm_mon = wtm.wMonth - 1;
    tm_.tm_mday = wtm.wDay;
    tm_.tm_hour = wtm.wHour;
    tm_.tm_min = wtm.wMinute;
    tm_.tm_sec = wtm.wSecond;
    tm_.tm_isdst = -1;
    clock = mktime(&tm_);
    tv->tv_sec = clock;
    tv->tv_usec = wtm.wMilliseconds * 1000;
    return 0;
}

int main()
{
    // struct tm t = {0, 0, 0, 0, 0, 0, 0, 0, 0};
    // time_t now;
    // time(&now);
    // localtime_s(&t, &now);
    // printf("现在是当地时间\n");
    // printf("%02d:%02d:%02d\n", t.tm_hour, t.tm_min, t.tm_sec);
    // printf("%04d/%02d/%02d\n", t.tm_year + 1900, t.tm_mon + 1, t.tm_mday);
    // printf("今天是周%d,是这一年中的第%d天。\n", t.tm_wday, t.tm_yday + 1);

    //     clock_t start, end;
    //     start = clock();
    //     time_t time0 = time(NULL);
    // #ifdef __STDC_LIB_EXT1__
    //     // char str[26];
    //     // ctime_s(str, sizeof(str), &time0);
    //     char str[80];
    //     const struct tm *info = localtime(&time0);
    //     // setlocale(LC_ALL, "zh-CN");
    //     strftime(str, sizeof(str), "现在是%Z时区%Y年%m月%d日\n星期%w\n%H:%M:%S%p", info); // 将其中一个 strftime 函数与从 gmtime 返回的 tm 指针一起使用时，通过 %Z 和 %z 说明符打印的值将不准确。 这是因为 C 标准指定的 tm 结构不包含时区名称或偏移量信息， 而是通过全局变量 _timezone 和 _dstbias 填充时区信息。
    //     printf("\n%s\n", str);
    // #endif
    //     end = clock();
    //     printf("本次程序运行了%.17f秒。\n", (double)(end - start) / CLOCKS_PER_SEC);

    // time_t time0;
    // char output[80];

    // while (!kbhit())
    // {
    //     time(&time0);
    //     const struct tm *pLocalTime = localtime(&time0);
    //     strftime(output, sizeof(output), "%H:%M:%S", pLocalTime);
    //     printf("%s\n", output);
    //     Sleep(500);
    // }

    time_t time0;
    struct timeval tv_;
    char output[20];

    while (!_kbhit())
    {
        time(&time0);
        const struct tm *pLocalTime = localtime(&time0);
        gettimeofday(&tv_, NULL);
        strftime(output, sizeof(output), "%H:%M:%S", pLocalTime);
        long tv_ms = tv_.tv_sec / 1000;
        long tv_us = tv_.tv_usec % 1000;
        printf("%s\t%ld:%ld\r", output, tv_ms / 10, tv_us / 10);
        Sleep(1);
    }
    return 0;
}
