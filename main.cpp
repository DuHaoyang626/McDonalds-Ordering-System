#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <time.h>

struct Time {
	int hour;
	int minute;
	int second;
};
struct Order {//订单的属性
	int Order_Status;//订单状态
	struct Time Order_StartTime;//订单开始时间
	int Order_Need_FoodIndx[100];//订单需要的食物在食物列表里面对应的索引
	int Num_of_food_queues;//该订单需要的食物排队个数
	struct Time Order_EndTime;//订单结束时间
	int Odrder_Need_foodNum;//订单需要的食物数量
};
//如果t1 > t2，返回 1
int Greater(struct Time* t1, struct Time* t2) {
	if (t1->hour > t2->hour) {
		return 1;
	}
	else {
		return t1->hour < t2->hour ? -1 : (t1->minute > t2->minute ? 1 : (t1->minute < t2->minute ? -1 : (t1->second > t2->second ? 1 : -1)));
	}
}

//如果t1 == t2,返回 1
int Equal(struct Time* t1, struct Time* t2){
	if (t1->hour == t2->hour && t1->minute == t2->minute && t1->second == t2->second) {
		return 1;
	}
	return 0;
}

//如果t1 < t2，返回 1
int Less(struct Time* t1, struct Time* t2) {
	if (t1->hour < t2->hour) {
		return 1;
	}
	else {
		return t1->hour > t2->hour ? -1 : (t1->minute < t2->minute ? 1 : (t1->minute > t2->minute ? -1 : (t1->second < t2->second ? 1 : -1)));
	}
}

struct TaoCan {//套餐的属性
	int TaoCan_Need_foodIndx[110];//套餐需要的食物在食物列表里面对应的索引
	int TaoCan_Need_foodNum;//套餐需要的食物数量
	char TaoCan_Name[1024];
};
//双向链表###########################
struct Node {
	struct Order* order;//订单节点
	struct Node* prev;//该节点上一个节点
	struct Node* next;//该节点下一个节点
};

//初始化头结点和尾节点
void initnode(struct Node** head, struct Node** tail) {
	*head = (struct Node*)malloc(sizeof(struct Node));
	*tail = (struct Node*)malloc(sizeof(struct Node));
	(*head)->prev = NULL;
	(*head)->next = *tail;
	(*head)->order = NULL;

	(*tail)->next = NULL;
	(*tail)->prev = *head;
	(*tail)->order = NULL;
}

//判断双向链表是否为空
int isempty(struct Node* head, struct Node* tail) {
	if (head->next == tail) {
		return 1;
	}
	return 0;
}

//链表插入元素,插入和删除元素都是在中间，保持head和tail不变
void offer(struct Node* tail, struct Order* val) {
	struct Node* pre = tail->prev;
	struct Node* tp = (struct Node*)malloc(sizeof(struct Node));
	tp->order = val;
	tp->prev = pre;
	tp->next = tail;

	pre->next = tp;
	tail->prev = tp;
}

//从节点pr开始，返回满足条件的节点
struct Node* getnode(struct Node** pr, const struct Node* tail, struct Time t) {//t是系统当前时间
	struct Node* tm = *pr;
	tm = tm->next;
	while (tm != NULL && tm != tail) {
		if (Less(&tm->order->Order_StartTime, &t) > 0 || Equal(&tm->order->Order_StartTime, &t) == 1) {
			*pr = tm;//设置pr指向tm节点
			return tm;
		}
		tm = tm->next;
	}
	return NULL;//找不到满足条件的节点
}

