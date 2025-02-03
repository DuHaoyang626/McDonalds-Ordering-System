#include<iostream>
#include<easyx.h>
using namespace std;

int main()
{
    initgraph(640, 480);

    IMAGE bk;

    loadimage(&bk, _T("IMAGE"), _T("P"), 640, 480);//从资源文件载入图片到bk

    putimage(0, 0, &bk);

    system("pause");
    return 0;
}

