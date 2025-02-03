#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <time.h>

const int Arrive = 0; //订单到了
const int Inproducetion = 1; //订单正在制作
const int Finished = 2; //订单已完成
const int DoingFail = 3; //订单制作失败

struct Time {
    int hour;
    int minute;
    int second;
};

struct Food {//食物的属性
    char FoodName[60];//食物名
    int ProdecetionTime;//制作时间
    int RemainTime;//剩余时间
    int MaxSpace;//最大存储量
    int CurrentSpace;//当前存储量
};

struct Order {//订单的属性
    struct Time OrderStartTime;//订单开始时间
    struct Time OrderEndTime;//订单结束时间
    int OrderStatus;//订单状态
    int OrderNeedFoodIndx[8];//订单需要的食物在食物列表里面对应的索引
    int OdrderNeedfoodNum;//订单需要的食物数量
};

struct TaoCan {//套餐的属性
    char TaoCanName[60];//套餐名
    int TaoCanNeedfoodIndx[8];//套餐需要的食物在食物列表里面对应的索引
    int TaoCanNeedfoodNum;//套餐需要的食物数量
};

struct Food FormFood[105] = { 0 };//食物表
struct TaoCan FormTaoCan[105] = { 0 };//套餐表
struct Order FormOrder[54005] = { 0 };//订单表

int AllnumFood = 0;//食物总数
int AllnumTaocan = 0;//套餐总数
int AllnumOrder = 0;//订单总数

int MaxnumOrder = 0;//最大订单数量
int MinnumOrder = 0;//最小订单数量

int ProcessnumOrder = 0;//系统正在处理的订单个数
int FinishnumOrder = 0;//系统完成的订单数量
int SystemReopen = 0;

int IsAcceptOrder = 1;//系统是否接单

struct Time SystemStartTime = { 6,59,59 };//系统开始的时间
struct Time FirstOrderStartTime = { 7,0,0 };//第一个订单开始的时间
struct Time AllOrdersEndTime = { 23,59,59 };//所有订单结束的时间
struct Time SystemStopTime = { 22,00,00 };//系统关闭时间

//每次加一秒，同时更新时间t
void addsecond(struct Time* t) {
    t->second++;
    if (t->second < 60) {
        return;
    }
    t->second -= 60;
    t->minute++;
    if (t->minute < 60) {
        return;
    }
    t->minute -= 60;
    t->hour++;
}

//如果t1 > t2，返回 1
int comp1(struct Time* t1, struct Time* t2) {
    return t1->hour > t2->hour ? 1 : (t1->hour < t2->hour ? -1 : (t1->minute > t2->minute ? 1 : (t1->minute < t2->minute ? -1 : (t1->second > t2->second ? 1 : -1))));
}

//如果t1 == t2,返回 1
int comp2(struct Time* t1, struct Time* t2)
{
    return t1->hour == t2->hour && t1->minute == t2->minute && t1->second == t2->second ? 1 : 0;
}

//根据食物名返回食物列表里其对应的索引
int returnNameFromFood(char* str) {
    int i = 0;
    while (i < AllnumFood) {
        if (strcmp(str, FormFood[i].FoodName) == 0) {
            return i;
        }
        i++;
    }
    return -1;
}

void making() {
    int i = 0;
    while (i < AllnumFood) {
        if (FormFood[i].CurrentSpace == FormFood[i].MaxSpace) {}
        else if (FormFood[i].RemainTime == 1) {//当前系统时间，该食物制作完成
            FormFood[i].CurrentSpace++;
            FormFood[i].RemainTime = FormFood[i].ProdecetionTime;
        }
        else {
            FormFood[i].RemainTime--;
        }
        i++;
    }
}

char* mgth(char* ch) {//忽略空格，获取下一个套餐名的开始
    int i = 0;
    while (ch[i] == ' ' || ch[i] == '\n' || ch[i] == '\t' || ch[i] == '\r') {
        i++;
    }
    return ch + i;
}

//订单索引：orderIdx,  i:食物列表食物的索引
void meetTheOrder(int orderIdx)
{
    int i = 0;
    while (i < AllnumFood) {

        if (FormFood[i].CurrentSpace - 1 < 0) {//该食物库存不足
            i++;
            continue;
        }

        int j = 0;
        int foodidx = -1;
        while (j < FormOrder[orderIdx].OdrderNeedfoodNum) {
            if (FormOrder[orderIdx].OrderNeedFoodIndx[j] == i) {//处理第(orderlist + orderIdx)个订单，返回该订单需要的食物在食物列表的索引
                foodidx = j;
                break;
            }
            j++;
        }

        if (foodidx == -1) {
            i++;
            continue;
        }

        FormOrder[orderIdx].OdrderNeedfoodNum--;
        for (int p = foodidx; p < FormOrder[orderIdx].OdrderNeedfoodNum; p++) {
            FormOrder[orderIdx].OrderNeedFoodIndx[p] = FormOrder[orderIdx].OrderNeedFoodIndx[p + 1];
        }
        FormFood[i].CurrentSpace--;

        if (FormOrder[orderIdx].OdrderNeedfoodNum == 0) {
            //订单需求已满足，无需遍历食物
            FinishnumOrder++;
            FormOrder[orderIdx].OrderEndTime = SystemStartTime;
            FormOrder[orderIdx].OrderStatus = Finished;
            break;
        }
        i++;
    }
}

