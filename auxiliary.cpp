//
// Created by duhao on 24-5-19.
//
#include<stdio.h>
#include<string.h>
#include "variable.h"
int correctfood(char ch[],struct foodkind food[],int foodnumber) {//返回餐品名称ch对应序号
    int n;
    for(n=0;n<foodnumber;n++) {
        if(strcmp(ch,food[n].name)==0)
            return n;
    }
}
int correctcomb(char ch[],struct combination comb[],int combnumber) {//返回套餐名称ch对应序号
    int n;
    for(n=0;n<combnumber;n++) {
        if(strcmp(ch,comb[n].name)==0)
            return n;
    }
}
int timeread() {//将hh:mm:ss时间转化为时间戳
    int hour=0,minute=0,second=0,time=0;
    scanf("%d:%d:%d",&hour,&minute,&second);
    time=second+60*minute+3600*hour;
    return time;
}
