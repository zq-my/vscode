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
	printf("                       ��ӭ����                               \n");
	printf("                   Ա����Ϣ����ϵͳ                           \n"); 
	printf("**************************************************************\n");
	printf("       1.¼��Ա����Ϣ");    printf("      2.���Ա����Ϣ       \n");
	printf("       3.��ѯԱ����Ϣ");    printf("      4.�޸�Ա����Ϣ       \n");
	printf("       5.ɾ��Ա����Ϣ");    printf("      6.Ա����Ϣ����   \n");
	printf("       7.���Ա����Ϣ");    printf("      8.�˳�           \n");
	printf("**************************************************************\n");
	printf("\n");
}

int luru(int *n)
{
	int i=0,t;
	do
	{ 
		    printf("�����%dԱ����Ϣ\n",i+1);
			printf("���빤��");
			scanf("%ld",&Staffer[i].Number);
			fflush(stdin);
			printf("��������");
			gets(Staffer[i].name);
	     	 fflush(stdin);
			 printf("�����Ա�");
			 	gets(Staffer[i].sex);
			  fflush(stdin);
			  printf("��������");
			  scanf("%d",&Staffer[i].age);
			  fflush(stdin);
			  printf("���빤��");
			  scanf("%f",&Staffer[i].pay);
			  fflush(stdin);
			  printf("�����ַ");
			  	gets(Staffer[i].addr);
			  fflush(stdin);
			  printf("����绰");
			  	gets(Staffer[i].Tel);
		      i++;
	    printf("�Ƿ����¼��\n");
	    printf("����1����������0����:"); 
	    scanf("%d",&t);
	    
    }while(t);	
	*n=i;
	printf("��������Ϊ%d\n",*n);
}




void display(int *n)  
{  
    int i,a;
	do{	
	printf("\n��˾����ְ����Ϣ:\n"); //printf("\n ԭ��ְ����Ϣ:\n"); 
	printf("\n     ְ����  ���� �Ա�  ����\t����\t\tסַ\t�绰\n"); 
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
	printf("�Ƿ񷵻ز˵���1������0��������");
	scanf("%d",&a); 	    
}while(a);
}   

