//
// Created by helisi on 2022/11/23.
//
#include <stdio.h>
#include <errno.h>
#include <string.h>

int main() {
    /*
     *  标准输入输出流
     *  stdout  标准输出
     *  stdin   标准输入
     *  stderr  标准错误
     *
     *  fopen(路径,对文件的操作)
     *  r   读   文件已经存在从头开始读     文件不存在打开失败
     *  w   写   文件已经存在就覆写文件     文件不存在创建新的
     *  a   追加  从文件末尾开始写          文件不存在创建新的
     *  r+  读/写 文件已经存在从头开始读     error
     *  w+  读/写 文件已经存在就覆写文件     文件不存在创建新的
     *  a+  读/写 从文件末尾开始写          文件不存在创建新的
     *
     *  如果在windows环境中，可以加上b，表示用二进制的方式处理文件，忽略'\n'和'\x1A'
     *  这两个字符，否则会将\n处理为换行符，而\x1A被处理为ctrl+z，windows环境中的ctrl+z
     *  是文件结束符
     * */
    FILE *file = fopen("CMakeLists.txt", "r");
    if(file != NULL) {
        puts("fopen successfully");
        /*
         *  ferror(FILE*) 获取文件错误码
         *  返回0 没有错误
         * */
        int err = ferror(file);
        printf("err: %d\n", err);
        /*
         *  feof(FILE*) 判断文件是否读取完毕
         *  返回0 没有结束
         * */
        int eof = feof(file);
        printf("eof: %d\n", eof);

        /*
         *  文件处理完必须要关闭，不继续占用系统资源
         * */
        fclose(file);
    }else {
        perror("fopen");
        /*
         *  #include<string.h>的strerror函数用来打印errno对应的异常信息
         * */
        strerror(errno);
    }

//    for (int i = 0; i < 10; ++i) {
//        printf("%d ", i);
//        puts(strerror(i));
//    }

    return 0;
}
















