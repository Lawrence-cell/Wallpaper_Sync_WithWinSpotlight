/*
 * @Author: lawrence-cell 850140027@qq.com
 * @Generate Date: Do not edit
 * @LastEditors: lawrence-cell 850140027@qq.com
 * @LastEditTime: 2022-06-29 15:17:47
 * @FilePath: \wallpapar_sync\main.cpp
 * @Description:
 *
 * Copyright (c) 2022 by lawrence-cell 850140027@qq.com, All Rights Reserved.
 */
#include <stdio.h>
#include <Windows.h>
#include <unistd.h>
#include "src/yg/Directory.h"

// void copyDir()
// {
//     char *source = "C:\\Users\\yangguang\\AppData\\Local\\Packages\\Microsoft.Windows.ContentDeliveryManager_cw5n1h2txyewy\\LocalState\\Assets"; //源文件
//     char *destination = "c://padcopy.exe";                                                                                                       //目标文件
//     copy(source, destination);                                                                                                                   // false代表覆盖，true不覆盖
// }

int main()
{
    std::string src = "C:\\Users\\yangguang\\AppData\\Local\\Packages\\Microsoft.Windows.ContentDeliveryManager_cw5n1h2txyewy\\LocalState\\Assets\\*";
    std::string des;

    des = getcwd(NULL, 0);
    des += "\\images";
    Directory sourceDir(src);
    std::string imageName = sourceDir.SortandChoose();

    std::string abs_path = "C:\\Users\\yangguang\\AppData\\Local\\Packages\\Microsoft.Windows.ContentDeliveryManager_cw5n1h2txyewy\\LocalState\\Assets\\";
    abs_path += imageName;

    PVOID64 *path = (PVOID64 *)abs_path.c_str();

    if (SystemParametersInfo(SPI_SETDESKWALLPAPER, 0, path, SPIF_SENDCHANGE | SPIF_UPDATEINIFILE))
    {
        printf("更换成功!\\n");
    }
    else
    {
        printf("更换失败\\n");
    }
    return 0;
}