void paixu(int *n)
{
	int i,j,a,s;
	int Number1; 
    char name1[20];     //����
	char sex1[2];        // �Ա�
	int  age1;          // ����	
	float pay1;        //����
	char  addr1[20];     //סַ
	char Tel1[15];      //�绰
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
	printf("\n��˾����ְ����Ϣ:\n"); //printf("\n ԭ��ְ����Ϣ:\n"); 
	printf("\nְ����\t����\t�Ա�\t����\t����\tסַ\t�绰\n"); 
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
	printf("�Ƿ񷵻ز˵���1������0��������");
	scanf("%d",&s); 	    
}while(s);
		   
	
 }
 void shanchu(int *n)
 {
 	FILE *fp;
	 char name1[10];
	 int i,j,k,t;
	 printf("Ҫɾ����ѧ��������");
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
	    	printf("\n     ְ����  ���� �Ա�  ����\t����\t\tסַ\t�绰\n");
	    	printf("  %8d   %4s   %s\t  %2d   %f   %8s %8s",Staffer[i].Number,
		Staffer[i].name,
		Staffer[i].sex,
		Staffer[i].age,
		Staffer[i].pay,
		Staffer[i].addr,
		Staffer[i].Tel);
	    	printf("�Ƿ�ɾ��\n");
			printf("ɾ����1��ȡ����2");
			scanf("%d",&t); 
	    	break;
			 
		}
    }
    fclose(fp);
    if(i==*n)
    {
    	printf("δ�ҵ���Ϣ\n");
    	
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
	char name[20];     //����
	char sex[2];        // �Ա�
	int  age;          // ����	
	float pay1;        //����
	char  addr[20];     //סַ
	char Tel[15];      //�绰
	    int i=*n,q,m,c;
	    printf("����Ҫ��ӵ�Ա��\n");
	    	printf("���빤��");
		    scanf("%ld",&Staffer[i].Number);
		for(m=0;m<*n;m++)
		{
			if(Staffer[i].Number==Staffer[m].Number)
			{
			printf("���и�Ա��������������"); 
			printf("\n��Ҫ�����޸ĵ�ѡ��\n  1.����  2.�Ա�  3.����    4.����  5.סַ  6.�绰  \n");
				printf("�����������޸ĵ���һ�����:  "); 
				fflush(stdin);
                scanf("%d",&c);               
					switch(c)     
					{                     
						case 1: printf("������Ϊ: "); 
								scanf("%s",name);         
								strcpy(Staffer[m].name,name);
								break;     
						case 2: printf("�Ա��Ϊ��"); 
								scanf("%s",sex);
							strcpy(Staffer[m].sex,sex);
								break;   
						case 3: printf("�����Ϊ: "); 
								scanf("%d",&age);
								Staffer[m].age=age;
								break; 
						case 4: printf("�������ʸ�Ϊ: "); 
								scanf("%f",&pay1);
								Staffer[m].pay=pay1; 
								break;      
						case 5: printf("סַ��Ϊ: ");
								scanf("%s",&addr); 
								strcpy(Staffer[m].addr,addr);
								break;               
						case 6: printf("�绰��Ϊ: ");  
								scanf("%s",Tel); 
								strcpy(Staffer[m].Tel,Tel);  
								break;   
			}
			break;
	  }
	}
	if(m>=*n)
	{
		printf("��������");
		scanf("%s",Staffer[i].name);
		fflush(stdin);
		printf("�����Ա�");
		scanf("%2s",Staffer[i].sex);
		fflush(stdin);
		printf("��������");
		scanf("%2d",&Staffer[i].age);
		fflush(stdin);
		printf("���빤��");
		scanf("%4f",&Staffer[i].pay);
		fflush(stdin);
		printf("�����ַ");
		scanf("%8s",Staffer[i].addr);
		fflush(stdin);
		printf("�������"); 
		scanf("%8s",Staffer[i].Tel);
		fflush(stdin);	
		printf("�Ƿ�������\n");
		printf("����1����0:\n");
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
	
	printf("\n������Ҫ���ҵ�����");
	scanf("%s",name1);
	for(i=0;i<*n;i++)
		if(strcmp(name1,Staffer[i].name)==0)
		{
			printf("\n���ҵ�������Ϣ:\n");	
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
		printf("\n�������Ա���Ĺ���");
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
	char name[20];     //����
	char sex[2];        // �Ա�
	int  age;          // ����	
	float pay1;        //����
	char  addr[20];     //סַ
	char Tel[15];      //�绰
	int number1,i,c,t;
	printf("������Ҫ�޸ĵĹ���");
	scanf("%d",&number1);
	for(i=0;i<*n;i++)
	{
		if(Staffer[i].Number==number1)
		break;	
	} 
	 if(i>=*n)
	 printf("û�ҵ���Ӧ����");
	 else
	 {
	 	printf("\n��Ҫ�����޸ĵ�ѡ��\n  1.����  2.�Ա�  3.����    4.����  5.סַ  6.�绰  \n");
				printf("�����������޸ĵ���һ�����:  "); 
				fflush(stdin);
                scanf("%d",&c);               
				do  {       
					switch(c)     
					{                     
						case 1: printf("������Ϊ: "); 
								scanf("%s",name);         
								strcpy(Staffer[i].name,name);
								break;     
						case 2: printf("�Ա��Ϊ��"); 
								scanf("%s",sex);
							    strcpy(Staffer[i].sex,sex);
								break;   
						case 3: printf("�����Ϊ: "); 
								scanf("%d",&age);
								Staffer[i].age=age;
								break; 
						case 4: printf("�������ʸ�Ϊ: "); 
								scanf("%f",&pay1);
								Staffer[i].pay=pay1; 
								break;      
						case 5: printf("סַ��Ϊ: ");
								scanf("%s",&addr); 
								strcpy(Staffer[i].addr,addr);
								break;               
						case 6: printf("�绰��Ϊ: ");  
								scanf("%s",Tel); 
								strcpy(Staffer[i].Tel,Tel);  
								break;   
	                }
	                printf("�Ƿ�����޸�");
					printf("������0,������1:");
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
	printf("��������1~8\n");
	scanf("%d",&s);
	switch(s)
	{
	case 1:printf("¼��Ա����Ϣ");
	fflush(stdin);
	luru(&n);
	writetofile(n);
	break;
	case 2:printf("���Ա����Ϣ");
	fflush(stdin);
	tianjia(&n);
	writetofile(n);
	break;
	case 3:printf("��ѯԱ����Ϣ");
	fflush(stdin);
	ReadfromFile(&n);
	search(&n);
	break;
	case 4:printf("�޸�Ա����Ϣ");
	fflush(stdin);
	xiugai(&n);
	writetofile(n);
	break;
	case 5:printf("ɾ��Ա����Ϣ");
	fflush(stdin);
	ReadfromFile(&n);
	shanchu(&n);
	writetofile(n);
	break;
	case 6:printf("Ա����Ϣ����");
	fflush(stdin);
	paixu(&n);
	writetofile(n);
	break;
	case 7:printf("���Ա����Ϣ");
	fflush(stdin);
	ReadfromFile(&n);
	display(&n);
	break;
	case 8:printf("����");
	exit(8);
	fflush(stdin);
	break;
	} 
	printf("�Ƿ񷵻ؽ���\n");
	printf("����1����0:\n");
	 scanf("%d",&t);
    }while(t);
	return 0;
}

