//头文件
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

//建立结构体
struct foodkind {//食物种类
    char name[51];//名称
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
    char name[51];//名称
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
    int foodnumber;//未完成餐品数量
    int state;//订单状态：0未开始，1进行中，2成功，3失败
    struct orderlink *kind;//餐品详情
};

//辅助函数
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

//主函数
int main() {
    //建立任务处理数据
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
    char ch[51]={0};
    char c=0;
    struct combinationlink *combinationlinknewp;
    struct combinationlink *combinationlinkcurp;
    struct orderlink *orderlinknewp;
    struct orderlink *orderlinkcurp;

    //读取菜单
    FILE *fp;
    fp=fopen("dict.dic","r");
    fscanf(fp,"%d%d",&foodnumber,&combnumber);//读取餐品数和套餐数
    combnumber+=foodnumber;//单点商品也算作套餐
    struct foodkind food[foodnumber];
    struct combination comb[combnumber];
    for(i=0;i<foodnumber;i++) {
        fscanf(fp,"%s",ch);//读取餐品名称
        strcpy(food[i].name,ch);
        food[i].number=0;
        food[i].max=0;
        food[i].currenttime=0;
        food[i].needtime=0;
        strcpy(comb[i].name,ch);//将餐品也定义为套餐
        comb[i].kindnumber=1;
        combinationlinknewp=(struct combinationlink*)malloc(sizeof(struct combinationlink));
        comb[i].kind=combinationlinknewp;
        comb[i].kind->link=&food[i];
        comb[i].kind->next=NULL;
    }
    for(i=0;i<foodnumber;i++) {
        fscanf(fp,"%d",&food[i].needtime);
    }//读取各餐品制作所需时间
    for(i=0;i<foodnumber;i++) {
        fscanf(fp,"%d",&food[i].max);
    }//读取各餐品最大容量
    fscanf(fp,"%d%d",&allowmax,&allowmin);//读取系统关闭订单量w1，系统恢复订单量w2
    for(;i<combnumber;i++) {//读取多餐品套餐
        fscanf(fp,"%s",ch);
        strcpy(comb[i].name,ch);
        comb[i].kindnumber=0;
        comb[i].kind=NULL;
        for(c=fgetc(fp);c==' ';c=fgetc(fp)) {
            fscanf(fp,"%s",ch);
            combinationlinknewp=(struct combinationlink*)malloc(sizeof(struct combinationlink));
            combinationlinknewp->link=&food[correctfood(ch,food,foodnumber)];
            comb[i].kindnumber++;
            if(comb[i].kind==NULL) {
                comb[i].kind=combinationlinknewp;
                combinationlinkcurp=combinationlinknewp;
            }
            else {
                combinationlinkcurp->next=combinationlinknewp;
                combinationlinkcurp=combinationlinknewp;
            }
        }
        combinationlinkcurp->next=NULL;
    }
    fclose(fp);

    //读取输入
    scanf("%d",&ordenumber);//读取订单数
    struct order orde[ordenumber];
    for(i=0;i<ordenumber;i++) {
        orde[i].begintime=timeread();//读取各订单开始时间并转化为时间戳
        orde[i].finishtime=0;
        orde[i].kind=NULL;
        orde[i].state=0;
        scanf("%s",ch);
        j=correctcomb(ch,comb,combnumber);//找出订单对应套餐编号
        orde[i].foodnumber=comb[j].kindnumber;//将套餐信息复制给订单
        combinationlinknewp=comb[j].kind;
        for(k=0;k<comb[j].kindnumber;k++) {
            orderlinknewp=(struct orderlink*)malloc(sizeof(struct orderlink));
            orderlinknewp->link=combinationlinknewp->link;
            orderlinknewp->provided=0;
            combinationlinknewp=combinationlinknewp->next;
            if(orde[i].kind==NULL) {
                orde[i].kind=orderlinknewp;
                orderlinkcurp=orderlinknewp;
            }
            else {
                orderlinkcurp->next=orderlinknewp;
                orderlinkcurp=orderlinknewp;
            }
        }
        orderlinkcurp->next=NULL;
    }
    //当日营业
    k=0;
    int ccc=0;
    int temp;
    int check[allowmax+3];
    for(i=0;i<=allowmax+2;i++) {
        check[i]=90000;
    }
    int pretime=25200,nowtime=orde[0].begintime,minustime,/*kk*/state=1;//0：旧订单结束，1：新订单开始，2：both
    while(k<ordenumber) {
        //制作食物
        minustime = nowtime - pretime;
        for (i = 0; i < foodnumber; i++) {
            if (food[i].number < food[i].max) {
                food[i].number += (minustime + food[i].currenttime) / food[i].needtime;
                food[i].currenttime = (minustime + food[i].currenttime) % food[i].needtime;
            }
            if (food[i].number >= food[i].max) {
                food[i].number = food[i].max;
                food[i].currenttime = 0;
            }
        }
        pretime = nowtime;
        //判断新增订单还是结束旧订单
        if (state == 1 || state == 2) {//有新增订单
            if (remainorder > allowmax)
                systemstate = 0;
            if (remainorder < allowmin)
                systemstate = 1;
            if (systemstate == 1) {
                orde[k].state = 1;
                orde[k].finishtime = orde[k].begintime;
                orderlinkcurp=orde[k].kind;
                for (j = 0; j < orde[k].foodnumber; j++) {
                    orderlinkcurp->link->number--;
                    if(orderlinkcurp->link->number<0)
                        temp=-orderlinkcurp->link->number*orderlinkcurp->link->needtime-orderlinkcurp->link->currenttime+orde[k].begintime;
                    orde[k].finishtime=(orde[k].finishtime > temp ? orde[k].finishtime : temp);
                    orderlinkcurp=orderlinkcurp->next;
                }//处理并计算结束时间
                if (orde[k].finishtime > orde[k].begintime) {
                    remainorder++;

                    for (temp = 0; temp <= allowmax+2; temp++) {
                        if (check[temp] == 90000) {
                            check[temp] = orde[k].finishtime;
                            break;
                        }
                    }
                }
            } else {
                orde[k].state = 3;
            }
            k++;
        }
        if (state == 0 || state == 2) {
            remainorder--;
            for (temp = 0; temp <= allowmax+2; temp++) {
                if (check[temp] == nowtime) {
                    check[temp] = 90000;
                    break;
                }
            }

        }
        if (k < ordenumber) {
            nowtime = orde[k].begintime;
            ccc=90000;
            for (i = 0; i <= allowmax+2; i++){
                ccc=(ccc<check[i]?ccc:check[i]);
            }
            if(ccc==nowtime)
                state=2;
            if(ccc<nowtime){
                nowtime=ccc;
                state=0;
            }
            if(ccc>nowtime)
                state=1;
        }
        else
            break;
    }

    //print
    for(i=0;i<ordenumber;i++) {
        if(orde[i].state==3)//orde[i]失败
            printf("Fail\n");
        else {//orde[i]成功
            //将时间戳转化为hh:mm:ss时间
            second1=orde[i].finishtime%60;
            second2=second1%10;
            second1=second1/10;
            minute1=(orde[i].finishtime%3600)/60;
            minute2=minute1%10;
            minute1=minute1/10;
            hour1=orde[i].finishtime/3600;
            hour2=hour1%10;
            hour1=hour1/10;

            printf("%d%d:%d%d:%d%d\n",hour1,hour2,minute1,minute2,second1,second2);
        }
    }
    return 0;
}