//
//founded by duhao on 5/31/2024.
//All rights reserved.
//

//头文件
#include<stdio.h>
#include<string.h>

//建立结构体
struct foodkind{//食物
    char name[51];//名称
    int number;//当前数量
    int max;//最大数量
    int currenttime;//当前已制作时间
    int needtime;//制作所需时间
};
struct combination{//套餐
    char name[51];//名称
    int kindnumber;//餐品数量
    struct foodkind *link[5];//对应餐品种类
};
struct order{//订单
    int begintime;//开始时间
    int finishtime;//结束时间
    int foodnumber;//餐品数量
    int state;//0未开始，1成功，2失败
    struct foodkind *link[5];//对应餐品种类
};
struct global{
    //建立任务处理数据
    FILE *fp;
    int hour1;//hh:mm:ss时间-第1位
    int hour2;//hh:mm:ss时间-第2位
    int minute1;//hh:mm:ss时间-第3位
    int minute2;//hh:mm:ss时间-第4位
    int second1;//hh:mm:ss时间-第5位
    int second2;//hh:mm:ss时间-第6位
    int foodnumber;//餐品种类数量
    int combnumber;//套餐种类数量
    int ordenumber;//订单数量
    int allowmax;//系统关闭订单量w1
    int allowmin;//系统恢复订单量w2
    int remainorder;//滞留订单量
    int systemstate;//系统开启情况，0关闭，1开启。
    int checkmin;//滞留订单最早结束时间
    int pretime;
    int nowtime;
    int minustime;
    int state;//0：旧订单结束，1：新订单开始
    int currentorder;
    //建立临时变量
    int i;
    int j;
    int k;
    int temp;
    char ch[51];
    char c;
    int n;
};