//系统开始接单
void systemProcessOrders()
{
    //对于每个订单，从最早的订单开始，到当前已开始的订单截止
    int i = 0;
    while (i < AllnumOrder) {
        //订单刚开始
        if (FormOrder[i].OrderStatus == Arrive) {
            if (comp1(&SystemStartTime, &FormOrder[i].OrderStartTime) > 0 || comp2(&SystemStartTime, &FormOrder[i].OrderStartTime) == 1) {//系统开始的时间大于等于订单i开始的时间
                //订单刚到
                if (IsAcceptOrder) {//系统接单状态
                    ProcessnumOrder++;//系统正在处理的订单个数++
                    FormOrder[i].OrderStatus = Inproducetion;//更新订单i的状态为正在制作
                    meetTheOrder(i);
                    if (FormOrder[i].OrderStatus == Finished) {
                        //已经完成
                    }
                    else {
                        //不能马上完成
                        int undoing = ProcessnumOrder - FinishnumOrder;
                        if (undoing > MaxnumOrder) {
                            IsAcceptOrder = 0;
                        }
                    }
                }
                else {
                    FormOrder[i].OrderStatus = DoingFail;//系统若不接单，则订单i状态为制作失败
                }

            }
        }

        //如果订单的状态正在制作中，
        if (FormOrder[i].OrderStatus == Inproducetion) {
            //对于每一个有库存的食物，都需要去满足这份订单
            meetTheOrder(i);
            if (FormOrder[i].OrderStatus == Finished) {
                //已经完成
                int undoing = ProcessnumOrder - FinishnumOrder;
                if (undoing < MinnumOrder && !(comp1(&SystemStartTime, &SystemStopTime)>0)) {
                    SystemReopen = 1;
                }
            }
        }
        i++;
    }

}

//从文件dict.dic读取所有食物属性
void getFood(FILE* file) {
    int i = 0, j = 0, b = 0, size = 0, time;

    //1.读取所有食物名
    char str[100] = { 0 };//存放读取到的第i个食物名
    while (i < AllnumFood) {
        if (fscanf(file, "%s", str) != 1) {
            printf("读取第 %d 个食物名失败！\n", i);
            return;
        }
        strcpy(FormFood[i].FoodName, str);
        ++i;
    }

    //2.读取所有食物的制作时间
    while (j < AllnumFood) {
        if (fscanf(file, "%d", &time) != 1) {
            printf("读取第 %d 个食物的制作时间失败！\n", j);
            return;
        }
        FormFood[j].ProdecetionTime = time;
        FormFood[j].RemainTime = time;
        ++j;
    }

    //3.读取所有食物的最大存储数量
    while (b < AllnumFood) {
        if (fscanf(file, "%d", &size) != 1) {
            printf("读取第 %d 个食物的最大存储数量失败！\n", b);
            return;
        }
        FormFood[b].MaxSpace = size;
        ++b;
    }
}

//解析套餐i
void ParsingTaoCan(char* str, int i) {
    char taocanname[105] = { 0 };//存放第i个套餐名
    if (sscanf(str, "%s", taocanname) != 1) {
        printf("读取第%d个套餐名失败！\n", i);
        return;
    }
    //为套餐名分配空间索引号
    strcpy(FormTaoCan[i].TaoCanName, taocanname);
    str += strlen(taocanname);
    str = mgth(str);//忽略空格，并更新sh的指向为第i个套餐的食物名

    char foodname[105] = { 0 };//套餐i中对应的食物名
    while (sscanf(str, "%s", foodname) == 1) {
        int idx = returnNameFromFood(foodname);//通过食物名字找到该食物对应的索引
        if (idx == -1) { continue; }
        FormTaoCan[i].TaoCanNeedfoodIndx[FormTaoCan[i].TaoCanNeedfoodNum] = idx;//把第i个套餐需要的食物的索引idx存入FormTaoCan[i].TaoCanNeedfoodIndx
        ++FormTaoCan[i].TaoCanNeedfoodNum;
        str += strlen(foodname);
        str = mgth(str);
    }
}

