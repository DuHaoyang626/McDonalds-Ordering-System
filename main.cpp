#include <graphics.h>              // 引用图形库头文件
#include <conio.h>
#include <stdio.h>
#include <windows.h>				//用到了定时函数sleep()
#include <math.h>

int main()
{
    int i;
    short win_width,win_height;//定义窗口的宽度和高度
    win_width = 480;win_height = 360;
    initgraph(win_width,win_height);//初始化窗口（黑屏）
    for(i=0;i<256;i+=5)
    {
        setbkcolor(RGB(i,i,i));//设置背景色，原来默认黑色
        cleardevice();//清屏（取决于背景色）
        Sleep(15);//延时15ms
    }
    closegraph();//关闭绘图界面
}