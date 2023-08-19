#include <stdio.h>
#include <stdlib.h>
#include <windows.h>//system("cls");清屏
#include <string.h> 
 
 struct Staff {  //员工信息结构体
	int Number;        //职工号号
	char name[20];     //姓名
	char sex;        // 性别
	int  age;          // 年龄
	char education[20]; //学历
	float wages;        //工资
	char  addr[20];     //住址
	char Tel[15];      //电话
};
struct Staff Staffer[100],Staffer1;
 
//功能函数声明
void menu();  //主菜单
void input();  //输入员工信息
void save(int m);   //存储信息
int  read();    // 读取信息
void display();//浏览信息
void add()  ;   //添加
void search();  //查找
void search_name();  //按编号查找
void search_EDU();  //按学历查找
void search_wages();  //按工资查找
void Delete();  //删除操作
void change();  //修改操作
void order();   //排序操作
void order_Num();  //按职工号排序    //浏览信息时按照职工号由小到大顺序排序
void order_name();//按职工姓名排序
void order_age();//按职工年龄排序
 
//主函数
 
int main()   
{   int n,f;
	while(1)
	{  
		do {          
			menu(); //*调用菜单函数*
			printf("请输入你需要操作的序号(1-8):  ");
			scanf("%d",&n);          
			if(n>=1&&n<=8)  {          
				f=1;         break;
			}             
			else {        
				f=0; 
				system("cls");
				printf("\n\t\t\t您输入有误，请重新选择!");
			}  
		}while(f==0); 
		switch(n)   {       
			case 1:   system("cls");
					  printf("\n");
					  printf("\t\t\t  录入职工信息\n\n");
					  input();  
					  break;         
			case 2:   system("cls");
					  printf("\n");
					  printf("\t\t\t\t浏览职工信息\n");
					  display();
					  printf("\n按Enter键继续\n"); 
					  getchar();  
					  getchar();
					  system("cls");
					  break;
			case 3:   system("cls");
					  printf("\n");
					  printf("\t\t\t\t查询职工信息\n");
					  search();  
					  break;         
			case 4:   system("cls");
					  printf("\n");
					  printf("\t\t\t\t删除职工信息\n\n"); 
					  Delete();  
			case 5:   system("cls");
					  printf("\n");
					  printf("\t\t\t\t修改职工信息\n");
					  display();                     /* 调用浏览函数*/  
					  change();
					  break; 
			case 6:   system("cls");
					  printf("\n");
					  printf("\t\t职工信息排序\n");
					  order();
					  break;     
			case 7:   system("cls");
					  printf("\n");
					  printf("\t\t添加职工信息\n\n");
					  add()  ;
					  break;     
			case 8:	  system("cls");        
					  printf("\n\n\n\n\n\n\t\t\tThank you for using !\n\n\n\n\n\n");
					  getchar();
					  getchar();
					  exit(8);
					  break;
			}  
	}
}
 
//其他函数
 
void menu()   /*菜单函数*/
{      
	printf("\n\n");
	printf("                             Welcome to                          \n"); 
	printf("            Staff Information Management System (SIMS)           \n\n"); 
	printf("*****************************************************************\n");
	printf("*          1.录入职工信息");	printf("	§	2.浏览职工信息          *\n");
	printf("*          3.查询职工信息");	printf("	§	4.删除职工信息          *\n");
    printf("*          5.修改职工信息");	printf("	§	6.职工信息排序          *\n");
    printf("*          7.添加职工信息");	printf("	§	8.退出职工系统          *\n");
	printf("*****************************************************************\n");
	printf("\n");     
}
 
