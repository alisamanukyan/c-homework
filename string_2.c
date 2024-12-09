#include <stdio.h>
#include <time.h>

int main() {
    time_t current_time;
    struct tm *time_info;

    time(&current_time);

    time_info = gmtime(&current_time);

    printf("Date: %04d-%02d-%02d\n", time_info->tm_year + 1900, time_info->tm_mon + 1, time_info->tm_mday);

    printf("Time: %02d:%02d:%02d\n", time_info->tm_hour, time_info->tm_min, time_info->tm_sec);

    return 0;
}