//删除节点
void pop(struct Node* p) {//p是在链表里面被删除的节点
	struct Node* pre = p->prev;
	struct Node* nex = p->next;
	pre->next = nex;
	nex->prev = pre;
	p->next = NULL;
	p->prev = NULL;
}
//#################################
struct Food {//食物的属性
	int Food_Prodecetion_Time;//制作时间
	char FoodName[1024];//食物名
	int Food_Max_Space;//最大存储量
	int Food_RemainTime;//剩余时间
	int Food_CurrentSpace;//当前存储量
	//订单链表
	struct Node* head;//头哨兵
	struct Node* tail;//尾哨兵
};
//全局变量
struct Globalvar {
	const int Just_Arrive; //订单到了
	const int Order_Inproducetion; //订单正在制作
	const int Order_Finished; //订单已完成
	const int Order_DoingFail; //订单制作失败
	int Allnum_Food;//食物总数
	int Allnum_Taocan;//套餐总数
	int Allnum_Order;//订单总数
	int Maxnum_Order;//最大订单数量
	int Minnum_Order;//最小订单数量
	int Process_num_Order;//系统正在处理的订单个数
	int Finish_num_Order;//系统完成的订单数量
	int System_Reopen;//系统是否再次打开
	int Is_Accept_Order;//系统是否接单
	struct Time System_Start_Time;//系统开始的时间
	struct Time First_Order_StartTime;//第一个订单开始的时间
	struct Time AllOrders_EndTime ;//所有订单结束的时间
	struct Time System_StopTime ;//系统关闭时间
};
struct TaoCan Form_TaoCan[105] = { 0 };//套餐表
struct Food Form_Food[105] = { 0 };//食物表
struct Order Form_Order[54005] = { 0 };//订单表
struct Globalvar globavar = { 0,1,2,3,0,0,0,0,0,0,0,0,1,{ 6,59,59 },{ 7,0,0 },{ 23,59,59 },{ 22,00,00 } };//初始化全局变量
//忽略空格，获取下一个套餐名的开始
char* Ignore_the_space(char* ch) {
	int i = 0;
	for (i = 0;;i++) {
		if (ch[i] == ' ' || ch[i] == '\t' || ch[i] == '\n' || ch[i] == '\r') {}
		else {
			break;
		}
	}
	return ch + i;
}
//食物供应订单
int Food_Supply_Orders(int foodidx, struct Node *tm) {//需要供应的订单的节点
	if (Form_Food[foodidx].Food_CurrentSpace - 1 < 0) {//该食物库存不足
		return 0;//返回0，该订单未完成
	}
	//foodidx对应的食物开始供应队首的订单
	Form_Food[foodidx].Food_CurrentSpace--;
	tm->order->Num_of_food_queues--;//队首订单对该食物的排队减一
	if (tm->order->Num_of_food_queues == 0) {
		globavar.Finish_num_Order++;
		tm->order->Order_EndTime = globavar.System_Start_Time;
		tm->order->Order_Status = globavar.Order_Finished;
	}
	pop(tm);//移除节点
	return 1;//该订单已完成
}

//食物供应订单主要逻辑
void meet_food(int foodidx) {//foodidx是食物索引
	struct Node* fh = Form_Food[foodidx].head;
	struct Node* v;
	do {
		v = getnode(&fh, Form_Food[foodidx].tail, globavar.System_Start_Time);//获取满足时间的节点
		if (v != NULL && v->order != NULL) {//找到满足条件的节点了
			if (v->order->Order_Status == globavar.Just_Arrive) {//订单刚到
				if (globavar.Is_Accept_Order) {//系统接单状态
					globavar.Process_num_Order++;//系统正在处理的订单个数++
					v->order->Order_Status = globavar.Order_Inproducetion;//更新订单i的状态为正在制作
					if (Food_Supply_Orders(foodidx, v) == 1) {//食物供应订单,订单完成
						//订单完成了
						fh = Form_Food[foodidx].head;
						continue;
					}
					else {
						//不能马上完成
						int undoing = globavar.Process_num_Order - globavar.Finish_num_Order;
						if (undoing > globavar.Maxnum_Order) {
							globavar.Is_Accept_Order = 0;
						}
						continue;
					}
				}
				else {
					v->order->Order_Status = globavar.Order_DoingFail;//系统若不接单，则订单状态为制作失败
					v->order->Num_of_food_queues--;
					pop(v);//移除节点v
					fh = Form_Food[foodidx].head;
					continue;
				}
			}
			else if (v->order->Order_Status == globavar.Order_Inproducetion) {//如果订单的状态正在制作中
				if (Food_Supply_Orders(foodidx, v) == 1) {//该订单完成
					int undoing = globavar.Process_num_Order - globavar.Finish_num_Order;
					if (undoing < globavar.Minnum_Order && !(Greater(&globavar.System_Start_Time, &globavar.System_StopTime) > 0)) {
						globavar.System_Reopen = 1;
					}
					fh = Form_Food[foodidx].head;
					continue;
				}
				else{
					continue;
				}
			}
			else if (v->order->Order_Status == globavar.Order_DoingFail) {
				v->order->Num_of_food_queues--;
				pop(v);//移除失败的节点
				fh = Form_Food[foodidx].head;
				continue;
			}
		}
		else {//找不到满足条件：食物订单到达时间小于等于当前系统时间
			break;
		}
	} while (fh->next != Form_Food[foodidx].tail);
}