void input()   /*录入函数*/ 
{   int i,m,num=0;     
	printf("请输入需要创建信息的职工人数(1--100): ");
    scanf("%d",&m); 
	system("cls");
	printf("\n");
	if(m>100)  
	{
		printf("\t\t\t超出范围！请重新输入。\n");
		input();
	}
	else{ 
		for (i=0;i<m;i++)   
		{   printf("第%d个员工信息输入（按回车确认输入）：\n", i+1);
			printf("请输入职工号： ");
			scanf("%d",&num);
			for(int j=0;j<i;j++)
				if(Staffer[j].Number==num)
				{	printf("职工号为 %d 的员工已存在，请重新输入：",num);
					scanf("%d",&num);
					j=0;
				}
			Staffer[i].Number=num;
			printf("请输入姓名：  ");  
			scanf("%s",Staffer[i].name);
			printf("请输入性别（F/M）：  "); 
			getchar();
			scanf("%c",&Staffer[i].sex); 
			printf("请输入年龄：  "); 
			scanf("%d",&Staffer[i].age);  
			printf("请输入学历：  ");  
			scanf("%s",Staffer[i].education);  
			printf("请输入工资：  ");   
			scanf("%f",&Staffer[i].wages);
			printf("请输入住址：  ");   
			scanf("%s",Staffer[i].addr);
			printf("请输入电话：  ");   
			scanf("%s",Staffer[i].Tel);
			system("cls"); 
			printf("\n一个新职工的信息档案创建完毕！\n\n");        
		 }       
		save(m);
		printf("");
	} 
} 
 
void save(int m)  /*保存文件函数*/ 
{    int i;
     FILE *fp;
     if ((fp=fopen("D:\\Staff_list.dat","wb"))==NULL) /*创建文件并判断是否能打开*/    
	 {  printf ("cannot open file!\n");
		exit(0); 
	 }     
	 for (i=0;i<m;i++) /*将内存中职工的信息输出到磁盘文件中去*/  
	if (fwrite(&Staffer[i],sizeof(struct Staff),1,fp)!=1)
		printf("file write error!\n");   
	fclose(fp); 
}  
 
int read()  /*导入函数*/ 
{   FILE*fp;  
	int i=0;    
	if((fp=fopen("D:\\Staff_list.dat","rb"))==NULL)
	{   printf ("cannot open file!\n");
		exit(0);      
    } 
	else 
	{   
		do {         
			fread(&Staffer[i],sizeof(struct Staff),1,fp); 
			i++;
			}while(feof(fp)==0); 
	}  
	fclose(fp);
	return(i-1); 
}      
 
void display()  /*浏览函数*/
{   int i; 
    int m=read();
	printf("\n贵公司所有职工信息:\n"); //printf("\n 原有职工信息:\n"); 
	printf("\n职工号\t姓名\t性别\t年龄\t学历\t    工资\t住址\t 电话   \n"); 
	order_Num();
	for(i=0;i<m;i++)        
		printf("\n  %d\t%s\t  %c\t %d\t%s\t %9.2f\t%s\t%s\n",Staffer[i].Number,Staffer[i].name,   Staffer[i].sex,Staffer[i].age,Staffer[i].education,Staffer[i].wages,Staffer[i].addr,Staffer[i].Tel);
	printf("\n");
} 
 
  
void Delete()   /*删除函数*/ 
{	int m=read();
	int i,j,t,n, f,Num;
	display();  /*调用浏览函数*/
	printf("请输入要删除的职工的职工号:  "); 
	scanf("%d",&Num);  
	for(f=1,i=0;f&&i<m;i++) 
	{    if(Staffer[i].Number==Num)
		{    
			printf("\n已找到此人，原始记录为：\n"); 
			printf("\n职工号\t姓名\t性别\t年龄\t学历\t    工资\t住址\t 电话    \n"); 
			printf("\n  %d\t%s\t  %c\t %d\t%s\t %9.2f\t%s\t%s\n",Staffer[i].Number,Staffer[i].name,   Staffer[i].sex,Staffer[i].age,Staffer[i].education,Staffer[i].wages,Staffer[i].addr,Staffer[i].Tel);
			printf("\n确认删除请按 1，取消删除请按 0: ");    
			scanf("%d",&n);              
			if(n==1)   /*如果删除，则其他的信息都向前移一行*/   
			{ 	for(j=i;j<m-1;j++)
					 Staffer[j]=Staffer[j+1];      /*当找到第j个职工时,for语句后j自加了1,所以下面的应该把改后的  信息赋值给第j-1个人*/      
				f=0; 
			}
			else f=2;
		} 
 
	}
	system("cls");
   switch(f){
		case 0: m=m-1;
				printf("\n\t\t\t\t删除成功！\n"); 
				save(m);     /*调用保存函数*/    
			    display();  /*调用浏览函数*/
				break;
		case 1: printf("\n\t\t\t对不起，贵公司没有该员工!\n");    
			    display();  /*调用浏览函数*/
				break;
		case 2: printf("\n\t\t\t\t取消删除！\n");
				break;
	}   
      //display();  /*调用浏览函数*/
   printf("\n继续删除请按1，返回主菜单请按0: "); 
   scanf("%d",&t); 
   system("cls");
   switch(t) 
   {    case 1:  Delete(); 
			     break;     
		case 0:  system("cls");
				 main();
				 break; 
		default: break;
   }
    system("cls"); 
} 
 
