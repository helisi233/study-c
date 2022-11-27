//
// Created by helisi on 2022/11/27.
//
#include <stdio.h>
#include "include/io_utils.h"

#define ERROR 0
#define OK 1

typedef struct {
    int visibility;
    int allowNotification;
    int refreshRate;
    int region;
    int fontSize;
} Settings;

void PrintSettings(Settings *settings) {
    PRINT_INT(settings -> visibility);
    PRINT_INT(settings -> allowNotification);
    PRINT_INT(settings -> refreshRate);
    PRINT_INT(settings -> region);
    PRINT_INT(settings -> fontSize);
}

int SaveSettings(Settings *settings, char *settingsFile) {
    FILE *file = fopen(settingsFile, "wb");
    if(file) {
        fwrite(&settings -> visibility, sizeof(settings -> visibility), 1, file);
        fwrite(&settings -> allowNotification, sizeof(settings -> allowNotification), 1, file);
        fwrite(&settings -> refreshRate, sizeof(settings -> refreshRate), 1, file);
        fwrite(&settings -> region, sizeof(settings -> region), 1, file);
        fwrite(&settings -> fontSize, sizeof(settings -> fontSize), 1, file);
        fclose(file);
        return OK;
    }else {
        perror("Failed to save settings");
        return ERROR;
    }
}

void LoadingSettings(Settings *settings, char *settingsFile) {
    FILE *file = fopen(settingsFile, "rb");
    if(file) {
        fread(&settings -> visibility, sizeof(settings -> visibility), 1, file);
        fread(&settings -> allowNotification, sizeof(settings -> allowNotification), 1, file);
        fread(&settings -> refreshRate, sizeof(settings -> refreshRate), 1, file);
        fread(&settings -> region, sizeof(settings -> region), 1, file);
        fread(&settings -> fontSize, sizeof(settings -> fontSize), 1, file);
        fclose(file);
    }else {
        settings -> visibility = 1;
        settings -> allowNotification = 1;
        settings -> refreshRate = 30;
        settings -> region = 86;
        settings -> fontSize = 18;
    }
}

int main() {
    Settings settings;
    LoadingSettings(&settings, "test.bin");
    PrintSettings(&settings);
    settings.fontSize = 40;
    settings.allowNotification = 2;
    SaveSettings(&settings, "test.bin");
    return 0;
}















