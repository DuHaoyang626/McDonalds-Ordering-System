//
// Created by duhao on 24-5-19.
//

#ifndef MCDONALDS_ORDERING_SYSTEM_MULTFILE_V1_0_VARIABLE_H
#define MCDONALDS_ORDERING_SYSTEM_MULTFILE_V1_0_VARIABLE_H

#endif //MCDONALDS_ORDERING_SYSTEM_MULTFILE_V1_0_VARIABLE_H
struct foodkind {//食物种类
    char name[50];//名称
    int number;//当前数量
    int max;//最大数量
    int currenttime;//当前已制作时间
    int needtime;//制作所需时间
};
struct combinationlink {//套餐对应链表
    struct foodkind *link;//对应餐品种类
    struct combinationlink *next;//下一餐品
};
struct combination {//套餐
    char name[50];//名称
    int kindnumber;//餐品数量
    struct combinationlink *kind;//餐品名称
};
struct orderlink {//订单对应链表
    struct foodkind *link;//对应餐品种类
    int provided;//是否已提供餐品
    struct orderlink *next;//下一餐品
};
struct order {//订单
    int begintime;//开始时间
    int finishtime;//结束时间
    int remainfoodnumber;//未完成餐品数量
    int state;//订单状态：0未开始，1进行中，2成功，3失败
    struct orderlink *kind;//餐品详情
};

extern int time;//时间戳
extern int hour1;//hh:mm:ss时间-第1位
extern int hour2;//hh:mm:ss时间-第2位
extern int minute1;//hh:mm:ss时间-第3位
extern int minute2;//hh:mm:ss时间-第4位
extern int second1;//hh:mm:ss时间-第5位
extern int second2;//hh:mm:ss时间-第6位
extern int foodnumber;//餐品种类数量
extern int combnumber;//套餐种类数量
extern int ordenumber;//订单数量
extern int allowmax;//系统关闭订单量w1
extern int allowmin;//系统恢复订单量w2
extern int remainorder;//进行中订单量
extern int systemstate;//系统开启情况，0关闭，1开启。

//建立临时变量
extern int i;
extern int j;
extern int k;
extern char ch[50];
extern char c;
extern struct combinationlink *combinationlinknewp;
extern struct combinationlink *combinationlinkcurp;
extern struct orderlink *orderlinknewp;
extern struct orderlink *orderlinkcurp;