int  System_Process_Orders() {
	int i = 0;
	int queueempty = 0;//食物链表为空的个数
	while (i < globavar.Allnum_Food) {
		//如果链表不为空，开始供应订单
		if (isempty(Form_Food[i].head, Form_Food[i].tail) == 0) {//链表不为空，有订单
			meet_food(i);//食物供应订单主要逻辑
		}
		else {
			queueempty++;
		}
		i++;
	}

	if (queueempty == globavar.Allnum_Food) {//所有食物链表都为空
		return 1;
	}
	return 0;
}

//1.读取所有食物名
void get_Foods_name(FILE* file,int i,char* str) {
	while (i < globavar.Allnum_Food) {
		fscanf(file, "%s", str);
		strcpy(Form_Food[i].FoodName, str);
		++i;
	}
}
//2.读取所有食物的制作时间
void get_Foods_makingtime(FILE* file, int j) {
	int time;
	while (j < globavar.Allnum_Food) {
		fscanf(file, "%d", &time);
		Form_Food[j].Food_Prodecetion_Time = time;
		Form_Food[j].Food_RemainTime = time;
		++j;
	}
}
//3.读取所有食物的最大存储数量
void get_Foods_maxspace(FILE* file, int b, int size) {
	while (b < globavar.Allnum_Food) {
		fscanf(file, "%d", &size);
		Form_Food[b].Food_Max_Space = size;
		initnode(&Form_Food[b].head, &Form_Food[b].tail);//初始化头结点和尾节点
		++b;
	}
}

//从文件dict.dic读取所有食物属性
void get_Foods_from_file(FILE* file) {
	int i = 0, j = 0, b = 0, size = 0;
	//1.读取所有食物名
	char str[100] = { 0 };//存放读取到的第i个食物名
	get_Foods_name(file, i,str);
	//2.读取所有食物的制作时间
	get_Foods_makingtime(file, j);
	//3.读取所有食物的最大存储数量
	get_Foods_maxspace(file,b,size);
}
//分析套餐i
void Parsing_TaoCan(char* str, int i) {
	char TaoCan_Name[110] = { 0 };//存放第i个套餐名
	sscanf(str, "%s", TaoCan_Name);
	strcpy(Form_TaoCan[i].TaoCan_Name, TaoCan_Name);
	str += strlen(TaoCan_Name);
	str = Ignore_the_space(str);//忽略空格，并更新sh的指向为第i个套餐的食物名

	int idx = -1;
	char foodname[110] = { 0 };//套餐i中对应的食物名
	while (sscanf(str, "%s", foodname) == 1) {
		//通过食物名字找到该食物对应的索引
		int j = 0;
		while (j < globavar.Allnum_Food) {
			if (strcmp(foodname, Form_Food[j].FoodName) == 0) {
				idx=j;
				break;
			}
			j++;
		}
		if (idx!=-1) {
			Form_TaoCan[i].TaoCan_Need_foodIndx[Form_TaoCan[i].TaoCan_Need_foodNum] = idx;//把第i个套餐需要的食物的索引idx存入Form_TaoCan[i].TaoCan_Need_foodIndx
			++Form_TaoCan[i].TaoCan_Need_foodNum;
			str += strlen(foodname);
			str = Ignore_the_space(str);
		}
		else {
			continue;
		}
	}
}

