#include "dict.h"
#include "QDebug"

int isClosed=0;//麦当劳是否关店
int isShutdownOrder=0;//是否关闭接单
int W1;//暂停接单的最大订单队列数量
int W2;//恢复接单的最小订单队列数量
int foodCount;//食物种类的数量
int orderCount;//订单数量
int comboCount;//套餐数量
Food* foods=NULL;//保存所有的食物
Order* orders=NULL;//保存所有的订单
Combo* combos=NULL;//保存所有的套餐

//获取食物
Food* getFood(int &Count){
    Count = foodCount;
    return foods;
}

//获取套餐
Combo* getCombo(int &Count){
    Count = comboCount;
    return combos;
}

//查找食物
Food* findFood(const char* name){
    for(int i=0;i<foodCount;++i){
        if(strcmp(name,foods[i].name)==0)
            return foods+i;
    }
    return NULL;
}

//查找套餐
Combo* findCombo(const char* name){
    for(int i=0;i<foodCount;++i){
        if(strcmp(name,combos[i].name)==0)
            return combos+i;
    }
    return NULL;
}

//初始化dict的数据
void init1(void){
    int i;
    char cTemp[MAX_NAME*(1+MAX_COMBO_FOOD)];
    char cTemp2[MAX_NAME];

    FILE* infile=fopen("dict.dic","r");

    fscanf(infile,"%d%d",&foodCount,&comboCount);

    foods = (Food*) malloc(sizeof(Food)*foodCount);
    combos = (Combo*)malloc(sizeof(Combo)*comboCount);

    for(i=0;i<foodCount;++i){
        fscanf(infile,"%s",foods[i].name);
        foods[i].stock=0;
        foods[i].isProducing=0;
    }

    for(i=0;i<foodCount;++i){
        fscanf(infile,"%d",&foods[i].productionTime);
    }

    for(i=0;i<foodCount;++i){
        fscanf(infile,"%d",&foods[i].maxCapacity);
    }

    fscanf(infile,"%d%d",&W1,&W2);
    fgetc(infile);

    for(i=0;i<comboCount;++i){
        fscanf(infile,"%[^\n]s",cTemp);
        fgetc(infile);

        combos[i].rqCount=0;

        char* token;
        Food* fFood;

        token = strtok(cTemp," ");
        strcpy(combos[i].name,token);

        do{
            token = strtok(NULL," ");
            if(token==NULL)
                break;
            strcpy(cTemp2,token);
            fFood = findFood(cTemp2);
            if(fFood!=NULL)
                combos[i].requestFoods[combos[i].rqCount++]=fFood;
        }while(1);
    }
    fclose(infile);
}

//更新所有需要制作的食物列表
void updateMakeFoods(){
    for(int i=0;i<foodCount;++i){
        if(foods[i].stock<foods[i].maxCapacity){
            foods[i].isProducing=1;
        }
    }
}

//递增时间
void incrementTime(ReachTime* t){
    ++(t->second);
    if(t->second!=60)
        return;

    t->second=0;
    t->minute++;
    if(t->minute!=60)
        return;

    t->minute=0;
    t->hour++;
    if(t->hour!=24)
        return;

    t->hour=0;
}

int isEqualReachTime(ReachTime* t1,ReachTime* t2){//判断t1是否等于t2
    return (t1->hour==t2->hour) && (t1->minute==t2->minute) && (t1->second == t2->second);
}

ReachTime stringChangeReachTime(const char*str){//将hh:mm:ss时间转化为ReachTime时间
    ReachTime t;
    t.hour = atoi(str);
    t.minute = atoi(str+3);
    t.second = atoi(str+6);
    return t;
}

//制作所有没达到最大库存的食物
void makeAllFoods(){
    for(int i=0;i<foodCount;++i){
        if(foods[i].stock<foods[i].maxCapacity){
            if(foods[i].isProducing==1){
                ++foods[i].currentPTime;
                if(foods[i].currentPTime==foods[i].productionTime){
                    ++foods[i].stock;
                    foods[i].currentPTime=0;
                    if(foods[i].stock==foods[i].maxCapacity)
                        foods[i].isProducing=0;
                }
            }else{
                foods[i].isProducing=1;
                foods[i].currentPTime=0;
            }
        }
    }
}

//判断麦当劳是否可以关店（超过22点00分00秒）
int isCanClosed(ReachTime* t){
    return t->hour>=22 && t->minute>=0 && t->second>0;
}

