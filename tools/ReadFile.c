//
// Created by lmy on 2021-02-20.
//

#include "Tools.h"

char* readFile(char *path)
{
    char *buffer = NULL;
    int string_size;
    FILE *handler =fopen(path,"r");

    if(handler)
    {
        // 搜寻文件的最后一个字节
        fseek(handler, 0, SEEK_END);
        // 从第一个字节到最后一个字节的偏移量，即文件大小
        string_size = ftell(handler);
        // 返回文件的开头
        rewind(handler);

        // 分配一个可以容纳所有内容的字符串
        buffer = (char *) malloc(sizeof(char)*(string_size+1));

        // 一次读出所有内容
        fread(buffer, sizeof(char), string_size, handler);

        // fread()没有设置它，所以在最后一个位置放置\0
        // 现在缓冲区是一个字符串
        buffer[string_size] = '\0';

        // 关闭文件
        fclose(handler);
    }
    return buffer;
};