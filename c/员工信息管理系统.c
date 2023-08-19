#include<stdio.h> 
#include<string.h>
#include <stdlib.h>
struct Staff 
{  
	int Number;        
	char name[10];     
	char sex[2];        
	int  age;          
	float pay;        
	char  addr[20];     
	char Tel[15];     
};
struct Staff Staffer[10],Staffer1;

void menu()
{

	printf("\n\n");
	printf("                       欢迎来到                               \n");
	printf("                   员工信息管理系统                           \n"); 
	printf("**************************************************************\n");
	printf("       1.录入员工信息");    printf("      2.添加员工信息       \n");
	printf("       3.查询员工信息");    printf("      4.修改员工信息       \n");
	printf("       5.删除员工信息");    printf("      6.员工信息排序   \n");
	printf("       7.浏览员工信息");    printf("      8.退出           \n");
	printf("**************************************************************\n");
	printf("\n");
}

int luru(int *n)
{
	int i=0,t;
	do
	{ 
		    printf("输入第%d员工信息\n",i+1);
			printf("输入工号");
			scanf("%ld",&Staffer[i].Number);
			fflush(stdin);
			printf("输入名字");
			gets(Staffer[i].name);
	     	 fflush(stdin);
			 printf("输入性别");
			 	gets(Staffer[i].sex);
			  fflush(stdin);
			  printf("输入年龄");
			  scanf("%d",&Staffer[i].age);
			  fflush(stdin);
			  printf("输入工资");
			  scanf("%f",&Staffer[i].pay);
			  fflush(stdin);
			  printf("输入地址");
			  	gets(Staffer[i].addr);
			  fflush(stdin);
			  printf("输入电话");
			  	gets(Staffer[i].Tel);
		      i++;
	    printf("是否结束录入\n");
	    printf("输入1继续，输入0结束:"); 
	    scanf("%d",&t);
	    
    }while(t);	
	*n=i;
	printf("输入人数为%d\n",*n);
}




void display(int *n)  
{  
    int i,a;
	do{	
	printf("\n贵公司所有职工信息:\n"); //printf("\n 原有职工信息:\n"); 
	printf("\n     职工号  姓名 性别  年龄\t工资\t\t住址\t电话\n"); 
	for(i=0;i<*n;i++)        
	{
		
		printf("  %8d   %4s   %s\t  %2d   %f   %8s %8s",Staffer[i].Number,
		Staffer[i].name,
		Staffer[i].sex,
		Staffer[i].age,
		Staffer[i].pay,
		Staffer[i].addr,
		Staffer[i].Tel);
        printf("\n");
	} 
	printf("是否返回菜单（1继续，0结束）：");
	scanf("%d",&a); 	    
}while(a);
}   

