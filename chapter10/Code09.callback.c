//
// Created by helisi on 2022/12/4.
//
#include "include/io_utils.h"
#include "include/time_utils.h"
#include "tinycthread/include/tinycthread.h"

/*
 *  并发任务执行与函数回调
 *  在线程中异步调用函数 使用回调的方式通知主线程
 * */
typedef struct Context {
    mtx_t mutex;
    int download_left;  // 剩余下载数
} Context;

typedef struct DownloadRequest {
    Context *context;
    char const *url;
    char const *filename;
    int progress;
    int interval;   // 模拟进度
    // callback指针 指向一个参数时DownloadRequest *的函数
    void (*callback)(struct DownloadRequest *);
} DownloadRequest;

int DownloadFile(DownloadRequest *request) {
    PRINTLNF("\rDownloading file from: %s into %s ...", request -> url, request -> filename);
    for (int i = 0; i < 1000000; ++i) {
        request -> progress = i;
        SleepMs(request -> interval);
    }
    request -> callback(request);
    return 0;
}

void DownloadCallback(DownloadRequest *request) {
    mtx_lock(&(request -> context -> mutex));

    request -> context -> download_left --;

    PRINTLNF("\rDownload file from: %s into %s successfully, left: %d",
            request -> url,
            request -> filename,
            request -> context -> download_left);

    mtx_unlock(&(request -> context -> mutex));
}

#define DOWNLOAD_TASKS 5

int main() {

    char *urls[] = {
            "https://www.helisi.com/file1",
            "https://www.helisi.com/file2",
            "https://www.helisi.com/file3",
            "https://www.helisi.com/file4",
            "https://www.helisi.com/file5"
    };

    char *filenames[] = {
            "downloads/file1",
            "downloads/file2",
            "downloads/file3",
            "downloads/file4",
            "downloads/file5"
    };

    DownloadRequest requests[DOWNLOAD_TASKS];
    Context context = {.download_left = DOWNLOAD_TASKS};
    mtx_init(&context.mutex, mtx_plain);

    for (int i = 0; i < DOWNLOAD_TASKS; ++i) {
        requests[i] = (DownloadRequest) {
          .context = &context,
          .url = urls[i],
          .filename = filenames[i],
          .progress = 0,
          .interval = i * 50 + 100,
          .callback = DownloadCallback
        };
        // 每一个任务启动一个线程下载 避免阻塞
        thrd_t t;
        thrd_create(&t, DownloadFile, &requests[i]);
        thrd_detach(t);
    }

    while(1) {
        mtx_lock(&context.mutex);
        int download_left = context.download_left;
        mtx_unlock(&context.mutex);
        if(download_left == 0) {
            break;
        }
        printf("\r");

        for (int i = 0; i < DOWNLOAD_TASKS; ++i) {
            printf("%s -- %3d%% \t", requests[i].filename, requests[i].progress);
        }

        fflush(stdout);
        SleepMs(100);
    }

    mtx_destroy(&context.mutex);

    return 0;
}