//处理第i个套餐
void Hand_TaoCan_From_File(FILE* file) {
	int i = 0;
	char str[1024] = { 0 };//存放一行的套餐
	while (i < globavar.Allnum_Taocan) {
		fgets(str, 1024, file);//读取一整行的套餐存入str
		Parsing_TaoCan(str, i);//解析第i个套餐
		i++;
	}
}

//读取所有订单
void Get_AllOrders_from_file() {
	int i = 0,j=0,k=0,d=0,g=0,index=-1;
	char time[110] = { 0 };
	char food_or_TaoCan_Name[110] = { 0 };//存放套餐名或食物名
	int TaoCan_idx[110] = { 0 };//存放套餐名food_or_TaoCan_Name需要的食物在食物列表里面对应的索引
	int TaoCan_Need_foodNum = 0;//存放套餐名food_or_TaoCan_Name需要的食物数量
	while (i < globavar.Allnum_Order) {
		j = 0; index = -1; g = 0; d = 0; k = 0;
		//1.读取订单i对应的开始时间和套餐名(或食物名)
		scanf("%s %s", time, food_or_TaoCan_Name);
		//设置套餐i对应的开始时间
		Form_Order[i].Order_StartTime.second = 10 * (time[6] - '0') + (time[7] - '0');
		Form_Order[i].Order_StartTime.minute = 10 * (time[3] - '0') + (time[4] - '0');
		Form_Order[i].Order_StartTime.hour = 10 * (time[0] - '0') + (time[1] - '0');
		//2.假设food_or_TaoCan_Name是套餐，则把套餐名food_or_TaoCan_Name需要的食物在食物列表对应的索引存入数组TaoCan_idx，套餐需要的食物数量存入变量TaoCan_Need_foodNum
		while (k < globavar.Allnum_Taocan) {
			if (strcmp(food_or_TaoCan_Name, Form_TaoCan[k].TaoCan_Name) == 0) {
				index = k;//获取套餐名对应的索引
				break;
			}
			k++;
		}
		if (index != -1) {//不是食物，是套餐
			while (j < Form_TaoCan[index].TaoCan_Need_foodNum) {
				TaoCan_idx[j] = Form_TaoCan[index].TaoCan_Need_foodIndx[j];//把该套餐中需要的食物在食物列表对应的索引赋值给TaoCan_idx[j]
				j++;
			}
			TaoCan_Need_foodNum = Form_TaoCan[index].TaoCan_Need_foodNum;//TaoCan_Need_foodNum为索引index对应的套餐需要的食物数量
			memcpy(&Form_Order[i].Order_Need_FoodIndx, &TaoCan_idx, sizeof(TaoCan_idx));//把数组TaoCan_idx复制到Form_Order[i].Order_Need_FoodIndx
			Form_Order[i].Odrder_Need_foodNum = TaoCan_Need_foodNum;//设置订单i需要的食物数量为TaoCan_Need_foodNum
			Form_Order[i].Num_of_food_queues = Form_Order[i].Odrder_Need_foodNum;//该订单需要的食物排队个数等于Form_Order[i].Odrder_Need_foodNum
			while (d < Form_Order[i].Odrder_Need_foodNum) {
				offer(Form_Food[Form_Order[i].Order_Need_FoodIndx[d]].tail, &Form_Order[i]);//把该订单Form_Order[i]插入该订单需要的所有食物对应的尾结点
				d++;
			}
		}
		else {//是食物
			while (g < globavar.Allnum_Food) {
				if (strcmp(Form_Food[g].FoodName, food_or_TaoCan_Name) == 0) {
					Form_Order[i].Order_Need_FoodIndx[0] = g;//food_or_TaoCan_Name对应的食物索引赋值给Form_Order[i].Order_Need_FoodIndx[0]
					Form_Order[i].Odrder_Need_foodNum = 1;//设置订单i需要的食物数量为1
					Form_Order[i].Num_of_food_queues = 1;
					offer(Form_Food[g].tail, &Form_Order[i]);//把该订单Form_Order[i]插入该订单需要的所有食物对应的尾结点Form_Food[g].tail
					break;
				}
				g++;
			}
		}
		i++;
	}
}