void paixu(int *n)
{
	int i,j,a,s;
	int Number1; 
    char name1[20];     //姓名
	char sex1[2];        // 性别
	int  age1;          // 年龄	
	float pay1;        //工资
	char  addr1[20];     //住址
	char Tel1[15];      //电话
	do{
	for(i=0;i<*n-1;i++)
	{
		for(j=1;j<*n;j++)
		{
			if(Staffer[i].pay<Staffer[j].pay)
			{
				pay1=Staffer[j].pay;
				Staffer[j].pay=Staffer[i].pay;
				Staffer[i].pay=pay1;
				age1=Staffer[j].age;
				Staffer[j].age=Staffer[i].age;
				Staffer[i].age=age1;
				strcpy(name1,Staffer[j].name);
				strcpy(Staffer[j].name,Staffer[i].name);
				strcpy(Staffer[i].name,name1);
				strcpy(sex1,Staffer[j].sex);
				strcpy(Staffer[j].sex,Staffer[i].sex);
				strcpy(Staffer[i].sex,sex1);
				strcpy(addr1,Staffer[j].addr);
				strcpy(Staffer[j].addr,Staffer[i].addr);
				strcpy(Staffer[i].addr,addr1);
				strcpy(Tel1,Staffer[j].Tel);
				strcpy(Staffer[j].Tel,Staffer[i].Tel);
				strcpy(Staffer[i].Tel,Tel1);
				Number1=Staffer[j].Number;
				Staffer[j].Number=Staffer[i].Number;
				Staffer[i].Number=Number1;	
			}
		}
		} 
	printf("\n贵公司所有职工信息:\n"); //printf("\n 原有职工信息:\n"); 
	printf("\n职工号\t姓名\t性别\t年龄\t工资\t住址\t电话\n"); 
	for(a=0;a<*n;a++)        
	{
		fflush(stdin);
		printf("%8d,%4s,%s,%2d,%f,%8s,%8s",Staffer[a].Number,
		Staffer[a].name,
		Staffer[a].sex,
		Staffer[a].age,
		Staffer[a].pay,
		Staffer[a].addr,
		Staffer[a].Tel);
        printf("\n");
	} 
	printf("是否返回菜单（1继续，0结束）：");
	scanf("%d",&s); 	    
}while(s);
		   
	
 }
 void shanchu(int *n)
 {
 	FILE *fp;
	 char name1[10];
	 int i,j,k,t;
	 printf("要删除的学生姓名：");
	 scanf("%s",name1);
	 fp=fopen("D:\\data.txt","r");
	 for(i=0;i<*n;i++)
	 {
	 	fscanf(fp, "%d%s%s%d%f%s%s",&Staffer[i].Number,
		 Staffer[i].name,
		 Staffer[i].sex,
		 &Staffer[i].age,
		 &Staffer[i].pay,
		 Staffer[i].addr,
		 Staffer[i].Tel);
	    if(!strcmp(Staffer[i].name,name1))
	    {
	    	printf("\n     职工号  姓名 性别  年龄\t工资\t\t住址\t电话\n");
	    	printf("  %8d   %4s   %s\t  %2d   %f   %8s %8s",Staffer[i].Number,
		Staffer[i].name,
		Staffer[i].sex,
		Staffer[i].age,
		Staffer[i].pay,
		Staffer[i].addr,
		Staffer[i].Tel);
	    	printf("是否删除\n");
			printf("删除按1，取消按2");
			scanf("%d",&t); 
	    	break;
			 
		}
    }
    fclose(fp);
    if(i==*n)
    {
    	printf("未找到信息\n");
    	
	}
	switch (t)
	{
		case 1:
		{
		for(j=i;j<*n-1;j++)
		{
			for(k=0;k<10;k++)
			{
				Staffer[j].name[k]= Staffer[j+1].name[k];
			}
			Staffer[j].Number=Staffer[j+1].Number;
	    	strcpy(	Staffer[j].sex,Staffer[j+1].sex);
			Staffer[j].age=Staffer[j+1].age;
			Staffer[j].pay=Staffer[j+1].pay;
			strcpy(Staffer[j].addr,Staffer[j+1].addr);
			strcpy(Staffer[j].Tel,Staffer[j].Tel);
		}
		fp=fopen("D:\\data.txt","w");
		fclose(fp);
		
		for(j=0;j<2;j++)
		{
			fprintf(fp, "%8d\t%4s\t%s\t%2d\t%f\t%8s\t%8s\n",Staffer[j].Number,
			Staffer[j].name,
			Staffer[j].sex,
			Staffer[j].age,
			Staffer[j].pay,
			Staffer[j].addr,
			Staffer[j].Tel);
		}
		fclose(fp);
	}
	*n=*n-1;
   break;
   case 2:
   main();
   break;}
	
  }
