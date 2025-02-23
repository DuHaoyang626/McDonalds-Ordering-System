#ifndef UNTITLED7_DICT_H
#define UNTITLED7_DICT_H

#include <bits/stdc++.h>
#include <QString>


typedef struct Order Order;
typedef struct Food Food;
typedef struct Combo Combo;
typedef struct ReachTime ReachTime;
typedef struct OrderNode OrderNode;

#define MAX_NAME (50+1)
#define MAX_COMBO_FOOD 5

struct ReachTime{
    int hour;
    int minute;
    int second;
};

struct Food{
    char name[MAX_NAME];//食物名称
    int maxCapacity;//最大容量
    int stock;//当前库存
    int productionTime;//生产时间
    int currentPTime;//当前生产时间
    int isProducing;//是否正在生产
};

struct Combo{
    char name[MAX_NAME];//套餐名称
    Food* requestFoods[MAX_COMBO_FOOD];//所需的食物
    int rqCount;//所需的食物数量
};

struct Order{
    char name[MAX_NAME];//订单名称
    char foods_name[MAX_COMBO_FOOD][MAX_NAME];//所需的食物列表
    int isGetFood[MAX_COMBO_FOOD];//表示食物是否获取成功
    int rqCount;//所需食物的种类数
    int isCompleted;//订单是否完成，0表示完成，1表示未完成，2表示订单被抛弃
    ReachTime tr;//订单到达时间
    ReachTime tr2;//订单完成时间
};

//获取食物
Food* getFood(int &Count);
//获取套餐
Combo* getCombo(int &Count);
//查找食物
Food* findFood(const char* name);
//查找套餐
Combo* findCombo(const char* name);
//初始化dict的数据
void init1(void);
//更新所有需要制作的食物列表
void updateMakeFoods();
//递增时间
void incrementTime(ReachTime* t);
int isEqualReachTime(ReachTime* t1,ReachTime* t2);
ReachTime stringChangeReachTime(const char*str);
ReachTime stringChangeReachTime(QString time);
//制作所有没达到最大库存的食物
void makeAllFoods();
//判断麦当劳是否可以关店（超过22点00分00秒）
int isCanClosed(ReachTime* t);
//获取当前未完成订单数量
int getCurrentOrdersCount(int f,int e);
//处理订单
Order* chuli(int count,std::string times[],std::string names[],std::string endtime);

#endif
