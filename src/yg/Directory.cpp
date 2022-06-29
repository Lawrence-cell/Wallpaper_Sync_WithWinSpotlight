#include "Directory.h"

Directory::Directory(std::string path)
{
    // std::string inPath = "C:\\Program Files\\*"; //遍历文件夹下的所有文件
    //用于查找的句柄

    long long handle;
    struct _finddata_t fileinfo;
    //第一次查找
    handle = _findfirst(path.c_str(), &fileinfo);
    if (handle == -1)
        return;
    do
    {
        //找到的文件的文件名
        // printf("%s\n", fileinfo.name);
        mFileList.emplace_back(fileinfo);

    } while (!_findnext(handle, &fileinfo));

    _findclose(handle);
    // system("pause");
    // return 0;
}

std::string Directory::SortandChoose()
{
    srand((unsigned)time(NULL));
    for (int i = 0; i < mFileList.size(); i++)
    {
        for (int j = 0; j < mFileList.size() - i - 1; j++)
        {
            if (mFileList[j].size < mFileList[j + 1].size)
                std::swap(mFileList[j], mFileList[j + 1]);
        }
    }

    int k = 0;
    while (k < mFileList.size() && mFileList[k].size > 1100000)
    {
        k++;
    }

    for (int i = 0; i < k; i++)
    {
        for (int j = 0; j < k - i - 1; j++)
        {
            if (mFileList[j].time_create < mFileList[j + 1].time_create)
                std::swap(mFileList[j], mFileList[j + 1]);
        }
    }

    int m = 0;
    while (m < k && mFileList[m].time_create == mFileList[0].time_create)
    {
        m++;
    }
    int randomChoose;
    randomChoose = (int)m * rand() / (RAND_MAX + 1); //有bug 只随机一次不是随机的
    randomChoose = (int)m * rand() / (RAND_MAX + 1);

    return mFileList[randomChoose].name;
}

void Directory::Print()
{

    for (int i = 0; i < mFileList.size(); i++)
    {
        std::cout << mFileList[i].size << std::endl;
    }
}