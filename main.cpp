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

//辅助函数
int correctfood(char ch[],struct foodkind food[],int foodnumber) {//返回餐品名称ch对应序号
    int n;
    for(n=0;n<foodnumber;n++) {
        if(strcmp(ch,food[n].name)==0)
            break;
    }
    return n;
}
int correctcomb(char ch[],struct combination comb[],int combnumber) {//返回套餐名称ch对应序号
    int n;
    for(n=0;n<combnumber;n++) {
        if(strcmp(ch,comb[n].name)==0)
            break;
    }
    return n;
}
int timeread() {//将hh:mm:ss时间转化为时间戳
    int hour=0,minute=0,second=0,time;
    scanf("%d:%d:%d",&hour,&minute,&second);
    time=second+60*minute+3600*hour;
    return time;
}
int main(){
    //建立任务处理数据
    int hour1;//hh:mm:ss时间-第1位
    int hour2;//hh:mm:ss时间-第2位
    int minute1;//hh:mm:ss时间-第3位
    int minute2;//hh:mm:ss时间-第4位
    int second1;//hh:mm:ss时间-第5位
    int second2;//hh:mm:ss时间-第6位
    int foodnumber=0;//餐品种类数量
    int combnumber=0;//套餐种类数量
    int ordenumber=0;//订单数量
    int allowmax=0;//系统关闭订单量w1
    int allowmin=0;//系统恢复订单量w2
    int remainorder=0;//滞留订单量
    int systemstate=1;//系统开启情况，0关闭，1开启。
    int checkmin;
    //建立临时变量
    int i;
    int j;
    int k;
    int temp;
    char ch[51]={0};
    char c;

    //读取菜单
    FILE *fp;
    fp=fopen("dict.dic","r");
    fscanf(fp,"%d%d",&foodnumber,&combnumber);//读取餐品数和套餐数
    combnumber+=foodnumber;//单点商品也算作套餐
    struct foodkind food[foodnumber];//创建餐品数组
    struct combination comb[combnumber];//创建套餐数组
    for(i=0;i<foodnumber;i++) {//读取和创建餐品数据
        fscanf(fp,"%s",ch);//读取餐品名称
        strcpy(food[i].name,ch);
        food[i].number=0;
        food[i].max=0;
        food[i].currenttime=0;
        food[i].needtime=0;
        strcpy(comb[i].name,ch);//将餐品也定义为套餐
        comb[i].kindnumber=1;
        comb[i].link[0]=&food[i];
    }
    for(i=0;i<foodnumber;i++) {//读取各餐品制作所需时间
        fscanf(fp,"%d",&food[i].needtime);
    }
    for(i=0;i<foodnumber;i++) {//读取各餐品最大容量
        fscanf(fp,"%d",&food[i].max);
    }
    fscanf(fp,"%d%d",&allowmax,&allowmin);//读取系统关闭订单量w1，系统恢复订单量w2
    for(;i<combnumber;i++) {//读取多餐品套餐
        fscanf(fp, "%s", ch);//读取套餐名称
        strcpy(comb[i].name, ch);
        comb[i].kindnumber = 0;
        j = 0;
        for (c =fgetc(fp); c==' '; c =fgetc(fp)) {//读取套餐中对应餐品名称并记录数据
            fscanf(fp, "%s", ch);
            comb[i].link[j] = &food[correctfood(ch, food, foodnumber)];
            j++;
            comb[i].kindnumber++;
        }
    }
    fclose(fp);

    //读取输入
    scanf("%d",&ordenumber);//读取订单数
    struct order orde[ordenumber];//创建订单数组
    for(i=0;i<ordenumber;i++) {//读取订单数据
        orde[i].begintime=timeread();//读取各订单开始时间并转化为时间戳
        orde[i].finishtime=0;
        orde[i].state=0;
        scanf("%s",ch);
        j=correctcomb(ch,comb,combnumber);//找出订单对应套餐编号
        orde[i].foodnumber=comb[j].kindnumber;
        for(k=0;k<comb[j].kindnumber;k++) {
            orde[i].link[k]=comb[j].link[k];
        }
    }

    //当日营业
    int check[allowmax+1];
    for(i=0;i<=allowmax;i++) {
        check[i]=90000;
    }
    int pretime=25200;
    int nowtime=orde[0].begintime;
    int minustime;
    int state=1;//0：旧订单结束，1：新订单开始
    int currentorder=0;
    while(currentorder<ordenumber){//订单循环
        minustime = nowtime - pretime;
        if(minustime!=0) {//进入下一时间节点，需要计算食物制作和系统状态判断
            pretime = nowtime;
            //食物制作
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
            //系统状态判断
            if (remainorder > allowmax)
                systemstate = 0;
            if (remainorder < allowmin)
                systemstate = 1;
        }
        //处理订单
        if (state == 1) {//有新增订单
            if (systemstate == 1) {
                orde[currentorder].state = 1;
                orde[currentorder].finishtime = orde[currentorder].begintime;
                for (j = 0; j < orde[currentorder].foodnumber; j++) {
                    orde[currentorder].link[j]->number--;
                    if (orde[currentorder].link[j]->number < 0)
                        temp = -orde[currentorder].link[j]->number * orde[currentorder].link[j]->needtime - orde[currentorder].link[j]->currenttime+orde[currentorder].begintime;
                    orde[currentorder].finishtime = (orde[currentorder].finishtime > temp ? orde[currentorder].finishtime : temp);
                }//处理并计算结束时间
                if (orde[currentorder].finishtime > orde[currentorder].begintime) {
                    remainorder++;
                    for (temp = 0; temp <= allowmax; temp++) {
                        if (check[temp] == 90000) {
                            check[temp] = orde[currentorder].finishtime;
                            break;
                        }
                    }
                }
            }
            else {
                orde[currentorder].state = 2;
            }
            currentorder++;
        }
        if (state == 0) {//有结束订单
            remainorder--;
            for (temp = 0; temp <= allowmax; temp++) {
                if (check[temp] == nowtime) {
                    check[temp] = 90000;
                    break;
                }
            }
        }
        //判断下一时间节点
        for(i=0;i<=allowmax;i++){
            checkmin=90000;
            for (i = 0; i <= allowmax; i++){
                checkmin=(checkmin<check[i]?checkmin:check[i]);
            }
            if(checkmin>=orde[currentorder].begintime){
                state=1;
                nowtime = orde[currentorder].begintime;
            }
            else{
                state=0;
                nowtime=checkmin;
            }
        }
    }

    //print
    for(i=0;i<ordenumber;i++) {
        if(orde[i].state==2)//orde[i]失败
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