void add()  /* 添加函数*/
{   int n=read();  
	int i,m,num=0;    
	printf("请输入需要添加信息的职工人数: ");    
	scanf("%d",&m);    
	if(m+n>100)  {
		system("cls");
		printf("\n对不起，你所构建的职工人数超出范围。请重新输入（0至%d之间）：\n\n",100-n);
		add();
	}
	else{
		for (i=n;i<m+n;i++)    
		{	printf("第%d个员工信息输入（按回车确认输入）： \n", i+1);
			printf("请输入职工号： ");
			scanf("%d",&num);
			for(int j=0;j<i;j++)
				if(Staffer[j].Number==num)
				{	printf("职工号为 %d 的员工已存在，请重新输入：",num);
					scanf("%d",&num);
					j=0;
				}
			Staffer[i].Number=num;
			printf("请输入姓名：  ");  
			scanf("%s",Staffer[i].name);
			printf("请输入性别（F/M）：  "); 
			getchar();
			scanf("%c",&Staffer[i].sex); 
			printf("请输入年龄：  "); 
			scanf("%d",&Staffer[i].age);  
			printf("请输入学历：  ");  
			scanf("%s",&Staffer[i].education);  
			printf("请输入工资：  ");   
			scanf("%f",&Staffer[i].wages);
			printf("请输入住址：  ");   
			scanf("%s",&Staffer[i].addr);
			printf("请输入电话：  ");   
			scanf("%s",&Staffer[i].Tel);
			system("cls"); 
			printf("\n一个职工的信息档案创建完毕！请输入下一个职工的信息\n"); 
			printf("\n");        
		}      
		save(m+n);
		system("cls"); 
		printf("\n添加职工档案完成!  \n"); 
		display();
		printf("\n按Enter键继续\n"); 
		getchar();  
		getchar();
		system("cls");
	}
 }
 
void search()/*查询函数*/
{   int t,f;
	do {      
		printf("\n按姓名查询请按 1;  按学历查询请按 2;  按工资查询请按 3;  进入主菜单按 0: ");
		scanf("%d",&t);     
		if(t>=0&&t<=4)    
		{     f=1;     break;     } 
		else {    f=0;     printf("您输入有误，请重新选择!");     }
	}while(f==0);
	system("cls");
	while(f==1) {      
		switch(t)     
		{   case 0: main();
				    break;
			case 1: printf("\n按姓名查询\n");
					search_name();
					break;      
			case 2: printf("\n按学历查询\n");
				    search_EDU();
					break; 
			case 3: printf("\n按工资查询\n");
				    search_wages();
					break; 
			default:break; 
		}      
		system("cls");     
	} 
}  
 