//辅助函数
int globalcorrectfood(struct foodkind food[],struct global globalvariables) {//返回餐品名称ch对应序号
    for(globalvariables.n=0;globalvariables.n<globalvariables.foodnumber;globalvariables.n++) {
        if(strcmp(globalvariables.ch,food[globalvariables.n].name)==0)
            break;
    }
    return globalvariables.n;
}
int globalcorrectcomb(struct combination comb[],struct global globalvariables) {//返回套餐名称ch对应序号
    for(globalvariables.n=0;globalvariables.n<globalvariables.combnumber;globalvariables.n++) {
        if(strcmp(globalvariables.ch,comb[globalvariables.n].name)==0)
            break;
    }
    return globalvariables.n;
}
int globaltimeread(struct global globalvariables) {//将hh:mm:ss时间转化为时间戳
    scanf("%d:%d:%d",&globalvariables.hour1,&globalvariables.minute1,&globalvariables.second1);
    globalvariables.nowtime=globalvariables.second1+60*globalvariables.minute1+3600*globalvariables.hour1;
    return globalvariables.nowtime;
}
int main(){
    //建立数据
    struct global globalvariables;

    //读取菜单
    globalvariables.fp=fopen("dict.dic","r");
    fscanf(globalvariables.fp,"%d%d",&globalvariables.foodnumber,&globalvariables.combnumber);//读取餐品数和套餐数
    globalvariables.combnumber+=globalvariables.foodnumber;//单点商品也算作套餐
    struct foodkind food[globalvariables.foodnumber];//创建餐品数组
    struct combination comb[globalvariables.combnumber];//创建套餐数组
    for(globalvariables.i=0;globalvariables.i<globalvariables.foodnumber;globalvariables.i++) {//读取和创建餐品数据
        fscanf(globalvariables.fp,"%s",globalvariables.ch);//读取餐品名称
        strcpy(food[globalvariables.i].name,globalvariables.ch);
        food[globalvariables.i].number=0;
        food[globalvariables.i].max=0;
        food[globalvariables.i].currenttime=0;
        food[globalvariables.i].needtime=0;
        strcpy(comb[globalvariables.i].name,globalvariables.ch);//将餐品也定义为套餐
        comb[globalvariables.i].kindnumber=1;
        comb[globalvariables.i].link[0]=&food[globalvariables.i];
    }
    for(globalvariables.i=0;globalvariables.i<globalvariables.foodnumber;globalvariables.i++) {//读取各餐品制作所需时间
        fscanf(globalvariables.fp,"%d",&food[globalvariables.i].needtime);
    }
    for(globalvariables.i=0;globalvariables.i<globalvariables.foodnumber;globalvariables.i++) {//读取各餐品最大容量
        fscanf(globalvariables.fp,"%d",&food[globalvariables.i].max);
    }
    fscanf(globalvariables.fp,"%d%d",&globalvariables.allowmax,&globalvariables.allowmin);//读取系统关闭订单量w1，系统恢复订单量w2
    for(;globalvariables.i<globalvariables.combnumber;globalvariables.i++) {//读取多餐品套餐
        fscanf(globalvariables.fp, "%s", globalvariables.ch);//读取套餐名称
        strcpy(comb[globalvariables.i].name, globalvariables.ch);
        comb[globalvariables.i].kindnumber = 0;
        globalvariables.j = 0;
        for (globalvariables.c =fgetc(globalvariables.fp);globalvariables.c==' '; globalvariables.c =fgetc(globalvariables.fp)) {//读取套餐中对应餐品名称并记录数据
            fscanf(globalvariables.fp, "%s", globalvariables.ch);
            comb[globalvariables.i].link[globalvariables.j] = &food[globalcorrectfood(food, globalvariables)];
            globalvariables.j++;
            comb[globalvariables.i].kindnumber++;
        }
    }
    fclose(globalvariables.fp);

    //读取输入
    scanf("%d",&globalvariables.ordenumber);//读取订单数
    struct order orde[globalvariables.ordenumber];//创建订单数组
    for(globalvariables.i=0;globalvariables.i<globalvariables.ordenumber;globalvariables.i++) {//读取订单数据
        orde[globalvariables.i].begintime=globaltimeread(globalvariables);//读取各订单开始时间并转化为时间戳
        orde[globalvariables.i].finishtime=0;
        orde[globalvariables.i].state=0;
        scanf("%s",globalvariables.ch);
        globalvariables.j=globalcorrectcomb(comb,globalvariables);//找出订单对应套餐编号
        orde[globalvariables.i].foodnumber=comb[globalvariables.j].kindnumber;
        for(globalvariables.k=0;globalvariables.k<comb[globalvariables.j].kindnumber;globalvariables.k++) {
            orde[globalvariables.i].link[globalvariables.k]=comb[globalvariables.j].link[globalvariables.k];
        }
    }

    //当日营业
    int check[globalvariables.allowmax+1];
    for(globalvariables.i=0;globalvariables.i<=globalvariables.allowmax;globalvariables.i++) {
        check[globalvariables.i]=90000;
    }
    globalvariables.pretime=25200;
    globalvariables.nowtime=orde[0].begintime;
    globalvariables.state=1;//0：旧订单结束，1：新订单开始
    globalvariables.currentorder=0;
    globalvariables.systemstate=1;
    globalvariables.remainorder=0;
    while(globalvariables.currentorder<globalvariables.ordenumber){//订单循环
        globalvariables.minustime =globalvariables. nowtime - globalvariables.pretime;
        if(globalvariables.minustime!=0) {//进入下一时间节点，需要计算食物制作和系统状态判断
            globalvariables.pretime = globalvariables.nowtime;
            //食物制作
            for (globalvariables.i = 0; globalvariables.i < globalvariables.foodnumber; globalvariables.i++) {
                if (food[globalvariables.i].number < food[globalvariables.i].max) {
                    food[globalvariables.i].number += (globalvariables.minustime + food[globalvariables.i].currenttime) / food[globalvariables.i].needtime;
                    food[globalvariables.i].currenttime = (globalvariables.minustime + food[globalvariables.i].currenttime) % food[globalvariables.i].needtime;
                }
                if (food[globalvariables.i].number >= food[globalvariables.i].max) {
                    food[globalvariables.i].number = food[globalvariables.i].max;
                    food[globalvariables.i].currenttime = 0;
                }
            }
            //系统状态判断
            if (globalvariables.remainorder > globalvariables.allowmax)
                globalvariables.systemstate = 0;
            if (globalvariables.remainorder < globalvariables.allowmin)
                globalvariables.systemstate = 1;
        }
        //处理订单
        if (globalvariables.state == 1) {//有新增订单
            if (globalvariables.systemstate == 1) {
                orde[globalvariables.currentorder].state = 1;
                orde[globalvariables.currentorder].finishtime = orde[globalvariables.currentorder].begintime;
                for (globalvariables.j = 0; globalvariables.j < orde[globalvariables.currentorder].foodnumber; globalvariables.j++) {
                    orde[globalvariables.currentorder].link[globalvariables.j]->number--;
                    if (orde[globalvariables.currentorder].link[globalvariables.j]->number < 0)
                        globalvariables.temp = -orde[globalvariables.currentorder].link[globalvariables.j]->number * orde[globalvariables.currentorder].link[globalvariables.j]->needtime - orde[globalvariables.currentorder].link[globalvariables.j]->currenttime+orde[globalvariables.currentorder].begintime;
                    orde[globalvariables.currentorder].finishtime = (orde[globalvariables.currentorder].finishtime > globalvariables.temp ? orde[globalvariables.currentorder].finishtime : globalvariables.temp);
                }//处理并计算结束时间
                if (orde[globalvariables.currentorder].finishtime > orde[globalvariables.currentorder].begintime) {
                    globalvariables.remainorder++;
                    for (globalvariables.temp = 0; globalvariables.temp <= globalvariables.allowmax; globalvariables.temp++) {
                        if (check[globalvariables.temp] == 90000) {
                            check[globalvariables.temp] = orde[globalvariables.currentorder].finishtime;
                            break;
                        }
                    }
                }
            }
            else {
                orde[globalvariables.currentorder].state = 2;
            }
            globalvariables.currentorder++;
        }
        if (globalvariables.state == 0) {//有结束订单
            globalvariables.remainorder--;
            for (globalvariables.temp = 0; globalvariables.temp <= globalvariables.allowmax; globalvariables.temp++) {
                if (check[globalvariables.temp] == globalvariables.nowtime) {
                    check[globalvariables.temp] = 90000;
                    break;
                }
            }
        }
        //判断下一时间节点
        for(globalvariables.i=0;globalvariables.i<=globalvariables.allowmax;globalvariables.i++){
            globalvariables.checkmin=90000;
            for (globalvariables.i = 0; globalvariables.i <= globalvariables.allowmax; globalvariables.i++){
                globalvariables.checkmin=(globalvariables.checkmin<check[globalvariables.i]?globalvariables.checkmin:check[globalvariables.i]);
            }
            if(globalvariables.checkmin>=orde[globalvariables.currentorder].begintime){
                globalvariables.state=1;
                globalvariables.nowtime = orde[globalvariables.currentorder].begintime;
            }
            else{
                globalvariables.state=0;
                globalvariables.nowtime=globalvariables.checkmin;
            }
        }
    }

    //print
    for(globalvariables.i=0;globalvariables.i<globalvariables.ordenumber;globalvariables.i++) {
        if(orde[globalvariables.i].state==2)//orde[i]失败
            printf("Fail\n");
        else {//orde[i]成功
            //将时间戳转化为hh:mm:ss时间
            globalvariables.second1=orde[globalvariables.i].finishtime%60;
            globalvariables.second2=globalvariables.second1%10;
            globalvariables.second1=globalvariables.second1/10;
            globalvariables.minute1=(orde[globalvariables.i].finishtime%3600)/60;
            globalvariables.minute2=globalvariables.minute1%10;
            globalvariables.minute1=globalvariables.minute1/10;
            globalvariables.hour1=orde[globalvariables.i].finishtime/3600;
            globalvariables.hour2=globalvariables.hour1%10;
            globalvariables.hour1=globalvariables.hour1/10;
            printf("%d%d:%d%d:%d%d\n",globalvariables.hour1,globalvariables.hour2,globalvariables.minute1,globalvariables.minute2,globalvariables.second1,globalvariables.second2);
        }
    }
    return 0;
}
//进程记录
//完成全局变量结构体化