void tianjia(int *n)
{
	char name[20];     //姓名
	char sex[2];        // 性别
	int  age;          // 年龄	
	float pay1;        //工资
	char  addr[20];     //住址
	char Tel[15];      //电话
	    int i=*n,q,m,c;
	    printf("输入要添加的员工\n");
	    	printf("输入工号");
		    scanf("%ld",&Staffer[i].Number);
		for(m=0;m<*n;m++)
		{
			if(Staffer[i].Number==Staffer[m].Number)
			{
			printf("已有该员工，请重新输入"); 
			printf("\n需要进行修改的选项\n  1.姓名  2.性别  3.年龄    4.工资  5.住址  6.电话  \n");
				printf("请输入你想修改的那一项序号:  "); 
				fflush(stdin);
                scanf("%d",&c);               
					switch(c)     
					{                     
						case 1: printf("姓名改为: "); 
								scanf("%s",name);         
								strcpy(Staffer[m].name,name);
								break;     
						case 2: printf("性别改为："); 
								scanf("%s",sex);
							strcpy(Staffer[m].sex,sex);
								break;   
						case 3: printf("年龄改为: "); 
								scanf("%d",&age);
								Staffer[m].age=age;
								break; 
						case 4: printf("基本工资改为: "); 
								scanf("%f",&pay1);
								Staffer[m].pay=pay1; 
								break;      
						case 5: printf("住址改为: ");
								scanf("%s",&addr); 
								strcpy(Staffer[m].addr,addr);
								break;               
						case 6: printf("电话改为: ");  
								scanf("%s",Tel); 
								strcpy(Staffer[m].Tel,Tel);  
								break;   
			}
			break;
	  }
	}
	if(m>=*n)
	{
		printf("输入名字");
		scanf("%s",Staffer[i].name);
		fflush(stdin);
		printf("输入性别");
		scanf("%2s",Staffer[i].sex);
		fflush(stdin);
		printf("输入年龄");
		scanf("%2d",&Staffer[i].age);
		fflush(stdin);
		printf("输入工资");
		scanf("%4f",&Staffer[i].pay);
		fflush(stdin);
		printf("输入地址");
		scanf("%8s",Staffer[i].addr);
		fflush(stdin);
		printf("输入号码"); 
		scanf("%8s",Staffer[i].Tel);
		fflush(stdin);	
		printf("是否结束添加\n");
		printf("继续1结束0:\n");
		scanf("%d",&q);
		i++;
     	*n=i;
     }
     
}