void search_name()/*按姓名查找函数*/ 
{   char name1[20];   
	int i,t,n=0;    
	int m=read();   
	printf("\n请输入要查找的姓名:  "); 
	scanf("%s",name1);   
	for(i=0;i<m;i++)      
		if(strcmp(name1,Staffer[i].name)==0) 
		{   
			if(n==0) 
			{	printf("\n已找到以下信息：\n");
				printf("\n职工号\t姓名\t性别\t年龄\t学历\t    工资\t住址\t 电话    \n"); 
			}
			n++;
			printf("\n  %d\t%s\t  %c\t %d\t%s\t %9.2f\t%s\t%s\n",Staffer[i].Number,Staffer[i].name,   Staffer[i].sex,Staffer[i].age,Staffer[i].education,Staffer[i].wages,Staffer[i].addr,Staffer[i].Tel);
		}     
	if(n==0)  
	{	printf("\n对不起，贵公司没有该员工!\n"); 
		getchar();getchar();
	}
	else  
	{	printf("\n查询到有 %d 个员工符合要求。\n",n);
		printf("\n");    
		printf("删除员工请按 1，修改信息请按 2，继续查询请按 3，返回上一层请按 4，\n\n\t\t\t返回主菜单请按 0 ：");
		scanf("%d",&t);    
		switch(t)
		{	case 0: system("cls");   
					main();
					break;  
			case 1: Delete();
					break;  
			case 2: change();
					break; 
			case 3: break;
			case 4: system("cls");   
					search();
					break;
			default:break;    
		}  
	}
}  
 
void search_EDU()/*按学历查找函数*/ 
{   char education1[20];  
	int i,t,n=0; 
	int m=read(); 
	printf("\n请输入要查找的学历: ");
	scanf("%s",education1);  
	for(i=0;i<m;i++)      
		if(strcmp(education1,Staffer[i].education)==0) 
		{   
			if(n==0)   
			{	printf("\n已找到以下员工，其记录为：\n"); 
				printf("\n职工号\t姓名\t性别\t年龄\t学历\t    工资\t住址\t 电话    \n"); 
			}
			n++;
			printf("\n  %d\t%s\t  %c\t %d\t%s\t %9.2f\t%s\t%s\n",Staffer[i].Number,Staffer[i].name,   Staffer[i].sex,Staffer[i].age,Staffer[i].education,Staffer[i].wages,Staffer[i].addr,Staffer[i].Tel);
		}
	if(n==0)  
	{	printf("\n对不起，贵公司没有该员工!\n"); 
		getchar();getchar();
	}
	else 
	{	printf("\n查询到有 %d 个员工符合要求。\n",n);
		printf("\n");    
		printf("删除员工请按 1，修改信息请按 2，继续查询请按 3，返回上一层请按 4，\n\n\t\t\t返回主菜单请按 0 ：");
		scanf("%d",&t);    
		switch(t)
		{	case 0: system("cls");   
					main();
					break;  
			case 1: Delete();
					break;  
			case 2: change();
					break; 
			case 3: break;
			case 4: system("cls");   
					search();
					break;
			default:break;    
		}
	}
} 
 
void search_wages()/*按工资查找函数*/ 
{   float wages1;  
	int i,t,n=0; 
	int m=read(); 
	printf("\n请输入要查找的工资数额:  ");
	scanf("%f",&wages1);  
	for(i=0;i<m;i++)      
		if(wages1==Staffer[i].wages) 
		{   
			if(n==0)
			{	printf("\n已找到此员工，其记录为：\n"); 
				printf("\n职工号\t姓名\t性别\t年龄\t学历\t    工资\t住址\t 电话    \n"); 
			}
			n++;
			printf("\n  %d\t%s\t  %c\t %d\t%s\t %9.2f\t%s\t%s\n",Staffer[i].Number,Staffer[i].name,   Staffer[i].sex,Staffer[i].age,Staffer[i].education,Staffer[i].wages,Staffer[i].addr,Staffer[i].Tel);
			break; 
		}     
	if(n==0)  
	{	printf("\n对不起，贵公司没有该员工!\n"); 
		getchar();
		getchar();
	}
	else  
	{	printf("\n查询到有 %d 个员工符合要求。\n",n);
		printf("\n");    
		printf("删除员工请按 1，修改信息请按 2，继续查询请按 3，返回上一层请按 4，\n\n\t\t\t返回主菜单请按 0 ：");
		scanf("%d",&t);    
		switch(t)
		{	case 0: system("cls");   
					main();
					break;  
			case 1: Delete();
					break;  
			case 2: change();
					break; 
			case 3: break;
			case 4: system("cls");   
					search();
					break;
			default:break;    
		} 
	}
} 
	
