//
// Created by duhao on 24-5-20.
//
int time=0;//时间戳
int hour1=0;//hh:mm:ss时间-第1位
int hour2=0;//hh:mm:ss时间-第2位
int minute1=0;//hh:mm:ss时间-第3位
int minute2=0;//hh:mm:ss时间-第4位
int second1=0;//hh:mm:ss时间-第5位
int second2=0;//hh:mm:ss时间-第6位
int foodnumber=0;//餐品种类数量
int combnumber=0;//套餐种类数量
int ordenumber=0;//订单数量
int allowmax=0;//系统关闭订单量w1
int allowmin=0;//系统恢复订单量w2
int remainorder=0;//进行中订单量
int systemstate=1;//系统开启情况，0关闭，1开启。

//建立临时变量
int i=0;
int j=0;
int k=0;
char ch[50]={0};
char c=0;
struct combinationlink *combinationlinknewp;
struct combinationlink *combinationlinkcurp;
struct orderlink *orderlinknewp;
struct orderlink *orderlinkcurp;