//获取当前未完成订单数量
int getCurrentOrdersCount(int f,int e){
    int sum=0;
    while(f<e){
        if(orders[f].isCompleted==1)
            ++sum;
        ++f;
    }
    return sum;
}

//处理订单，从第一个到当前订单
Order* chuli(int count,std::string times[],std::string names[],std::string endtime){
    init1();
    char cTemp1[MAX_NAME];
    ReachTime nowTime;
     char Time[MAX_NAME];
     strcpy(Time,endtime.c_str());
    ReachTime endtimes=stringChangeReachTime(Time);
    nowTime.minute = nowTime.second = 0;
    nowTime.hour = 7;
    //获取订单数量
    orderCount=count;

    //初始化订单内存
    orders = (Order*)malloc(sizeof(Order) * orderCount);

    //第一个订单
    int firstOrderIndex = 0;

    //最后一个订单
    int lastOrderIndex = 0;

    for (int i = 0; i < orderCount; ++i) {
        strcpy(cTemp1, times[i].c_str());
        strcpy(orders[i].name, names[i].c_str());
        //将到达时间转换成数字表示
        orders[i].tr = stringChangeReachTime(cTemp1);
        //订单被初始化位未接收
        orders[i].isCompleted = 1;

        //从foods中查找订单名称
        Food *tagFood = findFood(orders[i].name);
        Combo *tagCombo;
        //查找套餐名称
        if (tagFood == NULL) {
            tagCombo = findCombo(orders[i].name);

            //将套餐对应的食物列表加入到订单中
            for (int ii = 0; ii < tagCombo->rqCount; ++ii) {
                strcpy(orders[i].foods_name[ii], tagCombo->requestFoods[ii]->name);
                orders[i].isGetFood[ii] = 0;
            }

            orders[i].rqCount = tagCombo->rqCount;
        } else {
            strcpy(orders[i].foods_name[0], tagFood->name);
            orders[i].isGetFood[0] = 0;
            orders[i].rqCount = 1;
        }
    }

    //剩余订单数量
    int lastOrderCount = orderCount;

    //开始模拟订餐
    do {


        //关店
        if (!isClosed && isCanClosed(&nowTime))
            isClosed = 1;

        //检查当前时间是否等于订单队列的最后一个订单的时间。
        if (isEqualReachTime(&nowTime, &orders[lastOrderIndex].tr)) {
            //抛弃订单
            if (isClosed || isShutdownOrder) {
                orders[lastOrderIndex].isCompleted = 2;
                --lastOrderCount;//剩余订单数量-1
            }

            //否则接受订单。
            ++lastOrderIndex;
        }



        //制作所有没达到最大库存的食物
        makeAllFoods();

        //从第一个订单开始查找是否有食物可以供应
        for (int i = firstOrderIndex; i != lastOrderIndex; ++i) {
            if (orders[i].isCompleted != 1)
                continue;

            //表示该订单是否达到出餐条件
            int hasEnough = 1;
            for (int j = 0; j < orders[i].rqCount; ++j) {
                if (orders[i].isGetFood[j] == 0) {
                    Food *tagFood = findFood(orders[i].foods_name[j]);
                    if (tagFood->stock > 0) {
                        orders[i].isGetFood[j] = 1;
                        --tagFood->stock;
                    } else
                        hasEnough = 0;
                }
            }

            //可以出餐
            if (hasEnough) {
                //先记录完成时间
                orders[i].tr2 = nowTime;
                //标记完成
                orders[i].isCompleted = 0;
                --lastOrderCount;//剩余订单数量-1
            }
        }

        //达到暂停接单条件
        if (!isShutdownOrder && getCurrentOrdersCount(firstOrderIndex, lastOrderIndex) > W1) {
            isShutdownOrder = 1;
        } else if (isShutdownOrder && getCurrentOrdersCount(firstOrderIndex, lastOrderIndex) < W2) {
            isShutdownOrder = 0;//达到恢复营业条件
        }

        //查找当前的第一个订单
        for (; firstOrderIndex < lastOrderIndex; ++firstOrderIndex) {
            if (orders[firstOrderIndex].isCompleted == 1)
                break;
        }

        if(nowTime.hour>=endtimes.hour&&nowTime.minute>=endtimes.minute&&nowTime.second>=endtimes.second)
        {
            break;
        }
        //递增1秒
        incrementTime(&nowTime);
        //更新需要制作的食物
        updateMakeFoods();
    } while (lastOrderCount > 0);

    return orders;

}
