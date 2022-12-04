//
// Created by helisi on 2022/11/28.
//
#include <io.h>
#include <stdio.h>
#include "include/io_utils.h"

void RedirectStdout(char const *filename) {
    static int saved_stdout = -1;
    if(filename) {  // 文件名不为空，期望将标准输出流重定向到这个文件
        if(saved_stdout == -1) {    // save_stdout=-1时，第一次执行 需要让saved_stdout获取到标准输出流的文件描述符
            saved_stdout = dup(fileno(stdout));
        }
        fflush(stdout);
        freopen(filename, "a", stdout); // 将标准输出 输出到文件
    }else { // 文件名为空，期望恢复标准输出流，输出到控制台
        if(saved_stdout != -1) {    // 标准输出流被重定向过
            fflush(stdout);
            // stdout已经指向了文件 需要重新指向控制台
            // 控制台在前面已经赋值给了saved_stdout
            dup2(saved_stdout, fileno(stdout));
            close(saved_stdout);    // 关闭saved_stdout
            saved_stdout = -1;  // 初始化
        }
        // saved_stdout没有被改变过，即stdout没有被改变输出方向
    }
}

int main() {

//    freopen("output.log", "a", stdout);
//    puts("This will be writeen to file 'output.log'"); // 正常是将字符串输出到控制台，重定向后字符串输出到output.log这个文件
//    fclose(stdout); // 关闭标准输出流，即不在输出到output.log文件这个文件

    puts("1");
    RedirectStdout("output.log");
    puts("2");
    RedirectStdout(NULL);
    puts("3");
    RedirectStdout("output.log");
    puts("4");
    RedirectStdout(NULL);
    puts("end");

    return 0;
}