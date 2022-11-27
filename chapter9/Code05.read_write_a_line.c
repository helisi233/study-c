//
// Created by helisi on 2022/11/26.
//
#include <stdio.h>

void Echo() {
    char buffer[1024];
    while(1) {
        if(!gets_s(buffer, 1024)) {
            break;
        }
//        puts(buffer);   puts会自动输出一个换行符
        printf("%s", buffer);
    }
}

int main() {

    char buffer[1024];
    gets_s(buffer, 1024);
    fgets(buffer, 1024, stdin);
    puts(buffer);
    fputs(buffer, stdout);

    return 0;
}