//读取所有订单
void getAllOrders() {

    int i = 0;
    while (i < AllnumOrder) {

        //1.读取订单i对应的开始时间和套餐名(或食物名)
        char time[105] = { 0 };
        char Name[105] = { 0 };//存放套餐名或食物名
        int TaoCanidx[105] = { 0 };//存放套餐名Name需要的食物在食物列表里面对应的索引
        int TaoCanNeedFoodNum = 0;//存放套餐名Name需要的食物数量
        if (scanf("%s %s", time, Name) != 2) {
            return;
        }

        //设置套餐i对应的开始时间
        FormOrder[i].OrderStartTime.hour = 10 * (time[0] - '0') + (time[1] - '0');
        FormOrder[i].OrderStartTime.minute = 10 * (time[3] - '0') + (time[4] - '0');
        FormOrder[i].OrderStartTime.second = 10 * (time[6] - '0') + (time[7] - '0');

        //2.假设Name是套餐，则把套餐名Name需要的食物在食物列表对应的索引存入数组TaoCanidx，套餐需要的食物数量存入变量TaoCanNeedFoodNum
        int index = -1;
        int k = 0;
        while (k < AllnumTaocan) {
            if (strcmp(Name, FormTaoCan[k].TaoCanName) == 0) {
                index = k;//获取套餐名对应的索引
                break;
            }
            k++;
        }

        if (index == -1) {//不是套餐，是食物
            //处理食物的逻辑
            int g = 0;
            while (g < AllnumFood) {
                if (strcmp(FormFood[g].FoodName, Name) == 0) {
                    FormOrder[i].OrderNeedFoodIndx[0] = g;//Name对应的食物索引赋值给FormOrder[i].OrderNeedFoodIndx[0]
                    FormOrder[i].OdrderNeedfoodNum = 1;//设置订单i需要的食物数量为1
                    break;
                }
                g++;
            }
        }
        else {//是套餐
            int j = 0;
            while (j < FormTaoCan[index].TaoCanNeedfoodNum) {
                TaoCanidx[j] = FormTaoCan[index].TaoCanNeedfoodIndx[j];//把该套餐中需要的食物在食物列表对应的索引赋值给TaoCanidx[j]
                j++;
            }
            TaoCanNeedFoodNum = FormTaoCan[index].TaoCanNeedfoodNum;//TaoCanNeedFoodNum为索引index对应的套餐需要的食物数量
            memcpy(FormOrder[i].OrderNeedFoodIndx, TaoCanidx, sizeof(TaoCanidx));//把数组TaoCanidx复制到FormOrder[i].OrderNeedFoodIndx
            FormOrder[i].OdrderNeedfoodNum = TaoCanNeedFoodNum;//设置订单i需要的食物数量为TaoCanNeedFoodNum
        }
        i++;
    }

}

//处理第i个套餐
void handTaoCan(FILE* file) {
    int i = 0;
    while (i < AllnumTaocan) {
        char str[1024] = { 0 };//存放一行的套餐
        fgets(str, 1024, file);//读取一整行的套餐存入str
        ParsingTaoCan(str, i);//解析第i个套餐
        ++i;
    }
}

int printm()
{
    int i = 0;
    while (i < AllnumOrder) {
        if (FormOrder[i].OrderStatus == Finished) {
            struct Time et = FormOrder[i].OrderEndTime;
            printf("%02d:%02d:%02d\n", et.hour, et.minute, et.second);
        }
        else {
            printf("Fail\n");
        }
        i++;
    }
    return 0;
}
int main() {
    FILE* file1 = fopen("dict.dic", "r");
    if (!file1) {
        printf("打开文件dict.dic失败！\n");
        return 0;
    }
    if (fscanf(file1, "%d %d", &AllnumFood, &AllnumTaocan) != 2) {
        printf("读取AllnumFood和AllnumTaocan失败！\n");
        return 0;
    }
    char line1[1024] = { 0 };
    fgets(line1, 1024, file1);//读取第1行末尾的 \n
    getFood(file1);//读取所有食物
    if (fscanf(file1, "%d %d", &MaxnumOrder, &MinnumOrder) != 2) {
        printf("读取MaxnumOrder和MinnumOrder失败！\n");
        return 0;
    }
    char line2[1024] = { 0 };
    fgets(line2, 1024, file1);//读取第5行末尾的 \r\n
    handTaoCan(file1);//开始读取第6行开始的套餐
    fclose(file1);


    if (scanf("%d", &AllnumOrder) != 1) {
        printf("读取AllnumOrder失败！\n");
        return 0;
    }
    getAllOrders();//读取订单并处理
    for (int i = 1; i > 0; i = comp1(&AllOrdersEndTime, &SystemStartTime)) {
        addsecond(&SystemStartTime);//系统开始时间加一秒，同时更新系统开始时间
        if (comp1(&SystemStartTime, &SystemStopTime)>0) {
            IsAcceptOrder=0;
        }
        else if (SystemReopen == 1) {
            SystemReopen = 0;
            IsAcceptOrder = 1;
        }
        if (comp1(&SystemStartTime, &FirstOrderStartTime) > 0) {//如果系统开始时间大于第一个订单开始的时间
            making();//开始制作食物
        }
        systemProcessOrders();//系统开始接单
    }

    printm();
    return 0;
}
