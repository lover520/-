echo“＃king1”>> README.md
git init
git add README.md
git commit -m“first commit”
git remote add origin https://github.com/lover520/king1.git
 git push -u origin master

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<conio.h>
#define max 20
typedef struct school    //学院
{
char sno[max]; // 学院号
char sname[max];  //名称
char spot[max];   //地点
char head[max];  //人数
char phone[max];  //办公电话
struct school* next;
} school;
school* head;
void regist()
{
char ch;
school *s,*ptr;  //s用来建新结点，ptr用来暂存头结点
do
{
    s=(school*)malloc(sizeof(school)); // 新建一个学院结点
printf("\n开始注册...");            //开始注册
    printf("\n请输入该学院的学院号:");
    scanf("%s",s->sno);
    printf("\n请输入该学院的名称:");
    scanf("%s",s->sname);
    printf("\n请输入该学院的人数:");
    scanf("%s",s->head);
    printf("\n请输入该学院的地点:");
    scanf("%s",s->spot);
    printf("\n请输入该学院的办公电话:");
    scanf("%s",s->phone);
ptr=head;
head=s;//将新结点插入队头
s->next=ptr;
fflush(stdin);
printf("\n请问是否继续注册?(Y/N)");
scanf("%c",&ch);
}while(ch=='Y'||ch=='y');
return;
}
void ElePrint(char str[])  //输出单个元素
{
if(str==NULL) exit(0);
printf("%s",str);
for(unsigned int i=0;i<12-strlen(str);i++) printf(" ");//为了对齐输出，需插入一些空格
return;
}
int LinePrint(school *ptr) //输出一行
{
if(ptr==NULL)  //检查传进来的指针
return 0;
printf("\n");

return 1;
}
void print()  //输出全部学院信息
{
school *ptr=head;
printf("\n学院号        名称        人数        地点        办公电话          ");
while(ptr)
{
LinePrint(ptr);
ptr=ptr->next;
}
printf("\n");
return;
}
void search()//查询模块
{
int method;//查询方式
char no[max],name[max],phonem[max],heads[max],spots[max]; //用来接收查询关键字
while(1)
{
printf("\n请选择查询方式");
    printf("\n1.按学院号查询");
    printf("\n2.按名称查询");
    printf("\n3.按办公电话查询");
    printf("\n4.按人数查询");
    printf("\n5.按地点查询");
    printf("\n6.返回主菜单\n");
    scanf("%d",&method);
    school *p=head,*temp;
    switch(method)
{
       case 1:
   printf("\n请输入要查询的学院号:");
   scanf("%s",no);
   while(p)
   {
   if(!strcmp(p->sno,no))
   break;
   else
   {
   temp=p;
   p=p->next;
   }
   }
   printf("\n学院号        名称        人数        地点        办公电话         ");


LinePrint(p);
   break;
   case 2:
   printf("\n请输入要查询的名称:");
   scanf("%s",name);
   printf("\n学院号        名称        人数        地点        办公电话         ");
   while(p)
   {
   if(!strcmp(p->sname,name))
   LinePrint(p);
   p=p->next;
   }
   break;
   case 3:
   printf("\n请输入学院所在的办公电话:");
   scanf("%s",phonem);
   printf("\n学院号        名称        人数        地点        办公电话         ");
   while(p)
   {
   if(!strcmp(p->phone,phonem))
   LinePrint(p);
   p=p->next;
   }
   break;
   case 4:
   printf("\n请输入学院所在的人数:");
   scanf("%s",heads);
   printf("\n学院号        名称        人数        地点        办公电话         ");
   while(p)
   {
   if(!strcmp(p->head,heads))
   LinePrint(p);
   p=p->next;
   }
   break;

   case 5:
   printf("\n请输入学院所在的地点:");
   scanf("%s",spots);
   printf("\n学院号        名称        人数        地点        办公电话         ");
   while(p)
   {
   if(!strcmp(p->spot,spots))
   LinePrint(p);
   p=p->next;
   }
   break;

   case 6:
   return;
   default:
   printf("很抱歉，暂无此查询方式!");
   break;
}
}
}
void modify()//修改学院信息
{
char num[max];
school *p=head;
printf("\n请输入要修改的学院的学院号:");
scanf("%s",num);
printf("\n学院号        名称        人数        地点        办公电话         ");
while(p)
{
if(!strcmp(p->sno,num))
break;
else
p=p->next;
}
if(p==NULL)
{
printf("\n错误：没有此学院的信息!\n");
return;
}
LinePrint(p);
printf("\n请输入要修改的该学院的信息:");
printf("\n1.学院号");
printf("\n2.名称");
printf("\n3.地点");
printf("\n4.人数");
printf("\n5.办公电话\n");
char number[max],name1[max],spot1[max],head1[max],phone1[max];
int select;
fflush(stdin);
scanf("%d",&select);
printf("\n请输入新的信息:");
switch(select)
{
case 1:
scanf("%s",number);
strcpy(p->sno,number);
break;
case 2:
scanf("%s",name1);
strcpy(p->sname,name1);
break;
case 3:
scanf("%s",spot1);
strcpy(p->spot,spot1);


break;
case 4:
scanf("%s",head1);
strcpy(p->head,head1);
break;
case 5:
scanf("%s",phone1);
strcpy(p->phone,phone1);
break;
default:
printf("\nError!");
break;
}
printf("\n学院号        名称        人数        地点        办公电话         ");
LinePrint(p);
return;
}
void del()// 删除某学院的信息
{
school *p=head,*temp=head,*s;
char num1[max];
printf("\n请输入要删除的学院的学院号:");
scanf("%s",num1);
while(p)//查找该学院所在的结点
{
if(!strcmp(p->sno,num1))
break;
else
{
temp=p;
p=p->next;
}
}//while
if(!p)
{
printf("\n不存在此学院的信息.");
return;
}
LinePrint(p);//输出该学院的信息
printf("\n请问真的要删除该学院的信息吗?(Y/N)");
char ch;
fflush(stdin);
scanf("%c",&ch);
if(ch=='Y'||ch=='y')
{
s=p->next;
temp->next=s;
free(p);
printf("\n已经删除该学院的信息.");
}
return;
}
void quit()
{
char ch;
printf("\n真的要退出？(Y/N)");
fflush(stdin);
scanf("%c",&ch);
if(ch=='Y'||ch=='y')
exit(0);
return;
}
int main()
{
int option;
printf("\n欢迎使用学院信息管理系统!\n");
//登录模块

//办公电话统界面
while(1)
{
printf("\n\n请选择需要的服务:");
    printf("\n1.输入数据");
    printf("\n2.查询数据");
    printf("\n3.修改数据");
    printf("\n4.删除数据");
    printf("\n5.退出\n");
scanf("%d",&option);
switch(option)
{
case 1:
regist();
break;
case 2:
search();
break;
case 3:
modify();
break;
case 4:
del();
break;
case 5:
quit();
break;
}
}
return 0;
}