void change()  /*修改函数*/ 
{   int Number;        //职工号号
	char name[20];     //姓名
	char sex;        // 性别
	int  age;          // 年龄
	char education[20]; //学历
	float wages;        //工资
	char  addr[20];     //住址
	char Tel[15];      //电话
	int b=1,c,i,n,t,k=0; 
	int m=read();               /*导入文件内的信息*/ 
	printf("\n");      
	printf("请输入要修改的职工的职工号:  ");
	scanf("%d",&Number);
	system("cls");
	for(i=0;i<m;i++)
	{   if(Staffer[i].Number==Number) 
		{  	k=1;
			printf("\n已找到该职工号员工，其记录为：\n"); 
			printf("\n职工号\t姓名\t性别\t年龄\t学历\t    工资\t住址\t 电话    \n");
			printf("\n  %d\t%s\t  %c\t %d\t%s\t %9.2f\t%s\t%s\n",Staffer[i].Number,Staffer[i].name,   Staffer[i].sex,Staffer[i].age,Staffer[i].education,Staffer[i].wages,Staffer[i].addr,Staffer[i].Tel);
			printf("\n确认修改请按1，取消修改请按0：");
			scanf("%d",&n);             
			if(n==1)      
			{   printf("\n需要进行修改的选项\n 1.职工号  2.姓名  3.性别  4.年龄  5.学历  6.工资  7.住址  8.电话  \n");
				printf("请输入你想修改的那一项序号:  ");  
                scanf("%d",&c);               
				do  {       
					switch(c)     
					{   case 1: printf("职工号改为: ");
								scanf("%d",&Number);                   
								Staffer[i].Number=Number;                
								break;                  
						case 2: printf("姓名改为: "); 
								scanf("%s",name);         
								strcpy(Staffer[i].name,name);
								break;     
						case 3: printf("性别改为："); 
								scanf("%c",&sex);
								Staffer[i].sex=sex;
								break;   
						case 4: printf("年龄改为: "); 
								scanf("%d",&age);
								Staffer[i].age=age;
								break; 
						case 5: printf("学历改为: "); 
								scanf("%s",education);
								strcpy(Staffer[i].education,education);
								break; 
						case 6: printf("基本工资改为: "); 
								scanf("%f",&wages);
								Staffer[i].wages=wages; 
								break;      
						case 7: printf("住址改为: ");
								scanf("%s",&addr); 
								strcpy(Staffer[i].addr,addr);
								break;               
						case 8: printf("电话改为: ");  
								scanf("%s",Tel); 
								strcpy(Staffer[i].Tel,Tel);  
								break;               
					}            
					printf("\n确认修改 请按1，重新输入 请按2:   "); 
					scanf("%d",&b); 
					if(b==1)
					{
						system("cls");
						save(m);//储存修改后的数据
						printf("\n");    
						display();//浏览修改后的数据
					}
				} while(b==2);
			}        	
		} 
 
		else if(i==(m-1)) i++;        
	}   
	if(k==0) {
		printf("\n对不起，您输入有误!\n");
	    getchar();
		getchar();
	}
	else{
		printf("\n继续修改请按 1，退出修改请按 0:  "); 
	    scanf("%d",&t);
	}
	system("cls");
	switch(t) 
	{   case 1: display();
				change();//返回修改函数
				break; 
		case 0: break;   
		default:break; 
	}
	system("cls"); 
}  
 
 void order()/*排序函数*/    
 {  int d,f;
	do {     
		printf("\n按姓名排序请按 1，按年龄排序请按 2，返回主菜单请按 0:  "); 
		scanf("%d",&d);     
		if(d>=0&&d<=2) 
		{    f=1;     break;     }  
		else    
		{   f=0;    
			printf("对不起，您输入有误，请重新选择!");
		}
	}while(f==0);
	system("cls");
	while(f==1) {     
		switch(d) 
		{   case 1: printf("\n按姓名排序为(字母由小到大排列)：\n");
					order_name();
					break;   
			case 2: printf("\n按年龄排序为(由低到高排列)：\n");
					order_age();
					break;      
			case 0: system("cls");
					main();
					break;      
    
		}      
		system("cls");
	}     
}
 
 void order_Num()/*按职工号排序函数*/    //浏览信息时按照职工号由小到大顺序排序
{  int i,j;   
   int m=read();
   for(i=0;i<m-1;i++)
	   for(j=0;j<m-1-i;j++) 
		   if(Staffer[j].Number>Staffer[j+1].Number)/*排序*/   
		   {    Staffer1=Staffer[j];
				Staffer[j]=Staffer[j+1];
				Staffer[j+1]=Staffer1;
		   }  
   save(m); //按职工号由小到大的顺序存储
} 
 
