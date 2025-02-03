#include"EasyX/include/graphics.h"// 引用图形库头文件
#include<stdio.h>
int main()
{
    initgraph(640, 480);
    setbkcolor(WHITE);
    cleardevice();
    char time[9];
    time[0] = '0';
    time[1] = '7';
    time[2] = ':';
    time[3] = '0';
    time[4] = '7';
    time[5] = ':';
    time[6] = '0';
    time[7] = '7';
    time[8] = '\0';
    char str[500]="";
    sprintf_s(str, "%s", time);
    printf("%s\n%s", str, time);
    settextcolor(RED);
    outtextxy(100, 250,time);
    while (true);
    closegraph();
}