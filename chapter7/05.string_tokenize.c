//
// Created by helisi on 2022/11/14.
//
#include <stdlib.h>
#include <string.h>
#include "include/io_utils.h"

int main() {

    char string[] = "C, 1972; C++, 1983; Java, 1995; Rust, 2010; Kotlin, 2011";

    typedef struct language {
        char *name;
        int year;
    }Language;

    char *fieldTerminated = ",";
    char *languageTerminated = ";";

    int languageCapacity = 3;
    int languageSize = 0;

    Language *languages = malloc(sizeof(Language) * languageCapacity);
    if(languages == NULL) {
        abort();
    }

    // 需要拆分的字符串 将拆分字符串替换成NULL
    char *next = strtok(string, fieldTerminated);
    while(next != NULL) {
        Language language;
        language.name = next;
        next = strtok(NULL, languageTerminated);
        if(next != NULL) {
            language.year = atoi(next);
            if(languageSize + 1 >= languageCapacity) {
                languageCapacity *= 2;
                languages = realloc(languages, sizeof(Language) * languageCapacity);
                if(languages == NULL) {
                    abort();
                }
            }
            languages[languageSize++] = language;
        }
        next = strtok(NULL, fieldTerminated);
    }

    PRINTLNF("size: %d", languageSize);
    PRINTLNF("capacity: %d", languageCapacity);

    for (int i = 0; i < languageSize; ++i) {
        PRINTLNF("Language[name: %s, year: %d]", languages[i].name, languages[i].year);
    }

    free(languages);

    return 0;
}