void search(int *n)
{
	char name1[10];
	long number1;
	int i,t,w=0;
	
	printf("\n请输入要查找的名字");
	scanf("%s",name1);
	for(i=0;i<*n;i++)
		if(strcmp(name1,Staffer[i].name)==0)
		{
			printf("\n已找到以下信息:\n");	
			w++;
			printf("%8d,%4s,%s,%2d,%f,%8s,%8s",Staffer[i].Number,
			Staffer[i].name,
			Staffer[i].sex,
			Staffer[i].age,
			Staffer[i].pay,
			Staffer[i].addr,
			Staffer[i].Tel);
		}
	if(w==0)
	{
		printf("no");
	}
	if(w>1)
	{
		printf("\n请输入该员工的工号");
		scanf("%ld",&number1);
		for(i=0;i<*n;i++)
		{
			if(number1==Staffer[i].Number)
			{
			 printf("%8d,%4s,%s,%2d,%f,%8s,%8s",Staffer[i].Number,
			 Staffer[i].name,
			 Staffer[i].sex,
			 Staffer[i].age, 
			 Staffer[i].pay,
			 Staffer[i].addr,
			 Staffer[i].Tel);
		}
	}
}
}
void writetofile(int n)
{
	FILE *fp;
	int i,j;
	if((fp=fopen("D:\\data.txt","w+"))==NULL)
	{
		printf("Failure to open data.txt\n");
		exit(0);
	}
	for(i=0;i<n;i++)
	{
		
	
		fprintf(fp, "%8d %4s %s %2d %f %8s %8s\n",Staffer[i].Number,
		Staffer[i].name,
		Staffer[i].sex,
		Staffer[i].age,
		Staffer[i].pay,
		Staffer[i].addr,
		Staffer[i].Tel);
	}

	fclose(fp);
}
void ReadfromFile(int *n)
{
	
	FILE *fp;
	int i;
	if((fp=fopen("D:\\data.txt","r"))==NULL)
	{
		printf("Failure to open data.txt\n");
		exit(0);
	}
	else
	{
	for(i=0;i<*n;i++)
	{
	fscanf(fp,"%d",&Staffer[i].Number);
	fscanf(fp,"%s",Staffer[i].name);
	fscanf(fp,"%s",Staffer[i].sex);
	fscanf(fp,"%d",&Staffer[i].age);
	fscanf(fp,"%f",&Staffer[i].pay);
	fscanf(fp,"%s",Staffer[i].addr);
	fscanf(fp,"%s",Staffer[i].Tel);
	
	}
}
	fclose(fp);
	
}
void xiugai(int *n)
{
	char name[20];     //姓名
	char sex[2];        // 性别
	int  age;          // 年龄	
	float pay1;        //工资
	char  addr[20];     //住址
	char Tel[15];      //电话
	int number1,i,c,t;
	printf("输入需要修改的工号");
	scanf("%d",&number1);
	for(i=0;i<*n;i++)
	{
		if(Staffer[i].Number==number1)
		break;	
	} 
	 if(i>=*n)
	 printf("没找到对应工号");
	 else
	 {
	 	printf("\n需要进行修改的选项\n  1.姓名  2.性别  3.年龄    4.工资  5.住址  6.电话  \n");
				printf("请输入你想修改的那一项序号:  "); 
				fflush(stdin);
                scanf("%d",&c);               
				do  {       
					switch(c)     
					{                     
						case 1: printf("姓名改为: "); 
								scanf("%s",name);         
								strcpy(Staffer[i].name,name);
								break;     
						case 2: printf("性别改为："); 
								scanf("%s",sex);
							    strcpy(Staffer[i].sex,sex);
								break;   
						case 3: printf("年龄改为: "); 
								scanf("%d",&age);
								Staffer[i].age=age;
								break; 
						case 4: printf("基本工资改为: "); 
								scanf("%f",&pay1);
								Staffer[i].pay=pay1; 
								break;      
						case 5: printf("住址改为: ");
								scanf("%s",&addr); 
								strcpy(Staffer[i].addr,addr);
								break;               
						case 6: printf("电话改为: ");  
								scanf("%s",Tel); 
								strcpy(Staffer[i].Tel,Tel);  
								break;   
	                }
	                printf("是否结束修改");
					printf("结束按0,继续按1:");
					scanf("%d",&t); 
                   } while(t);          
    }

}
int main()
{
	int t,s,n;
    do
	{
	menu();
	printf("输入数字1~8\n");
	scanf("%d",&s);
	switch(s)
	{
	case 1:printf("录入员工信息");
	fflush(stdin);
	luru(&n);
	writetofile(n);
	break;
	case 2:printf("添加员工信息");
	fflush(stdin);
	tianjia(&n);
	writetofile(n);
	break;
	case 3:printf("查询员工信息");
	fflush(stdin);
	ReadfromFile(&n);
	search(&n);
	break;
	case 4:printf("修改员工信息");
	fflush(stdin);
	xiugai(&n);
	writetofile(n);
	break;
	case 5:printf("删除员工信息");
	fflush(stdin);
	ReadfromFile(&n);
	shanchu(&n);
	writetofile(n);
	break;
	case 6:printf("员工信息排序");
	fflush(stdin);
	paixu(&n);
	writetofile(n);
	break;
	case 7:printf("浏览员工信息");
	fflush(stdin);
	ReadfromFile(&n);
	display(&n);
	break;
	case 8:printf("结束");
	exit(8);
	fflush(stdin);
	break;
	} 
	printf("是否返回界面\n");
	printf("返回1结束0:\n");
	 scanf("%d",&t);
    }while(t);
	return 0;
}

