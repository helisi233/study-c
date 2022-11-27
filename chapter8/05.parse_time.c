//
// Created by helisi on 2022/11/22.
//
#include "include/io_utils.h"
#include "include/time_utils.h"

int main() {
    /*
     *  unix环境posix标准对C标准进行了扩展 strptime()
     *  char *time = "2020-11-10 06:30:32.123"; .123表示毫秒
     *  struct tm parsed_time;
     *  char *unparsed_string = strptime(time, "%F %T", &parsed_time);
     *  puts(unparsed_string);
     *  int millisecond;
     *  sscanf(unparsed_string, ".%3d", &millisecond);
     *  PRINT_INT(millisecond);
     * */

    char *time = "2020-11-10 06:30:32.123";
    struct tm parsed_time;
    int millisecond;
    sscanf(time, "%4d-%2d-%2d %2d:%2d:%2d.%3d",
            &parsed_time.tm_year,
           &parsed_time.tm_mon,
           &parsed_time.tm_mday,
           &parsed_time.tm_hour,
           &parsed_time.tm_min,
           &parsed_time.tm_sec,
           &millisecond);
    parsed_time.tm_year -= 1900;
    parsed_time.tm_mon -= 1;
    mktime(&parsed_time);

    PRINT_INT(parsed_time.tm_year);
    PRINT_INT(parsed_time.tm_mon);
    PRINT_INT(parsed_time.tm_mday);
    PRINT_INT(parsed_time.tm_hour);
    PRINT_INT(parsed_time.tm_min);
    PRINT_INT(parsed_time.tm_sec);
    PRINT_INT(millisecond);

    return 0;
}