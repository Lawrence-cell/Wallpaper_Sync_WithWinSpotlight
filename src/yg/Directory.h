/*
 * @Author: lawrence-cell 850140027@qq.com
 * @Generate Date: Do not edit
 * @LastEditors: lawrence-cell 850140027@qq.com
 * @LastEditTime: 2022-06-29 15:21:36
 * @FilePath: \wallpapar_sync\src\yg\Directory.h
 * @Description:
 *
 * Copyright (c) 2022 by lawrence-cell 850140027@qq.com, All Rights Reserved.
 */
#include <stdio.h>
#include <io.h>
#include <string>
#include <vector>
#include <iostream>
#include <cstdlib>
#include <time.h>

class Directory
{
private:
    std::vector<_finddata_t> mFileList;

public:
    Directory(std::string path);

    /**
     * @description: for test
     * @return {*}
     */
    void Print();

    std::string SortandChoose();
};
