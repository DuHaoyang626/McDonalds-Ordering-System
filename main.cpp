//头文件
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include "variable.h"
#include"auxiliary.h"
//建立结构体

//辅助函数

//主函数
int main() {
    //建立任务处理数据

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
        food[i].currenttime=-1;
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
        for(c=fgetc(fp);c!='\n';c=fgetc(fp)) {
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
        orde[i].remainfoodnumber=comb[j].kindnumber;//将套餐信息复制给订单
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
    for(time=25200;time<86400;time++) {//按秒循环
        //制作食物
        for(i=0;i<foodnumber;i++) {
            if(food[i].number<food[i].max) {
                food[i].currenttime++;
                if(food[i].currenttime==food[i].needtime) {
                    food[i].number++;
                    food[i].currenttime=0;
                }
            }
        }

        //点单处理
        //系统状态判断
        if(remainorder>allowmax)
            systemstate=0;
        if(remainorder<allowmin)
            systemstate=1;

        //订单处理
        for(i=0;i<ordenumber;i++) {
            if(orde[i].begintime>time)//未开始
                break;
            if(orde[i].begintime==time) {//开始时
                if(systemstate==1) {//系统开放点单
                    orde[i].state=1;//订单进行中
                    remainorder++;
                    //配餐
                    for(orderlinkcurp=orde[i].kind;orderlinkcurp!=NULL;orderlinkcurp=orderlinkcurp->next) {
                        if(orderlinkcurp->provided==0) {//当前餐品未配餐
                            if(orderlinkcurp->link->number!=0) {//当前餐品有存量
                                orderlinkcurp->link->number--;
                                orderlinkcurp->provided=1;
                                orde[i].remainfoodnumber--;
                            }
                        }
                    }

                    //判断订单是否完成
                    if(orde[i].remainfoodnumber==0) {
                        orde[i].state=2;
                        orde[i].finishtime=time;
                        remainorder--;
                    }
                }
                else {//系统暂停点餐
                    orde[i].state=3;//点单失败
                }
            }
            else {
                if(orde[i].state==2||orde[i].state==3)//订单已结束（完成/失败）
                    continue;
                else {//订单进行中
                    //配餐
                    for(orderlinkcurp=orde[i].kind;orderlinkcurp!=NULL;orderlinkcurp=orderlinkcurp->next) {
                        if(orderlinkcurp->provided==0) {//当前餐品未配餐
                            if(orderlinkcurp->link->number!=0) {//当前餐品有存量
                                orderlinkcurp->link->number--;
                                orderlinkcurp->provided=1;
                                orde[i].remainfoodnumber--;
                            }
                        }
                    }

                    //判断订单是否完成
                    if(orde[i].remainfoodnumber==0) {
                        orde[i].state=2;
                        orde[i].finishtime=time;
                        remainorder--;
                    }
                }
            }
        }
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

    //释放各链表占用空间
    for(i=0;i<ordenumber;i++) {
        orderlinkcurp=orde[i].kind;
        orderlinknewp=orderlinkcurp->next;
        orde[i].kind=NULL;
        while(orderlinknewp!=NULL) {
            free(orderlinkcurp);
            orderlinkcurp=orderlinknewp;
            orderlinknewp=orderlinkcurp->next;
        }
        free(orderlinkcurp);
    }
    orderlinkcurp=NULL;

    for(i=0;i<combnumber;i++) {
        combinationlinkcurp=comb[i].kind;
        combinationlinknewp=combinationlinkcurp->next;
        comb[i].kind=NULL;
        while(combinationlinknewp!=NULL) {
            free(combinationlinkcurp);
            combinationlinkcurp=combinationlinknewp;
            combinationlinknewp=combinationlinkcurp->next;
        }
        free(combinationlinkcurp);
    }
    combinationlinkcurp=NULL;

    return 0;
}