//同时更新时间t
void add_one_second(struct Time* t) {
	t->second+=1;
	if (t->second < 60) {
		return;
	}
	else {
		t->second -= 60;
		t->minute += 1;
		if (t->minute < 60) {
			return;
		}
		else {
			t->minute -= 60;
			t->hour += 1;
		}
	}
}

//制作食物
void making_the_food() {
	int i = 0;
	while (i < globavar.Allnum_Food) {
		if (Form_Food[i].Food_RemainTime == 1) {//当前系统时间，该食物制作完成
			Form_Food[i].Food_CurrentSpace++;
			Form_Food[i].Food_RemainTime = Form_Food[i].Food_Prodecetion_Time;
		}
		else if (Form_Food[i].Food_CurrentSpace == Form_Food[i].Food_Max_Space) {}
		else { Form_Food[i].Food_RemainTime--;}
		i++;
	}
}

void print_the_result()
{
	int i = 0;
	while (i < globavar.Allnum_Order) {
		if (Form_Order[i].Order_Status == globavar.Order_Finished) {
			printf("%02d:%02d:%02d\n", Form_Order[i].Order_EndTime.hour, Form_Order[i].Order_EndTime.minute, Form_Order[i].Order_EndTime.second);
		}
		else if (Form_Order[i].Order_Status == globavar.Order_Inproducetion) {
			printf("Fail\n");
		}
		else if (Form_Order[i].Order_Status == globavar.Just_Arrive) {
			printf("Fail\n");
		}
		else {
			printf("Fail\n");
		}
		i++;
	}
}
int main() {
	char line1[1024] = { 0 };
	char line2[1024] = { 0 };
	FILE* file1 = fopen("dict.dic", "r");
	fscanf(file1, "%d %d", &globavar.Allnum_Food, &globavar.Allnum_Taocan);
	fgets(line1, 1024, file1);//读取第1行末尾的 \n
	get_Foods_from_file(file1);//读取食物
	fscanf(file1, "%d %d", &globavar.Maxnum_Order, &globavar.Minnum_Order);
	fgets(line2, 1024, file1);//读取第5行末尾的 \n
	Hand_TaoCan_From_File(file1);//开始读取套餐
	fclose(file1);
	scanf("%d", &globavar.Allnum_Order);
	Get_AllOrders_from_file();//读取订单
	while(Greater(&globavar.AllOrders_EndTime, &globavar.System_Start_Time)>0) {
		add_one_second(&globavar.System_Start_Time);//模拟时间流逝
		if (Greater(&globavar.System_Start_Time, &globavar.System_StopTime) > 0) {
			globavar.Is_Accept_Order = 0;
		}
		else if (globavar.System_Reopen == 1) {
			globavar.System_Reopen = 0;
			globavar.Is_Accept_Order = 1;
		}
		if (Greater(&globavar.System_Start_Time, &globavar.First_Order_StartTime) > 0) {
			making_the_food();//制作食物
		}
		//系统开始接单
		if (System_Process_Orders() == 1) {//所有食物队列为空，无需遍历
			break;
		}
	}
	print_the_result();
	return 0;
}
