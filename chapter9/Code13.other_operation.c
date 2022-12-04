//
// Created by helisi on 2022/12/1.
//
#include <stdio.h>
#include <io.h>
#include <sys/stat.h>
#include "include/io_utils.h"

/*
 *  stat结构体
 *  struct stat {
    _dev_t st_dev;
    _ino_t st_ino;
    unsigned short st_mode;
    short st_nlink;
    short st_uid;
    short st_gid;
    _dev_t st_rdev;
    _off_t st_size;
    time_t st_atime;
    time_t st_mtime;
    time_t st_ctime;
  };
  在windows尚不支持4GB以上文件 因为windows上面long类型4字节 最多能表示4GB
 * */
long GetFileSize(char const *filename) {
    struct stat st;
    stat(filename, &st);
    return st.st_size;
}

int IsDirectory(char const *filename) {
    struct stat st;
    stat(filename, &st);
    return st.st_mode & S_IFDIR;
}

int main() {

    /*
     *  其他文件操作
     *  删除文件    remove(char const *filename)
     *      返回0 删除成功
     *      返回1 删除失败
     *  重命名     rename(oldfilepath, newfilepath)
     *  设置处理文件的编码   setlocale(LC_ALL, "zh_CN.utf-8")
     *  创建临时文件 使用后直接删除
     * */
//    int result = remove("output.log");
//    PRINT_INT(result);
//    int result2 = remove("output.log");
//    PRINT_INT(result);

    rename("test.bin", "t.bin");

//    FILE *file = tmpfile();
//    WinFile *winFile = (WinFile *)file;
//    puts(winFile -> tmpfname);
//    fclose(file);

    return 0;
}