void order_name()/*按姓名排序函数*/ 
{  int i,j,k; 
   int m=read();
   for(i=0;i<m-1;i++)
	   for(j=0;j<m-1-i;j++)/*冒泡法排序*/ 
		   if(strcmp(Staffer[j].name,Staffer[j+1].name)>0)
		   {    Staffer1=Staffer[j];
				Staffer[j]=Staffer[j+1];
				Staffer[j+1]=Staffer1;
		   }    
		save(m);   //按姓名存储
		printf("\n职工号\t姓名\t性别\t年龄\t学历\t    工资\t住址\t 电话    \n"); 
	    for(i=0;i<m;i++)        
			printf("\n  %d\t%s\t  %c\t %d\t%s\t %9.2f\t%s\t%s\n",Staffer[i].Number,Staffer[i].name,   Staffer[i].sex,Staffer[i].age,Staffer[i].education,Staffer[i].wages,Staffer[i].addr,Staffer[i].Tel);
		printf("\n返回上一层请按 1，返回主菜单请按 0:  ");   
		scanf("%d",&k);   
		switch(k) 
		{   case 1: system("cls");
					order(); //调用排序函数
					break;        
			case 0: system("cls");	
					main();
					break;    
			default:break;   
		}
	system("cls"); 
}  
 
void order_age()/*按年龄排序函数*/    
{  int i,k,j;   
   int m=read();
   for(i=0;i<m-1;i++)
	   for(j=0;j<m-1-i;j++) 
		   if(Staffer[j].age>Staffer[j+1].age)/*排序*/   
		   {    Staffer1=Staffer[j];
				Staffer[j]=Staffer[j+1];
				Staffer[j+1]=Staffer1;
		   }  
		save(m); //按年龄由低到高顺序存储 
		printf("\n职工号\t姓名\t性别\t年龄\t学历\t    工资\t住址\t 电话    \n"); 
	    for(i=0;i<m;i++)        
			printf("\n  %d\t%s\t  %c\t %d\t%s\t %9.2f\t%s\t%s\n",Staffer[i].Number,Staffer[i].name,   Staffer[i].sex,Staffer[i].age,Staffer[i].education,Staffer[i].wages,Staffer[i].addr,Staffer[i].Tel);
		printf("\n返回上一层请按 1，返回主菜单请按 0:  "); 
		scanf("%d",&k);    
		switch(k)    
		{    case 1: system("cls");
					 order();
			   	   	 break;      
			 case 0: system("cls"); 
					 main();
					 break;    
			 default:break;    
		}
	system("cls"); 
} 
